/*
    Title : Function to implement c_type library 
    Author : Shashi Kumar M
    Date : 09 October 2019
    Description : Implement the c type library functions.
		  Input : Read the character, choice of function.
		  Output : Print the ouput
 */

#include<stdio.h>

//Function to find alpha numeric
int is_alnum(char character)
{
    return (character >= '0' && character <= '9' || character >= 'a' && character <= 'z' || character >= 'A' && character <= 'Z') ? 1 : 0;
}

//Function to find alphabets
int is_alpha(char character)
{
    return (character >= 'a' && character <= 'z' || character >= 'A' && character <= 'Z') ? 1 : 0;
}

//Function to find control character
int is_cntrl(char character)
{
    return (character >= 0 && character <= 32 || character == 127) ? 1 : 0;
}

//Function to find digits
int is_digit(char character)
{
    return (character >= '0' && character <= '9') ? 1 : 0;
}

//Function to find blank spaces
int is_blank(char character)
{
    return (character == 32 || character == 9) ? 1 : 0;
}

//Function to lower case alphabets
int is_lower(char character)
{
    return (character >= 'a' && character <= 'z') ? 1 : 0;
}

int main()
{
    //Declare variables 
    char option, character;
    int choice;

    do
    {
	//Read the character
	printf("\nEnter the character : ");
	scanf("%c", &character);

	//Read the choice
	printf("\nChoose an option\n1. is_alnum() \n2. is_alpha() \n3. is_cntrl() \n4. is_digit() \n5. is_blank() \n6. is_lower()\n\nEnter your choice : ");
	scanf("%d", &choice);

	//Execute the choice
	switch(choice)
	{
	    case 1:
		    printf("The character is ");
		    is_alnum(character) == 1 ? printf("alphanumeric.\n") : printf("not alphanumeric.\n");
		break;
	    case 2:
		    printf("The character is ");
		    is_alpha(character) == 1 ? printf("an alphabet.\n") : printf("not an alphabet.\n");
		break;
	    case 3:
		    printf("The character is ");
		    is_cntrl(character) == 1 ? printf("a control character.\n") : printf("not a control character.\n");
		break;
	    case 4:
		    printf("The character is ");
		    is_digit(character) == 1 ? printf("a digit.\n") : printf("not a digit.\n");
		break;
	    case 5:
		    printf("The character is ");
		    is_blank(character) == 1 ? printf("a blank character.\n") : printf("not a blank character.\n");
		break;
	    case 6:
		    printf("The character is ");
		    is_lower(character) == 1 ? printf("lower case.\n") : printf("not lowercase.\n");
		break;
	    default:
		    printf("Error : Invalid choice\n");
	}

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);
	getchar();

    }while(option == 'Y' || option == 'y');

    return 0;
}
