/*Nombre Gener Alejandro Echeverria Chi
Fecha: 01/06/2020
a) Crear una lista con cinco alumnos ordenados por matrícula. 
b) Imprimir los datos de todos los alumnos de la lista. 
c) Imprimir los datos del alumno con mayor calificación. */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct alumno {
	int matricula;
	char nombre[50];
	int edad;
	float calificacion;
	struct alumno* enlace;
};
struct alumno* cabecera=NULL;
void insertarAlumno(int matri, char nom[],int ed, float calif);
void imprimirLista(struct alumno*);
void imprimirMayor(struct alumno*);
int main (){
	int matricula, i;
	char nombre[50];
	int edad;
	float calificacion;
	for (i=0;i<5;i++){
		printf("Escribe la matricula del alumno %d: ",i+1);
		scanf("%d",&matricula);
		printf("Escribe el nombre del alumno %d: ",i+1);
		fflush(stdin);
		gets(nombre);
		printf("Escribe la edad del alumno %d: ",i+1);
		scanf("%d",&edad);
		printf("Escribe la calificacion del alumno %d: ",i+1);
		scanf("%f",&calificacion);
		insertarAlumno(matricula,nombre,edad,calificacion);
		system("cls");
		imprimirLista(cabecera);
	}
	printf("\n");
	imprimirMayor(cabecera);
	system("pause");
	return 0;
}
void insertarAlumno(int matri, char nom[],int ed, float calif){
	struct alumno* nuevo;
	nuevo = (struct alumno*)malloc(sizeof(struct alumno));
	nuevo->matricula=matri;
	strcpy (nuevo->nombre,nom);
	nuevo->edad=ed;
	nuevo->calificacion=calif;
	nuevo->enlace=NULL;
	if (cabecera==NULL){
		cabecera=nuevo;
	} 
	else {
		if (matri<cabecera->matricula){
			nuevo->enlace=cabecera;
			cabecera=nuevo;
		}
		else {
			struct alumno* actual=cabecera;
			struct alumno* anterior=cabecera;
			while (matri>=actual->matricula && actual->enlace!=NULL){
				anterior=actual;
				actual=actual->enlace;
			}
			if (matri>=actual->matricula){
				actual->enlace=nuevo;
			}
			else {
				nuevo->enlace=actual;
				anterior->enlace=nuevo;
			}
			
		}
		
	}
}
void imprimirLista(struct alumno* cabecera){
	struct alumno* actual;
	actual=cabecera;
	puts("MATRICULA\tNOMBRE\t\tEDAD\t\tCALIFICACION");
	while (actual!=NULL){
		printf("%d\t\t",actual->matricula);
		printf("%s\t\t",actual->nombre);
		printf("%d\t\t",actual->edad);
		printf("%.2f",actual->calificacion);
		printf("\n");
		actual=actual->enlace;
	}
}
void imprimirMayor(struct alumno* cabecera){
	struct alumno* actual;
	float a,b;
	a=b=0;
	actual=cabecera;
	while(actual!=NULL){
		a=actual->calificacion;
		if (a>b){
			b=a;
		}
		actual=actual->enlace;
	}
	actual=cabecera;
	puts("\t\tALUMNO CON MAYOR CALIFICACION");
	puts("MATRICULA\tNOMBRE\t\tEDAD\t\tCALIFICACION");
	while (actual!=NULL){
		if(actual->calificacion==b){
			printf("%d\t\t",actual->matricula);
			printf("%s\t\t",actual->nombre);
			printf("%d\t\t",actual->edad);
			printf("%.2f",actual->calificacion);
			printf("\n");
			break;
		}
		actual=actual->enlace;
	}
}
