/*
    Title : Program to print prime numbers
    Author : Shashi Kumar M
    Date : 01 October 2019
    Description : Program to print number below a limit using sieve of erasthanos method.
		  Input : A number - limit.
		  Output : Prime numbers below that limit.
 */

#include<stdio.h>

int main()
{
    // Declare variables 
    int limit, i, j;
    char option;

    do
    {
	//Read the number and declare the array */
	printf("\nEnter the limit : ");
	scanf("%d", &limit);

	//Declare the array */
	int array[limit - 1];

	//Initialise the array */
	for(i = 0;i < limit - 1;i++)
        {
	    array[i] = i + 2;
	}

	//Update the array multiples of numbers upto (num / 2 - 2) to zero
	for(i = 0;i < limit / 2 - 2;i++)
	{
	    for(j = i + 1;j < limit - 1;j++)
	    {
		//If not updated , if not the same number , if a multiple, Update
		if(array[i] != 0 && array[j] % array[i] == 0)
	    	{
		    array[j] = 0;
		}
	    }
	}

	//Print the updated array
	printf("The prime numbers are : ");

	//Loop through the array and print all nonzeros
	for(i = 0;i < limit - 1;i++)
        {
	    if(array[i] != 0)
	    {    
		printf("%d ", array[i]);
	    }
	}
	printf("\n");
    
	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy || Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
