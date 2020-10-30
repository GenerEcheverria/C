#include<stdio.h>
#include<stdlib.h>
struct nodo {
	int dato;
	struct nodo* siguiente;
};
struct nodo* iniciarLista ();
void insertarNodo(int dat, struct nodo** puntero);
void imprimirLista(struct nodo**);

int main (){
	struct nodo* cima;
	cima=iniciarLista();
	insertarNodo(1,&cima);
	imprimirLista(&cima);
	return 0;
}
struct nodo* iniciarLista(){
	struct nodo* nuevo;
	nuevo = (struct nodo*)malloc (sizeof( struct nodo));
	nuevo-> dato = NULL;
	nuevo->siguiente= NULL;
	return nuevo;
}
void insertarNodo(int dat, struct nodo** puntero){
	struct nodo* nuevo;
	nuevo = (struct nodo*)malloc (sizeof(struct nodo));
	nuevo->dato = dat;
	nuevo->siguiente= NULL;
}
void imprimirLista(struct nodo** puntero){
	struct nodo* actual;
	actual = *puntero;
	while (actual!=NULL){
		printf("%d\t", actual->dato);
		actual=actual->siguiente;
	}
}
