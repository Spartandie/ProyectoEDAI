#ifndef FILES_H
#define FILES_H
#include "stdbool.h"
#include "list.h"
//bool borrar_temp();//Esta funcion sera re-hecha desde 0
int check(int actual_or_new);//Esta funcion sera modificada
//void rewrite(int cont);//Esta funcion sera eliminada
//int agregarlibro_temp();//Esta funcion sera re-hecha desde 0
int imprimirlibro();
//int salto();//Esta funcion sera eliminada
//int agregar_lib_temp();//Esta funcion sera re-hecha desde 0
void emptyc(char temp[], int tam);
bool borrar(list *l, int c);
node *buscar_nodo(list *l, int sel, char cadena[]);
#endif