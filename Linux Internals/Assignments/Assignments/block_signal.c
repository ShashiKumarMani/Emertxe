/*
    Title - Block signal
    Author - Shashikumar M
    Date - 11 February 2020
    Description - Program to block signals in the signal handler.
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

/* Signal handler */
void handler(int signum, siginfo_t *info, void *data)
{
    if(signum == SIGINT)
    {
	printf("\nSIGINT signal Recieved");

	for(int i = 0;i < 10;i++)
	{
	    sleep(1);

	    printf("\nInside signal handler %d / 10", i + 1);
	}
    }
  //  printf("Done\n");  
    return;
}

/* Main */
int main()
{
    /* Create a set of signals to block */
    sigset_t block;
    sigemptyset(&block);
    sigfillset(&block);
    sigdelset(&block, SIGINT);

    printf("PID - %d\n", getpid());
    struct sigaction action;
    memset(&action, 0, sizeof(action));

    action.sa_mask = block;
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = handler;

    /* Register the signal */
    sigaction(SIGINT, &action, NULL);

    /* Prompt the user to press Cntrl+C */    
    printf("Press Cntrl+c from the terminal \n");
    pause();
    
//    printf("ret\n");

    return 0;
}
