/*
    Title : Print the binary and binary of 2s complement of the given number. 
    Author : Shashi Kumar M
    Date : 30 September 2019
    Description : WAP to print bits of signed and unsigned types of a given number.
		  Print the 2s complement of the number
    Input : A number
    Output : Print the bits of the number and 2s complement.
 */

#include<stdio.h>

//Print the binary form of the number
void print_bits(int num) 
{
    //Declare variable
    unsigned mask;

    //Mask the number and print bits
    for(mask = 1 << sizeof(int) * 8 - 1; mask > 0; mask >>= 1)
    {
	(num & mask) == 0 ? printf("0") : printf("1");
    }
    printf("\n");
}

int main()
{
    //Declare variables and read input
    int num, two_comp;
    char option;
    unsigned mask;
    
    do
    {
	//Read the number
	printf("\nEnter the number : ");
	scanf("%d", &num);
	
	//2s complement of the number , OR num * -1
	two_comp = ~num + 1;
	
	//Print the binary
	printf("The binary form of the number   : ");	
	print_bits(num);

	//Print the 2s complement
	printf("The 2s complement of the number : ");
	print_bits(two_comp);

    	//Prompt to continue
	printf("\nDo you want to continue ? ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
