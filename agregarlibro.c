#include <stdlib.h>
#include "list.h"
#include<stdio.h>
#include<string.h>
bool insertar_final(list* l, char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]){
    if(l == NULL) return false;
    node *nuevo = create_node(titulo, autor, editorial, isbn, formato, cantidad, precio);
    if(is_empty_list(l)){        
        l->head = nuevo;
        l->tail = nuevo;
        l->nlib =1;
        return true;
    }
    l->tail->next = nuevo;
    nuevo->prev = l->tail;
    l->tail = nuevo;
    l->nlib++;
    return true;
}
