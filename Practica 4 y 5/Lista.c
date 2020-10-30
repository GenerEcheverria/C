//Gener Echeverria
//Lista
#include<stdio.h>
#include<stdlib.h>
struct nodo {
	int numero;
	struct nodo *siguiente;
};
struct nodo* cabecera = NULL;
void nuevoNodo ( int num);
void nuevoNodoOrdenadoMayor(int num);
void nuevoNodoOrdenadoMenor(int num);
void imprimirLista(struct nodo*);
void borrarPrimero(struct nodo**);
void borrarUltimo(struct nodo*);
int encontrar(struct nodo*, int num);
void encontrarBorrar(struct nodo*,int num);
void modificar(struct nodo*, int num);
int main (){
	//nuevoNodo(10);
	//nuevoNodo(11);
	//nuevoNodoOrdenadoMayor(10);
	//nuevoNodoOrdenadoMayor(9);
	//nuevoNodoOrdenadoMayor(11);
	nuevoNodoOrdenadoMenor(10);
	nuevoNodoOrdenadoMenor(9);
	nuevoNodoOrdenadoMenor(11);
	nuevoNodoOrdenadoMenor(5);
	imprimirLista(cabecera);
	puts("--------------");
	borrarPrimero(&cabecera);
	imprimirLista(cabecera);
	puts("--------------");
	borrarUltimo(cabecera);
	imprimirLista(cabecera);
	puts("--------------");
	nuevoNodoOrdenadoMenor(11);
	nuevoNodoOrdenadoMenor(5);
	imprimirLista(cabecera);
	puts("--------------");
	encontrar(cabecera,30);
	encontrarBorrar(cabecera,10);
	imprimirLista(cabecera);
	puts("--------------");
	modificar(cabecera,5);
	imprimirLista(cabecera);
	
	return 0;
}
void nuevoNodo (int num){
	struct nodo *nuevo;
	nuevo = (struct nodo*)malloc(sizeof(struct nodo));
	nuevo->numero = num;
	nuevo->siguiente = NULL;
	if (cabecera==NULL){
		cabecera=nuevo;
	}
	else {
		struct nodo* anterior;
		struct nodo* actual;
		actual=anterior=cabecera;
		while (actual!=NULL){
			anterior=actual;
			actual=actual->siguiente;
		}
		anterior->siguiente=nuevo;
	}
}
void nuevoNodoOrdenadoMayor(int num){
	struct nodo*nuevo;
	nuevo=(struct nodo*)malloc(sizeof(struct nodo));
	nuevo->numero=num;
	nuevo->siguiente=NULL;
	if (cabecera==NULL){
		cabecera=nuevo;
	}
	else {
		if (num>cabecera->numero){
			nuevo->siguiente=cabecera;
			cabecera=nuevo;
		}
		else {
			struct nodo* actual;
			struct nodo* anterior;
			anterior=actual=cabecera;
			while (num<=actual->numero && actual->siguiente!=NULL){
				anterior =actual;
				actual=actual->siguiente;
			}
			if(num<=actual->numero){
				actual->siguiente=nuevo;
			}
			else {
				nuevo->siguiente=actual;
				anterior->siguiente=nuevo;
			}
		}
	}
	
}
void nuevoNodoOrdenadoMenor(int num){
	struct nodo*nuevo;
	nuevo=(struct nodo*)malloc(sizeof(struct nodo));
	nuevo->numero=num;
	nuevo->siguiente=NULL;
	if (cabecera==NULL){
		cabecera=nuevo;
	}
	else {
		if (num<cabecera->numero){
			nuevo->siguiente=cabecera;
			cabecera=nuevo;
		}
		else {
			struct nodo* actual;
			struct nodo* anterior;
			anterior=actual=cabecera;
			while (num>=actual->numero && actual->siguiente!=NULL){
				anterior =actual;
				actual=actual->siguiente;
			}
			if(num>=actual->numero){
				actual->siguiente=nuevo;
			}
			else {
				nuevo->siguiente=actual;
				anterior->siguiente=nuevo;
			}
		}
	}
	
}
void borrarPrimero (struct nodo** cabecera){
	struct nodo * auxiliar = *cabecera;
	if (auxiliar!=NULL){
		*cabecera=auxiliar->siguiente;
		free(auxiliar);
	}
}
void borrarUltimo (struct nodo* cabecera){
	struct nodo* actual;
	struct nodo* anterior;
	actual=anterior=cabecera;
	while(actual->siguiente!=NULL){
		anterior=actual;
		actual=actual->siguiente;
	}
	if (actual==cabecera){
		cabecera=NULL;
	}
	else {
		anterior->siguiente=NULL;
	}
	free(actual);
}
int encontrar(struct nodo* cabecera, int num){
	struct nodo* actual;
	actual=cabecera;
	while(actual!=NULL){
		if (actual->numero==num){
			printf("El elemento %d se encuentra en la lista\n",actual->numero);
			return 0;
		}
		actual=actual->siguiente;
	}
	printf("El elemento %d no se encuentra en la lista\n",num);
	return 0;
}

void encontrarBorrar(struct nodo* cabecera,int num){
	int encontrado=0;
	struct nodo* actual;
	struct nodo* anterior;
	actual=cabecera;
	anterior = NULL;
	if(cabecera != NULL) {
		while (actual !=NULL && encontrado !=1) {
			if (actual->numero == num) {
				if (actual==cabecera) {
					cabecera = cabecera->siguiente;
				}
				else {
					anterior -> siguiente = actual->siguiente;
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
			puts("La lista no existe");
	}
}
void modificar(struct nodo* cabecera, int num){
	int encontrado=0;
	struct nodo* actual,*anterior;
	actual=cabecera;
	if(cabecera != NULL) {
		while (actual !=NULL && encontrado !=1) {
			if (actual->numero == num) {
				puts("Nuevo dato: ");
				scanf("%d",&actual->numero);
				encontrado=1;
			}
			actual = actual->siguiente;
		}
		if (encontrado==0){
			puts("\n Nodo no encontrado");
		}
	}
	else {
			puts("La lista no existe");
	}
}
void imprimirLista(struct nodo* cabecera){
	struct nodo* actual;
	actual=cabecera;
	while (actual!=NULL){
		printf("%d\n",actual->numero);
		actual=actual->siguiente;
	}
}
