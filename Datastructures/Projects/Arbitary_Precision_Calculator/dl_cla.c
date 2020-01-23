/*
    Function to validate and evalure command line arguments
 */

#include "Dlist.h"

int dl_cla(char *expression, Dlink **head1, Dlink **tail1, Dlink **head2, Dlink **tail2, char *operator)
{
    int flag = 0;

    //Loop through the expression
    while(*expression)
    {
	//If the character is a digit
	if(*expression >= '0' && *expression <= '9')
	{
	    if(flag)
	    {
		insert_last(head2, tail2, *expression - 48);
	    }
	    else
	    {
		insert_last(head1, tail1, *expression - 48);
	    }
	}
	else if(*expression == '+' || *expression == '-' || *expression == '/' || *expression == '*')
	{
	    //Set flag to start inserting to second number
	    if(flag)
		return FAILURE;
	    flag = 1;
	    *operator = *expression;
	}
	//Any other character is passed
	else
	{
	    return FAILURE;
	}
	expression++;
    }

    //Remove zeros at the beginning
    while((*head1)->next && (*head1)->data == 0)
    {
	delete_first(head1, tail1);
    }

    while((*head2)->next && (*head2)->data == 0)
    {
	delete_first(head2, head2);
    }

    //If second number is not passed
    if(*head1 == NULL || *head2 == NULL)
    {
	return FAILURE;
    }
}
