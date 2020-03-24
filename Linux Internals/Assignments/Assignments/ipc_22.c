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

/* Validate args for 2 commands*/
int validate_args(int argc, char *argv[],int *cmd2, int *cmd3)
{
    int flag = 0;
    //Validate
    for(int i = 1;i < argc;i++)
    {
	if(strcmp(argv[i], "|") == 0)
	{
	    if(i != 1 && i + 1 < argc)
	    {
		argv[i] = NULL;
		if(flag)
		{
		    *cmd3 = i + 1;
		    flag = 2;
		}
		else
		{
		    *cmd2 = i + 1;
		    flag = 1;
		}
	    }	
	}
    }
    return flag == 2 ? 1 : -1;
}

/* Main */
int main(int argc, char *argv[])
{
    int pipe1[2], cmd2, cmd3, status, ret;

    /* Error check CLA */
    if(argc < 4)
    {
	printf("ERROR : Usage ./a.out <command 1> '|' <command 2> '|' <command 3>\n");
	return 0;
    }	

    /* Validate CLA */
    if(validate_args(argc, argv, &cmd2, &cmd3) == -1)
    {
	printf("ERROR : Validation. Exiting...\n");
	return 0;
    }

    /* Create pipe*/
    if(pipe(pipe1) == -1)// || pipe(pipe2) == -1) 
    {
	printf("ERROR : Pipe. Exiting....\n");
	return 0;
    }

  //  printf("cmd2 - %d, cmd3 - %d\n", cmd2, cmd3);

    int num, stdout_dup = dup(1), stdin_dup = dup(0);

    if((ret = fork()) == 0)
    {
//	close(pipe1[0]);
	dup2(pipe1[1], 1);
	execvp(argv[1], &argv[1]);	  
//	close(pipe1[0]);
    }
    else if(ret > 0)
    {
	sleep(3);
	dup2(stdout_dup, 1);
//	dup2(pipe1[1], 1);	
	dup2(pipe1[0], 0);

	if((ret = fork()) == 0)
	{
	    execvp(argv[cmd2], &argv[cmd2]);
	}
	else if(ret > 0)
	{
	    sleep(2);

	    dup2(stdout_dup, 1);

	    if((ret = fork()) == 0)
	    {
//		dup2(pipe1[0], 0);
		execvp(argv[cmd3], &argv[cmd3]);	    
	    }
	}
    }

    return 0;
}
