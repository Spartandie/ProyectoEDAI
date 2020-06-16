#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
void empty(char temp[]);
int main(){
    char aux, temp[40], titulo[40];
    FILE *bib,*bibtemp;
    int  j =0, i=1;
    printf("Que libro se desea borrar por titulo: => ");
    gets(titulo);
    bibtemp=fopen("nuevo.txt","a");
    bib=fopen("biblioteca.txt","r");
    if (bib == NULL){
        perror("Error en la apertura del archivo");
        return false;
    }
    rewind(bib);
    empty(temp);
    while(!feof(bib))
    {
        aux='\0';
        aux=fgetc(bib);
        if (aux!='\n' && !feof(bib))
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
                if(!feof(bib))
                {
                    fprintf(bibtemp, "\n");
                }
            }
            if(strcmp(temp,titulo)==0)
            {
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
            empty(temp);
        }
    }
    fclose(bibtemp);
    fclose(bib);
    system("DEL biblioteca.txt");
    system("REN nuevo.txt biblioteca.txt");
    return 0;
}

void empty(char temp[])//Vacia la variable temporal Diego -14/06/2020
{
    for (int i = 0; i < 40; i++)
    {
        temp[i]='\0';
    }
}