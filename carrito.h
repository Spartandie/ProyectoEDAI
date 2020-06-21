#ifndef CARRITO_H
#define CARRITO_H
#include "node.h"
#include "list.h"
typedef clist* carrito;
bool add_carrito(clist *c, node *t);
bool purchase(clist *c);
void print_clist(clist *c);
bool is_empty_clist(clist *l);
#endif