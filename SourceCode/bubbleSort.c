#include "main.h"
#include "struct.h"

void bubbleSort(struct dist *start)
{
    int swapped, i;
    struct dist *ptr1;
    struct dist *lptr = NULL;
  
    //Checking for empty list 
    if (start == NULL)
    {
    	printf("Error! Empty list given.");
		exit(1);
	}
  
    do
    {	
        swapped = 0;
        ptr1 = start;
  		
  		//traversing the linked list
        while (ptr1->next != lptr)
        {
        	//comparing quantity between current node and adjacent node
            if (ptr1->quantity < ptr1->next->quantity)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next; //point to the next node
        }
        lptr = ptr1; //reset the pointer to point to first node
    }
    while (swapped);
}
  
//function to swap data of two nodes a and b
void swap(struct dist *a, struct dist *b)
{
    int temp = a->quantity;
    a->quantity = b->quantity;
    b->quantity = temp;
}
