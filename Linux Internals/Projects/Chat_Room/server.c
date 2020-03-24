/* Server */

#include "header.h"
#include "helper_functions.c"

//UserInfo *InfoList = NULL;

int sock_fd;

int main()
{
    int data_sock_fd,pid, ack, set = 1;
    struct sockaddr_in serv_addr; 
	Request Cli_req;
	UserInfo userinfo, *temp = NULL;
	Message Msg_packet;
	pthread_t thread;

    printf("TCP_SERVER: Concurrent server is waiting...\n");

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS);
    serv_addr.sin_port = htons(SERVER_PORT); 

    bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(sock_fd, SERVER_LENGTH);

	/* Update the LL from the file */
	update_database();

	printf("Users already present : ");
	temp = InfoList;

	while(temp)
	{
		printf("->%s, %s\n", temp->username, temp->password);
		temp = temp->next;
	}
	
	/* Concurrent server */
    while (1)
    {
		data_sock_fd = accept(sock_fd, (struct sockaddr*)NULL, NULL); 
		
	    printf("New child forked...awaiting client - sock %d\n", data_sock_fd);

	    recv(data_sock_fd, (void *) &Cli_req, sizeof(Cli_req),0);
	    printf("Here is the client data: %s, %s\n", Cli_req.username, Cli_req.password);

		/* Signup Or signin - error checking done in client */
		if(Cli_req.option == 1)
		{
			printf("Sign Up\n");

			/* If user not present Sign up */
			if(!user_registered(&Cli_req, 0))
			{
				printf("INFO : New User\n");

				if(register_user(&Cli_req, data_sock_fd))
				{
					printf("Sending acknowledgment\n");
					ack = 1;
					send(data_sock_fd, (void *)&ack, sizeof(int), 0);
				}
				else
				{
					ack = -1;
					send(data_sock_fd, (void *)&ack, sizeof(int), 0);
					continue;
				}
			}
			else
			{
				ack = 0;
				send(data_sock_fd, (void *)&ack, sizeof(int), 0);
				continue;
			}
		}
		else
		{
			printf("Sign In\n");
			
			if(user_registered(&Cli_req, 1))
			{
				user_login(Cli_req.username, data_sock_fd);
				
				/* Send success ack */
				ack = 1;
				send(data_sock_fd, (void *)&ack, sizeof(int), 0);
			}
			else
			{
				/* Send error */
				ack = 0;
				send(data_sock_fd, (void *)&ack, sizeof(int), 0);
				continue;
			}
		}

		printf("Creating thread\n");

		if(InfoList == NULL)
		{	
			printf("list empty\n");
		}
//		pthread_t thread;
		UserInfo *user = InfoList;
#if 0
		while(user)
		{
			if(user->status == LOGGED_IN && user->sock_fd != data_sock_fd)
			{
				send(data_sock_fd, (void *)user, sizeof(UserInfo), 0);
			}

		}
		send(data_sock_fd, (void *)NULL, sizeof(UserInfo), 0);

		user = InfoList;
#endif
		while(strcmp(user->username, Cli_req.username))
		{
			user = user->next;	
		}
		
		pthread_create(&thread, NULL, thread_function, (void *)user);
		pthread_detach(thread);
		printf("*****************Thread created***************\n");	
	}//while

	close(sock_fd);
}
