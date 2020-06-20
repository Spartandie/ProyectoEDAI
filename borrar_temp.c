#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include "files.h"
bool borrar_temp(){
    char aux, temp[40]="\0", titulo[40]="\0";
    FILE *bib,*bibtemp;
    int  j =0, i=1, found=0, cont=0;
    setbuf(stdin, NULL);
    printf("Que libro se desea borrar por titulo: => ");
    fgets(titulo, 40, stdin);
    bibtemp=fopen("nuevo.txt","a");
    bib=fopen("biblioteca.txt","r");
    if (bib == NULL){
        perror("Error en la apertura del archivo");
        return false;
    }
    rewind(bib);
    emptyc(temp, 40);
    while(!feof(bib))
    {
        aux='\0';
        aux=fgetc(bib);
        if (!feof(bib))
        {
            temp[j]=aux;
            j++;
        }
        if(aux=='\n' || feof(bib))
        {
            j=0;
            if(strcmp(temp,titulo)!=0)
            {
                fprintf(bibtemp,"%s", temp);
            }
            if(strcmp(temp,titulo)==0)
            {
                found=1;
                while(i<7)
                {
                    aux='\0';
                    aux=fgetc(bib);
                    if (aux=='\n' || feof(bib))
                    {
                        i++;
                    }   
                }
                
                i=1;
            }
            emptyc(temp, 40);
        }
    }
    fclose(bibtemp);
    fclose(bib);
    if(found==0)
    {
        printf("No se encontro el libro\n");
        system("DEL nuevo.txt");
        return -1;
    }
    if(found==1)
    {
        cont=check(1);
        if(cont%7!=0)
        {
            rewrite(cont);
            system("DEL biblioteca.txt");
            system("DEL nuevo.txt");
            system("REN nuevo2.txt biblioteca.txt");
            return 0;
        }
        system("DEL biblioteca.txt");
        system("REN nuevo.txt biblioteca.txt");
        return 0;
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
void rewrite(int cont)
{
    FILE *bibtemp, *bibtemp2;
    bibtemp=fopen("nuevo.txt","r");
    bibtemp2=fopen("nuevo2.txt","a");
    char aux, temp[40];
    int j=0, cont2=1;
    rewind(bibtemp);
    emptyc(temp, 40);
    while(!feof(bibtemp))
    {
        aux='\0';
        aux=fgetc(bibtemp);
        if (aux!='\n')
        {
            temp[j]=aux;
            j++;
        }
        if(aux=='\n')
        {
            cont2++;
            j=0;             
            fprintf(bibtemp2,"%s", temp);
            if(cont2!=cont)
            {
                fprintf(bibtemp2, "\n");
            }
            emptyc(temp, 40);
        }
    }
    fclose(bibtemp);
    fclose(bibtemp2);
}

void emptyc(char temp[], int tam)//Vacia la variable temporal Diego -14/06/2020
{
    for (int i = 0; i < tam; i++)
    {
        temp[i]='\0';
    }
}