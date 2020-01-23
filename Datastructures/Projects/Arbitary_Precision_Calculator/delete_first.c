/*
    Function to delete a node at the start of a doubly linked list
 */

#include "Dlist.h"

data_t delete_first(Dlink **head, Dlink **tail)
{
    //If list is empty
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }

    Dlink *temp = *head;

    //Move head to next node
    *head = temp->next;

    //Traverse till the last node
    if(temp->next)
    {
	(*head)->prev = NULL;
    }
    else
    {
	*tail = NULL;
    }	

    //Delete the node
    free(temp);

    return SUCCESS;
}
