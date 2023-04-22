#pragma once
typedef struct priorityQueue
{
    int prior;
    int data;
    struct priorityQueue* next;
} priorityQueueNode;

typedef priorityQueueNode* node;

void addElement(node* head, int val, int priority); // dodawanie nowego elementu
node getHighestPriority(node* head); // pobieranie elementu z najwy¿szym priorytetem i jego usuwanie z kolejki
void changeElementPriority(node* head, int val, int priority); // znajdowanie elementu o konktretnej wartoœci i zmiana jego priorytetu na wskazany
void printList(node head);