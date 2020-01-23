/*

    Title : Squeeze strings 
    Author : Shashi Kumar M
    Date : 18 October 2019
    Description : Write an alternative version of squeeze that deletes each caracter in s1 that matches any characters in  s2.

 */

#include<stdio.h>
#include<stdio_ext.h>

//Function to find sring length
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

//Function to move string one index left
void move_char(char *str)
{
    int i = 0;
    char *ptr = str;

    while(ptr[i] != 0)
    {
	ptr[i] = ptr[i + 1];
	i++;
    }
}

//Squeeze() Function
int string_squeeze(char *str1, char *str2)
{
    int i, j;

    printf("S1 - %s\n", str1);
    printf("S2 - %s\n", str2);
    
    //If the str2 is longer return error
    if(my_strlen(str2) > my_strlen(str1))
    {
	return -1;
    }

    //Compare and delete matched characters
    for(i = 0;str2[i] != '\n';i++)
    {
	for(j = 0;str1[j] != '\n';j++)
	{
	    if(str1[j] == str2[i])
	    {
		move_char(str1 + j);
		j--;
	    }
	}
    }

    return 0;
}

int main()
{
    //Declare varaibles
    char option, str1[50], str2[50];
    int ret;

    do
    {
	//Read the strings
	printf("\nEnter the first string : ");
	fgets(str1, 50, stdin);

	printf("\nEnter the second string : ");
	fgets(str2, 50, stdin);

	if(string_squeeze(str1, str2) == -1)
	{
	    printf("ERROR: str2 length is greater than str1\n");
	}
	else
	{
	    printf("The result string - %s\n", str1);
	}

	__fpurge(stdin);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	scanf("%c", &option);
	getchar();

	printf("Option - %d\n", option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
