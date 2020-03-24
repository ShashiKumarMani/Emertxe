/*
    Title - Alarm
    Author - Shashikumar M
    Date - 10 February 2020
    Description - Program to implement an alarm with snooze for given datetime using SIGALRM

 */

#define _XOPEN_SOURCE
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>

/* Function to get the user time */
time_t gettime(char **argv)
{
    struct tm tm;
    memset(&tm, 0, sizeof(tm));

    time_t cur_time = time(NULL);

    tm = *localtime(&cur_time);

    strptime(argv[1], "%H:%M", &tm);

    if(argv[2])
	strptime(argv[2], "%d/%m/%Y", &tm);
    
    time_t user_time = mktime(&tm);

    return user_time;
}

/* Function to set alarm */
int set_alarm(int user_time)
{
//    printf("alarm time - %d\n", user_time);

    /* If the time is negative */
    if(user_time > 0)
    {
	alarm(user_time);
	return 1;
    }
    else
	return 0;
}

/* Signal handler */
void signal_handler(int signum)
{
    if(signum == SIGALRM)
    {
//	printf("Alarm\n");
    }
}

/* Main */
int main(int argc, char **argv)
{
    int choice;
    time_t curr_time = time(NULL);

    /* Error check */
    if(argc < 2)
    {
	printf("Usage ./alarm <hh:mm> [dd/mm/yy]\n");
	return 0;
    }

    /* Register the sigalrm signal */
    signal(SIGALRM, signal_handler);

    /* Find the user time */
    time_t ret_time = gettime(argv);

    /* If time invalid */
    if(!set_alarm(ret_time - curr_time))
    {
	printf("ERROR : Invalid Time\n");
	return 0;
    }
    else
    {
	printf("Alarm set to %s hrs ", argv[1]);

	if(argv[2])
	{
	    printf("on %s\n", argv[2]);
	}
	else
	{
	    printf("today\n");
	}
    }

    /* Loop snooze */
    while(1)
    {
	pause();

	printf("\nAlarm Wake Up!\n1. Snooze 2. Exit\n");
	scanf("%d", &choice);

	/* If snooze */
	if(choice == 1)
	{
	    printf("Enter the snooze time : ");
	    scanf("%d", &choice);
	    signal(SIGALRM, signal_handler);

	    /* Set the alarm */
	    if(!set_alarm(choice * 60))
	    {
		printf("ERROR : Invalid time\n");
		return 0;
	    }
	}
	else if(choice == 2)
	{
	    break;
	}
    }

    return 0;
}
