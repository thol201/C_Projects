#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "heapSort.h"

void printTab(int* tab, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\n",tab[i]);
}

void prepTab(int* tab, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        tab[i] = rand();
}

void heap(int* arr, int j, int i)
{
    int temp;
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < j && arr[l] > arr[max])
        max = l;
    if (r < j && arr[r] > arr[max])
        max = r;
    if (max != i) 
    {
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        heap(arr, j, max);
    }
}

void hsort(int* tab,int j)
{
    int temp;
    for (int i = j / 2 - 1; i >= 0; i--)
        heap(tab,j, i);
    for (int i = j- 1; i >= 0; i--) 
    {
        temp = tab[0];
        tab[0] = tab[i];
        tab[i] = temp;
        heap(tab, i, 0);
    }
}

