/*
    Title - Pipes2
    Author - ShashiKumar M
    Date - 28 January 2020
    Description - Use 2 pipes execute 3 commands.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/* Main */
int main(int argc, char *argv[])
{
    int pipe1[2], pipe2[2], cmd2, cmd3, status, ret;
    char buffer[50];

    /* Create pipe*/
    if(pipe(pipe1) == -1 || pipe(pipe2) == -1) 
    {
	printf("ERROR : Pipe. Exiting....\n");
	return 0;
    }
    
    int num, stdout_dup = dup(1), stdin_dup = dup(0), ret1, ret2, ret3;
    char buffer2[50];

    /* C1 */
    if((ret1 = fork()) == 0)
    {
	close(pipe1[0]);
	dup2(pipe1[1], 1);
	write(pipe1[1], "string", strlen("string") + 1);
	close(pipe1[1]);
    }
    else if(ret1 > 0)
    {
	waitpid(ret1, NULL, 0);

	/* C2 */
	if((ret2 = fork()) == 0)
	{
	    dup2(pipe1[0], 0);
	    dup2(pipe1[1], 1);
	    read(pipe1[0], buffer, strlen("string") + 1);

	    write(pipe1[1], buffer, strlen("string") + 1);
	   //close(pipe1[1]);
	}
	else if(ret2 > 0)
	{
	    /* C3 */
	    waitpid(ret2, NULL, 0);
	    if((ret3 = fork()) == 0)
	    {
		dup2(pipe1[0], 0);
		read(pipe1[0], buffer2, strlen("string") + 1);
		printf("3 : string read from buffer - %s\n", buffer2);

	    }
	    else if(ret3 == -1)
	    {
		printf("ERROR : Fork()\n");
	    }
	    else
	    {

		waitpid(ret3, NULL, 0);
		sleep(1);
	    }
	}
	else
	{	    
	    printf("ERROR : Fork()\n");
	}
    }
    else
    {
	printf("ERROR : Fork()\n");
    }
    
    return 0;
}
