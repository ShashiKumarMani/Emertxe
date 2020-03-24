/*
    Title : My_scanf
    Author : Shashi Kumar M
    Date : 6 November 2019
    Description : Program to implement scanf function.
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdio_ext.h>

//Function to implement atoi function
long int my_atoi()
{
    long int num = 0, i = 1, flag = 0;
    char ch;

    //Loop through string till null
    while(ch = getchar())
    {
	if(ch == '-')
        {
             flag = 1;
        }
        else if(ch == '+')
        {
           flag = 0;
        }
        else if(ch >= '0' && ch <= '9')
        {
            num = num * 10 + (ch - 48);
        }
	else
	{
	    break;
	}
     }
    
    return flag ? -num : num;
}
 
//Function to implement printf function
int my_scanf(char *str,...)
{
    char *cptr = NULL, ch;
    int *ptr = NULL, num, i, flag;
    short int *sptr = NULL, s_num;
    long int *lptr = NULL, l_num;

    va_list ap;
    va_start(ap, str);

    //Loop through the string
    while(*str != 0)
    {
	//Read format specifiers
	if(*str == '%')
	{
	    str++;

	    switch(*str)
	    {
		case 'd':
			ptr = (int *)va_arg(ap, long);
			*ptr = my_atoi();
			
			__fpurge(stdin);

		    break;
		case 'h':
			if(*++str == 'd')
			{
			    sptr = (short int *)va_arg(ap, long);
			    *sptr = my_atoi();	
			}
			
			__fpurge(stdin);

		    break;
		case 'c':
		    	cptr = (char *)va_arg(ap, long);
			ch = getchar();
			*cptr = ch;

			__fpurge(stdin);

		    break;
		case 's':
			i = 0;

			cptr = (char *)va_arg(ap, long);

			//Loop and read characters			
			while(ch = getchar())
			{
			    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			    {
				*(cptr + i) = ch;	
			    }
			    else if(ch == ' ')
			    {
				*(cptr + i) = 0;
			    }
			    else if(ch == '\n')
			    {
				*(cptr + i) = 0;
				break;
			    }
			    i++;
			}
			__fpurge(stdin);

		    break;
		case 'l':
						
			if(*++str == 'd')
    			{
			    lptr = (long *)va_arg(ap, long);
			    *lptr = my_atoi();
			}	
			
			__fpurge(stdin);

		    break;
	    }
	}
	str++;
    }
}

int main()
{
    char option, ch, string[50];
    int num;
    short int s_num;
    long int l_num;
    
    do
    {
	printf("\nEnter integer : ");
	my_scanf("%d", &num);

	printf("Enter character : ");
	my_scanf("%c", &ch);

	printf("Enter short value : ");
	my_scanf("%hd", &s_num);

	printf("Enter long int : ");
	my_scanf("%ld", &l_num);

	printf("Enter string : ");
	my_scanf("%s", string);

	printf("\nprintf : \n Char - %c \n Short - %hd \n Int - %d \n Long int - %ld \n String - %s \n", ch, s_num, num, l_num, string);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	scanf("%c", &option);
	printf("%d\n", option);

	__fpurge(stdin);

    }while(option == 'Y' || option == 'y');

    return 0;
}
