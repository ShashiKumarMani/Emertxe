
#include "Dlist.h"

int insert_last(Dlink **head, Dlink **tail, data_t data)
{
    Dlink *temp = *head, *new = malloc(sizeof(Dlink));
    
    if(new == NULL)
    {
	printf("ERROR : Memory allocation.\n");
	return -1;
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
	printf("List empty\n");
	*head = new;
	*tail = new;
	return 1;
    }

    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;

    return 1;
}

