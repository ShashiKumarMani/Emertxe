/*
    Title : Factorial using main function 
    Author : Shashi Kumar M
    Date : 11 October 2019
    Description : Print factorial of a number using main function recursion.
		  Input : Read a number
		  Output : Print the factorial of the number.
*/

#include<stdio.h>

int main()
{
    //Declare variables
    char option;
    static int sum = 1, num, flag = 1, temp, count = 0;
    
    do
    {
	//Read variable once, make a copy, set flag to 0.
	if(flag)
	{
	    printf("\nEnter the number : ");
	    scanf("%d", &num);
	    temp = num;
	    flag = 0;
	}

	//If number greater than zero
	if(num > 0)
	{
	    sum = sum * num;
	    num = num - 1;

	    main();

	    //Count to track the number of stacks exited
	    count++;

	    //Return if not main stack
	    if(temp != count)
	    {
		return 0;
	    }
	    //Reset variables
	    else
	    {
		sum = 1;
		flag = 1;
		count = 0;
	    }
	}
	else
	{
	    //Print the output
	    printf("\nThe factorial of %d is %d\n", temp, sum);
	    
	    //If the entered input is 0
	    if(num == temp)
	    {
		flag = 1;
	    }
	    else
	    {
		return 0;
	    }
	}

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
