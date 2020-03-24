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
    pid_t pid1, pid2, pid3;
    int w, status, count = 0;

    //Fork 1 
    if((pid1 = fork()) != 0)
    {
	printf("Child %d with PID %d created\n", count++, pid1);

	//Fork 2
	if((pid2 = fork()) != 0)
	{
	    printf("Child %d with PID %d created\n", count++, pid2);

	    //Fork 3
	    if((pid3 = fork()) != 0)
	    {
		printf("Child %d with PID %d created\n", count++, pid3);	
		
		//Wait and print status
		waitpid(pid1, &status, 2);

		if(WIFEXITED(status))
		    printf("Child with PID %d terminated with code %d\n", pid1, WEXITSTATUS(status));	
		else
		    printf("Child %d exited abnormally\n", pid1);
	    }
	    else
	    {
		sleep(3);
		return 0;
	    }

	    //Wait and print status
	    waitpid(pid2, &status, 2);
	    
	    if(WIFEXITED(status))
		printf("Child with PID %d terminated with code %d\n", pid2, WEXITSTATUS(status));
	    else
		printf("Child %d exited abnormally\n", pid2);
	}
	else
	{
	    sleep(2);
	    return 0;
	}

	//Wait and print status
	waitpid(pid3, &status, 2);
	
	if(WIFEXITED(status))
            printf("Child with PID %d terminated with code %d\n", pid3, WEXITSTATUS(status));
	else
	    printf("Child %d exited abnormally\n", pid3);
    }
    else
    {
	sleep(1);
	return 0;
    }

    return 0;
}
