#ifndef NODE_H
#define NODE_H
#include<stdbool.h>
typedef struct _node node;
struct _node{
    char titulo[60];
    char autor[60];
    char editorial[60];
    char isbn[60];
    char formato[60];
    char cantidad[60];
    char precio[60];
    node *next;
    node *prev;
};
typedef struct _cnode cnode;
struct _cnode{
    char titulo[60];
    char autor[60];
    char editorial[60];
    char isbn[60];
    char formato[60];
    char cantidad[60];
    char precio[60];
    cnode *next;
};

//Crea el nodo -Diego 15/06/2020
node *create_node(char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]);
//Crea un nodo del carrito
cnode *create_cnode(char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]);
bool remove_node(node *n); //Remueve un nodo -Diego 15/06/2020
#endif