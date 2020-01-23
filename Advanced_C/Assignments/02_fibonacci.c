/*
    Title : Generate fibonacci numbers
    Author : Shashi Kumar M
    Date : 25 Sept 2019
    Description : Program to generate fibonacci numbers given a limit
 */

#include<stdio.h>

int main()
{
    //Declare variables and read the input
    int limit, num1 = 0, num2 = 1, num3;
    printf("Enter the limit value : ");
    scanf("%d", &limit);

    //print the series
    printf("The series : ");

    //if limit is positive
    if (limit >= 0) 
    {
	//print the fibonacci numbers
	while(num1 <= limit)
	{
	    printf("%d ", num1);
	    num3 = num1 + num2;			//add the first two numbers
	    num1 = num2;			// first number = second number
	    num2 = num3;			// second number = sum of 1 2
	}
    }
    //if the limit is negative
    else
    {
	//generate fibonacci numbers
	while(num1 >= limit)
	{
	    if (num1 > (limit * -1) ) //if positive sum is greater than |limit| 
	    {
		break;
	    }

	    printf("%d ", num1);
	    num3 = num1 - num2;
	    num1 = num2;
	    num2 = num3;
	}

    }
    printf("\n");
    return 0;
}
