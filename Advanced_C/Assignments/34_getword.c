/*
    ###
    Title : Implement - getword(), atoi(), itoa() functions.
    Author : Shashi Kumar M
    Date : 21 October 2019
    Description : Program to implement the functions getword, atoi, itoa functions.
		  Input - A string / Number
		  Output - Integer / string.
 */

#include<stdio.h>
#include<stdio_ext.h>

//Function to implement getword function
int my_getword(char *str)
{
    char ch;
    int i = 0;

    //Loop and read character
    while((ch = getchar()))
    {
	if(ch != ' ' && ch != '\t' && ch != '\n')
	{
	    str[i] = ch;
	}	    
	else
	{
	    //Enter null at the end, return size
	    str[i] = 0;
	    return i;
	}
	i++;
    }
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

//Function to implment itoa function
void my_itoa(int num, char *str)
{
    int i = 0,j;
    char temp;

    //Convert integer to string
    while(num > 0)
    {
	str[i] = num % 10 + 48;
	num /= 10;
	i++;
    }
    str[i] = 0;

    //Reverse the string
    for(j = 0;j < i / 2;j++)
    {
	temp = str[j];
	str[j] = str[i - j - 1];	
	str[i - j - 1] = temp;
    }
}

int main()
{
    //Declare variables
    char option, str[50];
    int choice, ret;

    do
    {
	//Read the choice
	printf("Choose \n1. Getword()\n2. Atoi\n3. Itoa\n\nEnter your choice : ");
	scanf("%d", &choice);

	//Execute choice
	switch(choice)
	{
	    case 1:
		    printf("Enter the string : ");

		    //Clear input buffer
		    __fpurge(stdin);

		    ret = my_getword(str);

		    printf("The string - %s, Length of the string - %d\n", str, ret);
		break;

	    case 2:
		    printf("Enter the string : ");
		    scanf("%s", str);

		    ret = my_atoi(str);

		    printf("The integer - %d\n", ret);

		break;

	    case 3:
		    printf("Enter the integer value : ");
		    scanf("%d", &ret);

		    my_itoa(ret, str);

		    printf("The string - %s\n", str);

		break;

	    default : 
		    printf("ERROR : Invalid choice\n");
	}

	__fpurge(stdin);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	scanf("%c", &option);
	getchar();
	//printf("option - %d\n", option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
