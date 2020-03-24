/*
    Title - nonblock_wait
    Author - Shashikumar M
    Date - 5 February 2020
    Description - Program to avoid a child process becoming a zombie withour blocking the parent process

 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status, ret;

    /* Child process */
    if((pid = fork()) == 0)
    {
	sleep(5);
	printf("Child Execution completed\n");
    }
    else if(pid > 0)
    {
	printf("Child with PID %d created\n\n", pid);

	/* Execute parent */
	for(int i = 1;i <= 10;i++)
	{
	    /* Returns immediately if child not exited */
	    ret = waitpid(pid, &status, WNOHANG);
	    sleep(1);
	    printf("Parent is running %d / 10\n", i);
	}

	/* Print the child exit status */
	if(WIFEXITED(status))
	{
	    printf("\nChild %d exited normally with exit status %d\n", pid, WEXITSTATUS(status));
	}
	else
	{
	    printf("Child terminated abnormally\n");
	}
    }
    else
    {
	printf("ERROR : Fork()\n");
    }

    return 0;
}

