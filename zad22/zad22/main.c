// proszę wykonać sortowanie przez kopcowanie na tablicy o długości przynajmniej 1000 słów
#include<stdio.h>
#include<stdlib.h>
#include "heapSort.h"

int main()
{
	int* tab = malloc(sizeof(int) * 1000);
	prepTab(tab,1000);
	hsort(tab, 1000);
	printTab(tab, 1000);
	return 0;
}