#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedList.h"

void push(node* head, int val) // dodawanie na pocz¹tek listy
{
	node new = malloc(sizeof(doublyLinkedListNode));
	new->next = *head;
	new->prev = NULL;
	new->data = val;
	if (*head)
		(*head)->prev = new;
	*head = new;
}
void pushEnd(node* head, int val) // dodawanie na koniec listy
{
	node previous = *head;
	node new;
	if (!*head)
	{
		push(head, val);
		return;
	}
	new = malloc(sizeof(doublyLinkedListNode));
	new->next = NULL;
	new->data = val;
	while (previous->next)
		previous = previous->next;
	previous->next = new;
	new->prev = previous;

}
int pop(node* head) // usuwanie pierwszego elementu listy i zwracanie jego wartoœci
{
	int val;
	node rem = *head;
	if (!*head)
		return 0;
	val = rem->data;
	*head = rem->next;
	free(rem);
	if (*head)
		(*head)->prev = NULL;
	return val;
}
int popEnd(node* head) // usuwanie ostatniego elementu listy i zwracanie jego wartoœci
{
	node ptr = *head;
	int val;
	if (!*head)
		return 0;
	if (!(*head)->next)
	{
		val = (*head)->data;
		pop(head);
		return val;
	}
	while (ptr->next->next)
	{
		ptr = ptr->next;
	}
	val = ptr->next->data;
	free(ptr->next);
	ptr->next = NULL;
	return val;
}
node find(node head, int val) // odszukaj zadany element
{
	while (head)
	{
		if (head->data == val)
			return head;
		head = head->next;
	}
	return 0;
}
void pushBefore(node* head, node current, int val) // dodaj element przed wskazanym
{
	node ptr = *head;
	if (!*head || !current)
		return;
	if (*head == current)
	{
		push(head, val);
		return;
	}
	while (ptr->next != current)
	{
		ptr = ptr->next;
	}
	push(&ptr->next, val);
}
void pushAfter(node* head, node current, int val) // dodaj za wskazanym elementem
{
	node ptr = *head;
	if (!*head || !current)
		return;
	while (ptr != current)
	{
		ptr = ptr->next;
	}
	push(&ptr->next, val);
}
void removeNode(node* head, node current) // usuñ wskazany element
{
	node ptr = *head;
	if (!*head || !current)
		return;
	if (*head == current)
	{
		pop(head);
		return;
	}
	while (ptr->next != current)
	{
		ptr = ptr->next;
	}
	pop(&ptr->next);
}
node readFromFile(char* fname) // wczytaj zawartoœæ listy z pliku
{
	FILE* wp = fopen(fname, "r");
	int tmp;
	node head = NULL;
	if (!wp)
	{
		printf("Error oppening file\n");
		return;
	}
	while (!feof(wp))
	{
		fscanf(wp, "%d", &tmp);
		if (tmp != NULL);
		push(&head, tmp);
	}

	return head;
}


int saveToFile(node head, char* fname) // zapisz zawartoœæ listy do pliku
{
	node l;
	if (head)
		l = head;
	else return;
	FILE* wp = fopen(fname, "w");
	if (!wp)
	{
		printf("Error oppening file\n");
		return;
	}
	while (l)
	{
		fprintf(wp, " %d", l->data);
		l = l->next;
	}
	fclose(wp);
}

void printList(node head) // wyœwietl zawartoœæ listy
{
	while (head)
	{
		printf("%d %p %p %p\n", head->data, head->prev, head, head->next);
		head = head->next;
	}
}

void addElementInOrder(node* head, int value) // dodaj element w kolejnoœci
{
	node ptr = *head,pre=NULL;
	if (!*head)
	{
		push(head, value);
		return;
	}
	while (ptr->next && ptr->next->data < value)
	{
		pre = ptr;
		ptr = ptr->next;
	}
	if (!pre&& ptr->data > value)
	{
		push(head, value);
	}
	else
	push(&ptr->next,value);
}
node findInOrder(node head, int value) // znajdowanie elementu o wskazanej wartoœci
{
	while (head && head->data != value)
		head = head->next;
	if (head->data == value)
		return head;
	else
		return 0;
}
void removeElementInOrder(node* head, node element) // usuwanie elementu wczeœniej znalezionego
{
	node ptr = *head;
	if (!*head || !element)
		return;
	if (ptr == element)
	{
		pop(head);
		return;
	}
	while (ptr->next != element)
	{
		ptr = ptr->next;
	}
	pop(&ptr->next);
}
node readFromFileInOrder(char* fname) // wczytanie listy Z! pliku (w porz¹dku, ale w pliku nie musi byæ zachowany porz¹dek)
{
	FILE* wp = fopen(fname, "r");
	int tmp;
	node head = NULL;
	if (!wp)
	{
		printf("Error oppening file\n");
		return;
	}
	while (!feof(wp))
	{
		fscanf(wp, "%d", &tmp);
		if (tmp != NULL);
		addElementInOrder(&head, tmp);
	}

	return head;
}