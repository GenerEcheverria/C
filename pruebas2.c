//listas simples
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct nodo {
	char dato;
	struct nodo* siguiente;
}nodo;
nodo* primero = NULL;
nodo* ultimo = NULL;
void insertarNodoLista(char expresion[], int i);
void desplegarLista();
void buscarNodo();
void modificarNodoLista();
void eliminarNodoLista();
int main (){
	char expresion [50];
	int i=0;
	fflush(stdin);
	gets (expresion);
	puts (expresion);
	while (expresion[i]!='\0') {
		insertarNodoLista(expresion,i);
		i++;
	}
	desplegarLista();
	eliminarNodoLista();
	desplegarLista();
	
	
	return 0;
}
void insertarNodoLista(char expresion[], int i){
	nodo* nuevo = (nodo*) malloc (sizeof(nodo));
	nuevo->dato=expresion[i];
	if (primero==NULL) {
		primero = nuevo;
		primero->siguiente=nuevo;
		ultimo=nuevo;
	}
	else {
		ultimo->siguiente=nuevo;
		nuevo->siguiente=NULL;
		ultimo=nuevo;
	}
}
void desplegarLista(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual=primero;
	if(primero!=NULL) {
		while(actual!=NULL){
			printf("\n %c", actual->dato);
			actual= actual->siguiente;
		}
	}
	else{
		printf("\n La lista se encuentra vacia");
	}
}
void buscarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual=primero;
	int nodoBuscado=0,encontrado=0;
	puts("\nNodo a buscar");
	scanf("%c",&nodoBuscado);
	if(primero!=NULL) {
		while(actual!=NULL&&encontrado!=1){
			if (actual->dato==nodoBuscado){
				printf("nodo con dato %c encontrado\n", nodoBuscado);
				encontrado=1;
			}
			actual= actual->siguiente;
		}
		if (encontrado==0){
			puts("Nodo no encontrado");
		}
	}
	else{
		printf("\n La lista se encuentra vacia");
	}
}
void modificarNodoLista(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual=primero;
	int nodoBuscado=0,encontrado=0;
	puts("\nNodo a buscar para modificar");
	scanf("%c",&nodoBuscado);
	if(primero!=NULL) {
		while(actual!=NULL&& encontrado!=1){
			if (actual->dato==nodoBuscado){
				printf("nodo con dato %c encontrado\n", nodoBuscado);
				puts("ingrese el nuevi dato");
				fflush(stdin);
				scanf("%c",&actual->dato);
				encontrado=1;
			}
			actual= actual->siguiente;
		}
		if (encontrado==0){
			puts("Nodo no encontrado");
		}
	}
	else{
		printf("\n La lista se encuentra vacia");
	}
}
void eliminarNodoLista(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual=primero;
	nodo* anterior = (nodo*) malloc (sizeof(nodo));
	anterior=NULL;
	int nodoBuscado=0,encontrado=0;
	puts("\nNodo a eliminar");
	scanf("%c",&nodoBuscado);
	if(primero!=NULL) {
		while(actual!=NULL&&encontrado!=1){
			if (actual->dato==nodoBuscado){
				if (actual==primero){
					primero=primero->siguiente;
				}
				else {
					if(actual==ultimo){
						anterior->siguiente=NULL;
						ultimo=anterior;
					}
					else {
						anterior->siguiente=actual->siguiente;
					}
				}
				puts("Nodo eliminado");
				encontrado=1;
			}
			anterior=actual;
			actual= actual->siguiente;
		}
		if (encontrado==0){
			puts("Nodo no encontrado");
		}
		else{
			free(anterior);
		}
	}
	else{
		printf("\n La lista se encuentra vacia");
	}
}
