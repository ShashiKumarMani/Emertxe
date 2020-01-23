/*
    Title : NRPS
    Author : Shashi Kumar M
    Date : 7 November 2019
    Description : Program to generate consecutive nrps of length n using k distinct characters.
		  Input - Read length n, k characters (0 < k <= 10).
		  Output - Print NRPS strings.
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

//Function to generate nrps string
void nrps(int length, char *str1, int num, char *str2)
{
    int i, pos = 0, start = 0;

    //Loop through result string
    for(i = 0;i < length;i++)
    {
	//Loop the pos
	if(pos >= num)
	{
	    pos = 0;
	}

	//If pos reaches start pos, inc start
	if(pos == start && i != 0)
	{
	    start++;

	    //Loop the start
	    if(start >= num)
	    {
		start = 0;
	    }

	    pos = start;
	}

	//Add chars to result
	str1[i] = str2[pos++];
    }

    //NULL
    str1[length] = 0;
}

int main()
{
    char option;
    int length, num, i;
    char *str1 = NULL, str2[10];

    do
    {
	//Read string length and k 
	printf("\nEnter the string length : ");
	scanf("%d", &length);

	printf("Enter the value of k [0 < k <= 10] : ");
	scanf("%d", &num);

	//If num within range
	if(num > 0 && num <= 10 && num <= length)
	{
	    str1 = malloc((length + 1) * sizeof(char));
	
	    printf("\nEnter the characters : \n");

	    //Read char
	    for(i = 0;i < num;i++)
	    {
		printf("i - %d : ", i);
		scanf("\n%c", str2 + i);
	    }
	    
	    //Call function and print result
	    nrps(length, str1, num, str2);

	    printf("\nResultant string - %s\n", str1);

	    free(str1);
	}
	else
	{
	    printf("ERROR : K value out of range [ 0 < k <= 10 AND k <= num ]\n");
	}

	__fpurge(stdin);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	scanf("\n%c", &option);
	printf("%d\n", option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
