#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct persona {
	char nombre[40];
	struct persona *siguiente;
};
struct persona *cabecera=NULL;
void nuevaPersona (char nom[]);
void nuevaPersonaMayor (char nom[]);
void nuevaPersonaMenor (char nom[]);
void borrarPersona (char nom[]);
void borrarPrimero ();
void borrarUltimo ();
void encontrar(char nom[]);
void modificar(char nom[]);
void imprimir();
int main (){
	int opcion;
	char Nombre[40];
	while (opcion!=6){
		puts("----------------------\nEscoge opcion:\n1-Nuevo\n2-Borrar\n3-Buscar\n4-Cambiar\n5-Mostrar\n6-Salir\n-------------------");
		scanf("%d",&opcion);
		system("cls");
		switch (opcion){
			case 1: 
			fflush(stdin);
			gets(Nombre);
			nuevaPersonaMayor(Nombre);
			//nuevaPersonaMenor(Nombre);
			//nuevaPersona(Nombre);
			break;
			case 2: 
			fflush(stdin);
			//gets(Nombre);
			//borrarPersona(Nombre);
			//borrarPrimero();
			borrarUltimo();
			break;
			case 3: 
			fflush(stdin);
			gets(Nombre);
			encontrar(Nombre); 
			break;
			case 4:
			fflush(stdin);
			gets(Nombre);
			modificar(Nombre); 
			break;
			case 5: imprimir(); break;
		}
	}
	
	return 0;
}
void nuevaPersona(char nom[]){
	struct persona *nuevo;
	nuevo=(struct persona*)malloc(sizeof(struct persona));
	strcpy(nuevo->nombre,nom);
	nuevo->siguiente=NULL;
	if (cabecera==NULL){
		cabecera=nuevo;
	}
	else {
		struct persona *actual,*anterior;
		actual=anterior=cabecera;
		while (actual!=NULL){
			anterior=actual;
			actual=actual->siguiente;
		}
		anterior->siguiente=nuevo;
	}
}
void nuevaPersonaMayor(char nom[]){
	struct persona *nuevo;
	nuevo=(struct persona*)malloc(sizeof(struct persona));
	strcpy(nuevo->nombre,nom);
	nuevo->siguiente=NULL;
	if (cabecera==NULL){
		cabecera=nuevo;
	}
	else {
		if (nom[0]<cabecera->nombre[0]){
			nuevo->siguiente=cabecera;
			cabecera=nuevo;
		}
		else {
			struct persona *actual,*anterior;
			actual=anterior=cabecera;
			while (nom[0]>=actual->nombre[0]&&actual->siguiente!=NULL){
				anterior=actual;
				actual=actual->siguiente;
			}
			if (nom[0]>=actual->nombre[0]){
				actual->siguiente=nuevo;
			}
			else {
				nuevo->siguiente=actual;
				anterior->siguiente=nuevo;
			}
		}
	}
}
void nuevaPersonaMenor (char nom[]){
	struct persona *nuevo;
	nuevo=(struct persona*)malloc(sizeof(struct persona));
	strcpy(nuevo->nombre,nom);
	nuevo->siguiente=NULL;
	if (cabecera==NULL){
		cabecera=nuevo;
	}
	else {
		if (nom[0]>cabecera->nombre[0]){
			nuevo->siguiente=cabecera;
			cabecera=nuevo;
		}
		else {
			struct persona *anterior,*actual;
			anterior=actual=cabecera;
			while (nom[0]<=actual->nombre[0]&&actual->siguiente!=NULL){
				anterior=actual;
				actual=actual->siguiente;
			}
			if (nom[0]<=actual->nombre[0]){
				actual->siguiente=nuevo;
			}
			else {
				nuevo->siguiente=actual;
				anterior->siguiente=nuevo;
			}
		}
	}
}
void borrarPrimero (){
	struct persona *auxiliar;
	auxiliar=cabecera;
	if (auxiliar!=NULL){
		cabecera=auxiliar->siguiente;
		free(auxiliar);
	}
}
void borrarUltimo (){
	struct persona *actual,*anterior;
	actual=anterior=cabecera;
	while (actual->siguiente!=NULL){
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
void borrarPersona (char nom[]) {
	int encontrado=0;
	struct persona *actual,*anterior;
	actual=cabecera;
	anterior=NULL;
	if (cabecera!=NULL){
		while (actual!=NULL&&encontrado!=1){
			if (strcmp(actual->nombre,nom)==0){
				if(actual==cabecera){
					cabecera=cabecera->siguiente;
				}
				else {
					anterior->siguiente=actual->siguiente;
				}
				encontrado=1;
			}
			anterior=actual;
			actual=actual->siguiente;
			
		}
	}
	else {
		puts ("No hay datos");
	}
}
void encontrar(char nom[]){
	int encontrado=0;
	struct persona *actual;
	actual=cabecera;
	if (cabecera!=NULL){
		while (actual!=NULL&&encontrado!=1){
			if (strcmp(actual->nombre,nom)==0){
				printf("'%s' Encontrado",nom);				
				encontrado=1;
			}
			actual=actual->siguiente;
		}
		if (encontrado==0){
			printf("'%s' No encontrado",nom);
		}
	}
	else {
		puts("No existe lista");
	}
}
void modificar(char nom[]){
	int encontrado=0;
	struct persona *actual;
	actual=cabecera;
	if (cabecera!=NULL){
		while (actual!=NULL&&encontrado!=1){
			if (strcmp(actual->nombre,nom)==0){
				puts("nuevo");
				gets(actual->nombre);				
				encontrado=1;
			}
			actual=actual->siguiente;
		}
		if (encontrado==0){
			printf("'%s' No encontrado",nom);
		}
	}
	else {
		puts("No existe lista");
	}
}
void imprimir (){
	struct persona *actual;
	actual=cabecera;
	while (actual!=NULL){
		puts(actual->nombre);
		actual=actual->siguiente;
	}
}
