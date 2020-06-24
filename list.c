#include <stdlib.h>
#include "list.h"
#include<stdio.h>
#include<string.h>
#include "files.h"
#include "carrito.h"
void empty(char temp[], int tam);
list *create_list()//crea la lista doble -Logan 14/06/2020
{
    list *t;
    t=(list*)malloc(sizeof(list));
    t->head=NULL;
    t->tail=NULL;
    return t;
}
clist *create_clist()
{
    clist *t;
    t=(clist*)malloc(sizeof(clist));
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
    char titulo[60]="\0", autor[60]="\0", editorial[60]="\0", isbn[60]="\0", formato[60]="\0";
    char cantidad[60]="\0", precio[60]="\0", temp[60]="\0", aux;
    FILE *bib;
    int renglon=0, j=0;
    bib=fopen("biblioteca.txt","r");
    if (bib == NULL){
        perror("Error en la apertura del archivo");
        return false;
    }
    rewind(bib);
    empty_list(l);//O(n)
    while (!feof(bib))//O(n)
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
            renglon++;
            j=0;
            switch (renglon)
            {
                case 1:
                    strcpy_s(titulo,60, temp);
                    break;
                case 2:
                    strcpy_s(autor, 60, temp);
                    break;
                case 3:
                    strcpy_s(editorial,60, temp);
                    break;
                case 4:
                    strcpy_s(isbn, 60, temp);
                    break;
                case 5:
                    strcpy_s(formato,60, temp);
                    break;
                case 6:
                    strcpy_s(cantidad,60, temp);
                    break;
                case 7:
                    strcpy_s(precio, 60, temp);
                    break;
            }
            empty(temp , 60);//O(n)
            if (renglon==7)
            {
                refresh_list(l, titulo, autor, editorial, isbn, formato, cantidad, precio);
                renglon=0;
                empty(titulo, 60);
                empty(autor, 60);
                empty(editorial, 60);
                empty(isbn, 60);
                empty(formato, 60);
                empty(cantidad, 60);
                empty(precio, 60);
            }
        }
    }
    fclose(bib);
    return true;
}
void empty(char temp[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        temp[i]='\0';
    }
}
void empty_list(list *l)
{
    if(is_empty_list(l)) return;
    while(remove_nodes(l));
    
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
    node *t=l->head;
    system("cls");
    for(int i=0;i!=l->nlib;i++)
    {
        printf("%s", t->titulo);
        printf("%s", t->autor);
        printf("%s", t->editorial);
        printf("%s", t->isbn);
        printf("%s", t->formato);
        printf("%s", t->cantidad);
        printf("%s", t->precio);
        t=t->next;
    }
}

bool insertar_final(list* l, char titulo[], char autor[], char editorial[], char isbn[], char formato[], char cantidad[], char precio[]){//Crea el espacio de memoria para almacenar un nuevo libro Nestor-18/06/2020
    if(l == NULL) return false;
    node *nuevo = create_node(titulo, autor, editorial, isbn, formato, cantidad, precio);
    if(is_empty_list(l)){        
        l->head = nuevo;
        l->tail = nuevo;
        l->nlib =1;
        return true;
    }
    l->tail->next = nuevo;
    nuevo->prev = l->tail;
    l->tail = nuevo;
    l->nlib++;
    return true;
}

