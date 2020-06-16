#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>
void empty(char temp[]);
int main(){
    char aux, temp[40];
    FILE *bib,*bibtemp;
    int  j =0;
    char titulo[40];
    printf("Que libro se desea borrar por titulo: => ");
    gets(titulo);
    bibtemp=fopen("nuevo.txt","a");
    bib=fopen("biblioteca.txt","r");
    getch();
    if (bib == NULL){
        perror("Error en la apertura del archivo");
        return false;
    }
    rewind(bib);
    while(!feof(bib))
    {
        empty(temp);
        aux='\0';
        aux=fgetc(bib);
        if (aux!='\n')
        {
            temp[j]=aux;
            printf("%s", temp[j]);
            j++;
        }
        if(aux=='\n'){
            if(!strcmp(temp,titulo)){
                fprintf(bibtemp,"%s\n", temp);
            }else{
                for(int i =1 ; i<=7;i++){
                    aux='\0';
                    aux=fgetc(bib);
                    if (aux!='\n'){
                    }   
                }
            }
            
        }
    }
    fclose(bibtemp);
    fclose(bib);
    return 0;
}

void empty(char temp[])//Vacia la variable temporal Diego -14/06/2020
{
    for (int i = 0; i < 40; i++)
    {
        temp[i]='\0';
    }
}