#include <stdio.h>
#include <stdlib.h>

struct punto {    
	float x;
	float y; 
}; 

struct recta { 
	struct punto p; 
	float m;
	struct recta* enlace;
};

struct recta* crearNodoInicial();
void insertarNodo(struct recta*);
void determinarPuntosInterseccion(struct recta*); 

int main(int argc, char *argv[]) {

	//crear el primer elemento recta de la lista
	struct recta* cabecera; //Se declara la variable puntero y se llama a la funci�n para crearNodoInicial
	cabecera = crearNodoInicial();
	//Se crean las dem�s rectas de la lista
	for(int i=0; i<2; i++){
		insertarNodo(cabecera);
	}
	
	//Funci�n para determinar puntos de intersecci�n
	determinarPuntosInterseccion(cabecera); 
	return 0;
}

struct recta* crearNodoInicial(){
	float valorX;
	float valorY;
	float valorPendiente;
	struct recta* nuevo; //Se declara la variable puntero
	
	puts("Introduce los valores de la recta:");
	puts("Introduce el valor de la coordenada x del punto:");
	scanf("%f", &valorX);
	puts("Introduce el valor de la coordenada y del punto:");
	scanf("%f", &valorY);	
	puts("Introduce el valor de la pendiente:");
	scanf("%f", &valorPendiente);			
	
	nuevo = (struct recta*)malloc(sizeof(struct recta)); // Se reserva la memoria para el nuevo nodo
	nuevo -> p.x = valorX; //Se asigna valor al miembro dato del nodo
	nuevo -> p.y = valorY; //Se asigna valor al miembro dato del nodo
	nuevo -> m = valorPendiente; //Se asigna valor al miembro dato del nodo
	nuevo -> enlace= NULL; //Se asigna NULL al miembro enlace del nodo
	return nuevo;
}

void insertarNodo(struct recta* cabecera){
	float valorX;
	float valorY;
	float valorPendiente;
	struct recta* nuevo; //Se declara la variable puntero
	struct recta* actual; //Se declara la variable puntero actual
	struct recta* anterior; //Se declara la variable puntero anterior
	actual = cabecera;
	anterior = NULL;
	
	while (actual != NULL ){
		anterior =actual;
		actual = actual-> enlace;
		
	}	
	puts("Introduce los valores de la recta:");
	puts("Introduce el valor de la coordenada x del punto:");
	scanf("%f", &valorX);
	puts("Introduce el valor de la coordenada y del punto:");
	scanf("%f", &valorY);	
	puts("Introduce el valor de la pendiente:");
	scanf("%f", &valorPendiente);	
		
	nuevo = (struct recta*)malloc(sizeof(struct recta)); // Se reserva la memoria para el nuevo nodo
	nuevo -> p.x = valorX; //Se asigna valor al miembro dato del nodo
	nuevo -> p.y = valorY; //Se asigna valor al miembro dato del nodo
	nuevo -> m = valorPendiente; //Se asigna valor al miembro dato del nodo		
	nuevo -> enlace = NULL; //Se asigna NULL al miembro enlace del nodo
	anterior -> enlace = nuevo;
	return;
}

void determinarPuntosInterseccion(struct recta* cabecera){
	float b;
	float valorY;
	float valorCalculo;
	struct recta* actual; //Se declara la variable puntero actual
	struct recta* anterior; //Se declara la variable puntero anterior
	actual = cabecera;
	anterior = NULL;
	
	struct recta* actualRecorridoInterior; 
	struct recta* anteriorRecorridoInterior;
	
	// Ciclo que toma de una en una, cada recta de la lista
	while (actual != NULL ){
		//Calculando el elemento b de la ecuaci�n y=2x+b, donde b=Yo-mXo
		b = actual -> p.y - (actual -> m)*(actual -> p.x);
		printf("\nRecta y = %fx + %f: \n",actual -> p.y,actual -> m, b);
		
		actualRecorridoInterior = cabecera;
		anteriorRecorridoInterior = NULL;
		// Ciclo que recorre todas rectas de la lista para compararlas con la seleccionada arriba
		while (actualRecorridoInterior != NULL ){
			//Verificando primero que las rectas podr�an ser paralelas (tienen la misma pendiente)
			if (actual!=actualRecorridoInterior){ //condici�n para que las rectas no se comparen a s� mismas
				if (actual -> m == actualRecorridoInterior -> m){
					puts("Las rectas son paralelas");
				}else{
					//Verificando que el punto de la otra recta satisface la recta actual
					//Veridicar que el punto satisface la ecuacion y=mx+b
					valorY= actualRecorridoInterior -> p.y; //Obteniendo la parte izquierda de la ecuaci�n
					valorCalculo= (actual -> m)*(actualRecorridoInterior -> p.x) + b;//Obteniendo la parte derecha de la ecuaci�n
					if(valorY==valorCalculo){
						printf("Es intersectada por el punto (%f,%f)\n",
							   actualRecorridoInterior -> p.x, actualRecorridoInterior -> p.y);
					}else{
						printf("No es intersectada por el punto (%f,%f)\n",
							   actualRecorridoInterior -> p.x, actualRecorridoInterior -> p.y);
					}				
				}				
			}
			anteriorRecorridoInterior =actualRecorridoInterior;
			actualRecorridoInterior = actualRecorridoInterior-> enlace;			
		}		
		anterior =actual;
		actual = actual-> enlace;
	}
	return;
}
