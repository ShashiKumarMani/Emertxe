/*

    Title : Find average
    Author : Shashi Kumar M
    Date : 14 November 2019
    Description : Program to find average in 3 different ways.
		  Input - Read elements from the user.
		  Output - Print the average.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

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
    for(i = 0; *(str1 + i) != 0;i++)
    {
	//Loop through delimiters
	for(j = 0;*(str2 + j) != 0;j++)
	{
	    //IF match
	    if(*(str1 + i) == *(str2 + j))
	    {
		//Update string[i] to null
		*(str1 + i) = '\0';

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

//Function to implement atoi function
int my_atoi(char *str)
{
    int num = 0, i = 1, flag = 0;

    //Loop through string till null
    while(*str != '\0')
    {
        if(*str == '-')
        {
            flag = 1;
        }
        else if(*str == '+')
        {
           flag = 0;
        }
        else if(*str >= '0' && *str <= '9')
        {
            num = num * 10 + (*str - 48);
        }
        else
        {
            break;
        }
        str++;
    }

    return flag ? -num : num;
}

int main(int argc, char *argv[])
{
    char option, *str = NULL, *token = NULL, name[50];
    int num, *arr = NULL, choice, i, average = 0;

    do
    {
	//Print menu
	printf("\nChoose input method : \n1. Stdin\n2. Command line\n3. Environmental variables\n\nEnter your choice : ");
	scanf("%d", &choice);

	//Execute choice
	switch(choice)
	{
	    case 1:
		
		/*Simple read */
		printf("\nEnter the number of elements : ");
		scanf("%d", &num);

		arr = malloc(num * sizeof(int));

		//Read
		printf("Enter the elements : ");

		for(i = 0, average = 0;i < num;i++)
		{
		    scanf("%d", arr + i);
		    average += *(arr + i);
		}
		
		printf("\nThe average is %.2f\n", (float)average / num);

		free(arr);

		break;

	    case 2:
		
		/*Cla */

		if(argc > 1)
		{
		    //Add each cla
		    for(i = 1, average = 0; i < argc;i++)
		    {
			average += my_atoi(argv[i]);
		    }		    

		    printf("\nThe average is %.2f\n", (float)average / (argc - 1));
		}
		else
		{
		    printf("ERROR : No command line arguments were passed\n");
		}

		break;

	    case 3:
		
		/* Environmental variables */

		printf("\nEnter the array name : ");
		scanf("%s", name);	
		
		average = 0;

		//Tokenize each value, convert to int, find average
		if((str = getenv(name)) && (token = my_strtok(str, " ")))
		{
		    i = 0;

		    //Tokenise and add
		    while(token)
		    {
			i++;
			average += my_atoi(token);
			token = my_strtok(NULL, " ");
		    }

		    printf("\nThe average is %.2f\n", (float)average / i);
		}
		else
		{
		    printf("ERROR : Environmental variable doesnt exist\n");
		}

    		break;

	    default:
		printf("ERROR : Invalid choice\n");
	}

	__fpurge(stdin);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
