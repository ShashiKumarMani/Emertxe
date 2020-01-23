/*
    Function to implement linked list multiplication using single digit
 */
#include "Dlist.h"

int dl_mul_one(Dlink **head, Dlink **tail, int num, Dlink **prod_h, Dlink **prod_t)
{
    Dlink *temp1 = *tail;

    int prod = 0, sum = 0, carry = 0;

//    printf("\nMultiplying ");
  //  print_list(*head);
    //printf(" and Num - %d\n", num);

   // printf("-----------\n");
    
    //Traverse through list in reverse
    while(temp1)
    {
	//Multiply each element with the num, store carry, insert the unit digit of product
	prod = temp1->data * num + carry;
	carry = prod / 10;

	insert_first(prod_h, prod_t, prod % 10);

	temp1 = temp1->prev;
    }

    //If final operation has carry
    if(carry)
	insert_first(prod_h, prod_t, carry);
    
    //printf("-------------\n");
}
