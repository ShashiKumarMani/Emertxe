/* Multiplication Server */

#include "header.h"

int main()
{
    int sock_fd, data_sock_fd;
    struct sockaddr_in serv_addr;
    Expression Expr;

    /* Create a socket */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    printf("Sock_fd - %d\n", sock_fd);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serv_addr.sin_port = htons(MUL_SERVER_PORT);

    bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    listen(sock_fd, SERVER_LENGTH);

    /* Serve Concurrently */
    while(1)
    {
	data_sock_fd = accept(sock_fd, (struct sockaddr *)NULL, NULL);
	
	/* Child process */
	if(!fork())
	{
	    recv(data_sock_fd, &Expr, sizeof(Expr), 0);	
	    printf("Recieved data : %d %d %c\n", Expr.num1, Expr.num2, Expr.operator);
	    int sum = Expr.num1 * Expr.num2;
	    send(data_sock_fd, &sum, sizeof(sum), 0);
//	    printf("Data sent to relay\n");
	    return 0;
	}
	close(data_sock_fd);
    }

    close(data_sock_fd);
    close(sock_fd);
}
