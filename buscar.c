#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "files.h"
node *buscar_nodo(list *l,int sel, char cadena[]){
    char t;
    int b;
    char car;
    node *temp=l->head;
    switch(sel)
    {
        case 1:
            while (true)
            {
                if(strcmp(temp->titulo, cadena)==0)
                {
                    return temp;
                }
                else
                {
                    if(temp->next==l->head)
                    {
                        printf("No se encontro el libro\n");
                        break;
                    }
                    temp=temp->next;
                }
            }
        break;
        case 2:
            while (true)
            {
                if(strcmp(temp->autor, cadena)==0)
                {
                    return temp;
                }
                else
                {
                    temp=temp->next;
                }
                if(temp->next==l->head)
                {
                    printf("No se encontro el libro\n");
                    break;
                }
            }
        break;
        case 3:
            while (true)
            {
                if(strcmp(temp->isbn, cadena)==0)
                {
                    return temp;
                }
                else
                {
                    temp=temp->next;
                }
                if(temp->next==l->head)
                {
                    printf("No se encontro el libro\n");
                    break;
                }
            }
        break;
    }
    return NULL;
}