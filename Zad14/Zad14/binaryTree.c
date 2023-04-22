#include "binaryTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert(node* root, char* value)
{
	if(!*root)
	{ 
		*root = (node)malloc(sizeof(treeNode));
		(*root)->word = value;
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*root)->parent = NULL;
	}
	else
	{
		if (strcmp((*root)->word, value) < 0) 
		{
			insert(&(*root)->right, value);
			(*root)->right->parent = (*root);
		}
		else {
			insert(&(*root)->left, value);
			(*root)->left->parent = (*root);
		}
	}
}
void removeNode(node* root, char* value)
{
	
	node tmp=*root,parr,tmp2;
	if (!*root)
		return;
	while (tmp->word!=value)
	{
		if (strcmp(tmp->word, value) < 0)
		{
			tmp = tmp->right;
		}
		else
			tmp = tmp->left;
	}
	if (!tmp)
		return;

	parr = tmp->parent;
	tmp2 = tmp->left;

	

	if (!tmp->right && !tmp->left)
	{
		free(tmp);
		if (parr->left = tmp)
			parr->left = NULL;
		else
			parr->right = NULL;
	}
	else if (!tmp->left)
	{
		if (tmp == *root)
		{
			*root = tmp->right;
			if ((*root)->right)
				Min((*root)->left)->left = tmp2;
			else
				(*root)->left = tmp2;
			return;
		}
		if (parr->left == tmp)
		{
			parr->left = tmp->right;
			if(parr->left)
				parr->left->parent = parr;
		}
		else
		{
			parr->right = tmp->right;
			if (parr->right)
				parr->right->parent = parr;
		}
		free(tmp);
	}
	else if (!tmp->right)
	{
		if (tmp == *root)
		{
			*root = tmp->left;
			if ((*root)->left)
				Min((*root)->left)->left = tmp2;
			else
				(*root)->left = tmp2;
			return;
		}
		if (parr->left == tmp)
		{
			parr->left = tmp->left;
			if (parr->left)
				parr->left->parent = parr;
		}
		else
		{
			parr->right = tmp->left;
			if (parr->right)
				parr->right->parent = parr;
		}
		free(tmp);
	}
	else
	{
		if (tmp == *root)
		{
			*root = tmp->right;
			if ((*root)->left)
				Min((*root)->left)->left = tmp2;
			else
				(*root)->left = tmp2;
			return;
		}
		if (parr->left == tmp)
		{
			parr->left = tmp->right;
			if (parr->left)
				parr->left->parent = parr;
			Min(parr->left)->left = tmp2;
		}
		else
		{
			parr->right = tmp->right;
			if (parr->right)
				parr->right->parent = parr;
			Min(parr->right)->left = tmp2;
		}
		free(tmp);
	}
}

node Min(node root)
{
	if (!root)
		return 0;
	while (root->left)
		root = root->left;
	return root;
}
node Max(node root)
{
	if (!root)
		return 0;
	while (root->right)
		root = root->right;
	return root;
}

void clearFile(char* fname)
{
	FILE* wp = fopen(fname, "w");
	fclose(wp);
}

char* treeMax(node root)
{
	if (!root)
		return 0;
	while (root->right)
		root = root->right;
	return root->word;
}
char* treeMin(node root)
{
	if (!root)
		return 0;
	while (root->left)
		root = root->left;
	return root->word;
}
char* ancestor(node root)
{
	node tmp;
	if (!root)
		return 0;
	if (root->right) 
	{
		return treeMin(root->right);
	}
	do
	{
		tmp = root;
		root = root->parent;
	} 
	while (root && root->right == tmp);
	
	return root->word;

}
char* descendant(node root)
{
	node tmp;
	if (!root)
		return 0;
	if (root->left) 
		return treeMax(root->left);
	do 
	{
		tmp = root;
		root = root->parent;
	} 
	while (root && root->left == tmp);
	return root->word;

}

void printtr(node root, int space)
{
	if (root == NULL)
		return;
	space += 5;
	printtr(root->right, space);
	printf("\n");
	for (int i = 5; i < space; i++)
		printf(" ");
	printf("%s\n", root->word);
	printtr(root->left, space);
}

void printTree(node root) {
	printtr(root, 0);
}

void readFromFile(node* head,char* fname) // wczytaj zawartoœæ listy z pliku
{
	FILE* wp = fopen(fname, "r");
	char* tmp;
	if (!wp)
	{
		printf("Error oppening file\n");
		return;
	}
	while (!feof(wp))
	{
		fscanf(wp, "%s", &tmp);
		if (tmp != NULL);
		insert(&head, tmp);
	}
	return head;
}


void saveToFile(node head, char* fname) // zapisz zawartoœæ listy do pliku
{
	node l;
	if (head)
		l = head;
	else return;
	FILE* wp = fopen(fname, "a");
	if (!wp)
	{
		printf("Error oppening file\n");
		return;
	}
	fprintf(wp, "%s\n", l->word);
	fclose(wp);
	saveToFile(head->right, fname);
	saveToFile(head->left, fname);
}