node *buscar_nodo(list *l,int sel, char cadena[]){
    int cont=0, opc=0;
    char car;
    node *temp=l->head;
    switch(sel)
    {
        case 1:
            while (true)
            {
                if(strcmp(temp->titulo, cadena)==0)
                {
                    return temp;
                }
                else
                {
                    if(temp->next==l->head)
                    {
                        printf("No se encontro el libro\n");
                        break;
                    }
                    temp=temp->next;
                }
            }
        break;
        case 2:
            printf("Resultados:\n\n");
            while (true)
            {
                opc:
                {
                    system("cls");
                    for (temp=l->head, cont=0; temp->next!=l->head; temp=temp->next)
                    {
                        if(strcmp(temp->autor, cadena)==0)
                        {
                            cont++;
                            printf("%i.-%s", cont, temp->titulo);   
                        }
                    }
                    if(strcmp(temp->autor, cadena)==0)
                    {
                        cont++;
                        printf("%i.-%s", cont, temp->titulo);   
                    }
                    if (temp->next=l->head)
                    {
                        if(cont!=0)
                        {
                            printf("Cual libro quieres? (selecciona el numero): ");
                            scanf("%i", &opc);
                            if(opc<=0 || opc>cont)
                            {
                                printf("Opcion no v%clida\n", 160);
                                printf("Presiona enter para continuar\n");
                                system("pause");
                                goto opc;
                            }
                            temp=l->head;
                            for (int i = 0; ; temp=temp->next)
                            {
                                if (strcmp(temp->autor, cadena)==0)
                                {
                                    i++;
                                    if (i==opc)
                                    {
                                        break;
                                    }
                                
                                }
                            }
                            return temp;
                        }
                        else
                        {
                            printf("No se encontraron libros\n");
                            break;
                    }
                    
                    }
                }

            }
        break;
        case 3:
            while (true)
            {
                if(strcmp(temp->isbn, cadena)==0)
                {
                    return temp;
                }
                if(temp->next==l->head)
                {
                    printf("No se encontro el libro\n");
                    break;
                }
                else
                {
                    temp=temp->next;
                }
            }
        break;
        default:

        break;
    }
    return NULL;
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
        l->nlib--;
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
        l->nlib--;
        return true;
    }
    t->prev->next=t->next;
    t->next->prev=t->prev;
    t->prev=NULL;
    t->next=NULL;
    remove_node(t);
    l->nlib--;
    free(t);
    return true;
}
void pedir_datos(list *l){
    char titulo[60],autor[60], editorial[60], isbn[60],formato[60],cantidad[60],precio[60];
    node *t;
    int opc;
    repetir:
        
        system("cls");
        t=l->head;
        printf("Introduzca los datos que se le pida\n");
        printf("De el nombre del Libro que va agregar:=> ");
        fflush(stdin);
        fgets(titulo,60,stdin);
        if (t!=NULL)
        {
            for(int i =0;i<l->nlib;i++){//O(n)
                if(strcmp(titulo,t->titulo)==0){
                    printf("Ese titulo ya existe, introduzca uno diferente\n");
                    system("pause");
                    goto repetir;
                }
                t=t->next;
            }    
            t=l->head;
        }
        printf("Autor del Libro que va agregar:=> ");
        fgets(autor,60,stdin);
        printf("Editorial :=> ");
        fgets(editorial,60,stdin);
        repetirisbn:
        printf("ISBN del libro(13 caracteres ):=> ");
        fgets(isbn,60,stdin);
        if(strlen(isbn)!=14){
            printf("ISBN invalido, introduzca uno de 13 caracteres\n");
            goto repetirisbn;
        }
        if (t!=NULL)
        {
            for(int i =0;i<l->nlib;i++)
            {
                if(strcmp(isbn,t->isbn)==0){
                    printf("Ese isbn ya esta en uso, introduzca uno diferente\n");
                    system("pause");
                    goto repetir;
                }
                t=t->next;
            } 
        }
        do{
        printf("El libro, %cTiene pasta dura o pasta blanda ?\n",168);
        printf("Para pasta Blanda (1), para pasta dura (2): => ");
        scanf("%i",&opc);
        fflush(stdin);
        setbuf(stdin,NULL);
        switch (opc)
        {
            case 1:
                strcpy(formato,"Pasta blanda\n");break;
            case 2:
                strcpy(formato,"Pasta dura\n");break;
            default:
                printf("Por favor, introduzca una opcion valida\n");break;
        }
        }while(opc !=1 && opc !=2);
        printf("Precio del libro:=> ");
        fgets(cantidad,60,stdin);
        printf("Las unidades disponibles son :=> ");
        fgets(precio,60,stdin);
        insertar_final(l,titulo,autor,editorial,isbn,formato,precio,cantidad);
        printf("Libro agregado con exito!");
        printf("Presione ENTER para continuar...");
        system("pause");
}

