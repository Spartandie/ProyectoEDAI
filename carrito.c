#include "carrito.h"
#include "list.h"
#include<stdio.h>
#include<stdlib.h>
bool add_carrito(clist *c, node *t)
{
    if(c == NULL){
		return false;
	}
	cnode *n=create_cnode(t->titulo, t->autor, t->editorial, t->isbn, t->formato, t->precio);

	if(c->head == NULL){
		c->head = n;
		c->tail = n;
	}else{
		n->next = c->head;
		c->head = n;
	}
	c->nlib++;
	return true;

}
bool purchase(clist *c)
{
    if(!is_empty_clist(c))
    {
        system("cls");
        printf("\n-----------Articulos comprados----------\n\n");
        print_clist(c);
        return true;
    }
    printf("Carrito vacio\nPresiona enter para continuar");
    getch();
    return false;
}   

void print_clist(clist *c)
{
    int total=0, precio;
	cnode *t;
	if(c==NULL)
	{
		printf("No existe\n ");
		return;
	}
	if(is_empty_clist(c)){
		return;
	}
	for(t=c->head; t!=NULL; t=t->next)
	{
		printf("->Titulo:%s", t->titulo);
        printf("Autor:%s", t->autor);
        printf("Formato:%s", t->formato);
        printf("Isbn:%s", t->isbn);
        printf("Precio:$%s\n", t->precio);
        precio=atoi(t->precio);
        total=total+precio;
	}

    printf("\n");
    printf("Total:$%i\n", total);
    remove_cnodes(c);
	return;
}
bool is_empty_clist(clist *l)
{
    if(l->head == NULL && l->tail == NULL) return true;
    return false;
}