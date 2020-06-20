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
    list *l=create_list();
    if(check(0)>=7)
    {
        refresh(l);
    }
    menu:
        {
            system("cls");
            printf("Bienvenido\n\n\n");
            printf("Escoje una opcion\n");
            printf("1)Admin\n2)Usuario\n3)Imprimir estructura\n4)Finalizar programa");
            scanf("%i", &opc);
            switch (opc)
            {
            case 1:
                admin:
                {
                    system("cls");
                    printf("Admin\n\n");
                    printf("Escoge una opcion\n");
                    printf("1)Agregar libros\n2)Agregar existencias\n3)Dar de baja libros\n4)Volver a menu\n");
                    scanf("%i", &opc);
                    switch (opc)
                    {
                    case 1:
                        /*do{
                            agregar_lib();
                            refresh(l);
                            printf("Deseas borrar otro libro 1=si?");
                            scanf("%i", &opc);
                        }while(opc==1);
                        goto menu;*/
                        break;
                    case 2:
                        break;
                    case 3:
                        if(check(0)<7)
                        {
                            printf("No hay libros para borrar\nPresione enter para continuar\n");
                            getch();
                            goto menu;
                        }
                        do{
                            borrar(l, 0);
                            printf("Deseas borrar otro libro 1=si?");
                            scanf("%i", &opc);
                        }while(opc==1);
                       
                        goto menu;
                        break;
                    case 4:
                        goto menu;
                        break;
                    default:
                        printf("Opcion no valida, presiona cualquier tecla para continuar\n");
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
                    printf("Escoja una opcion\n");
                    printf("1)Ver lista de libros\n2)Buscar libro\n3)Ver carrito\n4)Volver a menu\n");
                    scanf("%i", &opc);
                    switch (opc)
                    {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        goto menu;
                        break;
                    default:
                        printf("Opcion no valida, presiona cualquier tecla para continuar\n");
                        getch();
                        setbuf(stdin, NULL);
                        goto usr;
                        break;
                    }
                }
                break;
            case 3:
                print_list(l);
                printf("enter par continuar");
                getch();
                goto menu;
                break;
            case 4:
                empty_list(l);
                free(l);
                return 1;
                break;
            default:
                printf("Opcion no valida, presiona cualquier tecla para continuar\n");
                getch();
                setbuf(stdin, NULL);
                goto menu;
                break;
            }
        }
}