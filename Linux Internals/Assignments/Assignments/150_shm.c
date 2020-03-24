/*
    Title - SHM 2 process
    Author - Shashikumar M
    Date - 31 January 2020
    Description - Implement communication between 2 process using shared memory.
 */

#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <ctype.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SHMSIZE 50

int main()
{
    char string[50], buffer[50];
    int shmid, pipe_fd[2], status, fd;
    char *shm, buff = 'A', *myfifo = "myfifo";
    key_t key = 'S';
    
    if(pipe(pipe_fd) == -1)
    {
	printf("ERROR\n");
	return 0;
    }

    printf("Enter a string : ");
    scanf("%s", string);

    /* Child */
    if(fork() == 0)
    {
	close(pipe_fd[1]);

	/* Read from pipe */	
	for(int i = 0;buff != 0;i++)
	{
	    if(read(pipe_fd[0], &buff, 1) == 0)
	    {
		break;
	    }   
	    buffer[i] = toupper(buff);
	}

	close(pipe_fd[0]);

	printf("String read from pipe - %s\n", buffer);
   
	/* Create a shared memory and store the string */
	shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);

	if(shmid < 0)
	{
	    printf("ERROR : Shared memory not created");
	    return 0;
	}
	else
	{
	    /* Attach and store the string */
	    shm = shmat(shmid, NULL, 0);
	    strcpy(shm, buffer);
	}
    }
    else
    {
	/* Write string to pipe */
	close(pipe_fd[0]);
     
	write(pipe_fd[1], string, strlen(string) + 1);

	close(pipe_fd[1]);

	printf("Write over\n");

	wait(&status);
	
	printf("String copied to the shared memory\n");

	/* Reading string from FIFO*/
	sleep(3);

	printf("\nReading from FIFO...\n");

	fd = open(myfifo, O_RDONLY);

	read(fd, string, SHMSIZE);

	printf("String read from FIFO - %s\n", string);

	close(fd);
    }
}
