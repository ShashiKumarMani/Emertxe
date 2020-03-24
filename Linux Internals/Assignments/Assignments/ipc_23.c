/*
    Title - n_Pipes
    Author - ShashiKumar M
    Date - 30 January 2020
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

int validate_args(int argc, char *argv[],int **indices)
{
    int i = 1, j = 0, *ind = malloc(sizeof(int) * (argc / 2));

    ind[j++] = 1;

    while(argv[i])
    {
	if(!strcmp(argv[i], "|"))
	{
//	    printf("Match at %d\n", i);
	    argv[i] = NULL;
	    ind[j++] = i + 1;
	}
	i++;
    }
//    printf("j - %d\n", j);
    *indices = ind;
    
    return j;
}

/* Main */
int main(int argc, char *argv[])
{
    int i, ret = 0, *indices = NULL;
    pid_t pid;

    /* Error check CLA */
    if(argc < 4)
    {
	printf("ERROR : Usage ./a.out <command 1> '|' <command 2> '|' <command 3>\n");
	return 0;
    }	

    /* Validate CLA */
    if((argc = validate_args(argc, argv, &indices)) == -1)
    {
	printf("ERROR : Validation. Exiting...\n");
	return 0;
    }

  //  printf("argc - %d\n", argc);

    /* Execute the commands */
    for(i = 0;i < argc;i++)
    {
	int pipe_fd[2];
	
	if(pipe(pipe_fd) == -1)
	{
	    printf("ERROR : Pipe. Exiting....\n");
	    return 0;
	}

	/* Child */
	if((pid = fork()) == 0)
	{
	    /* If next command exist, print to the pipe OR stdout */
	    if(i < argc - 1)
		//redirecting stdout to write fd
		dup2(pipe_fd[1], 1);
	    
	    execvp(argv[indices[i]], &argv[indices[i]]);
	}
	/* Parent */
	else if(pid > 0)
	{
	    waitpid(pid, NULL, 0);
	    //printf("Execution completed - %s\n", argv[indices[i]]);
	    dup2(pipe_fd[0], 0);
	    close(pipe_fd[1]);
	}
	else
	{
	    printf("ERROR : Fork(). Exiting...\n");
	    return 0;
	}
    }

    return 0;
}
