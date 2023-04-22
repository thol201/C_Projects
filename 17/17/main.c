#include <stdio.h>
#include <stdlib.h>
#include "fileTree.h"

int Get_Command(char* com)
{

    int lenS1 = 0;
    int i = 0;
    char* tmp=calloc(50, sizeof(char));
    while (com[lenS1]) lenS1++;
    while (com[i]!=' '&&i<lenS1)
    {
        tmp[i] = com[i];
        i++;
    }
    if (tmp[0] == 'l' && tmp[1] == 's')
        return 1;
    else if (tmp[0] == 'c' && tmp[1] == 'd')
        return 2;
    else if (tmp[0] == 'r' && tmp[1] == 'm')
        return 3;
    else if (tmp[0] == 'a' && tmp[1] == 'd' && tmp[2] == 'd')
        return 4;
    else if (tmp[0] == 'f' && tmp[1] == 'i' && tmp[2] == 'n' && tmp[3] == 'd')
        return 5;
    else if (tmp[0] == 'e' && tmp[1] == 'x' && tmp[2] == 'i' && tmp[3] == 't')
        return 0;
}

int main()
{
    node root = malloc(sizeof(fileTreeNode));
    root->data = "Root";
    root->childNodes = NULL;
    node current = root;

    int select = 1, val,com;
    char* command=calloc(50,sizeof(char));


    while (select)
    {
        fgets(command, 50, stdin);
        com=Get_Command(command);
        switch (com)
        {
            case 1:
            {
               printNode(current);
               break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {

                break;
            }
            case 4:
            {

                break;
            }
            case 5:
            {
                break;
            }
            case 0:
            {
                select = 0;
                break;
            }
        }
        
    }
    return 0;


}