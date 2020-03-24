/* Helper Functions */

#include "header.h"

/* Function used to perform file operations */
int my_getline(char **line, int read_fd)
{
    char *string = malloc(sizeof(char) * LINE_SIZE), ch = 'A';
    int i = 0;

    while(ch != '\n')
    {
        if(!read(read_fd, &ch, 1))
            break;

        if(i >= LINE_SIZE)
            string = realloc(string, sizeof(string) * 2);
        
        string[i++] = ch;
    }
    
    string[--i] = 0;
    *line = string;
}

/* Function to get user information */
int get_userinfo(UserInfo *userinfo, char *line)
{
    printf("FUNC : get userinfo from line : %s\n", line);

    if(line == NULL)
    {
        return 0;
    }
    char *token = NULL;

    /* Assuming data was written without any errors */
    strcpy(userinfo->username, strtok(line, ","));
    strcpy(userinfo->password,strtok(NULL, ","));
    userinfo->status = LOGGED_OUT;//atoi(strtok(NULL, ","));
    userinfo->sock_fd = -1;//atoi(strtok(NULL, ","));
}

/* Function to update the LL from the file */
void update_database(void)
{
	int read_fd = open(USER_DB, O_RDONLY);
	char buff, *line = NULL;
	UserInfo *temp = NULL, *prev = NULL;
	InfoList = temp;

	while(read(read_fd, &buff, 1))
	{
		temp = malloc(sizeof(UserInfo));

		lseek(read_fd, -1, SEEK_CUR);
		my_getline(&line, read_fd);
		get_userinfo(temp, line);

		printf("%s %s %d %d", temp->username, temp->password, temp->sock_fd, temp->status);

		if(InfoList == NULL)
		{
			InfoList = prev = temp;
		}
		else
		{
			prev->next = temp;
			prev = prev->next;
		}
		printf("0\n");
	}
}

/* Function to find if a user is registered */
int user_registered(Request *Cli_req, int flag)
{
	printf("FUNC : User registered\n");
	UserInfo *temp = InfoList;

	if(temp == NULL)
	{
		return 0;
	}

	while(temp)
	{
		if(!strcmp(Cli_req->username, temp->username))
		{
			if(!flag)
				return 1;
			else if(!strcmp(Cli_req->password, temp->password))
				return 1;
			else
				return 0;
		}
		temp = temp->next;
	}
	return 0;
}

/* Function to add user to the database */
int register_user(Request *Cli_req, int data_sock_fd)
{
	printf("FUNC : Register user, User:%s, Pass:%s\n", Cli_req->username, Cli_req->password);

	UserInfo *new = malloc(sizeof(UserInfo));
	
	if(new == NULL)
		return 0;

	new->next = NULL;
	new->status = LOGGED_IN;
	strcpy(new->username, Cli_req->username);
	strcpy(new->password, Cli_req->password);
	new->sock_fd = data_sock_fd;

	printf("Packet created\n");
	UserInfo *temp = InfoList;

	if(temp == NULL)
	{
		printf("First user\n");
		InfoList = new;
		return 1;
	}

	while(temp->next)
	{
		temp = temp->next;
	}
	temp->next = new;
	
	printf("User registered\n");

	/* Add user to the file data base */
	add_user_db(Cli_req);

	return 1;
}

/* Function to update user status */
int user_login(char *username, int data_sock_fd)
{
	printf("FUNC : User login\n");

	UserInfo *temp = InfoList;

	while(temp)
	{
		if(!strcmp(username, temp->username))
		{
			temp->status = !temp->status;
			temp->sock_fd = data_sock_fd;
			return 1;
		}
		temp = temp->next;
	}
}

/* Print logged in users */
int print_logged_users(void)
{
	printf("FUNC : Print logged users\n");
	
	UserInfo *temp = InfoList;

	while(temp)
	{
		if(temp->status == LOGGED_IN)
		{
			printf("%s ONLINE\n", temp->username);
		}
		temp = temp->next;
	}
}

/* Send message to all logged in user except the sender */
int send_message(Message *Msg_packet, int sender_fd)
{
	printf("FUNC : Send message %s, sender : %d\n", Msg_packet->message, sender_fd);

	UserInfo *temp = InfoList;

	while(temp)
	{
		if(temp->sock_fd != sender_fd && temp->status == LOGGED_IN)
		{
			printf("Sending message to %s\n", temp->username);
			send(temp->sock_fd, &Msg_packet, sizeof(Msg_packet), 0);
		}
		temp = temp->next;
	}	
}

