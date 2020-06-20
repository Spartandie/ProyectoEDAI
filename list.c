#include <stdlib.h>
#include "list.h"
#include<stdio.h>
#include<string.h>
#include "files.h"
void empty(char temp[], int tam);
list *create_list()//crea la lista doble -Diego 14/06/2020
{
    list *t;
    t=(list*)malloc(sizeof(list));
    t->head=NULL;
    t->tail=NULL;
    return t;
}
bool refresh_list(list *l, char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[])
{
    if (l!=NULL)
    {
        node *new=create_node(titulo, autor, editorial, isbn, formato, cantidad, precio);
        if(is_empty_list(l))
        {
            l->head = new;
            l->tail = new;
            l->nlib =1;
            return true;
        }
        l->tail->next = new;
        new->prev = l->tail;
        new->next=l->head;
        l->head->prev=new;
        l->tail = new;
        l->nlib++;

        return true;
    }
    
}
bool refresh(list *l)
{
    char titulo[40]="\0", autor[40]="\0", editorial[40]="\0", isbn[40]="\0", formato[40]="\0";
    char cantidad[40]="\0", precio[40]="\0", temp[40]="\0", aux;
    FILE *bib;
    int renglon=0, j=0, linea=0;
    bib=fopen("biblioteca.txt","r");
    if (bib == NULL){
        perror("Error en la apertura del archivo");
        return false;
    }
    rewind(bib);
    empty_list(l);
    while (!feof(bib))
    {
        aux='\0';
        aux=fgetc(bib);
        if (!feof(bib))
        {
            temp[j]=aux;
            j++;
        }
        if (aux=='\n')
        {
            linea++;
            renglon++;
            j=0;
            switch (renglon)
            {
                case 1:
                    strcpy_s(titulo,40, temp);
                    break;
                case 2:
                    strcpy_s(autor, 40, temp);
                    break;
                case 3:
                    strcpy_s(editorial,40, temp);
                    break;
                case 4:
                    strcpy_s(isbn, 40, temp);
                    break;
                case 5:
                    strcpy_s(formato,40, temp);
                    break;
                case 6:
                    strcpy_s(cantidad,40, temp);
                    break;
                case 7:
                    strcpy_s(precio, 40, temp);
                    break;
            }
            empty(temp , 40);
            if (renglon==7)
            {
                refresh_list(l, titulo, autor, editorial, isbn, formato, cantidad, precio);
                renglon=0;
                empty(titulo, 40);
                empty(autor, 40);
                empty(editorial, 40);
                empty(isbn, 40);
                empty(formato, 40);
                empty(cantidad, 40);
                empty(precio, 40);
            }
        }
    }
    fclose(bib);
    return true;
}
void empty_list(list *l)
{
    if(is_empty_list(l)) return;
    while(remove_nodes(l));
    
}

bool is_empty_list(list *l)
{
    if(l->head == NULL && l->tail == NULL) return true;
    return false;
}
void print_list(list *l)
{
    node *t;
    for(t=l->head;t->next!=l->head;t=t->next)
    {
        printf("%s", t->titulo);
        printf("%s", t->autor);
        printf("%s", t->editorial);
        printf("%s", t->isbn);
        printf("%s", t->formato);
        printf("%s", t->cantidad);
        printf("%s", t->precio);
    }
        printf("%s", t->titulo);
        printf("%s", t->autor);
        printf("%s", t->editorial);
        printf("%s", t->isbn);
        printf("%s", t->formato);
        printf("%s", t->cantidad);
        printf("%s", t->precio);
}
void empty(char temp[], int tam)//Vacia la variable temporal Diego -14/06/2020
{
    for (int i = 0; i < tam; i++)
    {
        temp[i]='\0';
    }
}
bool remove_lib(list *l, node *t)
{
    
    if(l == NULL || is_empty_list(l)) return false;
    if(l->head==l->tail)
    {
        remove_node(l->head);
        l->head = l->tail = NULL;
        l->nlib = 0;
        return true;
    }
    if(t->prev==l->tail)
    {       
        l->head=t->next;
        l->tail->next=l->head;
        l->head->prev=l->tail;
        t->prev=NULL;
        t->next=NULL;
        remove_node(t);
        free(t);
        return true;
    }
    if (t->next==l->head)
    {
        l->tail=t->prev;
        l->tail->next=l->head;
        l->head->prev=l->tail;
        t->prev=NULL;
        t->next=NULL;
        remove_node(t);
        free(t);
        return true;
    }
    t->prev->next=t->next;
    t->next->prev=t->prev;
    t->prev=NULL;
    t->next=NULL;
    remove_node(t);
    free(t);
    return true;
}
bool remove_nodes(list *l)
{
    if(l == NULL || is_empty_list(l)) return false;
    if(l->head ==l->tail){
        remove_node(l->head);
        l->head = l->tail = NULL;
        l->nlib = 0;
        return true;
    }
    node *t = l->head->next;    
    t->prev = NULL;
    l->head->next= NULL;
    t->prev=l->tail;
    l->tail->next=t;
    remove_node(l->head);
    l->head = t;
    return true;
}