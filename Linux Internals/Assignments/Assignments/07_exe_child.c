/*
    Title - exe_child
    Author - Shashikumar M
    Date - 27 January 2020
    Description - Program to create a child process which will execute a command passed through command line
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    //Error check CLA
    if(argc < 2)
    {
	printf("\nERROR : Usage: ./a.out commands.\n");
	return 0;
    }

    int ret, wstatus;
    pid_t pid = fork();
   
    //If child process 
    if(pid == 0)
    {
	printf("\nThis is the child process with ID - %d\n", getpid());

	if(execvp(argv[1], &argv[1]) == -1)
	{
	    printf("\nERROR : Exec\n");
	}
    }
    //If parent process
    else
    {
	//Wait for the child process to complete, get status
	pid = wait(&wstatus);

	//If child termainated normally, print the exit status
	if(WIFEXITED(wstatus))
	{
	    printf("\nChild terminated normally with code - %d\n", WEXITSTATUS(wstatus));
	}
	else
	{
	    printf("Child terminated abnormally  with code - %d\n", WTERMSIG(wstatus));
	}
    }
    
    return 0;
}
