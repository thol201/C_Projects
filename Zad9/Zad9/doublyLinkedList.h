typedef struct listNode
{
	int data;
	struct listNode* next;
	struct listNode* prev;
} doublyLinkedListNode;

typedef doublyLinkedListNode* node;

// ZADANIE 9

// Lista dwukierunkowa nieposortowana 
void push(node* head, int val); // dodawanie na pocz�tek listy
void pushEnd(node* head, int val); // dodawanie na koniec listy
int pop(node* head); // usuwanie pierwszego elementu listy i zwracanie jego warto�ci
int popEnd(node* head); // usuwanie ostatniego elementu listy i zwracanie jego warto�ci
node find(node head, int val); // odszukaj zadany element
void pushBefore(node* head, node current, int val); // dodaj element przed wskazanym
void pushAfter(node* head, node current, int val); // dodaj za wskazanym elementem
void removeNode(node* head, node current); // usu� wskazany element
node readFromFile(char* fname); // wczytaj zawarto�� listy z pliku
int saveToFile(node head, char* fname); // zapisz zawarto�� listy do pliku
void printList(node head); // wy�wietl zawarto�� listy

// lista dwukierunkowa posortowana
void addElementInOrder(node* head, int value); // dodaj element w kolejno�ci
node findInOrder(node head, int value); // znajdowanie elementu o wskazanej warto�ci
void removeElementInOrder(node* head, node element); // usuwanie elementu wcze�niej znalezionego
node readFromFileInOrder(char* fname); // wczytanie listy do pliku (w porz�dku, ale w pliku nie musi by� zachowany porz�dek)

// UWAGA! W driverze nale�y da� u�ytkownikowi mo�lwo�� wyboru, czy chce dzia�a� na li�cie posortowanej czy te� nie

