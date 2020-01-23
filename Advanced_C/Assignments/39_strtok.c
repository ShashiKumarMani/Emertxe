/*
    Title : my_strtok() 
    Author : Shashi Kumar M
    Date : 22 October 2019
    Description : Program to implement the strtok function.
		  Input - Read two strings.
		  Output - Print the string tokens.
*/

#include<stdio.h>
#include<string.h>

//Function to implement strtok function
char *my_strtok(char *str1, char *str2)
{
    static char *ptr = 0;
    int i = 0, j = 0;
    static int flag = 0;

    //IF flag is set
    if(flag)
    {
	flag = 0;
	return NULL;
    }

    //Second call 
    if(str1 == NULL)
    {
	str1 = ptr;
    }

    //Loop through string
    for(i = 0; str1[i] != 0;i++)
    {
	//Loop through delimiters
	for(j = 0;str2[j] != 0;j++)
	{
	    //IF match
	    if(str1[i] == str2[j])
	    {
		//Update string[i] to null
		str1[i] = '\0';

		//Point to next char
		ptr = str1 + i + 1;
		
		//IF printable
		if(*str1 != 0)
		{
		    return str1;
		}
		//If start char is delim
		else
		{
		    str1 = ptr;
		    i--;
		}
	    }
	}
    }
   
    //If eostring 
    if(*str1 != 0)
    {
	flag = 1;
	return str1;
    }
    
    return NULL;
}

int main()
{
    //Declare variables
    char option, str1[50], str2[50];
    char *token = NULL;

    do
    {
	//Read the strings
	printf("\nEnter string - ");
	scanf("%s", str1);

	printf("Enter delimiters - ");
	scanf("%s", str2);

	//First call
	token = my_strtok(str1, str2);

	printf("\n");

	//Loop and print the tokens
	while(token != NULL)
	{
	    printf("%s\n", token);
	    token = my_strtok(NULL, str2);
	}

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
