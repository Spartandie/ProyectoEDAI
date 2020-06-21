#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "list.h"
#include "files.h"
/*Notas de compilacion: 
-getch manda un warning pero no pasa nada
-Se uso setbuf para limpiar la basura del teclado y evitar saltos
*/
int main()//Menus. Funcion principal -Diego Monroy 13/06/2020
{   
    int opc;
    int sel, cantidad;
    char cadena[60]="\0";
    list *l=create_list();
    list *c=create_clist();
    if(check(0)>=7)
    {
        refresh(l);
    }
    menu:
        {
            system("cls");
            printf("-----BIENVENIDO------\n");
            printf("-----LIBRERIA PUMA---\n\n\n");
            printf("Escoge una opci%cn\n",162);
            printf("1)Admin\n2)Usuario\n3)Imprimir estructura\n4)Finalizar programa\n");
            printf("=>");
            scanf("%i", &opc);
            switch (opc)
            {
            case 1:
                admin:
                {
                    system("cls");
                    printf("Admin\n\n");
                    printf("Escoge una opci%cn\n",162);
                    printf("1)Agregar libros\n2)Agregar existencias\n3)Dar de baja libros\n4)Volver a menu\n");
                    printf("=>");
                    scanf("%i", &opc);
                    switch (opc)
                    {
                    case 1:
                        pedir_datos(l);
                        goto admin;
                        break;
                    case 2:
                        existencias:
                        {
                        system("cls");
                        printf("Para añadir nuevas existencias de un libro, elije una opci%cn \n",162);
                        printf("1)Titulo\n2)Autor\n3)ISBN\n4)Regresar\n");
                        scanf("%i", &opc);
                        setbuf(stdin,NULL);
                        if (opc==1 || opc==2 || opc==3)
                            {
                                    switch (opc)
                                    {
                                        case 1:
                                            printf("Ingrese el titulo del libro: ");
                                            setbuf(stdin, NULL);
                                            fgets(cadena, 60, stdin);
                                            sel=1;
                                        break;
                                        case 2:
                                            printf("Ingrese el autor del libro: ");
                                            setbuf(stdin, NULL);
                                            fgets(cadena, 60, stdin);
                                            sel=2;
                                        break;
                                        case 3:
                                            printf("Ingrese el isbn del libro: ");
                                            setbuf(stdin, NULL);
                                            fgets(cadena, 60, stdin);
                                            sel=3;
                                        break;
                                    }
                                    node *t=buscar_nodo(l, sel, cadena);
                                    if(t!=NULL)
                                    {   
                                        existencias(t);
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
                                printf("Opci%cn no valida, presiona cualquier tecla para continuar \n",162);
                                getch();
                                setbuf(stdin, NULL);
                                goto existencias;
                            }  
                        }//final de eliminar(case2)
                        else if(opc==4){
                            goto admin;
                        } else{
                            printf("Opcion no valida\nPresione ENTER para continuar...\n");
                            getch();
                            goto existencias;
                        }                        
                        break;
                    case 3:
                        if(check(0)<7)
                        {
                            printf("No hay libros para borrar\nPresione enter para continuar\n");
                            getch();
                            goto menu;
                        }
                        do{
                            borrar(l, 0, NULL);
                            printf("Deseas borrar otro libro si(1), no(2)?");
                            scanf("%i", &opc);
                        }while(opc==1); 
                        goto admin;
                        break;
                    case 4:
                        goto menu;
                        break;
                    default:
                        printf("Opci%cn no v%clida, presiona cualquier tecla para continuar\n",162,134);
                        getch();
                        setbuf(stdin, NULL);
                        goto admin;
                        break;
                    }
                }
                break;
            case 2:
                usr:
                {
                    system("cls");
                    printf("Hasta %i libros a la venta!!\n\n", l->nlib);
                    printf("Escoja una opci%cn\n",162);
                    printf("1)Ver lista de libros\n2)Buscar libro\n3)Ver carrito\n4)Menu\n=>");
                    scanf("%i", &opc);
                    setbuf(stdin,NULL);
                    switch (opc)
                    {
                    case 1:
                        reclista(l, c);
                        goto usr;
                        break;
                    case 2:
                        search:
                        {
                            system("cls");
                            printf("Buscar libro por: \n1)Titulo\n2)Autor\n3)Isbn\n4)Regresar\n");
                            scanf("%i", &opc);
                            setbuf(stdin,NULL);
                            if(opc==4){
                                goto usr;
                            }
                            if (opc==1 || opc==2 || opc==3)
                            {
                                    char temp[60]="\0";
                                    switch (opc)
                                    {
                                        case 1:
                                            printf("Ingrese el titulo del libro:\n=>");
                                            setbuf(stdin, NULL);
                                            fgets(cadena, 60, stdin);
                                            sel=1;
                                        break;
                                        case 2:
                                            printf("Ingrese el autor del libro:\n=> ");
                                            setbuf(stdin, NULL);
                                            fgets(cadena, 60, stdin);
                                            sel=2;
                                        break;
                                        case 3:
                                            printf("Ingrese el isbn del libro:\n=> ");
                                            setbuf(stdin, NULL);
                                            fgets(cadena, 60, stdin);
                                            sel=3;
                                        break;
                                    
                                    }
                                    node *t=buscar_nodo(l, sel, cadena);
                                    if(t!=NULL)
                                    {
                                        printf("Titulo:%s", t->titulo);
                                        printf("Autor:%s", t->autor);
                                        printf("Editorial:%s", t->editorial);
                                        printf("Isbn:%s", t->isbn);
                                        printf("Formato:%s", t->formato);
                                        printf("Precio:$%s", t->precio);
                                        printf("\n%cDesea a%cadir al carrito el libro? Si=1 No=otro", 168, 164);
                                        scanf("%i", &opc);
                                        setbuf(stdin,NULL);
                                        if (opc==1)
                                        {
                                            if(add_carrito(c,t))
                                            {
                                                cantidad=atoi(t->cantidad);
                                                cantidad--;
                                                sprintf(temp, "%d\n", cantidad);
                                                strcpy_s(t->cantidad, 60, temp);
                                                printf("Libro a%cadido!\n",164);
                                            }    
                                        }
                                    }
                                    printf("%cDesea buscar otro libro? Si=1 No=otro", 168);
                                    scanf("%i", &opc);
                                    setbuf(stdin,NULL);
                                    if(opc==1)
                                    {
                                        goto search;
                                    }
                                    else
                                    {
                                        goto usr;
                                    }
                            }
                            else
                            {
                                printf("Opci%cn no v%clida, presiona cualquier tecla para continuar\n",162,134);
                                getch();
                                setbuf(stdin, NULL);
                                goto search;
                            }                            
                        }
                        break;
                    case 3:
                        carrito:
                        {
                            system("cls");
                            printf("1)Confirmar compra\n2)Seguir explorando catalogo\n");
                            scanf("%i", &opc);
                            setbuf(stdin,NULL);
                            switch (opc)
                            {
                                case 1:
                                    if(purchase(c))
                                    {
                                        printf("Presione enter para salir\n");
                                        getch();
                                        goto usr;
                                    }
                                    else
                                    {
                                        goto usr;
                                    }
                                    ;
                                break;
                                case 2:
                                    goto usr;
                                break;
                                default:
                                    printf("Opcion no valida\n");
                                    getch();
                                    goto carrito;
                                break;
                            }            
                        }
                        break;
                    case 4:
                        goto menu;
                        break;
                    default:
                        printf("Opci%cn no v%clida, presiona cualquier tecla para continuar\n",162,134);
                        getch();
                        setbuf(stdin, NULL);
                        goto usr;
                        break;
                    }
                }
                break;
            case 3:
                print_list(l);
                printf("Presione ENTER para continuar....\n");
                getch();
                goto menu;
                break;
            case 4:
                print_txt(l);
                empty_list(l);
                free(l);
                remove_cnodes(c);
                free(c);
                return 1;
                break;
            default:
                printf("Opci%cn no v%clida, presiona cualquier tecla para continuar\n",162,134);
                getch();
                setbuf(stdin, NULL);
                goto menu;
                break;
            }
        }
    }
}