#include <stdio.h>
#include <stdlib.h>
 int main(){

   FILE *flujo;
   flujo=fopen("libro.txt","rb");
   if (flujo == NULL){
      perror("Error en la apertura del archivo");
      return 1;
   }
   fseek(flujo, 0, SEEK_END);
   int num_elementos = ftell(flujo);
   rewind(flujo);

   char * cadena = (char *) calloc(sizeof(char), num_elementos);
   if (cadena == NULL) {
      perror("Error en reserva de memoria");
      return 2;
   }

   int num_elementos_leidos = fread(cadena, sizeof(char), num_elementos, flujo);
   if (num_elementos_leidos!=num_elementos){
      perror("Error leyendo el archivo");
      return 3;
   }   

   printf("%s", cadena);

   free(cadena);
   fclose(flujo);
   printf("\n\nSe ha leido el archivo correctamente..");
   return 0;
}
