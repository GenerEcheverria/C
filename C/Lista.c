#include <stdio.h>
#include <stdlib.h>

struct nodo* crearNodoInicial(int);
void insertarNodo(int, struct nodo**);
void imprimirLista(struct nodo**);

struct nodo{
int dato;
struct nodo* enlace;
};


int main(int argc, char *argv[]) {
struct nodo* cabecera;
cabecera = crearNodoInicial(10);
//printf("%d",cabecera->dato);
insertarNodo(4,&cabecera);
insertarNodo(89,&cabecera);
insertarNodo(12,&cabecera);
insertarNodo(5,&cabecera);
imprimirLista(&cabecera);

return 0;
}

struct nodo* crearNodoInicial(int dato){
struct nodo* nuevo; //Se declara la variable puntero
nuevo = (struct nodo*)malloc(sizeof(struct nodo)); // Se reserva la memoria para el nuevo nodo
nuevo -> dato= dato; //Se asigna valor al miembro dato del nodo
nuevo -> enlace= NULL; //Se asigna NULL al miembro enlace del nodo
return nuevo;
}

void insertarNodo(int dato, struct nodo** puntero){
struct nodo* actual; //Se declara la variable puntero actual
struct nodo* anterior; //Se declara la variable puntero anterior
actual = *puntero;
anterior = NULL;

while (actual != NULL && actual->dato < dato){
anterior =  actual;
actual = anterior-> enlace;
}

struct nodo* nuevo;
nuevo = (struct nodo*)malloc(sizeof(struct nodo)); // Se reserva la memoria para el nuevo nodo
if (actual == *puntero){
nuevo->dato =  dato;
nuevo->enlace = *puntero;
*puntero = nuevo;
}else{
nuevo->dato =  dato;
nuevo->enlace = anterior->enlace;
anterior->enlace = nuevo;
}
return;
}


void imprimirLista(struct nodo **puntero){
struct nodo* actual; //Se declara la variable puntero actual
actual = *puntero;

while (actual != NULL){
printf("%d \t",actual->dato);
actual = actual->enlace;
}

return;
}
