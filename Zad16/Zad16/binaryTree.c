#include "binaryTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert(node* root, int val)
{
	if (!*root)
	{
		*root = (node)malloc(sizeof(treeNode));
		(*root)->value = val;
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*root)->parent = NULL;
	}
	else
	{
		if (val > (*root)->value)
		{
			insert(&(*root)->right, val);
			(*root)->right->parent = (*root);
		}
		else {
			insert(&(*root)->left, val);
			(*root)->left->parent = (*root);
		}
	}
}


node treeMax(node root)
{
	if (!root)
		return 0;
	while (root->right)
		root = root->right;
	return root;
}
node treeMin(node root)
{
	if (!root)
		return 0;
	while (root->left)
		root = root->left;
	return root;
}

node ancestor(node root)
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
	} while (root && root->right == tmp);

	return root;

}
node descendant(node root)
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
	} while (root && root->left == tmp);
	return root;

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

void printtr(node root, int space)
{
	if (root == NULL)
		return;
	space += 10;
	printtr(root->right, space);
	printf("\n");
	for (int i = 5; i < space; i++)
		printf(" ");
	printf("%d\n", root->value);
	printtr(root->left, space);
}


void printTree(node root)
{
	printtr(root, 0);
}


int containSameValues(node* tree1, node* tree2)
{
	node min1, min2;
	if (!*tree1 || !*tree2)
		return 0;
	min1 = Min(*tree1);
	min2 = Min(*tree2);

	while (min1 || min2)
	{
		if (!min1 || !min2 || (min1->value != min2->value))
			return 0;
		min1 = ancestor(min1);
		min2 = ancestor(min2);
	}
	return 1;
}
