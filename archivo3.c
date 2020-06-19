#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"archivo.h"

int main(){ //Funcion que pregunta datos
    
    char ayu[5];
    char deci, ele;
    char uno[]="Pasta blanda";
    char dos[]="Pasta Dura";
    int opc;
    do{
    
    borrar();

    printf("\nInserta el titulo del libro:=> ");
    fgets(libro.titulo,30,stdin);
    system("cls");

    printf("\nInserta el autor del libro:=> ");
    fgets(libro.autor,30,stdin);
    system("cls");

    printf("\nInserta la editorial del libro:=> ");
    fgets(libro.editorial,20,stdin);
    system("cls");

    printf("\nIntroduzca el ISBN dado para el libro:=> ");
    fgets(libro.isbn,5,stdin);
    system("cls");

    do{
        printf("\nEl libro, %cTiene pasta dura o pasta blanda ?",168);
        printf("\nPara pasta Blanda (1), para pasta dura (2): =>");
        scanf("%i",&opc);
        system("cls");
        fflush(stdin);
        setbuf(stdin,NULL);
        switch (opc)
        {
            case 1:
                strcpy(libro.formato,"blanda");break;
            case 2:
                strcpy(libro.formato,"dura");break;
            default:
                printf("Por favor, introduzca una opcion valida\n");break;
        }
    }while(opc !=1 && opc !=2);

    printf("\n%cCuantos libros hay en existencia?:=>",168);
    fgets(libro.cantidad,5,stdin);
    system("cls");

    printf("\n%cQue precio se va a manejar en su salida? (Asegurese de manejar unicamente el numero):=>",168);
    gets(ayu);
    strcpy(libro.precio,ayu);
    system("cls");

    imprimirlibro();

    printf("\n%cEscribio bien los datos del libro?",168);
    printf("\nPara 'si' pulse (s), para 'no' cualquier otro boton: =>");
    scanf("%c",&ele);
    setbuf(stdin,NULL);

    if(ele=='s'){
        salto();
        agregarlibro();
    }

    printf("\n%cQuiere agregar otro libro  ?(s|n):=> ",168);
    scanf("%s", &deci);
    system("cls");
    setbuf(stdin,NULL);
    
    }while(deci=='s' || deci == 'S');

    return 0;
}

int agregarlibro( ){//coloca los datos pedidos en el archivo si se le sa guardar
    FILE *bib;
    bib=fopen("biblioteca.txt","a");
    if (bib == NULL){
        perror("Error en la apertura del archivo");
        return -1;
    }
    rewind(bib);

    fprintf(bib,"%s",libro.titulo);
    fprintf(bib,"%s",libro.autor);
    fprintf(bib,"%s",libro.editorial);
    fprintf(bib,"%s\n",libro.isbn);
    fprintf(bib,"Pasta %s\n",libro.formato);
    fprintf(bib,"%s",libro.cantidad);
    fprintf(bib,"%s",libro.precio);
    fclose(bib);
    fclose(bib);
    return 0;
}

int imprimirlibro(){//imprime el libro para ver si se escribio bien antes de guardarlo
    printf("TITULO: %s", libro.titulo);
    printf("AUTOR: %s", libro.autor);
    printf("EDITORIAL: %s", libro.editorial);
    printf("ISBN: %s", libro.isbn);
    printf("\nFORMATO: %s", libro.formato);
    printf("\nEXISTENCIAS: %s", libro.cantidad);
    printf("PRECIO: %s", libro.precio);
    
}

int salto(){
    FILE *bib;
    bib=fopen("biblioteca.txt","a");
    if (bib == NULL){
        perror("Error en la apertura del archivo");
        return -1;
    }
    fprintf(bib,"\n");
    fclose(bib);    
}

int borrar(){
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
void empty(char temp[]){
    for (int i = 0; i < 40; i++)
    {
        temp[i]='\0';
    }
}