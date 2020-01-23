
#include "Dlist.h"

int print_list(Dlink *head)
{
    //1. Create a temporary pointer
    Dlink *temp = head;

    //2. Check if list is empty
    if(head == NULL)
    {
	printf("List empty\n");
	return 1;
    }

    //3. Loop and print the linked list
    while(temp)
    {
	if(temp->data == NEGATIVE)
	{
	    printf("-");
	}
	else if(temp->data == DOT)
	{
	    printf(".");
	}
	else
	{
	    printf("%d", temp->data);
	}
	temp = temp->next;
    }
    printf("\n");
    return 1;
}

