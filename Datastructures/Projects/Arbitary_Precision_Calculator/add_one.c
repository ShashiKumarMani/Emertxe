/*
    Function to add one to the linked list
 */

#include "Dlist.h"

int add_one(Dlink **head, Dlink **tail, Dlink *temp)
{
    //Loop and add one
    while(temp)
    {
	temp->data++;

	if(temp->data == 10)
	{
	    temp->data = 0;
	    temp = temp->prev;
	}
	else
	{
	    break;
	}
    }

    //If carry exists in last addition
    if((*head)->data == 0)
    {
	insert_first(head, tail, 1);
    }
    
}
