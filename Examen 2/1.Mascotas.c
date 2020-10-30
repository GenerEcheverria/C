//Gener Echeverria
//24/06/2020
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct mascota {
	int claveEntera;
	char tipo[30];
	char nombre[30];
	int meses;
	struct mascota *siguiente;
};
struct mascota *cabecera=NULL;
void agregar3();
void nuevaMascota(int i);
void imprimirPerro();
void imprimirPajaro();
int main (){
	agregar3();
	puts("\n\n");
	imprimirPerro();
	puts("\n\n");
	imprimirPajaro();
}
void agregar3(){
	int i;
	puts("\t---AGREGAR MASCOTA---\n");
	for (i=0;i<3;i++){
		nuevaMascota(i);
	}
}
void nuevaMascota(int i){
	struct mascota *nuevo;
	nuevo=(struct mascota*)malloc(sizeof(struct mascota));
	printf("Escribe la clave entera de la mascota %d\n",i+1);
	scanf("%d",&nuevo->claveEntera);
	printf("Escribe el tipo de la mascota %d\n",i+1);
	fflush(stdin);
	gets(nuevo->tipo);
	printf("Escribe el nombre de la mascota %d\n",i+1);
	fflush(stdin);
	gets(nuevo->nombre);
	printf("Escribe los meses de edad de la mascota %d\n",i+1);
	scanf("%d",&nuevo->meses);
	puts("--------------------------------");
	nuevo->siguiente=NULL;
	if (cabecera==NULL){
		cabecera=nuevo;
	}
	else {
		struct mascota *actual,*anterior;
		actual=anterior=cabecera;
		while (actual!=NULL){
			anterior=actual;
			actual=actual->siguiente;
		}
		anterior->siguiente=nuevo;
	}
	
}
void imprimirPerro(){
	struct mascota *actual;
	char mas[]="perro";
	int i=0,aux;
	actual=cabecera;
	puts("  -----LISTA DE MASCOTAS 'Perro'-----\n");
	while(actual!=NULL){
		if (strcmp(actual->tipo,mas)==0){
			printf("\t Mascota %d\n", i+1);
			printf("Clave: %d\n",actual->claveEntera);
			printf("Tipo: %s\n",actual->tipo);
			printf("Nombre: %s\n",actual->nombre);
			printf("Meses: %d\n",actual->meses);
			puts("------------------------------");
			aux++;
		}
		i++;
		actual=actual->siguiente;
	}
	if (aux==0){
		puts("No hay mascotas de tipo perro");
	}
}
void imprimirPajaro(){
	struct mascota *actual;
	char mas[]="pajaro";
	int i=0,aux;
	actual=cabecera;
	puts("  -----LISTA DE MASCOTAS 'Pajaro' MAYORES A 12 MESES-----\n");
	while(actual!=NULL){
		if (strcmp(actual->tipo,mas)==0&&actual->meses>12){
			printf("\t Mascota %d\n", i+1);
			printf("Clave: %d\n",actual->claveEntera);
			printf("Tipo: %s\n",actual->tipo);
			printf("Nombre: %s\n",actual->nombre);
			printf("Meses: %d\n",actual->meses);
			puts("------------------------------");
			aux++;
		}
		i++;
		actual=actual->siguiente;
	}
	if (aux==0){
		puts("No hay mascotas de tipo pajaro mayores a 12 meses");
	}
}