/* Server thread too interact with client threads, one for every client */
void *thread_function(void *user)
{
		/* Print all users LOGGED IN */
		UserInfo *userinfo = user, *temp = InfoList;
		Message Msg_packet;
		int data_sock_fd = userinfo->sock_fd, ack, ret;
		char name[50];
		fd_set set;
		FD_ZERO(&set);
		FD_SET(data_sock_fd, &set);
		struct timeval tv;
		tv.tv_sec = 1;
		tv.tv_usec = 0;

       /* Send all online users */
        while(temp)
        {
            memset(&Msg_packet, 0, sizeof(Msg_packet));
            if(temp->sock_fd != data_sock_fd && temp->status == LOGGED_IN)            {
                sprintf(Msg_packet.message, "%s", temp->username);
                send(data_sock_fd, (void *)&Msg_packet, sizeof(Msg_packet), 0);
            }
            temp = temp->next;
        }

        Msg_packet.message[0] = 0;;
        send(data_sock_fd, (void *)&Msg_packet, sizeof(Msg_packet), 0);
		
		/* Recieve name*/
		recv(data_sock_fd, name, sizeof(name), 0);
		
		printf("*****Checking %s \n", name);
		ack = single_chat_fd(name);

		/* Send sock fd if user exists OR -1*/
		send(data_sock_fd, (void *)&ack, sizeof(ack), 0);
		
		printf("Data_sock_Fd : %d\n", data_sock_fd);

		temp = InfoList;
        memset(&Msg_packet, 0, sizeof(Msg_packet));
        sprintf(Msg_packet.message, "User %s is ONLINE->", userinfo->username);

       /* Send msg to all users */
        while(temp)
        {
            if(temp->sock_fd != data_sock_fd && temp->status == LOGGED_IN)            {
                send(temp->sock_fd, (void *)&Msg_packet, sizeof(Msg_packet), 0);
            }
            temp = temp->next;
        }

	
		/* Recv and send to all clients */
		while(1)
		{
			memset(&Msg_packet, 0, sizeof(Msg_packet));
			
//			ret = select(data_sock_fd + 1, &set, NULL, NULL, &tv);
//			if(!ret)
//			{
//				printf("BREAK\n");
//				break;
//			}
			/* Recieve message from client */
			recv(data_sock_fd, (void *)&Msg_packet, sizeof(Msg_packet), 0);
			printf("Message recieved from a client\nMsg: %s\n", Msg_packet.message);

			Msg_packet.sender_fd = data_sock_fd;

			temp = InfoList;

			/* If logout break from loop*/
			if(Msg_packet.chat_option == 3)
			{
				while(temp->sock_fd != data_sock_fd)
				{
					temp = temp->next;
				}

				sprintf(Msg_packet.message, "%s Logged Out\n", temp->username);
//				break;
			}
				
			/* Send the message to reciever/s*/
//			send_message(&Msg_packet, data_sock_fd);

			printf("***Reciever fd : %d\n", Msg_packet.reciever_fd);
		
			temp = InfoList;

			if(Msg_packet.reciever_fd == -1)
			{
				while(temp)
				{
					if(temp->sock_fd != data_sock_fd && temp->status == LOGGED_IN)
					{
						printf("Sending message to %s\n", temp->username);
						send(temp->sock_fd, &Msg_packet, sizeof(Msg_packet), 0);
						
					}
					temp = temp->next;
				}
			}
			else
			{
				printf("Sending SG message to %s\n", temp->username);
				send(Msg_packet.reciever_fd, &Msg_packet, sizeof(Msg_packet), 0);
			}
			if(Msg_packet.chat_option == 3)
				break;

		}

		/* User logout remove node from LL */
		user_logout(Msg_packet.sender_fd);
		printf("Logging the user out...\n");

		close(data_sock_fd);
}

/* Function to get sock fd given a username */
int single_chat_fd(char *uname)
{
	printf("FUNC : Single Chat, find : %s\n", uname );

	UserInfo *temp = InfoList;

	if(temp == NULL)
		printf("List Empty\n");

	while(temp)
	{
		printf("User : %s\n", temp->username);

		if(!strcmp(temp->username, uname))
		{
			printf("User found\n");
			return temp->sock_fd;
		}
		temp = temp->next;
	}
	
	printf("User not found\n");
	return -1;
}

/* Function to logout the user */
void user_logout(int user_fd)
{
	UserInfo *temp = InfoList, *prev = NULL;

	while(temp)
	{
		if(temp->sock_fd == user_fd)
		{
			temp->status = LOGGED_OUT;
			return;
		}
		temp = temp->next;
	}
}

/* Function to add user to the data file*/
void add_user_db(Request *Cli_req)
{
	printf("Adding new user\n");

	int read_fd = open(USER_DB, O_RDONLY), write_fd = open(TEMP_FILE, O_WRONLY | O_CREAT, 0666);
	char buff, buffer[LINE_SIZE * 2];

	while(read(read_fd, &buff, 1))
	{
		write(write_fd, &buff, 1);
	}
	sprintf(buffer, "%s,%s\n", Cli_req->username, Cli_req->password);
	printf("->%s\n", buffer);
	write(write_fd, buffer, strlen(buffer));
	close(read_fd);
	close(write_fd);

	read_fd = open(TEMP_FILE, O_RDONLY), write_fd = open(USER_DB, O_WRONLY);

	if(read_fd == -1 || write_fd == -1)
		printf("ERROR : Open()\n");

	while(read(read_fd, &buff, 1))
	{
		printf("%c\n", buff);
		write(write_fd, &buff, 1);
	}
	close(read_fd);
	close(write_fd);
}
