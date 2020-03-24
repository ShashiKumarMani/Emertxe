/* Client */

#include "header.h"
#include "helper_functions.c"

//extern UserInfo *InfoList;

int sock_fd;

char *buff = "Enter the message to send / exit to exit : ";
void *write_message(void *packet)
{
	Message Msg_packet = *(Message *)packet;
	int ack = 0, retval;// sock_fd = Msg_packet.reciever_fd;

	/* Write message to server */
	while(1)
	{
		__fpurge(stdin);
		printf("\n%s\n", buff);

		if(Msg_packet.chat_option != 3)
		{	
				//memset(&Msg_packet, 0, sizeof(Msg_packet));
    //		scanf("%[^\n]s", Msg_packet.message);
			fgets(Msg_packet.message, MSG_LEN - 1, stdin);

			if(!strncmp(Msg_packet.message, "exit", 4))
			{
				Msg_packet.chat_option = 3;
			}
		}
		else
			printf("Log out request sent\n");

        /* Send message */
        send(sock_fd, (void *)&Msg_packet, sizeof(Msg_packet), 0); 
                
		printf("Message sent successfully\n");

    	/* If logout dont wait for ACK quit */
   	 	if(Msg_packet.chat_option == 3)
    	{
			printf("Logging out...\n");
        	exit(0);
    	}	
	}
}

void *read_message(void *packet)
{
	Message Msg_packet = *(Message *)packet;
	int ret, retval = 0;//, sock_fd = Msg_packet.reciever_fd;

	/* Read message */
	while(1)
	{
		memset(&Msg_packet, 0, sizeof(Msg_packet));
		ret = recv(sock_fd, (void *)&Msg_packet, sizeof(Msg_packet), 0);
					
		if(ret > 0)
		{
			printf("\nMessage from server : \n%s\nEnter the message to send / exit to exit :\n", Msg_packet.message);
		}
	}
}

int main()
{
    int c_size, ack, ret;
	size_t size;
    struct sockaddr_in serv_addr; 
	Request Cli_req;
	Message Msg_packet;
	pthread_t thread1, thread2;
	UserInfo *temp = NULL;
	char name[50] = DEF_NAME;
	signal(SIGINT, SIG_IGN);

    /* Create a client socket */
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
		printf("Error: Could not create socket\n");
		return 1;
    } 
	else
	{
		printf("Socket Created\n");
	}
    
	serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT); 
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(sock_fd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) == -1)
    {
		perror("connect");
		printf("Error connecting to server\n");
		exit(1);
    }
    else
		printf("Connection successful\n");

	printf("Enter the option\n1. Register\n2. Login\n->");
	scanf("%d", &Cli_req.option);

	/* Execute option */
	if(Cli_req.option == 1 || Cli_req.option == 2)
	{
		__fpurge(stdin);

		printf("Enter the username : ");
		scanf("%s", Cli_req.username);
		printf("Enter the password : ");
		scanf("%s", Cli_req.password);

		/* Send request packet */
    	c_size = send(sock_fd, (void *)&Cli_req, sizeof(Cli_req), 0);	
		if(c_size != -1)
			printf("Connection Request Sent\n");

		/* Recieve Acknowledgement */
		recv(sock_fd, (void *)&ack, sizeof(int), 0);
		
		if(Cli_req.option == 1)
		{
			switch(ack)
			{
				case -1:
						printf("\nERROR : Memory Allocation\n");
						return 0;
				break;
				case 0:
						printf("\nERROR : User Already registered\n");
						return 0;
				break;
				case 1:
						printf("\nINFO : Registration success\n");
				break;
			}
		}
		else if(Cli_req.option == 2)
		{
			switch(ack)
			{
				case 0:
					printf("\nERROR : Username OR Password Incorrect\n");
					return 0;
				break;
				case 1:
					printf("\nINFO : User signed in\n");
				break;
			}
		}
	#if 1
		/* Recieve all online users - TODO header,extern*/
		Message Name_packet;
		
		printf("\nList of online users : \n");

		while(1)
		{
			recv(sock_fd, (void *)&Name_packet, sizeof(Message), 0);
			if(Name_packet.message[0] == 0)
				break;
			else
				printf("User %s ONLINE\n", Name_packet.message);
		}
#endif
        printf("Select\n1. Single Chat\n2. Group Chat\n3. Logout\n->");
        scanf("%d", &Msg_packet.chat_option);

		printf("Option selected : %d\n", Msg_packet.chat_option);

		Msg_packet.reciever_fd = -1;
		
		/* If single chat read the user name and get theyy sock fd */
		if(Msg_packet.chat_option == 1)
		{
			printf("Enter the name : ");
			scanf("%s", name);
		}
		send(sock_fd, (void *)name, sizeof(name), 0);

		recv(sock_fd, (void *)&Msg_packet.reciever_fd, sizeof(Msg_packet.reciever_fd), 0);

		/* For safety */
		if(Msg_packet.chat_option == 2)
			Msg_packet.reciever_fd = -1;

		if(Msg_packet.chat_option == 1 && Msg_packet.reciever_fd == -1)
		{
			printf("User not found OR not logged in, Switching to Group Chat...\n");
		}

		printf("Chat fd : %d\n", Msg_packet.reciever_fd);

		/* Create write read threads for parallel read and write */
		pthread_create(&thread1, NULL, (void *)write_message, (void *)&Msg_packet);
        pthread_create(&thread1, NULL, (void *)read_message, (void *)&Msg_packet);
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
    }   
    else
    {   
        printf("ERROR : Invalid Option\n");
    }   
    close(sock_fd);
}
