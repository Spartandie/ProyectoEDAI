#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "files.h"
node *buscar_nodo(list *l,int sel, char cadena[]){
    int cont=0;
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
            printf("Resultados:\n\n");
            while (true)
            {
                for (; temp->next!=l->head; temp=temp->next)
                {
                    if(strcmp(temp->autor, cadena)==0)
                    {
                        cont++;
                        printf("%i.-%s", cont, temp->titulo);   
                    }
                }

                if (temp->next=l->head)
                {
                    if(cont!=0)
                    {
                        printf("Cual libro quieres? (selecciona el numero): ");
                        scanf("%i", &cont);
                        temp=l->head;
                        for (int i = 0; ; temp=temp->next)
                        {
                            if (strcmp(temp->autor, cadena)==0)
                            {
                                i++;
                                if (i==cont)
                                {
                                    break;
                                }
                                
                            }
                        }
                        return temp;
                    }
                    else
                    {
                        printf("No se encontraron libros\n");
                        break;
                    }
                    
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
        default:

        break;
    }
    return NULL;
}