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
#include <signal.h>

void handler(int signum)
{
    printf("Signal recieved\n");
}

int main(int argc, char **argv)
{
    struct tm tm;
    char buf[255];

    signal(SIGALRM, handler);

    alarm(3);
    pause();

    sleep(2);
    printf("Another\n");

    signal(SIGALRM, handler);
    alarm(4);
    pause();

    return 0;
}