bool borrar(list *l,  node* t)
{
    if(t!=NULL){
        remove_lib(l, t);
        printf("Titulo borrado con exito\n");
        return true;
    }
    else{
        return false;
    } 
}
void existencias(node *t){ 
    
        int extra, cantidad, opc;
        char temp[60];
        printf("%cCu%cntos libros va agregar a los ya existentes?\n",168, 160);
        printf("Libros actuales:%s=>", t->cantidad);
        scanf("%i", &extra);
        setbuf(stdin, NULL);
        cantidad=atoi(t->cantidad);
        cantidad=cantidad+extra;
        sprintf(temp,"%d\n",cantidad);
        printf("Existencias actualizadas: %s",temp);
        strcpy_s(t->cantidad,60, temp);
    
}
void reclista(list *l, clist *c){

    char qst, temp[60]="\0";
    node *rec;
    rec = l->head;
    int cantidad;
    setbuf(stdin, NULL);
    do
    {
        
        printf("Libro actual: \n");
        printf("Titulo: %sAutor: %sEditorial: %sISBN: %sFormato: %sExistencias: %sPrecio: %s\n", rec->titulo, rec->autor, rec->editorial, rec->isbn, rec->formato, rec->cantidad, rec->precio);
        printf("Ver siguiente (s)\n");
        printf("Ver Anterior (a)\n");
        printf("Agregar al carrito (c)\n");
        printf("Salir (o)\n");
        scanf("%c", &qst);
        setbuf(stdin, NULL);
        switch(qst){//O(n)
            case 's':
                rec = rec->next;
                break;
            
            case 'a':
                rec = rec->prev;
                break;
            
            case 'c'://O(n)
                if(add_carrito(c,rec, NULL))
                {
                    cantidad=atoi(rec->cantidad);
                    cantidad--;
                    sprintf(temp, "%d\n", cantidad);
                    strcpy_s(rec->cantidad, 60, temp);
                    rec=rec->next;
                    if(strcmp("0\n", rec->prev->cantidad)==0)
                    {
                        borrar(l, rec->prev);
                    }
                    
                    printf("Libro a%cadido!\n",164);
                }
                system("pause");    
                break;

            case 'o':
                break;

            default:
                system("pause");
                break;
        }
    } while (qst!= 'o');//O(n)


}
void remove_cnodes(clist *c)

{
    cnode *t=c->head;
    if(c->head==NULL)
    {
        return;
    }
    while (true)
    {
        if(c->head==c->tail)
        {
            remove_cnode(t);
            c->head=NULL;
            c->tail=NULL;
            break;
        }
        if(t->next!=c->tail)
        {
            t=t->next;
        }
        else
        {
            c->tail=t;
            remove_cnode(t->next);
            c->tail->next=NULL;
            t=c->head;
        }
        

    }
    
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
node  *buscar_por(list *l, int opc)
{
    buscar:
    {
                            char cadena[60];
                            char temp[60]="\0";
                            switch (opc)
                            {
                                case 1:
                                    printf("Ingrese el titulo del libro:\n=>");
                                    setbuf(stdin, NULL);
                                    fgets(cadena, 60, stdin);
                                break;
                                case 2:
                                    printf("Ingrese el autor del libro:\n=> ");
                                    setbuf(stdin, NULL);
                                    fgets(cadena, 60, stdin);
                                break;
                                case 3:
                                    printf("Ingrese el isbn del libro:\n=> ");
                                    setbuf(stdin, NULL);
                                    fgets(cadena, 60, stdin);
                                break;
                                default:
                                    printf("Opcion no valida\n");
                                    system("pause");
                                    return NULL;
                                break;
                                    
                            }
                            node *t=buscar_nodo(l , opc, cadena);
                            return t;
    }
            
}
