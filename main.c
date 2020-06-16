#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "list.h"
/*Notas de compilacion: 
-getch manda un warning pero no pasa nada
-Se uso setbuf para limpiar la basura del teclado y evitar saltos
*/
int main()//Menus. Funcion principal -Diego Monroy 13/06/2020
{
    int opc;
    list *l=create_list();
    refresh(l);
    menu:
        {
            system("cls");
            printf("Bienvenido\n\n\n");
            printf("Escoje una opcion\n");
            printf("1)Admin\n2)Usuario\n");
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
                        goto admin;
                        break;
                    }
                }
                break;
            case 2:
                usr:
                {
                    system("cls");
                    printf("Usuario\n\n");
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
                break;
            default:
                printf("Opcion no valida, presiona cualquier tecla para continuar\n");
                getch();
                setbuf(stdin, NULL);
                goto menu;
                break;
            }
        }
    empty_list(l);
    free(l);
    return 1;
}