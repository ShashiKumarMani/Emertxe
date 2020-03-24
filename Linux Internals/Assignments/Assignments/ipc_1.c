/*
    Title - Pipes1
    Author - ShashiKumar M
    Date - 28 January 2020
    Description - Use pipes to pass the output of one command to the other.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/* Validate args for 2 commands*/
int validate_args(int argc, char *argv[],int *cmd2)
{
    //Validate
    for(int i = 1;i < argc;i++)
    {
	if(strcmp(argv[i], "|") == 0)
	{
	    if(i != 1 && i + 1 < argc)
	    {
		argv[i] = NULL;
		*cmd2 = i + 1;
		return 1;
	    }	
	    return -1;
	}
    }	
    return -1;
}

int main(int argc, char *argv[])
{
    int pipe_fd[2], cmd2, status, ret1, ret2;

    /*Error check CLA*/
    if(argc < 4)
    {
	printf("ERROR : Usage ./a.out <command 1> '|' <command 2>\n");
	return 0;
    }	

    /* Validate CLA*/
    if(validate_args(argc, argv, &cmd2) == -1)
    {
	printf("ERROR : validation. Exiting...\n");
	return 0;
    }

    /* Create pipe*/
    if(pipe(pipe_fd) == -1) 
    {
	printf("ERROR : Pipe. Exiting....\n");
	return 0;
    }

    int stdout_dup = dup(1);

    /* Child 1 */
    if((ret1 = fork()) == 0)
    {
	/* Write */
	    
	/* Close read end and duplicate write end with stdout*/	    
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	execvp(argv[1], &argv[1]);	  

    }
    else if(ret1 > 0)
    {
	/* Read */

	/* Wait for write*/
	wait(&status);

	/* Restore the standard fd*/
	dup2(stdout_dup, 1);

	/* Close the write end & Duplicate the read end with stdin */
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);

	/* Child 2*/
	if((ret2 = fork()) == 0)
	{	
	    /*Execute the command on the contents of the pipe*/
	    execvp(argv[cmd2], &argv[cmd2]);
	}
	else if(ret2 == -1)
	{	    
	    printf("ERROR : Fork()\n");
	}
	else
	{
	    sleep(1);
	}
    }
    else
    {
	printf("ERROR : Fork()\n");
    }

    return 0;
}
