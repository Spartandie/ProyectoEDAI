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

list *create_list();//crea la lista doble -Diego 14/06/2020
//Se encarga del manejo del nodo   -Diego 15/06/2020 
bool refresh_list(list *l, char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]);
bool refresh(list *l);//Pasa las cadenas a la estructura -Diego 16/06/2020
bool remove_nodes(list *l);//Remueve desde el principio Diego -15/06/2020
void empty_list(list *l);//Vacia la lista -Diego 15/06/2020
bool is_empty_list(list *l);//Comprueba si la lista está vacia -Diego 15/06/2020
void print_list(list *l);//Imprime la lista -Diego 15/06/2020
bool remove_lib(list *l, node *t);
bool insertar_final(list* l, char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]);
void reclista(list *l, clist *c);
bool borrar(list *l, int c, node *t);
node *buscar_nodo(list *l,int sel, char cadena[]);
void pedir_datos(list *l);//Pide cada dato para almacenarlos en un nodo -Nestor 18/06/2020
void existencias(node *t);//Aumenta las existencias de un libro existente -Nestor 19/06/2020


//Carrito
clist *create_clist();//crea el carrito -Diego 20/06/2020
bool add_carrito(clist *c, node *t);
bool purchase(clist *c);
bool is_empty_clist(clist *l);
void remove_cnode(cnode *c);
void remove_cnodes(clist *c);
#endif