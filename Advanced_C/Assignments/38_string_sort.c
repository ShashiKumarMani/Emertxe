/*
    Title : String sort
    Author : Shashi Kumar M
    Date : 8 November 2019
    Description : Program to print geiven strings in alphabetical order.
		  Input - Read n and n names.
		  Output - Sort their names in alphabetical order.
 */

#include<stdio.h>
#include<stdlib.h>

//Function to sort strings
void sort_names(char **str, int num)
{
    int i = 0, pos = 0, j;
    char *temp;

    //Bubble sort
    for(j = 0;j < num;j++)
    {
	for(i = 0;i < num - 1 - j;i++)
	{
	    //If characters are equal inc. position
	    while(str[i][pos] == str[i + 1][pos])
	    {
		pos++;
	    }

	    //Compare char and swap
	    if(str[i][pos] > str[i + 1][pos])
	    {
		temp = str[i];
		str[i] = str[i + 1];
		str[i + 1] = temp;
	    }
	    pos = 0;
	}
    }
}

int main()
{
    char option;
    char **names = NULL;
    int num, i;

    do
    {
	//Read variables and allocate memory
	printf("\nEnter the number of names : ");
	scanf("%d", &num);

	names = malloc(num * sizeof(char *));

	for(i = 0;i < num;i++)
	{
	    names[i] = malloc(32 * sizeof(char));
	}

	//Read names
	printf("Enter names \n");
	
	for(i = 0;i < num;i++)
	{
	    scanf("%s", names[i]);
	    names[i][31] = 0;
	}

	//Sort and print names
	sort_names(names, num);

	printf("The names \n");
	
	for(i = 0;i < num;i++)
	{
	    printf("%s\n", names[i]);
	}

	//Free memory
	for(i = 0;i < num;i++)
	{
	    free(names[i]);
	}
	
	free(names);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
