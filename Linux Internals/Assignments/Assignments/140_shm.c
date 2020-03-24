/*
    Title - SHM 2 process
    Author - Shashikumar M
    Date - 31 January 2020
    Description - Implement communication between 2 process using shared memory.
 */

#include <sys/ipc.h>
#include <sys/shm.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SHMSIZE 50

int main()
{
    char string[50];
    int shmid;
    char *shm;

    printf("Enter a string : ");
    scanf("%s", string);

    //Common for both processes
    int key = 'S';

    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);

    shm = shmat(shmid, NULL, 0);

    /* Convert to uppercase */
    for(int i = 0;string[i];i++)
    {
	string[i] = toupper(string[i]);
    }

    /* Copy the string to the shared memory */
    strcpy(shm, string);

    shmdt(NULL);

    return 0;
}
