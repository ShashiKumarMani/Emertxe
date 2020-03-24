/*
    Title - SHM 2 process
    Author - Shashikumar M
    Date - 31 January 2020
    Description - Implement communication between 2 process using shared memory.
 */

#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
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
    int shmid, len;
    char *shm, temp, buffer[50], *myfifo = "myfifo";
    key_t key = 'S';
    
    shmid = shmget(key, SHMSIZE, 0);

    if(shmid < 0)
    {
	printf("ERROR : Shared memory not created, Execute 150 first\n");
	return 0;
    }
    else
    {
	shm = shmat(shmid, NULL, 0);

	printf("Reading from Shared memory...\n");

	sscanf(shm, "%s", buffer);

	printf("\nString scanned from SHM - %s\n", buffer);
	
	shmdt(NULL);

	/* Delete the shared memory */
	shmctl(shmid, IPC_RMID, NULL);
    }

    /* Reverse the string */
    len = strlen(buffer);

    for(int i = 0; i < len / 2;i++)
    {
	temp = buffer[i];
	buffer[i] = buffer[len - 1 - i];
	buffer[len - 1 - i] = temp;
    }

    /* Store the string in the FIFO */
    mkfifo(myfifo, 0666);

    int fd = open(myfifo, O_WRONLY);
    
    write(fd, buffer, strlen(buffer) + 1);
    
    close(fd);

    return 0;
}
