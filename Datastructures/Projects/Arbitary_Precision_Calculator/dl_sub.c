/*
    Function to implement linked list subtraction
 */
#include "Dlist.h"

int dl_sub(Dlink **head1, Dlink **tail1, Dlink **head2, Dlink **tail2, Dlink **head3, Dlink **tail3)
{
    int num, carry = 0, data1, data2, flag = 0;
    Dlink *temp1 = *tail1, *temp2 = *tail2;
    
    //Traverse through the list and subtract
    while(temp1 || temp2)
    {
	data1 = temp1 ? temp1->data : 0;
	data2 = temp2 ? temp2->data : 0;

	//If the number was borrowed, decrement by 1
	data1 = carry ? data1 - 1 : data1;
	carry = 0;

	num = data1 - data2;

	//If subtr negative, add 10 to first num
	if(num < 0)
	{
	    data1 = data1 + 10;
	    num = data1 - data2;
	    carry = 1;
	}

	insert_first(head3, tail3, num);
	    
	temp1 = temp1 ? temp1->prev : NULL;
	temp2 = temp2 ? temp2->prev : NULL;
    }

    //If first number smaller than second number, last carry
    if(carry)
    {
	delete_list(head3, tail3);
	dl_sub(head2, tail2, head1, tail1, head3, tail3);
    }

    //Remove zeros at the start of the number
    while((*head3)->data == 0 && (*head3)->next)
    {
	delete_first(head3, tail3);
    }

    //Add negative symbol
    if(carry)
    {
	insert_first(head3, tail3, NEGATIVE);
    }
}
