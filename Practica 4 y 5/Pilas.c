#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//PILAS
typedef struct nodo {
	char dato;
	struct nodo* siguiente;
}nodo;
nodo* primero = NULL;
void insertarNodo (char expresion[], int i);
void desplegarPila ();
void modificarNodo ();
void eliminarNodo ();
int main (){
	char expresion [50];
	int i=0;
	fflush(stdin);
	gets (expresion);
	puts (expresion);
	while (expresion[i]!='\0') {
		insertarNodo(expresion,i);
		i++;
	}
	desplegarPila();
	//eliminarNodo();
	modificarNodo();
	desplegarPila();
	return 0;
}
void insertarNodo (char expresion[], int i){
	nodo* nuevo = (nodo*) malloc (sizeof(nodo));
	nuevo->dato = expresion [i];
	nuevo->siguiente = primero;
	primero=nuevo;
}
void desplegarPila (){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if (primero!=NULL){
		while (actual != NULL){
			printf("\n%c", actual->dato);
			actual = actual->siguiente;	
		}
	}
	else {
		puts("La pila se encuentra vacia");
	}
}
void modificarNodo(){
	nodo* actual = (nodo*) malloc (sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	puts("\nIngrese el valor del nodo a modificar");
	scanf("%c", &nodoBuscado);
	if(primero != NULL) {
		while (actual !=NULL && encontrado !=1) {
			if (actual->dato == nodoBuscado) {
				printf("\nNodo con el dato %c encontrado \n", nodoBuscado);
				puts("Ingresa el nuevo nodo");
				fflush(stdin);
				scanf("%c", &actual->dato);
				puts("Nodo modificado\n");
				encontrado =1;
			}
			actual = actual->siguiente;
		}
		if (encontrado==0){
			puts("\n Nodo no encontrado");
		}
	}
	else {
			puts("La cola no existe");
		}
}
void eliminarNodo(){
	nodo* actual = (nodo*) malloc (sizeof(nodo));
	actual = primero;
	nodo * anterior = (nodo*) malloc (sizeof(nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	puts("\nIngrese el dato del nodo que desea eliminar");
	scanf("%c", &nodoBuscado);
	if(primero != NULL) {
		while (actual !=NULL && encontrado !=1) {
			if (actual->dato == nodoBuscado) {
				if (actual==primero) {
					primero = primero->siguiente;
				}
				else {
					anterior -> siguiente= actual->siguiente;
				}
				puts("Nodo eliminado\n");
				encontrado =1;
			}
			anterior=actual;
			actual = actual->siguiente;
		}
		if (encontrado==0){
			puts("\n Nodo no encontrado");
		}
	}
	else {
			puts("La cola no existe");
	}
}
