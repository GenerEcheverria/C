#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct cliente {
	int claveEntera;
	char nombre[50];
	int montoFacturado;
	char estado[20];
	struct cliente *siguiente;
};
struct cliente* cabecera=NULL;
void nuevoCliente3(int i);
void imprimirMorosos();
void imprimirPagado(int monto);
int comparar(char uno[],char dos[]);
int main (){
	int i;
	int monto;
	for (i=0;i<3;i++){
		nuevoCliente3(i);
	}
	puts("\nClientes morosos:");
	imprimirMorosos();
	puts("Cantidad de factura:");
	scanf("%d",&monto);
	printf("\nClentes con factura pagada mayor a %d\n",monto);
	imprimirPagado(monto);
	return 0;
}
void nuevoCliente3(int i){
	struct cliente *nuevo;
	nuevo=(struct cliente*)malloc(sizeof(struct cliente));
		system("cls");
		printf("Escribe la clave entera del cliente %d: ",i+1);
		scanf("%d",&nuevo->claveEntera);
		printf("Escribe el nombre del cliente %d: ",i+1);
		fflush(stdin);
		gets(nuevo->nombre);
		printf("Escribe el monto facturado del cliente %d: ",i+1);
		scanf("%d",&nuevo->montoFacturado);
		printf("Escribe el estado del cliente %d: ",i+1);
		fflush(stdin);
		gets(nuevo->estado);
		nuevo->siguiente=NULL;
		if (cabecera==NULL){
			cabecera=nuevo;
		}
		else {
			struct cliente *actual,*anterior;
			anterior=actual=cabecera;
			while(actual!=NULL){
				anterior=actual;
				actual=actual->siguiente;
			}
			anterior->siguiente=nuevo;
		}
}
void imprimirMorosos(){
	struct cliente *actual;
	char mor[]="moroso";
	int i=0;
	actual=cabecera;
	while (actual!=NULL){
		if (strcmp(actual->estado,mor)==0){
			printf("\tCliente %d\n",i+1);
			printf("Clave: %d\n",actual->claveEntera);
			printf("Nombre: %s\n",actual->nombre);
			printf("Monto facturado: %d\n",actual->montoFacturado);
			printf("Estado: %s\n", actual->estado);
			puts("---------------------");
		}
		i++;
		actual=actual->siguiente;
	}
}
void imprimirPagado(int monto){
	struct cliente *actual;
	char mor[]="pagado";
	int i=0;
	actual=cabecera;
	while (actual!=NULL){
		if (/*strcmp(actual->estado,mor)==0*/comparar(mor,actual->estado)==0&&actual->montoFacturado>monto){
			printf("\tCliente %d\n",i+1);
			printf("Clave: %d\n",actual->claveEntera);
			printf("Nombre: %s\n",actual->nombre);
			printf("Monto facturado: %d\n",actual->montoFacturado);
			printf("Estado: %s\n", actual->estado);
			puts("---------------------");
		}
		i++;
		actual=actual->siguiente;
	}
}
int comparar (char uno[],char dos[]){
	int i=0,auxiliar=0;
	while (uno[i]!='\0'){
		if(uno[i]!=dos[i]){
			auxiliar++;
		}
		i++;
	}
	return auxiliar;
}
