#include "binaryTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert(node* root, char* value)
{
	if(!*root)
	{ 
		*root = (node)malloc(sizeof(treeNode));
		//strncpy((*root)->word, value, sizeof((*root)->word));

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
		else if (strcmp((*root)->word, value) > 0)
		{
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

	if (tmp == *root)
	{
		*root = tmp->right;
		if((*root)->left)
		Min((*root)->left)->left = tmp2;
		else
			(*root)->left = tmp2;
		return;
	}

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
	
	return tmp->word;

}

node ancestor2(node root)
{
	node tmp;
	if (!root)
		return 0;
	if (root->right)
	{
		return Min(root->right);
	}
	do
	{
		tmp = root;
		root = root->parent;
	} while (root && root->right == tmp);

	return root;

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
	return tmp->word;

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

void save(node root)
{
	FILE* wp = fopen("tree.txt", "a");
	if (!wp)
	{
		printf("Error oppening file\n");
		return;
	}
	if(root->parent)
		fprintf(wp, "%s %s\n", root->parent->word, root->word);
	else
		fprintf(wp, "%s %s\n", "00", root->word);
	fclose(wp);

}

void saveToFile(node root)
{
	FILE* wp = fopen("tree.txt", "w");

	node l=root;

	if (!root)
		return;
	l = Min(root);
	while (l)
	{
		save(l);
		l = ancestor2(l);
	}
	fclose(wp);
}

node find(node root,char* val)
{
	node tmp = root;

	while (tmp&&tmp->word != val)
	{
		if (strcmp(tmp->word, val) < 0)
		{
			tmp = tmp->right;
		}
		else if (strcmp(tmp->word, val) > 0)
			tmp = tmp->left;
		else
			break;
	}
	if (!tmp)
		return NULL;
	return tmp;
}

void read(node root, char* ch1, char* ch2)
{

	node fou = find(root, ch1);
	if (!fou)
	{
		FILE* wp = fopen("tree.txt", "a");
		fprintf(wp, "%s %s\n", ch1, ch2);
		fclose(wp);
	}
	else
		insert(&fou, ch2);
}

int contains(char* fst, char* snd)
{
	int len1 = 0;
	while (fst[len1]) len1++;
	int s;

	if (fst[0]==snd[0]&&fst[1]==snd[1])
	{
		return 1;
	}
	return 0;
}

void readFromFile(node* root, char* filename)
{
	FILE* wp = fopen("tree.txt", "r");
	node l = root;
	char ch[60];
	char* ch1 = (char*)calloc(20,sizeof(char));
	char* ch2 = (char*)calloc(20, sizeof(char));
	int len1 = 3;
	int reset = 1;
	int len2 = 0;
	while (!feof(wp)) 
	{
		fgets(ch,60,wp);
		if (contains(ch, "00"))
		{
			while (ch[len1]!='\n')
			{
				ch1[len1-3] = ch[len1];
				len1++;
			}
			insert(root, ch1);
			fclose(wp);
			break;
		}
	}
	wp = fopen("tree.txt", "r+");
		while (!feof(wp))
		{
		ch1 = (char*)calloc(20, sizeof(char));
		ch2 = (char*)calloc(20, sizeof(char));
		len1 = 0;
		fgets(ch, 60, wp);
		if (!contains(ch, "00"))
		{
			while (ch[len1] != ' ')
			{

				ch1[len1] = ch[len1];
				len1++;
			}
			len1++;
			while (ch[len1] != '\n')
			{
				ch2[len2] = ch[len1];
				len1++;
				len2++;
			}
			read(*root, ch1, ch2);
		}

		len1 = 0;
		len2 = 0;

	}





}