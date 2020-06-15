#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int agregarlibro(char * dato);
int main(){ 
   char deci;
   char uno[]="Pasta blanda";
   char dos[]="Pasta Dura";
   int opc;
   char titulo[40], autor[40], editorial[20], formato[12], cantidad[5], precio[5], isbn[21];

   do{
      
      printf("\nInserta el titulo del libro:=> ");
      gets(titulo);
      agregarlibro(titulo);

      printf("\nInserta el autor del libro:=> ");
      gets(autor);
      agregarlibro(autor);

      printf("\nInserta la editorial del libro:=> ");
      gets(editorial);
      agregarlibro(editorial);

      printf("\nIntroduzca el ISBN dado para el libro:=> ");
      gets(isbn);
      agregarlibro(isbn);

      do{
         printf("\nEl libro, ¿Tiene pasta dura o pasta blanda ?");
         printf("\nPara pasta Blanda (1), para pasta dura (2)");
         scanf("%i",&opc);
         setbuf(stdin,NULL);
         switch (opc)
         {
            case 1:agregarlibro(uno);break;
            case 2:agregarlibro(dos);break;
            default:
               printf("Por favor, introduzca una opcion valida\n");break;
         }
      }while(opc !=1 && opc !=2);

      printf("\n¿Cuantos libros hay en existencia?:=>");
      gets(cantidad);
      agregarlibro(cantidad);

      printf("\nQue precio se va a manejar en su salida? (Asegurese de manejar unicamente el numero):=>");
      gets(precio);
      agregarlibro(precio);
      printf("\nQuiere agregar otro libro  ?(s|n)");
      scanf("%s", &deci);
      setbuf(stdin,NULL);

   }while(deci=='s' || deci == 'S');

   return 0;


}
int agregarlibro(char *dato){
   FILE *bib;
   bib=fopen("biblioteca.txt","a");
   if (bib == NULL){
         perror("Error en la apertura del archivo");
         return -1;
      }

   fprintf(bib,"%s\n",dato);
   fclose(bib);
   return 0;
}
/*
+Ciclo en switch,
+Preguntar para agregar otro libro
*/