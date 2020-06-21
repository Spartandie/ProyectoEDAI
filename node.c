#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
node *create_node(char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]){//crea nodo -Diego 14/06/2020
    node *t;
    t=(node*)malloc(sizeof(node));
    t->next=NULL;
    t->prev=NULL;
    strcpy_s(t->titulo, 60, titulo);
    strcpy_s(t->autor, 60, autor);
    strcpy_s(t->editorial, 60, editorial);
    strcpy_s(t->isbn, 60, isbn);
    strcpy_s(t->formato, 60, formato);
    strcpy_s(t->cantidad, 60, cantidad);
    strcpy_s(t->precio, 60, precio);
    return t;
}
cnode *create_cnode(char titulo[], char autor[], char editorial[], char isbn[],char formato[], char precio[]){//crea nodo carrito -Diego 20/06/2020
    cnode *t;
    t=(cnode*)malloc(sizeof(cnode));
    t->next=NULL;
    strcpy_s(t->titulo, 60, titulo);
    strcpy_s(t->autor, 60, autor);
    strcpy_s(t->editorial, 60, editorial);
    strcpy_s(t->isbn, 60, isbn);
    strcpy_s(t->formato, 60, formato);
    strcpy_s(t->precio, 60, precio);
    return t;
}
bool remove_node(node *n){
    if(n->prev == NULL && n->next == NULL){
        free(n);
        return true;
    }
    return false;
}
void remove_cnode(cnode *c)
{
    free(c);
}
