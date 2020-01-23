/*
    Title : Replace blanks 
    Author : Shashi Kumar M
    Date : 18 October 2019
    Description : Replace each strings of one or more blank with a single blank.
		  Input - Read a string.
		  Output - Print the string with multiple blanks removed.
*/

#include<stdio.h>
#include<stdio_ext.h>

//Function to return string length
int my_strlen(char *str)
{
    int count = 0;

    while(*str != '\0')
    {
	count++;
	str++;
    }

    return count;
}

//Function to shift string
void move_char(char *str)
{
    char *ptr = str;
    int i = 0;

    //IF char is -1 shift left
    while(ptr[i] != 0)
    {
	if(ptr[i] == -1)
	{
	    ptr[i] = ptr[i + 1];
	    continue;
	}
	i++;
    }

}

//Function to remove extra blank spaces
void replace_blanks(char *str)
{
    char *ptr = str;
    int flag = 0, count = 0;

    //Loop and replace multiple blanks with -1
    while(*ptr != 0)
    {
	//If blank or tab
	if(*ptr == ' ' || *ptr == '\t')
	{
	    //If multiple blanks
	    if(flag == 1)
	    {
		*ptr = -1;
		continue;
	    }
	    else
	    {
		flag = 1;
	    }
	}
	else
	{
	    flag = 0;
	}
	ptr++;
    }

    //Remove all blanks by shifting
    move_char(str);
}

int main()
{
    //Declare variables
    char option, str[100];
    int i = 0, ret;

    do
    {
	//Read string
	printf("\nEnter string [Max length - 100] : \n");
	scanf("%[^\n]", str);

	//Call function
	replace_blanks(str);

	//Print result
	printf("\nThe string with multiple blanks removed : \n%s\n", str);

	__fpurge(stdin);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	//getchar();
	scanf("\n%c", &option);

	getchar();

    }while(option == 'Y' || option == 'y');

    return 0;
}
