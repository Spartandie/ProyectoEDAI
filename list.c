#include <stdlib.h>
#include "list.h"
#include<stdio.h>
#include<string.h>
list *create_list()//crea la lista doble -Diego 14/06/2020
{
    list *t;
    t=(list*)malloc(sizeof(list));
    t->head=NULL;
    t->tail=NULL;
    return t;
}
bool refresh_list(list *l, char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[])//
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
        l->tail->prev=new;
        l->tail = new;
        l->nlib++;
        return true;
    }
    
}
bool refresh(list *l)
{
    char titulo[40], autor[30], editorial[20], isbn[11], formato[12], cantidad[8], precio[6], temp[40], aux;
    FILE *bib;
    int renglon=0, j=0;
    bib=fopen("biblioteca.txt","r");
    if (bib == NULL){
        perror("Error en la apertura del archivo");
        return false;
    }
    rewind(bib);
    empty_list(l);
    while(!feof(bib))
    {
        aux='\0';
        aux=fgetc(bib);
        if (aux!='\n')
        {
            temp[j]=aux;
            j++;
        }
        if (aux=='\n')
        {
            renglon++;
            j=0;
            switch (renglon)
            {
                case 1:
                    strcpy(titulo, temp);
                    break;
                case 2:
                    strcpy(autor, temp);
                    break;
                case 3:
                    strcpy(editorial, temp);
                    //printf("%s\n", editorial);
                    break;
                case 4:
                    strcpy(isbn, temp);
                    //printf("%s\n", isbn);
                    break;
                case 5:
                    strcpy(formato, temp);
                    //printf("%s\n", formato);
                    break;
                case 6:
                    strcpy(cantidad, temp);
                    //printf("%s\n", cantidad);
                    break;
                case 7:
                    strcpy(precio, temp);
                    //printf("%s\n", precio);
                    renglon=0;
                    refresh_list(l, titulo, autor, editorial, isbn, formato, cantidad, precio);
                    break;
            }
            empty(temp);
                
        }
        if(feof(bib))
        {
            strcpy(precio, temp);
            refresh_list(l, titulo, autor, editorial, isbn, formato, cantidad, precio);
        }
    }
    fclose(bib);
    return true;
}
void empty(char temp[])//Vacia la variable temporal Diego -14/06/2020
{
    for (int i = 0; i < 40; i++)
    {
        temp[i]='\0';
    }
}
void empty_list(list *l)
{
    if(is_empty_list(l)) return;
    while(remove_init(l));
    
}
bool remove_init(list *l)
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
        printf("%s\n", t->titulo);
        printf("%s\n", t->autor);
        printf("%s\n", t->editorial);
        printf("%s\n", t->isbn);
        printf("%s\n", t->formato);
        printf("%s\n", t->cantidad);
        printf("%s\n", t->precio);
    }
        printf("%s\n", t->titulo);
        printf("%s\n", t->autor);
        printf("%s\n", t->editorial);
        printf("%s\n", t->isbn);
        printf("%s\n", t->formato);
        printf("%s\n", t->cantidad);
        printf("%s\n", t->precio);
}