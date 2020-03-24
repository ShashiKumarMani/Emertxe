
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

char string[50];

int main()
{
    pid_t pid = fork();

    if(pid > 0)
    {
	sleep(1);
	printf("PID - %d\n", getpid());

	sprintf(string, "head -3 /proc/%d/status", pid);

	system(string);
	printf("\n");

	system(string);
	printf("\n");

	sleep(1);
	system(string);

	return 0;
    }
    else
    {
	sleep(2);

	printf("-----------------\n");

	return 0;
    }

    return 0;
}

