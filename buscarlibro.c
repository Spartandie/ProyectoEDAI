#include <stdlib.h>
#include "buscarlibro.h"
#include<stdio.h>
#include<string.h>

void buscarLista(list *l, char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]){
    char t;
    int b;
    int sel;
    char car;
    node *temp;
    temp = l->head;
    printf("Como quieres buscar el libro?\n");
    printf("(1) Por titulo (2) Por ISBN \n");
    scanf("%i",&sel);
    switch(sel){
        case 1:
            printf("Escribe el titulo del libro (asegurate de que este bien escrito)\n");
                fgets(t,40,stdin);
                while(temp != NULL){
                    if(strcmp(temp->titulo, t)!=0){
                        temp =temp->next;
                    }else{
                        printf("El libro esta disponible, tiene un precio de %i\n", temp->precio);
                        printf("Quieres agregarlo al carrito (si/no)?\n");
                        car=getchar();
                        switch(car){
                            case 's':

                            case 'n':

                            default:
                                printf("Por favor, introduzca una opcion valida\n");
                                break;
                        }
                    }
                }
        printf("El libro no fue encontrado\n");
        case 2:
            printf("Escribe el ISBN del libro (asegurate de que este bien escrito)\n");
                scanf("%i",&b);
                while(temp != NULL){
                    if(*temp->isbn != b){
                        temp =temp->next;
                    }else{
                        printf("El libro esta disponible, tiene un precio de %i\n", temp->precio);
                        printf("Quieres agregarlo al carrito (s/n)?\n");
                        car = getchar();
                        switch(car){
                            case 's':

                            case 'n':

                            default:
                                printf("Por favor, introduzca una opcion valida\n");
                                break;
                        }
                    }
                }
        printf("El libro no fue encontrado\n");
    }
}
