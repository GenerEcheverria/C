#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno { 
	int matricula;
	char nombre[50]; 
	int edad; 
	float calificacion;
	struct alumno* enlace;
};

struct alumno* crearNodoInicial();
void insertarNodo(struct alumno**);
void imprimirLista(struct alumno**);
void imprimirDatosAlumnoMayorCalificacion(struct alumno **puntero);

int main(int argc, char *argv[]) {
	
	struct alumno* cabecera;
	//Crea el primer alumno de la lista
	cabecera = crearNodoInicial();
	//crea los 4 alumnos faltantes de la lista
	for (int i=0; i<2; i++){
		insertarNodo(&cabecera);	
	}

	//Imprime los datos de la lista
	imprimirLista(&cabecera);
	
	//imprimir alumnos con mayor calificación
	imprimirDatosAlumnoMayorCalificacion(&cabecera);
	
	return 0;
}

struct alumno* crearNodoInicial(){
	int mat;
	char nom[50];
	int ed;
	float cal;
	
	puts("Introduce los datos del alumno:");
	puts("Matrícula: ");
	scanf("%d",&mat);
	puts("Nombre:");
	fflush(stdin);
	gets(nom);
	puts("Edad: ");
	scanf("%d",&ed);
	puts("Calificación: ");
	fflush(stdin);
	scanf("%f",&cal);
	fflush(stdin);
	
	struct alumno* nuevo; //Se declara la variable puntero
	nuevo = (struct alumno*)malloc(sizeof(struct alumno)); // Se reserva la memoria para el nuevo nodo
	nuevo -> matricula = mat; 
	strcpy(nuevo -> nombre,nom);
	nuevo -> edad = ed;
	nuevo -> calificacion = cal;
	nuevo -> enlace= NULL; //Se asigna NULL al miembro enlace del nodo
	return nuevo;
}

void insertarNodo(struct alumno** puntero){
	int mat;
	char nom[50];
	int ed;
	float cal;
	struct alumno* actual; //Se declara la variable puntero actual
	struct alumno* anterior; //Se declara la variable puntero anterior
	actual = *puntero;
	anterior = NULL;

	puts("Introduce los datos del alumno:");
	puts("Matrícula: ");
	scanf("%d",&mat);
	puts("Nombre:");
	fflush(stdin);
	gets(nom);
	puts("Edad: ");
	scanf("%d",&ed);
	puts("Calificación: ");
	fflush(stdin);
	scanf("%f",&cal);	
	fflush(stdin);
		
	while (actual != NULL && actual -> matricula < mat){
		anterior =  actual;
		actual = anterior-> enlace;
	}
	
	struct alumno* nuevo;
	nuevo = (struct alumno*)malloc(sizeof(struct alumno)); // Se reserva la memoria para el nuevo nodo
	if (actual == *puntero){
		nuevo -> matricula = mat; 
		strcpy(nuevo -> nombre,nom);
		nuevo -> edad = ed;
		nuevo -> calificacion = cal;		
		nuevo -> enlace = *puntero;
		*puntero = nuevo;
	}else{
		nuevo -> matricula = mat; 
		strcpy(nuevo -> nombre,nom);
		nuevo -> edad = ed;
		nuevo -> calificacion = cal;		
		nuevo->enlace = anterior->enlace;
		anterior->enlace = nuevo;	
	}
	return;
}
void imprimirLista(struct alumno **puntero){
	struct alumno* actual; //Se declara la variable puntero actual
	actual = *puntero;
	puts("D A T O S  D E   L O S  A L U M N O S: ");
	while (actual != NULL){
		printf("Matrícula: %d \n",actual->matricula);
		puts(actual ->nombre);
		printf("Edad: %d \n",actual->edad);
		printf("Calificación: %f \n",actual->calificacion);
		actual = actual->enlace;
	}
	return;
}

void imprimirDatosAlumnoMayorCalificacion(struct alumno **puntero){
	float mayorCalificacion = 0;
	struct alumno* actual; //Se declara la variable puntero actual
	actual = *puntero;
	
	//Se recorre la lista para encontrar la mayor calificación
	while (actual != NULL){
		if (actual-> calificacion > mayorCalificacion){
			mayorCalificacion = actual->calificacion;
		}
		actual = actual->enlace;
	}
	
	//Se recorre la lista para encontrar a los alumnos con la calificación anterior
	puts("\n A L U M N O S  CON  M A Y O R  C A L I F I C A C I O N");
	actual = *puntero;
	while (actual != NULL){
		if (actual -> calificacion == mayorCalificacion){

			printf("Matrícula: %d \n",actual->matricula);
			puts(actual ->nombre);
			printf("Edad: %d \n",actual->edad);
			printf("Calificación: %f \n",actual->calificacion);
		}
		actual = actual->enlace;
	}	
	return;
}
