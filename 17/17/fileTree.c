#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"fileTree.h"


void insertSubtree(node* root, node subTree) // usuwanie ca³ego poddrzewa
{

}
void insert(node* root, char* element) // usuwanie pojedynczego elementu w drzewie
{

}
void removeSubtree(node* root, node subTree)
{

}

void removetree(node* root, char* element)
{

}

node find(node* root, char* element) // zwraca liœæ lub ca³e poddrzewo
{

}
void printNode(node root) // wyœwietla zawartoœæ przekazanego poddrzewa
{
	listnode tmp = root->childNodes;
	while (tmp)
	{
		printf("%s\n", tmp->catalog->data);
		tmp = tmp->next;
	}
}