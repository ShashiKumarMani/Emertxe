/*
    Function to delete at node at the end of a doubly linked list
 */

#include "Dlist.h"

data_t delete_last(Dlink **head, Dlink **tail)
{
    //If link empty
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }

    Dlink *temp = *tail;

    //Move tail to previous node
    *tail = temp->prev;

    if(temp->prev)
    {
	(*tail)->next = NULL;
    }
    else
    {
	*head = NULL;
    }
    free(temp);

    return SUCCESS;
}
