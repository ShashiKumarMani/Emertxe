/*
    Title : Program to replace bits from a value
    Author : Shashi Kumar M
    Date : 4 October 2019   
Description : Program to replace b - a + 1 bits a number into val(b : a)
	      Input : 0 <= a <= b <= 31, number, value.
	      Output : Print the updated value.
 */

#include<stdio.h>

//Function to print bits
void print_bits(int num)
{
    //Declare variables
    unsigned mask;

    //Loop and print bits
    for(mask = 1 << sizeof(int) * 8 - 1; mask > 0; mask >>= 1)
    {
        (num & mask) == 0 ? printf("0") : printf("1");
    }
    printf("\n");
}

//Function to replace bits of value
int replace_bits(int num, int val, int a, int b)
{
    //mask 
    unsigned mask = (1 << b - a + 1) - 1;

    //Take b - a + 1 bits from lsb of num  ADD it in value from bth index after removing bits
    return (mask & num) << a | (~(mask << a ) & val);
}

int main()
{
    //Declare variables
    char option;
    int num, value, a, b, result;

    do
    {
	//Read variables
	printf("\nEnter the number : ");
	scanf("%d", &num);

	printf("Enter the value : ");
	scanf("%d", &value);

	printf("Enter the value of a and b : ");
	scanf("%d %d", &a, &b);

	//If inputs cross the ranges print error message
	if (a <= b && a >= 0 && a <= 31 && b >= 0 && b <= 31)
	{
            //Call function
	    result = replace_bits(num, value, a, b);

	    //Print the binary form of num and result
	    printf("The binary form of the number  : ");
	    print_bits(num);

	    printf("The binary form of the value   : ");
	    print_bits(value);

	    printf("The binary form of updated num : ");
	    print_bits(result);
	
	}
	else
	{
	    printf("Error : Please provide input within range. [ 0 <= a <= b <= 31 ]\n");
	}

        //Prompt to continue or not
        printf("\nDo you want to continue? [Yy | Nn] : ");
        getchar();
        scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
