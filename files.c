#include "files.h"
#include<stdio.h>
int check(int actual_or_new)
{
    FILE *bibtemp;
    if(actual_or_new==1)
    {
        bibtemp=fopen("nuevo.txt","r");
    }
    else
    {
        bibtemp=fopen("biblioteca.txt","r");
    }
    
    char aux;
    int cont=0;
    rewind(bibtemp);
    while(!feof(bibtemp))
    {
        aux='\0';
        aux=fgetc(bibtemp);
        if(aux=='\n')
        {
            cont++;
        }
    }
    cont++;
    fclose(bibtemp);
    return cont;
}
void print_txt(list *l)
{
    FILE *newbib;
    node *t=l->head;
    newbib=fopen("nuevo.txt", "a");
    for(int i=0; i!=l->nlib;t=t->next)
    {
        fprintf(newbib,"%s", t->titulo);
        fprintf(newbib,"%s", t->autor);
        fprintf(newbib,"%s", t->editorial);
        fprintf(newbib,"%s", t->isbn);
        fprintf(newbib,"%s", t->formato);
        fprintf(newbib,"%s", t->cantidad);
        fprintf(newbib,"%s", t->precio);
        i++;
    }
    fclose(newbib);
    system("DEL biblioteca.txt");
    system("REN nuevo.txt biblioteca.txt");
}