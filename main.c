#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "list.h"
#include "files.h"
#include "carrito.h"
#define contra 12345
/*Notas de compilacion: 
-getch manda un warning pero no pasa nada
-Se uso setbuf para limpiar la basura del teclado y evitar saltos
*/
int main()//Menus. Funcion principal -Diego Monroy 13/06/2020
{         //Modificada por logan y nestor 19/06/2020, 20/06/2020, 21/06/2020
    int pass;
    int opc;
    int sel, cantidad;
    char cadena[60]="\0", temp[60]="\0";
    list *l=create_list();//O(1)
    clist *c=create_clist();//O(1)
    node *t;
    if(check()>=7)//O(n)
    {
        refresh(l);//O(n^2)
    }
    menu:
        {
            system("cls");
            printf("-----BIENVENIDO------\n");
            printf("-----LIBRERIA PUMA---\n\n\n");
            printf("Escoge una opci%cn\n",162);
            printf("1)Admin\n2)Usuario\n3)Finalizar programa\n");
            printf("=>");
            scanf("%i", &opc);
            switch (opc)
            {
            case 1://O(n)
                printf("Ingresa la contrase%ca\n=> ", 164);
                scanf("%i", &pass);
                setbuf(stdin,NULL);
                if(pass!=contra)
                {
                    printf("Contrase%ca incorrecta\n", 164);
                    system("pause");
                    goto menu;
                }
                admin:
                {
                    system("cls");
                    
                    printf("Admin\n\n");
                    printf("Escoge una opci%cn\n",162);
                    printf("1)Agregar libros\n2)Agregar existencias\n3)Dar de baja libros\n4)Ver estructura\n");
                    printf("5)Volver a menu\n");
                    printf("=>");
                    scanf("%i", &opc);
                    switch (opc)
                    {
                    case 1:
                        pedir_datos(l);//O(n)
                        goto admin;
                        break;
                    case 2:
                        existencias:
                        {
                            if(l->head==NULL)
                            {
                                printf("No hay libros disponibles\n");
                                system("pause");
                                goto admin;
                            }
                            system("cls");
                            printf("Para a%cadir nuevas existencias de un libro, elije una opci%cn \n",164, 162);
                            printf("1)Titulo\n2)Autor\n3)ISBN\n4)Regresar\n=> ");
                            scanf("%i", &opc);
                            setbuf(stdin,NULL);
                            if(opc==4)
                            {
                                goto admin;
                            }
                            t=buscar_por(l, opc);
                            if(t!=NULL)
                            {   
                                existencias(t);//O(1)
                                printf("%cDesea agregar mas existencias de un libro? Si=1 No=2: =>",186);
                                scanf("%i", &opc);
                                if(opc==1)
                                {
                                    goto existencias;
                                }
                                else
                                {
                                    goto admin;
                                }
                            }
                            else
                            {
                                printf("Opci%cn no valida\n",162);
                                system("pause");
                                setbuf(stdin, NULL);
                                goto existencias;
                            }  
                        } 
                        break;
                    case 3:
                    erase:
                    {
                        if(is_empty_list(l))//O(n)
                        {
                            printf("No hay libros para borrar\n");
                            system("pause");
                            goto admin;
                        }
                            system("cls");
                            printf("Buscar por:\n",164, 162);
                            printf("1)Titulo\n2)Autor\n3)ISBN\n4)Regresar\n=> ");
                            scanf("%i", &opc);
                            setbuf(stdin,NULL);
                            if (opc==4)
                            {
                                goto admin;
                            }
                            t=buscar_por(l, opc);
                            borrar(l, t);
                            printf("Deseas borrar otro libro si(1), no(2)?");
                            scanf("%i", &opc);
                            if(opc==1)
                            {
                                goto erase;
                            }
                        goto admin;
                    }
                    break;
                    case 4:
                        if(is_empty_list(l))//O(n)
                        {
                            printf("Estrcutrua vacia\n");
                            system("pause");
                            goto admin;
                        }
                        print_list(l);//O(n)
                        printf("Presione ENTER para continuar....\n");
                        system("pause");
                        goto admin;
                        break;
                    case 5:
                        goto menu;
                    break;
                    default:
                        printf("Opci%cn no v%clida, presiona cualquier tecla para continuar\n",162,134);
                        system("pause");
                        setbuf(stdin, NULL);
                        goto admin;
                        break;
                    }
                }
                break;
            case 2://O(n)
                usr:
                {
                    system("cls");
                    if (l->head==NULL)
                    {
                        printf("No hay libros disponibles\n");
                        system("pause");
                        goto menu;
                    }
                    printf("-----BIENVENIDO------\n");
                    printf("-----LIBRERIA PUMA---\n\n\n");
                    printf("Hasta %i libros a la venta!!\n\n", l->nlib);
                    printf("Escoja una opci%cn\n",162);
                    printf("1)Ver lista de libros\n2)Buscar libro\n3)Ver carrito\n4)Menu\n=>");
                    scanf("%i", &opc);
                    setbuf(stdin,NULL);
                    switch (opc)
                    {
                    case 1:
                        reclista(l, c);//O(n^2)
                        goto usr;
                        break;
                    case 2://O(n)
                        search:
                        {
                                    system("cls");
                                    printf("Buscar libro por: \n1)Titulo\n2)Autor\n3)Isbn\n4)Regresar\n=> ");
                                    scanf("%i", &opc);
                                    setbuf(stdin,NULL);
                                    if(opc==4){
                                        goto usr;
                                    }
                                    if(opc==1 || opc==2 || opc==3)
                                    {
                                        t=buscar_por(l, opc);
                                    }
                                    else
                                    {
                                        goto search;
                                    }
                                    
                                    if(t!=NULL)
                                    {
                                        printf("Titulo:%s", t->titulo);
                                        printf("Autor:%s", t->autor);
                                        printf("Editorial:%s", t->editorial);
                                        printf("Isbn:%s", t->isbn);
                                        printf("Formato:%s", t->formato);
                                        printf("Existencias:%s", t->cantidad);
                                        printf("Precio:$%s", t->precio);
                                        printf("\n%cDesea a%cadir al carrito el libro? Si=1 No=2\n=> ", 168, 164);
                                        scanf("%i", &opc);
                                        setbuf(stdin,NULL);
                                        switch (opc)//O(n)
                                        {
                                            case 1:
                                                if(add_carrito(c,t, NULL))//O(n)
                                                {
                                                    cantidad=atoi(t->cantidad);
                                                    cantidad--;
                                                    sprintf(temp, "%d\n", cantidad);
                                                    strcpy_s(t->cantidad, 60, temp);
                                                    printf("Libro a%cadido!\n",164);
                                                    if(strcmp("0\n", t->cantidad)==0)
                                                    {
                                                        borrar(l, t);//O(n)
                                                    }
                                            }    
                                            break;
                                            default:
                                                printf("El libro no fue a%cadido\n", 164);
                                            break;
                                        }
                                        
                                    }
                                    printf("%cDesea buscar otro libro? Si=1 No=2", 168);
                                    scanf("%i", &opc);
                                    setbuf(stdin,NULL);
                                    switch (opc)
                                    {
                                        case 1:
                                            goto search;
                                        break;
                                        default:
                                            goto usr;
                                        break;
                                    }
                    
                            }                          
                        break;
                    case 3://O(n)
                        carrito:
                        {
                            if(see_carrito(c, l))
                            {
                                
                            }
                            goto usr;       
                        }
                        break;
                    case 4:
                        goto menu;
                        break;
                    default:
                        printf("Opci%cn no v%clida, presiona cualquier tecla para continuar\n",162,134);
                        system("pause");
                        setbuf(stdin, NULL);
                        goto usr;
                        break;
                    }
                }
                break;
            case 3:
                print_txt(l);//O(n)
                empty_list(l);
                free(l);
                remove_cnodes(c);
                free(c);
                return 1;
                break;
            default:
                printf("Opci%cn no v%clida\n",162,160);
                system("pause");
                setbuf(stdin, NULL);
                goto menu;
                break;
            }
        }
}
