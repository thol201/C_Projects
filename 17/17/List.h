#pragma once
#include"fileTree.h"

typedef struct listNode
{
	struct listNode* next;
	struct fileTree* catalog;
} linkedListNode;

typedef linkedListNode* listnode; 

void listaddElement(listnode* head, int value); // dodaj element w kolejnoœci
int listpop(listnode* head); // usuwanie pierwszego elementu listy i zwracanie jego wartoœci
listnode listfind(listnode head, int value); // znajdowanie elementu o wskazanej wartoœci
void listremoveElement(listnode* head, listnode element); // usuwanie elementu wczeœniej znalezionego
void listprintList(listnode head); // wyœwietlanie listy
