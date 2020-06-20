#ifndef NODE_H
#define NODE_H
#include<stdbool.h>
typedef struct _node node;
struct _node{
    char titulo[40];
    char autor[40];
    char editorial[40];
    char isbn[40];
    char formato[40];
    char cantidad[40];
    char precio[40];
    node *next;
    node *prev;
};
//Crea el nodo -Diego 15/06/2020
node *create_node(char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]);
bool remove_node(node *n); //Remueve un nodo -Diego 15/06/2020
#endif