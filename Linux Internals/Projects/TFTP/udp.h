
#ifndef TFTP_UDP
#define TFTP_UDP
#define SERVER_IP   "127.0.0.1"
#define SERVER_PORT     5001
#define SERVER_LENGTH   10
#define SERVER_BUFF 20

#include <sys/socket.h>
#include "tftp.h"

void udp_bind_server();
void udp_rebind_server();
void udp_bind_client();
void udp_send_packet(int, packet_t, struct sockaddr_in);
void udp_recv_packet(int, packet_t *, struct sockaddr_in *);
#endif
