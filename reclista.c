#include <stdlib.h>
#include "reclista.h"
#include<stdio.h>
#include<string.h>

void reclista(list *l){
    char qst;
    node *rec;
    rec = l->head;
    do
    {
        
        printf("Libro actual: \n");
        printf("Titulo: %sAutor: %sEditorial: %sISBN: %sFormato: %sCantidad: %sPrecio: %s\n", rec->titulo, rec->autor, rec->editorial, rec->isbn, rec->formato, rec->cantidad, rec->precio);
        printf("Ver siguiente (s)\n");
        printf("Ver Anterior (a)\n");
        printf("Agregar al carrito (c)\n");
        printf("Salir (o)\n");
        scanf("%c", &qst);
        setbuf(stdin, NULL);
        switch(qst){
            case 's':
                rec = rec->next;
                break;
            
            case 'a':
                rec = rec->prev;
                break;
            
            case 'c':
                break;

            case 'o':
                break;

            default:
                printf("Opcion no valida, presiona cualquier tecla para continuar");
                getch();
                break;
        }
    } while (qst!= 'o');






}