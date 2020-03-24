/*

    Title - Create three child
    Author - Shashikumar M
    Date - 23 January 2020
    Description - Create three child processes using fork command, and print the PID and status of each child processes.

 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    int w, status, count = 0;

    //Fork 1 
    if((pid = fork()) != 0)
    {
	printf("Child %d with PID %d created\n", count++, pid);

	//Fork 2
	if((pid = fork()) != 0)
	{
	    printf("Child %d with PID %d created\n", count++, pid);

	    wait(&status);

	    printf("->PID %d terminated\n", pid);
	}
	else
	{
	    printf("C2\n");
	    sleep(5);
	}

	wait(&status);
	printf("PID %d terminated\n", pid);
    }
    else
    {
	printf("C1\n");
	sleep(3);
    }
}
