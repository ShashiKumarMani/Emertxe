/*
    Title : Circular shift
    Author : Shashi Kumar M
    Date : 04 October 2019
    Description : Program to perform circular left & right of the given number.
		  Input : A number, Number of bits to shift
		  Output : Print the bits of the number after 
				performing shift operation.
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

//Function to perform left shift
int circular_left_shift(int num,int num_bits)
{
    //Print the shifted value
    print_bits(num >> sizeof(int) * 8 - num_bits | num << num_bits);
}

//Function to perform right shift
int circular_right_shift(int num, int num_bits)
{
    //Print the shifted value
    print_bits(num << sizeof(int) * 8 - num_bits | num >> num_bits);
}

int main()
{
    //Read variables
    char option;
    int left, right, num_bits, num, choice;
    
    do
    {
	//Read the variables
	printf("\nEnter the number : ");
	scanf("%d", &num);

	printf("Enter the number of bits  to shift : ");
	scanf("%d", &num_bits);

	printf("\nPossible operations : \n 1. Circular right shift\n 2. Circular left shift\nEnter your choice : ");
	scanf("%d", &choice);

        //Print the binary form 
        printf("\nThe binary form before shift      : ");
        print_bits(num);

	//Switch case to excecute the choice
	switch(choice)
	{
	    case 1 : 
		    printf("The binary form after right shift : ");
		    circular_right_shift(num, num_bits);
		break;
	    case 2 :
		    printf("The binary form after left shift  : ");
		    circular_left_shift(num, num_bits);
		break;
	    default :
		    printf("Error : Invalid choice for operation.\n");
	}

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
