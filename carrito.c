#include "carrito.h"
#include "list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool add_carrito(clist *c, node *t, cnode *n_t)
{
    //Añadir libro de lista a carrito

    if (t!=NULL)
    {
        if(c == NULL)
        {
		    return false;
	    }
	    cnode *n=create_cnode(t->titulo, t->autor, t->editorial, t->isbn, t->formato, t->cantidad, t->precio);
	    if(c->head == NULL)
        {
		    c->head = n;
		    c->tail = n;
            c->nlib=1;
            return true;
	    }
        cnode *f=c->head;
        for(int i=0;i!=c->nlib;i++)
        {
            if(strcmp(f->titulo,n->titulo)==0)
            {        
                break;
            }
            if(f->next!=NULL)
            {
                f=f->next;
            }   
        }
        if(strcmp(f->titulo,n->titulo)==0)
        {
            printf("El libro ya fue agregado con anteroridad\n");
        
            remove_cnode(n);
            free(n);
            return false;
        }
        if(c->head != NULL)
        {
		    n->next = c->head;
		    c->head = n;
            c->nlib++;
	    }
	    return true;
    }
    //Añadir libro de carrito a carrito temporal
    if (is_empty_clist(c))
    {
        c->head=n_t;
        c->head->next=NULL;
        c->tail=n_t;
        c->nlib=1;
        return true;
    }
    else
    {
        n_t->next=c->head;
        c->head=n_t;
        c->nlib++;
        return true;
    }
    
    
    /*c->head=n_t;

    //Añadir libro de carrito temporal a carrito

	if(c->head == NULL)
    {
		c->head = n_t;
		c->tail = n_t;
        c->nlib=1;
        return true;
	}
    if(c->head != NULL)
    {
		n_t->next = c->head;
		c->head = n_t;
        c->nlib++;
    }*/

}
bool see_carrito(clist *c, list *l)
{
    if(!is_empty_clist(c))
    {
        system("cls");
        printf("\n-----------Articulos comprados----------\n\n");
        print_clist(c, l);
        return true;
    }
    printf("Carrito vacio\n");
    system("pause");
    return false;
}   

void print_clist(clist *c, list *l)
{
    int total=0, precio, lib=0, opc;
	cnode *t;
    print:
    {
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
        lib++;
        printf("---------Libro %i--------\n\n", lib);
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
    printf("1)Confirmar compra\n2)Eliminar libro\n");
    printf("3)Seguir explorando catalogo\n=> ");
    scanf("%i", &opc);
    setbuf(stdin,NULL);
    switch (opc)//O(n)
    {
        case 1:
            remove_cnodes(c);
            printf("Gracias por comprar!!\n");
            printf("Deje que otro usuario explore el catalogo\n");
            system("pause");
            return;
        break;
        case 2:
            sel:
            {
                printf("Que libro quieres eliminar?(Inserte numero)\n=> ");
                scanf("%i", &opc);
                setbuf(stdin,NULL);
                if (opc<=0 || opc>lib)
                {
                    printf("Opcion no valida\n");
                    system("pause");
                    goto sel;
                }
                delete_clib(c, opc, l);
                return;          
            }
        break;
        case 3:
            return;
        break;
        default:
            printf("Opcion no valida\n");
            system("pause");
            goto print;
        break;
    }     
    }
    
	return;
}
bool is_empty_clist(clist *l)
{
    if(l->head == NULL && l->tail == NULL) return true;
    return false;
}
bool delete_clib(clist *c, int opc, list *l)
{
    char titulo[60], autor[60], editorial[60], isbn[60], formato[60], cant[60], precio[60], temp[60];
    clist *c_t=create_clist();
    int cantidad=0;
    cnode *t;
    for (int  i = 1; i!=opc; i++)
    {   
        t=c->head;
        add_carrito(c_t, NULL, c->head);
        c->head=c->head->next;
        t->next=NULL;
        c->nlib--;
        free(t);
    }
    node *a=l->head;
    //1.-Ya esta el libro, agrega existencia
    for (int i = 0; i!=l->nlib; i++)
    {
        if (strcmp(c->head->titulo, a->titulo)==0)
        {
            cantidad=atoi(a->cantidad);
            cantidad++;
            sprintf(temp, "%d\n", cantidad);
            strcpy_s(a->cantidad, 60, temp);
            t=c->head;
            c->head=c->head->next;
            free(t);
            re_add(c, c_t);
            return true;
        }
        a=a->next;
    }
    //2.-No hay existencias
    for (int i = 1; i <=7; i++)
    {
        
        switch (i)
        {
            case 1:
                strcpy_s(titulo,60, c->head->titulo);
            break;
            case 2:
                strcpy_s(autor,60, c->head->autor);
            break;
            case 3:
                strcpy_s(editorial,60, c->head->editorial);
            break;
            case 4:
                strcpy_s(isbn,60, c->head->isbn);
            break;
            case 5:
                strcpy_s(formato,60, c->head->formato);
            break;
            case 6:
                strcpy_s(cant,60, c->head->cantidad);
            break;
            case 7:
                strcpy_s(precio,60, c->head->precio);
            break;
        }
    }
    node *new=create_node(titulo, autor, editorial, isbn, formato, cant, precio);
    if (new!=NULL)
    {
        if(is_empty_list(l))
        {
            l->head = new;
            l->tail = new;
            l->nlib =1;
            re_add(c, c_t);
            return true;
        }
        l->tail->next = new;
        new->prev = l->tail;
        new->next=l->head;
        l->head->prev=new;
        l->tail = new;
        l->nlib++;
        t=c->head;
        c->head=c->head->next;
        remove_cnode(t);
        re_add(c, c_t);
        return true;
    }
    
}

void re_add(clist *c, clist *c_t)
{
    cnode *t;
    for (int i = 0; i!=c_t->nlib; i++)
    {
        add_carrito(c, NULL, c_t->head);
        t=c_t->head;
        c_t->head=c_t->head->next;
        t->next=NULL;
        free(t);
    }
    
}
