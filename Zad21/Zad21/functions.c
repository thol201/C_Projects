#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "functions.h"

int* prepTab(int* tab, int size)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < size; i++)
		tab[i] = rand();
	return tab;
}

void sort_bubble(int* tab, int size,int* comp,int* sets)
{
	int i, j, tmp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			(*comp)++;
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = tmp;
				(*sets) += 3;
			}
		}
	}
}

void sort_insert(int* tab, int size, int* comp, int* sets)
{
	int i,tmp,j;
	for (i = 2;i<size;i++)
	{
		tmp = tab[i];
		j = i - 1;
		(*sets) ++;
		while (j >= 0)
		{
			(*comp)++;
			if (tab[j] > tmp)
			{
				tab[j + 1] = tab[j];
				--j;
				(*sets) ++;
			}
			else
				break;
		}
		tab[j + 1] = tmp;
		(*sets)++;
	}
}

void sort_shell(int* tab, int n, int* comp, int* sets)
{
	int divider = n / 2;
	int i = divider;
	int temp;
	int j;
	while (divider >= 1) 
	{
		for (i = divider; i < n; i += 1) {
			temp = tab[i];
			(*sets) ++;
			for (j = i; j >= divider; j -= divider)
			{
				(*comp)++;
				if (tab[j - divider] > temp)
				{
					tab[j] = tab[j - divider];
					(*sets)++;
				}
				else
					break;

			}
			tab[j] = temp;
			(*sets)++;
		}
		divider /= 2;
	}
}

void quicksort(int* number, int first, int last, int* comp, int* sets) {
	int i, j, pivot, temp;
	if (first < last) {
		pivot = first;
		i = first;
		j = last;
		while (i < j) {
			while (number[i] <= number[pivot] && i < last)
			{
				(*comp)++;
				i++;
			}
			while (number[j] > number[pivot])
			{
				(*comp)++;
				j--;
			}
			if (i < j) {
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
				(*sets) += 3;
			}
		}
		temp = number[pivot];
		number[pivot] = number[j];
		number[j] = temp;
		(*sets) += 3;
		quicksort(number, first, j - 1,comp,sets);
		quicksort(number, j + 1, last,comp,sets);
	}
}