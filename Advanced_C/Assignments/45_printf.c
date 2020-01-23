/*
    Title : My_printf
    Author : Shashi Kumar M
    Date : 6 November 2019
    Description : Program to implement printf function.
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdio_ext.h>

//Function to implment itoa function
void my_itoa(long int num, char *str)
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

//Function to implement printf function
int my_printf(char *str,...)
{
    unsigned int num;
    char ch, *string = NULL, arr[100], *ptr = NULL;
    unsigned long int l_num;
    short s_num;

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
		        num = va_arg(ap, int);
			my_itoa(num, arr);
			    
			ptr = arr;

			while(*ptr != 0)
			{
			    putchar(*ptr);
			    ptr++;
			}
		    break;

		case 'h':
			if(*++str == 'd')
			{
			    s_num = va_arg(ap, int);
			    my_itoa(s_num, arr);
			    
			    ptr = arr;

			    while(*ptr)
			    {
				putchar(*ptr);
				ptr++;
			    }
			}
		    break;

		case 'c':
		        ch = va_arg(ap, int);
			putchar(ch);
		    break;

		case 's':
		        string = va_arg(ap, char *);
			
			while(*string != 0)
			{
			    putchar(*string);
			    string++;
			}
		    break;

		case 'l':

			if(*++str == 'd')
			{
			    l_num = va_arg(ap, long);

			    my_itoa(l_num, arr);

			    ptr = arr;

			    while(*ptr)
			    {
				putchar(*ptr);
				ptr++;
			    }
			}	

		    break;
		case '%' :
			putchar('%');
		    break;
	    }
	}
	else
	{
	    putchar(*str);
	}
	str++;
    }
}

int main()
{
    char option, ch;
    int num;
    short int s_num;
    char string[50];
    long int po = 10;

    do
    {
	my_printf("\nmy_printf - print string : ABCDDEFF\n");		

	my_printf("\nEnter char : ");
	scanf("\n%c", &ch);

	my_printf("\nEnter integer : ");
	scanf("%d", &num);

	my_printf("Enter short value : ");
	scanf("%hd", &s_num);

	my_printf("Enter long int : ");
	scanf("%ld", &po);

	my_printf("Enter string : ");
	scanf("%s", string);

	 printf("\nprintf    - Char - %c  Short - %hd Int - %d Long int - %ld String - %s %%\n", ch, num, s_num, po, string);
	my_printf("my_printf - Char - %c  Short - %hd Int - %d Long int - %ld String - %s %%\n", ch, num, s_num, po, string);

	__fpurge(stdin);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
