/*
    Title : Swap two values using pass by reference method. 
    Author : Shashi Kumar M
    Date : 11 October 2019
    Description : Program to swap two values using pass by reference method.
		  Input : Read a numbers.
		  Output : Print the swapped values.
 */

#include<stdio.h>

//Function to swap two values
void swap(int *ptr1, int *ptr2)
{
    //Swap ptr1 and ptr2
    *ptr1 = *ptr1 ^ *ptr2;
    *ptr2 = *ptr1 ^ *ptr2;
    *ptr1 = *ptr1 ^ *ptr2;    
}

int main()
{
    //Declare variables
    char option;
    int val1, val2;

    do
    {
	//Read values
	printf("\nEnter the two values : ");
	scanf("%d %d", &val1, &val2);
	
	//Print values
	printf("Values before swap - Value 1 : %d and Value 2 : %d\n", val1, val2);

	//Call function
	swap(&val1, &val2);

	//Print the swapped values
	printf("Values after  swap - Value 1 : %d and Value 2 : %d\n", val1, val2);	

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
