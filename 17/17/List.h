#pragma once
#include"fileTree.h"

typedef struct listNode
{
	struct listNode* next;
	struct fileTree* catalog;
} linkedListNode;

typedef linkedListNode* listnode; 

void listaddElement(listnode* head, int value); // dodaj element w kolejności
int listpop(listnode* head); // usuwanie pierwszego elementu listy i zwracanie jego wartości
listnode listfind(listnode head, int value); // znajdowanie elementu o wskazanej wartości
void listremoveElement(listnode* head, listnode element); // usuwanie elementu wcześniej znalezionego
void listprintList(listnode head); // wyświetlanie listy
