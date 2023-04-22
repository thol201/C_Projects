typedef struct listNode
{
	int data;
	struct listNode* next;
	struct listNode* prev;
} doublyLinkedListNode;

typedef doublyLinkedListNode* node;

// ZADANIE 9

// Lista dwukierunkowa nieposortowana 
void push(node* head, int val); // dodawanie na pocz¹tek listy
void pushEnd(node* head, int val); // dodawanie na koniec listy
int pop(node* head); // usuwanie pierwszego elementu listy i zwracanie jego wartoœci
int popEnd(node* head); // usuwanie ostatniego elementu listy i zwracanie jego wartoœci
node find(node head, int val); // odszukaj zadany element
void pushBefore(node* head, node current, int val); // dodaj element przed wskazanym
void pushAfter(node* head, node current, int val); // dodaj za wskazanym elementem
void removeNode(node* head, node current); // usuñ wskazany element
node readFromFile(char* fname); // wczytaj zawartoœæ listy z pliku
int saveToFile(node head, char* fname); // zapisz zawartoœæ listy do pliku
void printList(node head); // wyœwietl zawartoœæ listy

// lista dwukierunkowa posortowana
void addElementInOrder(node* head, int value); // dodaj element w kolejnoœci
node findInOrder(node head, int value); // znajdowanie elementu o wskazanej wartoœci
void removeElementInOrder(node* head, node element); // usuwanie elementu wczeœniej znalezionego
node readFromFileInOrder(char* fname); // wczytanie listy do pliku (w porz¹dku, ale w pliku nie musi byæ zachowany porz¹dek)

// UWAGA! W driverze nale¿y daæ u¿ytkownikowi mo¿lwoœæ wyboru, czy chce dzia³aæ na liœcie posortowanej czy te¿ nie

