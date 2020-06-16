#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int imprimirlibro();
int agregarlibro();
int salto();
struct libro
{
    char titulo[30];
    char autor[30];
    char editorial[20];
    char formato[12];
    char cantidad[5];
    char precio[5];
    char isbn[21];
}libro;

int main(){ //Funcion que pregunta datos
    char ayu[5];
    char deci, ele;
    char uno[]="Pasta blanda";
    char dos[]="Pasta Dura";
    int opc;
    do{

    salto();

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
    fgets(libro.isbn,21,stdin);
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
                strcpy(libro.formato,"bland");break;
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

    fprintf(bib,"%s",libro.titulo);
    fprintf(bib,"%s",libro.autor);
    fprintf(bib,"%s",libro.editorial);
    fprintf(bib,"%s",libro.isbn);
    fprintf(bib,"Pasta %s\n",libro.formato);
    fprintf(bib,"%s",libro.cantidad);
    fprintf(bib,"%s",libro.precio);
    fclose(bib);
    fclose(bib);
    return 0;
}

int imprimirlibro(){//imprime el libro para ver si se escribio bien antes de guardarlo
    printf("\nTITULO: %s", libro.titulo);
    printf("\nAUTOR: %s", libro.autor);
    printf("\nEDITORIAL: %s", libro.editorial);
    printf("\nISBN: %s", libro.isbn);
    printf("\nFORMATOR: %s", libro.formato);
    printf("\nEXISRENCIA: %s", libro.cantidad);
    printf("\nPRECIO: %s", libro.precio);
    
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
