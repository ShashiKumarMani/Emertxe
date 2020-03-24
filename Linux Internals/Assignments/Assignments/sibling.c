/*
    Title : Zombie_Orphan
    Author - Shashikumar M
    Date - 23 January 2020
    Description - Create a zombie process and clear it using init process.
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

/* Function to print the status using the file*/
int print_status(pid_t pid)
{
    char string[50], buff;
    int fd, line = 0;

    /* Create the path */
    printf("\n");
    sprintf(string, "/proc/%d/status", pid);

    if((fd = open(string, O_RDONLY)) == -1)
    {
	return -1;
    }

    /* Print 2 lines of status */
    while(line != 3)
    {
	read(fd , &buff, 1);
	printf("%c", buff);

	if(buff == '\n')
	    line++;
    }
}

/* Main */
int main()
{
    pid_t pid1, pid2;
    
    //Fork1
    if((pid1 = fork()) > 0)
    {
	printf("Child with PID %d created\n", pid1);

	print_status(pid1);
	
	//Wait for child one to terminate
	sleep(2);
	print_status(pid1);
	
	//Fork2
	if((pid2 = fork()))
	{
	    sleep(1); 
	}
	else
	{
	    printf("\nChild2 - PID - %d, Parent ID - %d\n", getpid(), getppid());
	    
	    //Wait for parent to terminate
	    sleep(1);

	    printf("\nChild2 - PID - %d, Parent ID - %d\n", getpid(), getppid());
	    printf("Parent terminated. Child processes %d & %d adopted by init\n", pid1, getpid());

	    if(print_status(pid1) == -1)
	    {
		printf("Child %d cleared by init\n", pid1);
	    }

	    return 0;
	}
    }
    else
    {
	sleep(2);
	return 0;
    }
}
