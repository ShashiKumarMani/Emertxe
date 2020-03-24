/*############################################################################################### 
 *
 *           Author         : 
 *           Date           : 
 *           File           : udp.c©
 *           Descriptions   : Functions to bind udp sockets for server and clients.
 *           Objective      : Create a UDP socket and bind with given IP address and PORT number
 *           Usage          :
 *           Output         :
 *
###############################################################################################*/

#include <netinet/in.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "tftp.h"

/* To create sockets and binding for server and clients*/

void udp_send_packet(int sock_fd, packet_t data_packet, struct sockaddr_in serv_addr)
{
	sendto(sock_fd, &data_packet, sizeof(data_packet), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
}

void udp_recv_packet(int sock_fd, packet_t *data_packet, struct sockaddr_in *cli_addr)
{
	socklen_t cli_len = sizeof(struct sockaddr_in);
	recvfrom(sock_fd, data_packet, sizeof(*data_packet), 0, (struct sockaddr *)cli_addr, &cli_len);
}

