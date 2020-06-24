#ifndef CARRITO_H
#define CARRITO_H
#include "node.h"
#include "list.h"
typedef clist* carrito;
bool add_carrito(clist *c, node *t , cnode *n_t);//Añade libro al carrito -Diego 20/06/2020
//Modificada por Logan y nestor 20/06/2020

bool see_carrito(clist *c, list *l);//Manda a imprimir el carrito -Diego 20/06/2020
void print_clist(clist *c, list *l);//Imprime el carrito , se le añado funcion para borrar libro -Diego 20/06/2020
bool delete_clib(clist *c, int opc, list *l);//Borra un libro del carrito -Diego 21/06/2020
//Modificada por Logan, Diego y Nestor 23/06/2020
void re_add(clist *c, clist *c_t);// Añade de nuevo al carrito -Diego 21/06/2020
//Modificada por Logan, Diego y Nestor 23/06/2020
#endif