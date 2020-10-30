#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct temperatura {    
	float temperaturaMaxima;
	float temperaturaMinima; 
	struct temperatura* enlace;
}; 

struct temperatura* crearNodoInicial();
void insertarNodo(struct temperatura*);
void convertirGradosFarenheit(struct temperatura*);

int main(int argc, char *argv[]) {

	//crear el primer elemento de la lista
	struct temperatura* cabecera;	
	cabecera = crearNodoInicial();
	//Creando los 4 elementos faltantes
	for (int i=0; i<4;i++){
		insertarNodo(cabecera);	
	}
	
	//Función para convertir a grados Farenheit
	convertirGradosFarenheit(cabecera); 
	
	return 0;
}

struct temperatura* crearNodoInicial(){
	float temp1;
	float temp2;
	struct temperatura* nuevo; //Se declara la variable puntero
	nuevo = (struct temperatura*)malloc(sizeof(struct temperatura)); // Se reserva la memoria para el nuevo nodo
	temp1 = rand() % 41;
	temp2 = rand() % 41;
	if (temp1>=temp2){
		nuevo -> temperaturaMaxima = temp1;
		nuevo -> temperaturaMinima = temp2;	
	}else{
		nuevo -> temperaturaMaxima = temp2;
		nuevo -> temperaturaMinima = temp1;				
	}
	nuevo -> enlace= NULL; //Se asigna NULL al miembro enlace del nodo
	return nuevo;
}

void insertarNodo(struct temperatura* cabecera){
	float temp1;
	float temp2;
	struct temperatura* actual; //Se declara la variable puntero actual
	struct temperatura* anterior; //Se declara la variable puntero anterior
	actual = cabecera;
	anterior = NULL;
	
	while (actual != NULL ){
		anterior = actual;
		actual = actual-> enlace;
	}	
	struct temperatura* nuevo; //Se declara la variable puntero
	nuevo = (struct temperatura*)malloc(sizeof(struct temperatura)); // Se reserva la memoria para el nuevo nodo
	temp1 = rand() % 41;
	temp2 = rand() % 41;
	if (temp1>=temp2){
		nuevo -> temperaturaMaxima = temp1;
		nuevo -> temperaturaMinima = temp2;	
	}else{
		nuevo -> temperaturaMaxima = temp2;
		nuevo -> temperaturaMinima = temp1;				
	}	
	nuevo -> enlace = NULL; //Se asigna NULL al miembro enlace del nodo
	anterior -> enlace = nuevo;
	return;
}

void convertirGradosFarenheit(struct temperatura* cabecera){
	float farenheitTempMaxima;
	float farenheitTempMinima;
	struct temperatura* actual; //Se declara la variable puntero actual
	struct temperatura* anterior; //Se declara la variable puntero anterior
	actual = cabecera;
	anterior = NULL;
	
	while (actual != NULL ){
		farenheitTempMaxima = actual -> temperaturaMaxima*(9/5) + 32;
		farenheitTempMinima = actual -> temperaturaMinima*(9/5) + 32;
		printf("Temperatura Máxima: Celsius (%f), Farenheit (%f)\n",
			   actual -> temperaturaMaxima, farenheitTempMaxima);
		printf("Temperatura Míxima: Celsius (%f), Farenheit (%f)\n",
			   actual -> temperaturaMinima, farenheitTempMinima);		
		anterior = actual;
		actual = actual-> enlace;
	}
	return;
}
