/* Relay - 1. Server to Client, 2. Client to Arithmetic servers */

#include "header.h"

/* Function to find the port number of the servers */
int find_port(char operator)
{
    switch(operator)
    {
	case '+':
	    return SUM_SERVER_PORT; 
	    break;
	case '-':
	    return SUB_SERVER_PORT; 
	    break;
	case '/':
	    return DIV_SERVER_PORT; 
	    break;
	case '*':
	    return MUL_SERVER_PORT; 
	    break;
	case '%':
	    return MOD_SERVER_PORT; 
	    break;
    }
    return INVALID_OP;
}

/* Relay main */
int main()
{
    int sock_fd, data_sock_fd, sum, port;
    struct sockaddr_in serv_addr;
    Expression Expr;
    
    /* 1. Create a socket */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    printf("Sock_fd 1H - %d\n", sock_fd);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serv_addr.sin_port = htons(RELAY_PORT);

    /* 2. Bind and listen for connections */
    bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    listen(sock_fd, RELAY_LENGTH);

    /* Loop to run multiple clients concurrently */
    while(1)
    {
	printf("Accepting connections on sock_fd :  %d\n", sock_fd);

	/* 3. Accept connection from CLIENT */
	data_sock_fd = accept(sock_fd, (struct sockaddr *)NULL, NULL);
   
	printf("Created a new fd : %d for I/O\n", data_sock_fd);

	/* 4. Create a child and Perform I/O Operation */	
	if(!fork())
	{
	    /* Recieve data from client */
	    recv(data_sock_fd, (void *)&Expr, sizeof(Expression), 0);

	    printf("%d %d %c\n", Expr.num1, Expr.num2, Expr.operator);
	    close(sock_fd);

	    /* Create a socket Send data to the server */
	    printf("Data recieved, sending it to server\n");

	    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	    printf("Sock_fd 2H - %d\n", sock_fd);

	    /* Find the port number accn., to the operator */
	    struct sockaddr_in rel_addr;
	    rel_addr.sin_family = AF_INET;
	    rel_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	    /* Operator error checking done in the client */ 
	    rel_addr.sin_port = htons(find_port(Expr.operator));

	    /* Conect and send*/
	    connect(sock_fd, (struct sockaddr *)&rel_addr, sizeof(rel_addr));

	    /* Send the data to the server of Portnum 5005 */
	    send(sock_fd, &Expr, sizeof(Expr), 0);

	    /* Recieve data from server */	    
	    recv(sock_fd, &sum, sizeof(sum), 0);
	    printf("Data recieved from server - %d\n", sum);

	    /* Send the data back to the client */
	    send(data_sock_fd, &sum, sizeof(sum), 0);

	    close(sock_fd);
	
	    return 0;
	}   
	close(data_sock_fd);
    }
    close(sock_fd);
}
