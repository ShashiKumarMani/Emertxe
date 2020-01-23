/*
    Title : Endianess
    Author : Shashi Kumar M
    Date : 11 November 2019
    Description : Program to find whether the system is little endian or big endian.
		  Input - Read a number
		  Output - Print endianess.
 */

#include<stdio.h>

int main()
{
    char option;
    int num;
    char *ptr = NULL;

    do
    {
	//Read value
	printf("\nEnter a number less than or equal to 15 1Byte: ");
	scanf("%d", &num);

	{
	    //Point to the first byte
	    ptr = (char *)&num;

	    if(*ptr == (char)num)
	    {
		printf("Your system is Little Endian\n");
	    }	    
	    else
	    {
		printf("Your system is Big Endian\n");
	    }
	}

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
