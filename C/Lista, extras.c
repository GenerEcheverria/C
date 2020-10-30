#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	float salario;
	struct nodo* enlace;
};

void insertarNodo(struct nodo*, int, float);
void imprimirDatos (struct nodo*);
void eliminarPrimeroDatos (struct nodo**);
void eliminarDatos(struct nodo* cabecera);
struct nodo* crearInicial(int dato, float sal);

int main(int argc, char *argv[]) {
	//Se crea el primer elemento de la lista
	struct nodo* cabecera;
	cabecera = crearInicial(10,34.8);
	
	// Insertamos otro elemento al final de lista dato:5 y salario:100
	insertarNodo(cabecera,5,100);
	// Insertamos otro elemento al final de lista dato:80 y salario:900.8
	insertarNodo(cabecera,80,900.8);
	// Insertamos otro elemento al final de lista dato:980 y salario:1567.8
	insertarNodo(cabecera,980,1567.8);

	//Imprimir la lista
	imprimirDatos(cabecera);
	
	//Eliminar ultimo elemento
	eliminarDatos(cabecera);
	//eliminarPrimeroDatos(&cabecera);
	//eliminarPrimeroDatos(&cabecera);
	
	imprimirDatos(cabecera);
	return 0;
}
struct nodo* crearInicial(int dat, float sal){
	struct nodo* nuevo;
	nuevo = (struct nodo*)malloc(sizeof(struct nodo)); // Se reserva la memoria para el nuevo nodo
	nuevo -> dato = dat; //Se asigna valor al miembro dato del nodo
	nuevo -> salario = sal;
	nuevo -> enlace = NULL; //Se asigna NULL al miembro enlace del nodo
	return nuevo;
}

void insertarNodo(struct nodo* cabecera, int dat, float sal){
	struct nodo* actual; //Se declara la variable puntero actual
	struct nodo* anterior; //Se declara la variable puntero anterior
	actual = cabecera;
	anterior = NULL;
	
	while (actual != NULL ){
		anterior =actual;
		actual = actual-> enlace;
	
	}
	struct nodo* nuevo; //Se declara la variable puntero
	nuevo = (struct nodo*)malloc(sizeof(struct nodo)); // Se reserva la memoria para el nuevo nodo
	nuevo -> dato = dat; //Se asigna valor al miembro dato del nodo
	nuevo -> salario = sal;
	nuevo -> enlace = NULL; //Se asigna NULL al miembro enlace del nodo
	anterior -> enlace = nuevo;
	return;
}

void imprimirDatos (struct nodo* cabecera){
	struct nodo* actual;
	actual = cabecera;
	while (actual != NULL){
		printf("%d \t",actual->dato);
		printf("%f \t",actual->salario);
		printf("%d \t",actual->enlace);
		printf("\n");
		actual = actual->enlace;
	}	
}
//eliminar primero
void eliminarPrimeroDatos (struct nodo** cabecera) {
	struct nodo* aux=*cabecera;
	if (aux != NULL) {
		*cabecera=aux->enlace;
		free(aux);
		puts ("Nodo eliminado");
	}
}
//eliminar ultimo
void eliminarDatos(struct nodo* cabecera){
    struct nodo *ultimo, *anterior;
    ultimo = cabecera;
    anterior = cabecera;
    while(ultimo->enlace != NULL){
        anterior = ultimo;
        ultimo = ultimo->enlace;
    }
    if(ultimo == cabecera){
        cabecera = NULL;
    }
    else{
        anterior->enlace = NULL;
    }
    free(ultimo);
    puts("Ultimo dato eliminado");
}
	 
 

