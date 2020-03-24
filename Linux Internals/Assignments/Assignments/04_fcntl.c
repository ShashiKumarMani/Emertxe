/*
    Title - 04_fcntl
    Author - Shashikumar M
    Date - 
    Description -  
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv)
{
    pid_t pid;
    struct flock lock;
    char buff[10];

    if(argc < 2)
    {
	printf("ERROR : Please enter a file\n");
	return 0;
    }
    
    int fd = open(argv[1], O_WRONLY | O_CREAT, 0666);
    
    /* Child */
    if((pid = fork()) == 0)
    {
	printf("Child : File lock\n");

	fcntl(fd, F_WRLCK);

	write(fd, "\nChild : File lock\n", strlen("Child : File lock\n") + 1);
	write(fd, "Child : Prime number upto 20 : \n", strlen("Child : Prime number upto 20 : \n") + 1);

	write(fd, "1\n", strlen("1\n") + 1);

	/* Prime numbers */
	for(int i = 2;i <= 20;i++)
	{
	    /* Loop the number till half of its value */
	    for(int j = i;j <= i / 2;j++)
	    {

	    }
	}

	fcntl(fd, F_UNLCK);	

	write(fd, "Child : File Unlock\n", strlen("Child : File Unlock\n") + 1);
	printf("Child : File unlock\n");
    }
    else if(pid > 0)
    {
	printf("Parent : File lock\n");

	write(fd, "Parent : File lock\n", strlen("Parent : File lock\n") + 1);
	write(fd, "Parent : Fibonacci series upto 20 : \n", strlen("Parent : Fibonacci series upto 20 : \n") + 1);

	/* Lock the file */
        fcntl(fd, F_WRLCK);     
	
	int num1 = 0;
	int num2 = 1;
	int num3 = 0;
	char buff[10];

	/*  Write Fibonacci series to the file*/	
	while(num1 <= 20)
	{
//	    printf("%d\n", num1);
	    sprintf(buff, "%d\n", num1);
	    write(fd, buff, strlen(buff) + 1);
	    num3 = num1 + num2;
	    num1 = num2;
	    num2 = num3;
	}

	/* Unlock the file */
	fcntl(fd, F_UNLCK);

	write(fd, "Parent : File unlock\n", strlen("Parent : File unlock\n") + 1);
	printf("Parent : File unlock\n");
    }
    else
    {
	printf("ERROR : Fork()\n");
    }

    close(fd);
}
