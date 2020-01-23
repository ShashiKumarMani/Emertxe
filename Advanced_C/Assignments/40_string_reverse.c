/*

    Title : String reverse
    Author : Shashi Kumar M
    Date : 4 November 2019
    Description : Program to reverse a given string.
		  Input - Read a string.
		  Output - Reverse the given string.
 
*/

#include <stdio.h>
#include <stdio_ext.h>

//Function to find string length
int my_strlen(char *string)
{
    int count = 0;

    while(*string)
    {
	count++;
	string++;
    }

    return count;
}

//Function to swap character
void swap_char(char *ptr, char *str)
{
    char temp = *ptr;
    *ptr = *str;
    *str = temp;
}

//Function to reverse string using non-recursion
void reverse_string(char *arr)
{
    int len = my_strlen(arr);
    char temp;

    //Loop till mid of string
    for(int i = 0; i < len / 2;i++)
    {
	swap_char(arr + i, arr + len - i - 1);
    }
}

//Function to print reverse string using recursion
void reverse_recursion(char *arr, int begin, int end)
{
    //End condition
    if(begin >= end)
    {
	return;
    }
    
    //Swap char and move indexes by 1
    swap_char(arr + begin, arr + end);
    reverse_recursion(arr, begin + 1, end - 1);    
}

int main()
{
    char option, arr[50];
    int choice;

    do
    {
	//Read string
	printf("\nEnter a string [Max length - 50] : ");
	scanf("%s", arr);

	printf("\nMenu\n1. Non-recursion\n2. Recursion\n\nEnter your choice : ");
	scanf("%d", &choice);

	//Execute the choice
	switch(choice)
	{
	    case 1:
		    reverse_string(arr);
		    printf("\nReverse of the string  %s\n ", arr);
		    
		break;
	    case 2:
		    reverse_recursion(arr, 0, my_strlen(arr) - 1);
		    printf("\nReverse of the string  %s\n ", arr);
		
		break;
	    default:
		    printf("ERROR : Invalid choice\n");
	}

	__fpurge(stdin);

	//Prompt to continue or not
	printf("\n\nDo you want to continue? [Yy | Nn] : ");
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
