#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"

int main()
{
	node* head1=NULL;

	addElement(&head1, 2, 4);
	addElement(&head1, 4, 4);
	addElement(&head1, 1, 5);
	addElement(&head1, 10, 2);


	changeElementPriority(&head1, 2, 10);
	//getHighestPriority(&head1);


	printList(head1);
}