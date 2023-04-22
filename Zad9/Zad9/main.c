#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedList.h"


int main()
{
    node head = NULL;
    int select = 1,select2, val, val2;
    printf("lista nieposortowana = 0 \nposortowana = 1\n");
    scanf("%d", &select2);
    if(select2==0)
    while (select)
    {
        printf("\n\n");
        printf("basic menu.take it or leave it\n");
        printf("1 - dodaj element na poczatek listy\n");
        printf("2 - dodaj element na koniec listy\n");
        printf("3 - usun pierwszy element\n");
        printf("4 - usun ostatni element\n");
        printf("5 - znajdz element\n");
        printf("6 - dodaj przed elementem\n");
        printf("7 - dodaj za elementem\n");
        printf("8 - usun wskazany element\n");
        printf("9 - wczytaj z pliku\n");
        printf("10 - wypisz liste\n");
        printf("11 - zapisz do pliku\n");


        scanf("%d", &select);
        system("cls");
        switch (select)
        {
        case 1:
            printf("insert value\n");
            scanf("%d", &val);
            push(&head, val);
            break;
        case 2:
            printf("insert value\n");
            scanf("%d", &val);
            pushEnd(&head, val);
            break;
        case 3:
            printf("usuniento %d", pop(&head));
            break;
        case 4:
            printf("usuniento %d", popEnd(&head));
            break;
        case 5:
            printf("insert value\n");
            scanf("%d", &val);
            printf("%p\n", find(head, val));
            break;
        case 6:
            printf("insert find value\n");
            scanf("%d", &val);
            printf("insert value\n");
            scanf("%d", &val2);
            pushBefore(&head, find(head, val), val2);
            break;
        case 7:
            printf("insert find value\n");
            scanf("%d", &val);
            printf("insert value\n");
            scanf("%d", &val2);
            pushAfter(&head, find(head, val), val2);
            break;
        case 8:
            printf("insert remove value\n");
            scanf("%d", &val);
            removeNode(&head, find(head, val));
            break;
        case 9:
            head =readFromFile("nodes.txt");
            break;
        case 11:
            saveToFile(head, "nodes.txt");
            break;
        case 10:
            printList(head);
            break;
        default:
            break;

        }
    }
    else
        while (select)
        {
            printf("\n\n");
            printf("basic menu.take it or leave it\n");
            printf("1 - dodaj do listy\n");
            printf("2 - znajdz element\n");
            printf("3 - usun wskazany element\n");
            printf("4 - wczytaj z pliku\n");
            printf("10 - wypisz liste\n");
            scanf("%d", &select);
            system("cls");
            switch (select)
            {
            case 1:
                printf("insert value\n");
                scanf("%d", &val);
                addElementInOrder(&head, val);
                break;
            case 2:
                printf("insert value\n");
                scanf("%d", &val);
                printf("%p\n", findInOrder(head, val));
                break;
            case 3:
                printf("insert remove value\n");
                scanf("%d", &val);
                removeElementInOrder(&head, findInOrder(head, val));
                break;
            case 4:
                head = readFromFileInOrder("nodes2.txt");
                break;
            case 10:
                printList(head);
                break;
            }
        }
    return 0;


}