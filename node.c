#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
node *create_node(char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]){//crea nodo -Diego 14/06/2020
    node *t;
    t=(node*)malloc(sizeof(node));
    t->next=NULL;
    t->prev=NULL;
    strcpy_s(t->titulo, 40, titulo);
    strcpy_s(t->autor, 40, autor);
    strcpy_s(t->editorial, 45, editorial);
    strcpy_s(t->isbn, 40, isbn);
    strcpy_s(t->formato, 40, formato);
    strcpy_s(t->cantidad, 40, cantidad);
    strcpy_s(t->precio, 640, precio);
    return t;
}
bool remove_node(node *n){
    if(n->prev == NULL && n->next == NULL){
        free(n);
        return true;
    }
    return false;
}
