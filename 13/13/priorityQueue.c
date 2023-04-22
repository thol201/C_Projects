#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"

void addElement(node* head, int val, int priority) // dodawanie nowego elementu
{
	node new = malloc(sizeof(priorityQueueNode));
	node tmp = *head;

	new->data = val;
	new->prior = priority;

	if (!*head)
	{
		*head = new;
		new->next = NULL;
	}
	else
	{
		if ((*head)->prior <= priority)
		{
			new->next = *head;
			*head = new;
		}
		else
		{
			while (tmp->next && tmp->next->prior > priority)
			{
				tmp = tmp->next;
			}
			
			new->next = tmp->next;
			tmp->next = new;
		}
	}
}

node getHighestPriority(node* head) // pobieranie elementu z najwy¿szym priorytetem i jego usuwanie z kolejki
{
	node tmp = *head;
	if (!*head)
		return;
	*head = tmp->next;
	free(tmp);
}

void changeElementPriority(node* head, int val, int priority) // znajdowanie elementu o konktretnej wartoœci i zmiana jego priorytetu na wskazany
{
	node tmp = *head;
	node tmp2 = *head;
	node prev = tmp;
	if (!*head)
		return;
	while (tmp && tmp->data != val)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev == tmp)
	{
		tmp->prior = priority;
		return;
	}

	prev->next = tmp->next;
	tmp->prior = priority;
	prev = *head;

	while (tmp2 && tmp2->prior >= priority)
	{
		prev = tmp2;
		tmp2 = tmp2->next;
	}

	if (prev == tmp2)
	{
		tmp->next = *head;
		*head = tmp;
		return;
	}

	tmp->next = prev->next;
	prev->next = tmp;

}

void printList(node head)
{
	node ptr = head;
	if (!ptr)
		return;
	do
	{
		printf("%d %d %p %p\n", ptr->data, ptr->prior, ptr, ptr->next);
		ptr = ptr->next;
	} while (ptr);
}