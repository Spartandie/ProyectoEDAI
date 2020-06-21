#ifndef CARRITO_H
#define CARRITO_H
#include "node.h"
#include "list.h"
typedef clist* carrito;
bool add_carrito(clist *c, node *t);
bool see_carrito(clist *c, list *l);
void print_clist(clist *c, list *l);
bool is_empty_clist(clist *l);
bool delete_clib(clist *c, int opc, list *l);
#endif