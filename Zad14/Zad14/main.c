#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    node head = NULL;
	node head2 = NULL;

	insert(&head, "20");
	insert(&head, "13");
	insert(&head, "12");
	insert(&head, "16");
	insert(&head, "15");
	insert(&head, "22");
	insert(&head, "26");
	insert(&head, "25");
	
	printTree(head);

	clearFile("Tree.txt");
	saveToFile(head, "Tree.txt");
	
	readFromFile(&head2, "Tree.txt");
	printf("---------------------------\n");

	printTree(head2);

	return 0;
}