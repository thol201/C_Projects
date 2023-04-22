#pragma once
#include"List.h"

typedef struct fileTree
{
    char* data; // nazwa katalogu lub pliku
    struct fileTree* parent;
    struct linkedListNode* childNodes; // ? uzupełnić należy odpowiednim typem danych
} fileTreeNode;

typedef fileTreeNode* node;

void insertSubtree(node* root, node subTree); // usuwanie całego poddrzewa
void insert(node* root, char* element); // usuwanie pojedynczego elementu w drzewie
void removeSubtree(node* root, node subTree);
void removetree (node* root, char* element);
node find(node* root, char* element); // zwraca liść lub całe poddrzewo
void printNode(node root); // wyświetla zawartość przekazanego poddrzewa