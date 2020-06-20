#include "files.h"
#include<stdio.h>
#include<string.h>
bool borrar(list *l, int c)
{
    char titulo[40]="\0";
    if(c==0)
    {
        printf("Que libro se quiere borrar?\n");
        setbuf(stdin, NULL);
        fgets(titulo, 40, stdin);
        node *t=buscar_nodo(l, 1, titulo);
        remove_lib(l, t);
        return true;
    }
    else
    {
        /* code */
    }
    
}
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