/*
    Title : Factorial using recursion.
    Author : Shashi Kumar M
    Date : 11 October 2019
    Description : Program to print factorial of a number using recursion.   
		  Input - A number
		  Output - Print the factorial of the number. 
 */

#include<stdio.h>
#include<stdio_ext.h>

//Function to print positive fibonacci series
void fibonacci_pos(int num1, int num2, int limit)
{
    int num3;

    //If num1 less than limit print num1, operations, call function
    if(num1 <= limit)
    {
	printf("%d ", num1);
	num3 = num1 + num2;
	num1 = num2;
	num2 = num3;
	fibonacci_pos(num1, num2, limit);	
    }    
}

//Function to print negative fibonacci series
void fibonacci_neg(int num1, int num2, int limit)
{
    int num3;

    //If the negative sum is greater than the limit
    if(num1 >= limit)
    {
	//If the positive greater than the |limit|
	if(num1 > limit * -1)
	{
	    return;
	}

	printf("%d ", num1);
	num3 = num1 - num2;
	num1 = num2;
	num2 = num3;
	fibonacci_neg(num1, num2, limit);
    }
}

int main()
{
    //Declare variables
    char option;
    int num1 = 0, num2 = 1, limit;

    do
    {
	//Read the limit
	printf("\nEnter the limit : ");
	scanf("%d", &limit);

	//Positive
	if(limit > 0)
	{
	    printf("\nThe fibonacci series : ");
	    fibonacci_pos(num1, num2, limit);
	}
	//Negative
	else if(limit < 0)
	{
	    printf("\nThe fibonacci series : ");
	    fibonacci_neg(num1, num2, limit);
	}
	else
	{
	    printf("\nERROR : Invalid Input [ Limit < 0 OR Limit > 0 ]\n");
	}

	//Prompt to continue or not
	printf("\n\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
