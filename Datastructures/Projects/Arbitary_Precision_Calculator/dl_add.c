/*
    Function to implement linked list addition
 */

#include "Dlist.h"

int dl_add(Dlink **head1, Dlink **tail1, Dlink **head2, Dlink **tail2, Dlink **head3, Dlink **tail3)
{
    int carry = 0, num = 0, sum = 0, data1, data2;
    Dlink *temp1 = *tail1, *temp2 = *tail2;

    while(temp1 || temp2)
    {
	data1 = temp1 ? temp1->data : 0;
	data2 = temp2 ? temp2->data : 0;

	temp1 = temp1 ? temp1->prev : NULL;
	temp2 = temp2 ? temp2->prev : NULL;

	//printf("N1 - %d, N2 - %d, CY - %d\n", data1, data2, carry);
	sum = data1 + data2 + carry;

	num = sum % 10;

	insert_first(head3, tail3, num);

	//If sum >= 10
	carry = sum / 10;

    }
    //If carry exists in the last addition
    if(carry)
    {
	insert_first(head3, tail3, carry);
    }
}
