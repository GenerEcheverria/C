#include <stdio.h>

struct punto {    
	float x;
	float y; 
}; 

struct recta { 
	struct punto p; 
	float m;
};

void insertarRectas(struct recta[], int);
void determinarPuntosInterseccion(struct recta[], int);

int main(int argc, char *argv[]) {

	//crear el ventor de cinco estructuras recta
	struct recta vectorRecta[5]; 
	
	//Introducir datos al vector
	insertarRectas(vectorRecta, 2);
	
	//Función para determinar puntos de intersección
	determinarPuntosInterseccion(vectorRecta, 2); 
	return 0;
}

void insertarRectas(struct recta vectorRecta[], int n){
	float valorX;
	float valorY;
	float valorPendiente;

	for (int i=0; i<n; i++){
		puts("Introduce los valores de recta: \n");
		puts("Introduce el valor de la coordenada x del punto:");
		scanf("%f", &valorX);
		puts("Introduce el valor de la coordenada y del punto:");
		scanf("%f", &valorY);	
		puts("Introduce el valor de la pendiente:");
		scanf("%f", &valorPendiente);			
		
		vectorRecta[i].p.x = valorX; //Se asigna valor al miembro dato del nodo
		vectorRecta[i].p.y = valorY; //Se asigna valor al miembro dato del nodo
		vectorRecta[i].m = valorPendiente; //Se asigna valor al miembro dato del nodo		
	}
	return;
}

void determinarPuntosInterseccion(struct recta vectorRectas[], int n){
	float b;
	float valorY;
	float valorCalculo;
	
	// Ciclo que toma de una en una, cada recta de la lista
	for (int i=0; i<n; i++){
		//Calculando el elemento b de la ecuación y=2x+b, donde b=Yo-mXo
		b = vectorRectas[i].p.y - (vectorRectas[i].m)*(vectorRectas[i].p.x);
		printf("Recta y = %fx + %f: \n",vectorRectas[i].p.y, vectorRectas[i].m, b);
		
		// Ciclo que recorre todas rectas de la lista para compararlas con la seleccionada arriba
		for(int j=0;j<n;j++){
			//Verificando primero que las rectas podrían ser paralelas (tienen la misma pendiente)
			if (i!=j){ //condición para que las rectas no se comparen a sí mismas
				if (vectorRectas[i].m == vectorRectas[j].m){
					puts("Las rectas son paralelas \n");
				}else{
					//Verificando que el punto de la otra recta satisface la recta actual
					//Veridicar que el punto satisface la ecuacion y=mx+b
					valorY= vectorRectas[j].p.y; //Obteniendo la parte izquierda de la ecuación
					valorCalculo= (vectorRectas[i].m)*(vectorRectas[j].p.x) + b;//Obteniendo la parte derecha de la ecuación
					if(valorY==valorCalculo){
						printf("Es intersectada por el punto (%f,%f)\n",
							   vectorRectas[j].p.x, vectorRectas[j].p.y);
					}else{
						printf("No es intersectada por el punto (%f,%f)\n",
							   vectorRectas[j].p.x, vectorRectas[j].p.y);
					}				
				}				
			}
		}		
	}
	return;
}
