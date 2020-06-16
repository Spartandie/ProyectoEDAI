#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
node *create_node(char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]){//crea nodo -Diego 14/06/2020
    node *t;
    t=(node*)malloc(sizeof(node));
    t->next=NULL;
    t->prev=NULL;
    strcpy(t->titulo, titulo);
    strcpy(t->autor, autor);
    strcpy(t->editorial, editorial);
    strcpy(t->isbn, isbn);
    strcpy(t->formato, formato);
    strcpy(t->cantidad, cantidad);
    strcpy(t->precio, precio);
    return t;
}
bool remove_node(node *n){
    if(n->prev == NULL && n->next == NULL){
        free(n);
        return true;
    }
    return false;
}
