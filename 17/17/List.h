#pragma once
#include"fileTree.h"

typedef struct listNode
{
	struct listNode* next;
	struct fileTree* catalog;
} linkedListNode;

typedef linkedListNode* listnode; 

void listaddElement(listnode* head, int value); // dodaj element w kolejno�ci
int listpop(listnode* head); // usuwanie pierwszego elementu listy i zwracanie jego warto�ci
listnode listfind(listnode head, int value); // znajdowanie elementu o wskazanej warto�ci
void listremoveElement(listnode* head, listnode element); // usuwanie elementu wcze�niej znalezionego
void listprintList(listnode head); // wy�wietlanie listy
