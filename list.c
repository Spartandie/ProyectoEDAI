#include <stdlib.h>
#include "list.h"
#include<stdio.h>
#include<string.h>
#include "files.h"
#include "carrito.h"
list *create_list()//crea la lista doble -Diego 14/06/2020
{
    list *t;
    t=(list*)malloc(sizeof(list));
    t->head=NULL;
    t->tail=NULL;
    return t;
}
clist *create_clist()//crea el carrito -Diego 14/06/2020
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
            empty(temp , 60);
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
    node *t=l->head;
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
void reclista(list *l, clist *c){

    char qst, temp[60]="\0";
    node *rec;
    rec = l->head;
    int cantidad;
    setbuf(stdin, NULL);
    do
    {
        
        printf("Libro actual: \n");
        printf("Titulo: %sAutor: %sEditorial: %sISBN: %sFormato: %sCantidad: %sPrecio: %s\n", rec->titulo, rec->autor, rec->editorial, rec->isbn, rec->formato, rec->cantidad, rec->precio);
        printf("Ver siguiente (s)\n");
        printf("Ver Anterior (a)\n");
        printf("Agregar al carrito (c)\n");
        printf("Salir (o)\n");
        scanf("%c", &qst);
        setbuf(stdin, NULL);
        switch(qst){
            case 's':
                rec = rec->next;
                break;
            
            case 'a':
                rec = rec->prev;
                break;
            
            case 'c':
                if(add_carrito(c,rec))
                {
                    cantidad=atoi(rec->cantidad);
                    cantidad--;
                    sprintf(temp, "%d\n", cantidad);
                    strcpy_s(rec->cantidad, 60, temp);
                    rec=rec->next;
                    borrar(l, 1, rec->prev);
                    printf("Libro a%cadido!\n",164);
                }
                printf("Presiona enter para continuar\n");
                getch();    
                break;

            case 'o':
                break;

            default:
                printf("Opcion no valida, presiona cualquier tecla para continuar");
                getch();
                break;
        }
    } while (qst!= 'o');


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
        if(t->next!=c->tail)//falta caso de un nod
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
bool borrar(list *l, int c, node* t)
{
    char titulo[60]="\0";
    if(c==0)
    {
        printf("Que libro se quiere borrar?\n");
        setbuf(stdin, NULL);
        fgets(titulo, 60, stdin);
        node *t=buscar_nodo(l, 1, titulo);
        if(t!=NULL)
        {
            remove_lib(l, t);
            return true;
        }
        else
        {
            return false;
        }
        
    }
    else
    {
        remove_lib(l, t);
        return true;
    }
    
}
node *buscar_nodo(list *l,int sel, char cadena[]){
    int cont=0;
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
                for (; temp->next!=l->head; temp=temp->next)
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
                        scanf("%i", &cont);
                        temp=l->head;
                        for (int i = 0; ; temp=temp->next)
                        {
                            if (strcmp(temp->autor, cadena)==0)
                            {
                                i++;
                                if (i==cont)
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