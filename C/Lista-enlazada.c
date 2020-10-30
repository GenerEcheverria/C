//31/05/2020
#include<stdio.h>
#include<stdlib.h>
struct nodo {
	int numero;
	struct nodo* siguiente;
};
struct nodo* inicial (int num);
void insertarNodo (int num,struct nodo*);
void verLista(struct nodo*);
void eliminarUltimo(struct nodo*);
int main (){
	struct nodo* cabecera;
	cabecera = inicial(1);
	insertarNodo(2,cabecera);
	insertarNodo(10,cabecera);
	insertarNodo(8,cabecera);
	verLista(cabecera);
	eliminarUltimo(cabecera);
	verLista(cabecera);
	return 0;
}
struct nodo* inicial (int num){
	struct nodo* nuevo;
	nuevo = (struct nodo*)malloc (sizeof(struct nodo));
	nuevo -> numero= num;
	nuevo-> siguiente=NULL;
	return nuevo;
}
void insertarNodo(int num, struct nodo* cabecera) {
	struct nodo* actual;
	struct nodo* anterior;
	struct nodo* nuevo;
	actual=cabecera;
	anterior=NULL;
	while(actual!=NULL){
		anterior=actual;
		actual=actual->siguiente;		
	}
	nuevo=(struct nodo*)malloc (sizeof(struct nodo));
	nuevo->numero=num;
	nuevo->siguiente=NULL;
	anterior->siguiente= nuevo;
}
void verLista(struct nodo* cabecera){
	struct nodo* actual;
	actual=cabecera;
	while(actual!=NULL){
		printf("%d\t",actual->numero);
		actual=actual->siguiente;		
	}
}
void eliminarUltimo(struct nodo* cabecera){
	struct nodo *ultimo, *anterior;
    ultimo = cabecera;
    anterior = cabecera;
    while(ultimo->siguiente != NULL){
        anterior = ultimo;
        ultimo = ultimo->siguiente;
    }
    if(ultimo == cabecera){
        cabecera = NULL;
    }
    else{
        anterior->siguiente = NULL;
    }
    free(ultimo);
}
