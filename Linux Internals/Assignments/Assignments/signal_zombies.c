/*
    Title - Avoid signal
    Author - Shashikumar M
    Date - 12 February 2020
    Description - Program ro avoid child becoming a zombie using signal handlers.
 */

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void handler(int signum, siginfo_t *info, void *data)
{
    if(signum == SIGCHLD)
    {
//	printf("Child pid : %d\n", info->si_pid);

//	waitpid(info->si_pid, NULL, 0);

	printf("Exit status : %d\n", info->si_status);
    }
}

int main()
{
    pid_t pid;
    struct sigaction action;
    action.sa_sigaction = handler;
    action.sa_flags = SA_SIGINFO | SA_NOCLDSTOP;

    sigaction(SIGCHLD, &action, NULL);
    
    /* Child */
    if((pid = fork()) == 0)
    {
	printf("Child Executing...\n");
	sleep(2);
	printf("Child execution done.\n");
    }
    /* Parent */
    else if(pid > 0)
    {
	printf("Child with PID : %d created\n", pid);
	sleep(5);
    }
    else
    {
	printf("ERROR : Fork(). Exiting....\n");
    }

    return 0;
}
