#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

	node head = NULL;
	node head2 = NULL;

	insert(&head, 20);
	insert(&head, 13);
	insert(&head, 12);
	insert(&head, 16);
	insert(&head, 15);
	insert(&head, 22);
	insert(&head, 26);
	insert(&head, 25);

	insert(&head2, 15);
	insert(&head2, 22);
	insert(&head2, 26);
	insert(&head2, 25);
	insert(&head2, 20);
	insert(&head2, 13);
	insert(&head2, 12);
	insert(&head2, 16);
	//insert(&head2, 36);

	printTree(head);

	printf("---------------------------\n");

	printTree(head2);

	printf("%d\n",containSameValues(&head,&head2));

	return 0;
}