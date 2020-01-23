/*
    Title : Pre and post increment
    Author : Shashi Kumar M
    Date : 11 October 2019
    Description : Program to implement pre and post increment using functions.	
		  Input : Read a number
		  Output : Print the number and pre / post increment value.
 */

#include<stdio.h>

//Function to increment number using bitwise operators
int increment(int val)
{
    unsigned mask = 1;
    
    //If even, add 1 to lsb
    if(val & 1 == 0)
    {
	return val | 1;
    }

    //IF odd add 1 to first 0 from lsb and clear bits
    while(val & mask == 1)
    {
	mask = mask << 1;
    }
    mask = mask << 1;

    //Toggle first 0 and clear bits till lsb
    mask =  mask | val & ~(mask - 1);

    return mask;
}

//Function to implement pre increment
int pre_increment(int *ptr)
{
    *ptr = increment(*ptr);

    return *ptr;
}

//Functiom to implement post increment
int post_increment(int *ptr)
{
    int val = *ptr;

    *ptr = increment(*ptr);
    
    return val;
}

int main()
{
    //Declare variables
    char option;
    int choice, ret, value;

    do
    {
	//Read values
	printf("\nEnter the value : ");
	scanf("%d", &value);

	//Choose an option
	printf("\nChoose an option :\n1. Pre increment\n2. Post Increment\n\nEnter your choice : ");
	scanf("%d", &choice);

	//Execute the option
	switch(choice)
	{
	    case 1:
		    ret = pre_increment(&value);
		    printf("\nReturn value - %d, original value = %d\n", ret, value);
		break;
	    case 2:
		    ret = post_increment(&value);
		    printf("\nReturn value - %d, original value = %d\n", ret, value);
		break;
	    default: 
		    printf("Enter a valid option. \n");
	}

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(opti= 'Y' || option == 'y');

    return 0;
}
