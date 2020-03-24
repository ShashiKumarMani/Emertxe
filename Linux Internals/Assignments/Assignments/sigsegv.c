/*
    Assignment - Sigsegv
    Author - Shashikumar M
    Date - 4 February 2020
    Description - Print the address causing segmentation fault.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

/* User defined signal handler */
void handler(int signum, siginfo_t *siginfo, void *arg)
{
    if(signum == SIGSEGV)
    {
	printf("Segmentation Fault!!\n");
	printf("Address - %p\n", siginfo->si_addr);
    }
//    exit(0);
    return;
}

int main()
{
    int *ptr = NULL;
    struct sigaction action;
    memset(&action, 0, sizeof(action));

    /* Set sigaction flags */
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = handler;

    sigaction(SIGSEGV, &action, NULL);

    /* Send the signal to the process*/
    kill(getpid(), 11);

//    ptr = (int *)5;
//    printf("%d", *ptr);

    /* Loop till signal is recieved */
//    while(1)
//    {
//	sleep(1);
//	printf("Running\n");
//    }

    return 0;
}
