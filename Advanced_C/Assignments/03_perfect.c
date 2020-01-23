/*
	Title  : Perfect number or not
	Author : Shashi Kumar M
	Date   : 25 Sept 2019
	Description : Program to find if a given number is perfect or not.
*/

#include<stdio.h>

int main()
{
	//Declaration and read input
	int num, i, sum = 0;
	printf("Enter the number : ");
	scanf("%d", &num);

	//Validation , number should be greater than 1
	if (num > 1)
	{
		for (i = 1;i <= (num / 2);i++)   // i : 1 - (num/2)- largest factor other than the num
		{
			if ((num % i) == 0) // if the number is a factor add sum
			{
				sum += i;
			}
		}	
		//if num is equal to sum 
		if (sum == num)
		{
			printf("The entered number is perfect\n");
		}
		else
		{
			printf("The entered number is not perfect\n");
		}
	}
	else
	{
		printf("ERROR : Invalid Input. Number should be greater than 1\n");
	}

	return 0;
}
