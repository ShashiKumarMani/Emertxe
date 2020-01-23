/*
    Function to implement linked list multiplication
 */
#include "Dlist.h"

int dl_mul(Dlink **head1, Dlink **tail1, Dlink **head2, Dlink **tail2, Dlink **head3, Dlink **tail3)
{
    Dlink *temp = *tail2, *prod_h = NULL, *prod_t = NULL, *temp2_h = NULL, *temp2_t = NULL;
    int count = 0;
    
    //printf("MUL : Num1 : ");
    //print_list(*head1);
    //printf("	  Num2 : ");
    //print_list(*head2);

    //Initialise sum to zero
    insert_first(head3, tail3, 0);

    //Traverse through list-2
    while(temp)
    {
	temp2_h = NULL;
	temp2_t = NULL;

	//Add zeros at end for each product list
	for(int i = 0;i < count;i++)
	{
	    insert_first(&prod_h, &prod_t, 0);
	}

	//Multiply the list-1 with each digit from list-2, store in prod-list
	dl_mul_one(head1, tail1, temp->data, &prod_h, &prod_t);

	//Add result with final result
	dl_add(&prod_h, &prod_t, head3, tail3, &temp2_h, &temp2_t);
	delete_list(&prod_h, &prod_t); 
	delete_list(head3, tail3);

	*head3 = temp2_h;
	*tail3 = temp2_t;

	count++;

	temp = temp->prev;
    }	    

    //Remove zeros at the beginning
    while((*head3)->next && (*head3)->data == 0)
    {
	delete_first(head3, tail3);
    }

    //printf("	    Mul-res : ");
    //print_list(*head3);
}
