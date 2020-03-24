/*############################################################################################### 
 *
 *           Author         : Shashi Kumar M 
 *           Date           : March 2020
 *           File           : client.c©
 *           Descriptions   : Client side of tftp protocol
 *           Objective      : To send/recive file to/from server
 *           Usage          : ./client <server ip> <port> <filename> <output filename> [get|put]
 *           Output         :
 *
			 References : https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
###############################################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "file.h"
#include "udp.h"
#include "tftp.h"
#include <sys/time.h>

/* Client code for tftp Protocol */

int get_command(char *line, char **args)
{
	char *temp = line;

//	printf("get command\n");

	while(*temp != ' ' && *temp != '\0')
	{
//		printf("->%c:%d\n", *temp, *temp);
		temp++;
	}
//	printf("->END\n");
	
	*args = ++temp;
}

int main()
{
	char *line = NULL, *args = NULL;
	size_t size;
	int sock_fd = -1, c_size, cli_len, serv_len, ret, read_fd, write_fd;
	struct sockaddr_in serv_addr, cli_addr;
	struct timeval tv;
	unsigned long int bytes = 0;
	tv.tv_sec = 2;
	tv.tv_usec = 0;

	packet_t data_packet;
	cli_len = sizeof(cli_len);
	serv_len = sizeof(serv_len);
	fd_set read_fds;
		
	FD_ZERO(&read_fds);

	while(1)
	{
		printf("< tftp >");
		getline(&line, &size, stdin);
	//	printf("Line : %s\n", line);
		line[strlen(line) - 1] = 0;
		int option = get_command(line, &args);

	//	printf("args : %s\n", args);

		memset(&data_packet, 0, sizeof(data_packet));

		/* Connect */
    	if(!strncmp(line, "connect", strlen("connect")))
    	{
//			printf("Command : Connect\n");
    
			if((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
			{
				printf("ERROR : Could not connect\n");
				return 0;
			}

			serv_addr.sin_family = AF_INET;
			serv_addr.sin_port = htons(SERVER_PORT);
			serv_addr.sin_addr.s_addr = inet_addr(args);
			FD_SET(sock_fd, &read_fds);
		}   
		/* Get */
    	else if(!strncmp(line, "get", strlen("get")))
    	{	
//			printf("Command : get, %s\n", args);
    		
			if(sock_fd == -1)
			{
				printf("ERROR : Make connection\n");
				continue;
			}
			
			if(args == NULL)
			{
				printf("Enter file name\n");
				continue;
			}

//			int write_fd = open(args, O_WRONLY | O_CREAT | O_EXCL, 0666);
			/* Create a request packet */
			packet_form_rrq(&data_packet, args);
//			data_packet.opcode = OPCODE_RRQ;
  //  		strcpy(data_packet.filename, args);
    //		strcpy(data_packet.mode, MODE_NETASCII);

	//		printf("Packet created\n");

	//		printf("File name : %s\nMode : %s\n", args, MODE_NETASCII);
//			sendto(sock_fd, &data_packet, sizeof(data_packet), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
			udp_send_packet(sock_fd, data_packet, serv_addr);
			
			printf("INFO : Message sent successfully to the server\n");
			cli_len = sizeof(cli_addr);

            udp_recv_packet(sock_fd, &data_packet, &serv_addr);

            if(data_packet.opcode == OPCODE_ERROR)
            {
                printf("ERROR : File doesnt exist in server\n");
                continue;
            }
            
			write_fd = file_open_write(args);
			if(write_fd == -1)
            {
                printf("ERROR : File already exist\n");
                continue;
            }
			
			bytes = 0;

			while(1)
			{
				ret = select(sock_fd + 1, &read_fds, NULL, NULL, &tv);

				if(ret && ret != -1)
				{
					//recvfrom(sock_fd, &data_packet, sizeof(data_packet), 0, (struct sockaddr *)&cli_addr, &cli_len);
					udp_recv_packet(sock_fd, &data_packet, &cli_addr);
				}
				else
					break;

	//			printf("Recieved a data packet, %lu\n", strlen(data_packet.data));
//				printf("-> %s\n", data_packet.data);

				if(data_packet.opcode == 5)
				{
					printf("ERROR : File doesnt exist\n");
					break;
				}
				else if(data_packet.opcode == 3)
				{
					bytes += strlen(data_packet.data);
					printf(ANSI_COLOR_GREEN "Recieved data packet number %d" ANSI_COLOR_RESET, data_packet.blocknum);
					printf(ANSI_COLOR_YELLOW "\tSending acknowledgement\n"ANSI_COLOR_RESET);
					write(write_fd, data_packet.data, strlen(data_packet.data));
				//	memset(&data_packet, 0, sizeof(data_packet));
					packet_form_ack(&data_packet);
//					data_packet.opcode = 4;
//					data_packet.blocknum = data_packet.blocknum;
			//		sendto(sock_fd, &data_packet, sizeof(data_packet), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
					udp_send_packet(sock_fd, data_packet, serv_addr);		
					if(strlen(data_packet.data) < BLIMIT)
					{
						break;
					}
				}	

					memset(&data_packet, 0, sizeof(data_packet));
			}
			
			printf(ANSI_COLOR_YELLOW "Total bytes recieved : %lu\n"ANSI_COLOR_RESET, bytes);
		}   
		/* Put */
    	else if(!strncmp(line, "put", strlen("put")))
    	{
		#if 1
//		printf("Command : put\n");

            if(sock_fd == -1)
            {
                printf("ERROR : Make connection\n");
                continue;
            }

            if(args == NULL)
            {
                printf("Enter file name\n");
                continue;
            }
			
	//		printf("%s\n", args);

			//read_fd = open(args, O_RDONLY);
            read_fd = file_open_read(args);
			
	//		printf("readfd %d\n", read_fd);

			if(read_fd == -1) 
            {
                printf("ERROR : File Doesnt exist\n");
                continue;
            }

			/* Create a request packet */
            packet_form_wrq(&data_packet, args);

  //          printf("Packet created\n");

            //sendto(sock_fd, &data_packet, sizeof(data_packet), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
			udp_send_packet(sock_fd, data_packet, serv_addr);

			udp_recv_packet(sock_fd, &data_packet, &serv_addr);

			if(data_packet.opcode == OPCODE_ERROR)
			{
				printf("ERROR : File exists in server\n");
				continue;
			}
			printf("INFO : Message sent successfully to the server\n");
			unsigned short num = 0;
			bytes = 0;

//			printf("File name : %s\nMode : %s\n", args, MODE_NETASCII);

			while(read(read_fd, data_packet.data, BLIMIT))
			{
		//		data_packet.blocknum = num;
		//		data_packet.opcode = 3;
				packet_form_data(&data_packet, num);
				
				bytes += strlen(data_packet.data);

			//	sendto(sock_fd, &data_packet, sizeof(data_packet), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
				udp_send_packet(sock_fd, data_packet, serv_addr);

				printf(ANSI_COLOR_GREEN "Sending %dth data packet\t" ANSI_COLOR_RESET, num);
			
				memset(&data_packet, 0, sizeof(data_packet));
	
				ret = select(sock_fd + 1, &read_fds, NULL, NULL, &tv);			
				if(ret && ret != -1)
				{
					recvfrom(sock_fd, &data_packet, sizeof(data_packet), 0, (struct sockaddr *)&serv_addr, &serv_len);

					if(data_packet.blocknum == num)
					{
						printf(ANSI_COLOR_RED "Recieved acknowledgement\n" ANSI_COLOR_RESET);
					}
				}
				else
				{
					printf(ANSI_COLOR_RED "\nERROR : Acknowledgement not recieved for packet %d. Resending packet.\n" ANSI_COLOR_RESET, num);
					lseek(read_fd, -BLIMIT, SEEK_CUR);
					continue;
				}
				num++;
				
				memset(&data_packet, 0, sizeof(data_packet));
			}

			printf(ANSI_COLOR_RED "File content sent to server\n" ANSI_COLOR_RESET);
    	#endif
		}   
		/* Mode */
    	else if(!strncmp(line, "mode", strlen("mode")))
    	{
			printf("Mode Fixed : netascii\n");
		}
		/* Quit */
    	else if(!strncmp(line, "quit", strlen("quit")))
   	 	{
			printf("Command : quit\n");
			return 0;
		}  
		/* Other */
   	 	else 
    	{
			printf("ERROR : Command not found\n");
		}
	}
}

