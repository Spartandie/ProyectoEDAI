#ifndef ARCHIVO_H
#define ARCHIVO_H
struct libro
{
    char isbn[5];
    char titulo[30];
    char editorial[20];
    char autor[30];
    char formato[12];
    char precio[5];
    char cantidad[5];
};
typedef struct libro book;
book libro;

int agregarlibro();
int imprimirlibro();
int salto();
int borrar();
void empty(char temp[]);

#endif