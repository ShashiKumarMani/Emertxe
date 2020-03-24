/* Client */

#include "header.h"

/* Function to fill the expression structure */
int cla_to_args(char **argv, Expression *Expr)
{
    Expr->num1 = atoi(argv[1]);
    Expr->num2 = atoi(argv[3]);
    Expr->operator = argv[2][0];    

    switch(Expr->operator)
    {
	case '+':
	case '-':
	case '%':
	case '/':
	case '*':
		return 1;
		    break;
	default :
		return 0;
    }
}

/* Client main */
int main(int argc, char **argv)
{
    int sock_fd, sum;
    struct sockaddr_in serv_addr;
    Expression Expr;

    /* Error check CLA*/
    if(argc < 4)
    {
	printf("ERROR: Usage ./a.out <num1> <operator> <num2>\n");
	return 0;
    }

    /* Update expression structure */
    if(!cla_to_args(argv, &Expr))
    {
	printf("ERROR : Enter valid operators < + - / %% *> ");
	return 0;
    }

    printf("Entered : %d %d %c\n", Expr.num1, Expr.num2, Expr.operator);

    /* Create a socket */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(RELAY_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    /* Assuming connection is robust */
    connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    send(sock_fd, &Expr, sizeof(Expr), 0);

    /* Recieve the result from the relay */
    recv(sock_fd, &sum, sizeof(sum), 0);

    printf("Result : %d\n", sum);
    close(sock_fd);

    return 0;
}
