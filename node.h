#ifndef NODE_H
#define NODE_H
#include<stdbool.h>
typedef struct _node node;
struct _node{
    char titulo[40];
    char autor[30];
    char editorial[20];
    char isbn[11];
    char formato[12];
    char cantidad[8];
    char precio[6];
    node *next;
    node *prev;
};

node *create_node(char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]);
bool remove_node(node *n);
#endif