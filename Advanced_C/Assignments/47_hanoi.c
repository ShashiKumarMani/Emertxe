/*
    Title : Tower of hanoi
    Author : Shashi Kumar M
    Date : 21 November 2019
    Description : Program to implement solution for tower of hanoi.
		  Input - Read number of disks.
		  Output - Print the order of traversal.
 */

#include<stdio.h>

//Function to implement tower of hanoi
void hanoi(int num, char source, char temp, char dest)
{
    if(num > 0)
    {
	//To move nth to dest, move n - 1 disks from source to temp, then temp to dest	
	hanoi(num - 1, source, dest, temp);
	printf("Move Disk %d from %c to %c\n", num, source, dest);
	hanoi(num - 1, temp, source, dest);
    }
}

int main()
{
    char option;
    int num_disks;

    do
    {
	printf("\nEnter the number of disks : ");
	scanf("%d", &num_disks);	

	printf("\n");

	//Call function
	hanoi(num_disks, 's', 't', 'd');	
    
	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
