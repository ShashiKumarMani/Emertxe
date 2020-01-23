/*  

    Title : Bitwise library
    Author : Shashi Kumar M
    Date : 3 October 2019
    Description : Program to perform implement bitwise library functions.
		  Input :  Integers, number, position, number_of_bits
		  Output : Print the value

*/

#include </usr/include/stdio.h>
#include "../bitwise.h"
#include "bitwise.c"

int main()
{
    //Declare variables
    char option;
    int num, result, value, position, num_bits, choice;

    do
    {
	//Display the menu
	printf("\nChoose an option\n1. Get n bits\n2. Replace n bits \n3. Get n bits from position\n4. Replace n bits from position\n5. Toggle n bits from position\n\nEnter your choice : ");
	scanf("%d", &choice);

	//Switch to execute the choice
	switch(choice)
	{
	    case 1:
		    //Get n bits, read variables
		    printf("Enter the number : ");
		    scanf("%d", &num);
		    printf("Enter the number of bits : ");
		    scanf("%d", &num_bits);
		    
		    //Call function
		    result = get_n_bits(num, num_bits);

		    //Print binary form and result
		    printf("The binary of the number : ");
		    print_bits(num);

		    printf("The result is %d\n", result);
		    
		break;
	    case 2:
		    //Replace n bits read variables
		    printf("Enter the number : ");
                    scanf("%d",&num);
 
                    printf("Enter the value : ");
                    scanf("%d", &value);
 
		    printf("Enter the number of bits : ");
		    scanf("%d", &num_bits);
		    
		    //Call function
		    result = replace_n_bits(num, value, num_bits);

		    //Print the binary form and result
		    printf("The binary form of number  : ");
		    print_bits(num);

		    printf("The binary form of value   : ");
		    print_bits(value);

		    printf("The result is %d\n",result);

		    printf("The binary form of the result : ");
                    print_bits(result);
		break;
	    case 3:
		    //Read num, position, number of bits
		    printf("Enter the number : ");
		    scanf("%d", &num);

		    printf("Enter the position : ");
		    scanf("%d", &position);

		    printf("Enter the number of bits : ");
		    scanf("%d", &num_bits);

		    //Call function
		    result = get_n_bits_from_pos(num, position, num_bits);

		    //Print the binary of num
		    printf("The binary form of number : ");
		    print_bits(num);

		    //Print the result and binary form
		    printf("The result - %d\n", result);
		    
		break;
	    case 4:
		    //Replace n bits from pos, Read the number, value, number of bits
		    printf("Enter the number : ");
		    scanf("%d",&num);

		    printf("Enter the value : ");
		    scanf("%d", &value);

		    printf("Enter the position : ");
		    scanf("%d", &position);

		    printf("Enter the number of bits : ");
		    scanf("%d", &num_bits);

		    //Call function
		    result = replace_n_bits_from_pos(num, value, position, num_bits);

		    //Print the binary of num, value and updated number
		    printf("The Binary of number is  : ");
		    print_bits(num);

		    printf("The binary of value is   : ");
		    print_bits(value);

		    printf("Binary of updated number : ");
		    print_bits(result);

		    printf("The result is %d\n",result);

		break;
	    case 5:
		    //Read number, number of bits, position
		    printf("Enter the number : ");
		    scanf("%d", &num);

		    printf("Enter the number of bits : ");
		    scanf("%d", &num_bits);

		    printf("Enter the position : ");
		    scanf("%d", &position);

		    //Call function
		    result = toggle_n_bits_from_pos(num, num_bits, position);
		    
		    //Print result and binary
		    printf("The binary of the number : ");
		    print_bits(num);

		    printf("The result is %d\n",result);

		    printf("The binary of the result : ");
		    print_bits(result);

		break;
	    default:
		    printf("ERROR : Invalid choice\n");
	}	

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
