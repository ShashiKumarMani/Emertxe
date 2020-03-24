#ifndef HEADER_H
#define HEADER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

#define SERVER_IP_ADDRESS   "127.0.0.1"
#define SERVER_PORT         6330
#define SERVER_LENGTH   50

#define USER_DB "user_database.txt"
#define TEMP_FILE "user_temp.txt"
#define LOGGED_IN 1
#define LOGGED_OUT 0
#define LINE_SIZE 100
#define MAX_LEN 50
#define MSG_LEN 1024
#define DEF_NAME "SERV"

/* Client request structure */
typedef struct request{
    
    char username[MAX_LEN];
	char password[MAX_LEN];
    int option;

}Request;

/* Message */
typedef struct message{
        
    int reciever_fd;
    int sender_fd;
    char message[MSG_LEN];
    int chat_option;

}Message;

typedef struct userinfo{

	char username[MAX_LEN];
	char password[MAX_LEN];
	int status;
	int sock_fd;
	struct userinfo *next;

}UserInfo;

UserInfo *InfoList = NULL;
//int sock_fd;

int get_userinfo(UserInfo *userinfo, char *line);
int register_user(Request *userinfo, int data_sock_fd);
int user_login(char *username, int data_sock_fd);
int print_logged_users(void);
int send_message(Message *Msg_packet, int sender_fd);
void *thread_function(void *);
void user_logout(int sock_fd);
int single_chat_fd(char *name);
void add_user_db(Request *);
#endif
