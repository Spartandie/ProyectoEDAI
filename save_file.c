#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
   FILE *bib;
   char titulo[30], autor[30], editorial[20], isbn[20], formato[12], cantidad[5], precio[5], temp[21];
   bib=fopen("biblioteca.txt","a+");
   if (bib == NULL){
      perror("Error en la apertura del archivo");
      return -1;
   }
   printf("Inserta el titulo del libro: ");
   /* 
      Escribir en el archivo de la siguiente manera:
      Titulo1
      Autor2
      Editorial1
      isbn1
      formato1(Aqui simplemente dale a escojer al admin entre pasta dura o blanda y dependiendo de su respuesta escribes de forma predeterminada el formato
      Que  todo esto sea de tal manera que eel no tenga la posibilidad de escribir otra cosa como no se, tacos de suadero xD)
      Cantidad1
      Precio1
      Titulo2
      Autor2
      Editorial2
      isbn2
      formato2
      Cantidad2
      Precio2
      .
      .
      .
      Titulo n
      Autor n
      Editorial n
      isbn n
      formato n
      Cantidad n
      Precio n
   */
   fclose(bib);
   return 0;
}