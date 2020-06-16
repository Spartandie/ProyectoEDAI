#ifndef LIST_H
#define LIST_H
#include "node.h"
typedef struct _list list;
struct _list
{
    node *head;
    node *tail;
    int nlib;
};

list *create_list();
bool refresh_list(list *l, char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]);
bool refresh(list *l);
void empty(char temp[]);
bool remove_init(list *l);
void empty_list(list *l);
bool is_empty_list(list *l);
void print_list(list *l);
#endif