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

typedef struct _clist clist;
struct _clist
{
    cnode *head;
    cnode *tail;
    int nlib;
};

//LIST

list *create_list();//crea la lista doble -Logan 14/06/2020
//Se encarga del manejo del nodo   -Diego 15/06/2020 
bool refresh_list(list *l, char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]);
bool refresh(list *l);//Pasa las cadenas a la estructura -Diego 16/06/2020
bool remove_nodes(list *l);//Remueve desde el principio de la lista Diego -15/06/2020
void empty_list(list *l);//Vacia la lista -Diego 15/06/2020
bool is_empty_list(list *l);//Comprueba si la lista está vacia -Diego 15/06/2020
void print_list(list *l);//Imprime la lista -Diego 15/06/2020
bool remove_lib(list *l, node *t);//Remueve un libro de la list -Diego 17/06/2020
//Inserta al final de la lista -Diego 17/06/2020
bool insertar_final(list* l, char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]);
void reclista(list *l, clist *c);//Recorre la lista -Logan 19/06/2020
//Modificada por Diego

bool borrar(list *l, int c, node *t);//Borra un libro -Diego  15/06/2020
node *buscar_nodo(list *l,int sel, char cadena[]);//Busca un nodo -Logan 15/06/2020
//Modificada por Diego 16/06/2020

void pedir_datos(list *l);//Pide cada dato para almacenarlos en un nodo -Nestor 18/06/2020
void existencias(node *t);//Aumenta las existencias de un libro existente -Nestor 19/06/2020


//Carrito
clist *create_clist();//crea el carrito -Logan 20/06/2020
bool is_empty_clist(clist *l);//Comprueba si el carrito esta vacio -Diego 20/06/2020
void remove_cnode(cnode *c);//Remueve un nodo del carrito -Diego 20/06/2020
void remove_cnodes(clist *c); //Remueve los nodos del carrito -Diego 20/06/2020
#endif