/*
    Title - Zomb_orph
    Author - Shashkumar M
    Date - 27 January 2020
    Description - Create zombie and orphan process and print their status.

 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int status, fd, line = 0;
    pid_t pid = fork();
    char string[50];

    //Child process
    if(pid == 0)
    {
	printf("Child process\n");
	sprintf(string, " head -3 /proc/%d/status", getpid());

	system(string);

//	fd = open(string, O_RDONLY);

	//Print the process stat	
//	while(line != 3)
//	{
//	    read(fd, string, 1);
//	
//	    printf("%c", string[0]);    
//	    if(string[0] == '\n')
//		line++;
//	}

	sleep(4);
	
	printf("\nChild process still running\n");
	
	lseek(fd, 0, SEEK_SET);

	line = 0;
        //Print the process stat
        while(line != 3)
        {
	    read(fd, string, 1);

            printf("%c", string[0]);
            if(string[0] == '\n')
                line++;
        }

	printf("Yes\n");
    }
    else 
    {
	printf("A child was created with PID - %d\n", pid);	
    }

    return 0;
}
