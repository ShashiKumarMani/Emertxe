/*############################################################################################### 
 *
 *           Author         : Shashi Kumar M 
 *           Date           : 05 March 2020 
 *           File           : server.c©
 *           Descriptions   : Server side of tftp protocol
 *           Objective      : Ready to recive/send data to client 
 *           Usage          : ./server <port number>
 *           Output         : 
 *
###############################################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "file.h"
#include "udp.h"
#include "tftp.h"
#include <arpa/inet.h>

int main()
{

	int sock_fd, cli_len, read_fd, write_fd, ret, num;
	struct sockaddr_in serv_addr;
	struct sockaddr_in cli_addr;
	struct timeval tv;
	packet_t data_packet;
	fd_set read_fds;

	tv.tv_sec = 2;
	tv.tv_usec = 0;

	sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serv_addr.sin_port = htons(SERVER_PORT);

	bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	FD_ZERO(&read_fds);
	FD_SET(sock_fd, &read_fds);

	/* Server RRQ & WRQ */
	while(1)
	{
		memset(&data_packet, 0, sizeof(data_packet));
		
		cli_len = sizeof(struct sockaddr_in);
		
		/* Recieve Initial Connection request packet */
//		recvfrom(sock_fd, (void *)&data_packet, sizeof(data_packet), 0, (struct sockaddr *)&cli_addr, &cli_len);
		udp_recv_packet(sock_fd, &data_packet, &cli_addr);

		printf("Packet recieved, %s %d %s\n", data_packet.filename, data_packet.opcode, data_packet.mode);		

		/* Read Request */
		if(data_packet.opcode == 1)
		{
			printf("Read request\nfile : %s\nMode : %s", data_packet.filename, data_packet.mode);
			
			read_fd = open(data_packet.filename, O_RDONLY);
		
			/* Send ERROR packet */
			if(read_fd == -1)
			{
				printf("ERROR : File open\n");
				memset(&data_packet, 0, sizeof(data_packet));
				
				packet_form_error(&data_packet);

				//sendto(sock_fd, (void *)&data_packet, sizeof(data_packet), 0, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
				udp_send_packet(sock_fd, data_packet, cli_addr);
				continue;
			}

            packet_form_ack(&data_packet);

           // sendto(sock_fd, (void *)&data_packet, sizeof(data_packet), 0, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
            udp_send_packet(sock_fd, data_packet, cli_addr);			

			/* Loop and send the data to the client */
    		while(read(read_fd, data_packet.data, BLIMIT))
			{
		//		data_packet.blocknum = num;
				
				packet_form_data(&data_packet, num);
		//		data_packet.opcode = 3;

				printf("Sending %dth Data packet of size %lu\t", num, strlen(data_packet.data));
				
    			//sendto(sock_fd, &data_packet, sizeof(data_packet), 0, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
				udp_send_packet(sock_fd, data_packet, cli_addr);

				printf("Packet sent\n");
    			
				ret = select(sock_fd + 1, &read_fds, NULL, NULL, &tv);
				
				if(ret && ret != -1)
				{
					/* Recieve acknowledgement-packet num from client */
    				//recvfrom(sock_fd, &data_packet, sizeof(data_packet), 0, (struct sockaddr *)&cli_addr, &cli_len);
					udp_recv_packet(sock_fd, &data_packet, &cli_addr);
    				if(data_packet.blocknum == num)
    				{  	 
						printf("Recieved Acknowledgement\n");
    				}
				}
				else
				{
        			printf("\nERROR : Acknowledgement not recieved for the data packet. Resending packet..\n");
					lseek(read_fd, -BLIMIT, SEEK_CUR);
					continue;
				}
    			num++;
   					
				memset(&data_packet, 0, sizeof(data_packet));
			} 
			
			printf("INFO : Request Done.\n");
		}
		/* Write Request */
		else if(data_packet.opcode == 2)
		{
#if 1
			printf("Write request\n");
			
//			write_fd = open(data_packet.filename, O_WRONLY | O_CREAT, 0666);
			write_fd = file_open_write(data_packet.filename);

			printf("writefd - %d\n", write_fd);

            /* Send ERROR packet */
            if(write_fd == -1)
            {
                printf("ERROR : File open\n");
                memset(&data_packet, 0, sizeof(data_packet));

                packet_form_error(&data_packet);

                //sendto(sock_fd, (void *)&data_packet, sizeof(data_packet), 0, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
				udp_send_packet(sock_fd, data_packet, cli_addr);
                continue;
            }

			packet_form_ack(&data_packet);

           // sendto(sock_fd, (void *)&data_packet, sizeof(data_packet), 0, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
			udp_send_packet(sock_fd, data_packet, cli_addr);

			cli_len = sizeof(cli_addr);

			while(1)
			{
				ret = select(sock_fd + 1, &read_fds, NULL, NULL, &tv);

				if(ret && ret != -1)
//					recvfrom(sock_fd, &data_packet, sizeof(data_packet), 0, (struct sockaddr *)&cli_addr, &cli_len);
					udp_recv_packet(sock_fd, &data_packet, &cli_addr);
				else
					break;

				if(data_packet.opcode == 3)
				{
					write(write_fd, data_packet.data, strlen(data_packet.data));
					//memset(&data_packet, 0, sizeof(data_packet));

					packet_form_ack(&data_packet);

					printf("Sending Acknowledgement\n");

				sendto(sock_fd, &data_packet, sizeof(data_packet), 0, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
	//				udp_send_packet(sock_fd, data_packet, cli_addr);

					printf("Ack sent.\n");

					if(strlen(data_packet.data) < BLIMIT)
					{
						printf("File EOF\n");
						break;
					}
					memset(&data_packet, 0, sizeof(data_packet));
				}
			}

			printf("INFO : Request Done.\n");
	#endif
	}
	}
}
