#ifndef MAIN_H
#define MAIN_H


#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"

#define RELAY_PORT     5001
#define RELAY_LENGTH   10

#define SUM_SERVER_PORT 5005
#define SUB_SERVER_PORT 5006
#define MUL_SERVER_PORT 5007
#define DIV_SERVER_PORT 5008
#define MOD_SERVER_PORT 5009
#define SERVER_LENGTH 10

#define INVALID_OP -2345

/* Structure to store the user's input */
typedef struct expr{
    int num1, num2;
    char operator;
}Expression;

#endif
