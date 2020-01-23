/*
    Title : Combinations 
    Author : Shashi Kumar M
    Date : 4 November 2019
    Description : Print all possible string combinations.
		  Input - Read a string.
		  Output - Print all permutations.

    References : String permutation algorithm - https://youtu.be/GuTPwotSdYw
*/

#include <stdio.h>
#include <string.h>

//Function to swap variables
void swap(char *str1, char *str2)
{
    char temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

//Function to print combinations
void print_combinations(char *string, int begin, int end)
{
    //Begin equals end
    if(begin == end)
    {
	printf("%s\n", string);
	return;
    }

    //Loop through the string, swap and recurse
    for(int i = begin;i <= end;i++)
    {
	swap(string + begin, string + i);
	print_combinations(string, begin + 1, end);
	swap(string + begin, string + i);
    }
}

//Function to find duplicates
int check_duplicates(char *string, int end)
{
    int i, j;

    for(i = 0;i < end;i++)
    {
	for(j = 0;j < end;j++)
	{
	    //IF character match,
	    if(string[i] == string[j] && i != j)
	    {
		return 0;
	    }
	}
    }

    return 1;
}

int main()
{
    char option, string[50];

    do
    {
	//Read string and call function
	printf("\nEnter a string : ");
	scanf("%s", string);

	//Check for duplicates
	if(check_duplicates(string, strlen(string)))
	{
	    print_combinations(string, 0, strlen(string) - 1);	
	}
	else
	{
	    printf("ERROR : Duplicate characters. \n");
	}

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
