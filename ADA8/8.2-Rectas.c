/*Nombre Gener Alejandro Echeverria Chi
Fecha: 01/06/2020
a)Crear una lista de cinco estructuras recta.
b) Mostrar los puntos de intersección de cada recta representada de la lista con las demás restantes. En el caso de que dos rectas sean paralelas indicarlo. */
#include<stdio.h>
#include<stdlib.h>
struct coordenada {
	double x;
	double y;
};
struct recta {
    struct coordenada punto;       
	double pendiente;
	struct recta* enlace; 
};
struct recta* cabecera=NULL;
void insertarRecta(double x, double y,double pendiente);
void imprimirLista(struct recta*);
double imprimirRecta(struct recta*);
void encontrarInterseccion(struct recta*, struct recta*,double d1, double d2);
int main (){
	int i,j;
	double x,y,pendiente;
	for (i=0;i<5;i++){
		printf("Escribe el valor de 'x' de la recta %d: ", i+1);
		scanf("%lf",&x);
		printf("Escribe el valor de 'y' de la recta %d: ", i+1);
		scanf("%lf",&y);
		printf("Escribe el valor de pendiente de la recta %d: ", i+1);
		scanf("%lf",&pendiente);
		insertarRecta(x,y,pendiente);
		system("cls");
		imprimirLista(cabecera);
	}
	struct recta* rec1;
	struct recta* rec2;
	int d1,d2;
	rec1=cabecera;
	i=0;
	while(rec1!=NULL){
		rec2=cabecera;
		j=0;
		while (rec2!=NULL){
			if ((i==0&&j==1)||(i==0&&j==2)||(i==0&&j==3)||(i==0&&j==4)||(i==1&&j==2)||(i==1&&j==3)||(i==1&&j==4)||(i==2&&j==3)||(i==2&&j==4)||(i==3&&j==4)){
				puts("\t COMPARAR");
				d1=imprimirRecta(rec1);
				printf("\n");
				d2=imprimirRecta(rec2);
				printf("\n");
				if (rec1->pendiente==rec2->pendiente){
					puts("Las rectas son paralelas");
					puts("-------------------------------");
				}
				else{
					encontrarInterseccion(rec1,rec2,d1,d2);
					puts("-------------------------------\n");
				}
			}
			j++;
			rec2=rec2->enlace;
		}
		i++;
		rec1=rec1->enlace;
	}
	
	
	system("pause");
	return 0;
}
void insertarRecta(double x, double y,double pendiente){
	struct recta* nuevo;
	struct recta* actual;
	struct recta* anterior;
	nuevo=(struct recta*)malloc(sizeof(struct recta));
	nuevo->punto.x=x;
	nuevo->punto.y=y;
	nuevo->pendiente=pendiente;
	nuevo->enlace=NULL;
	if (cabecera==NULL){
		cabecera=nuevo;
	}
	else {
		actual=cabecera;
		anterior=NULL;
		while (actual!=NULL){
			anterior=actual;
			actual=actual->enlace;
		}
		anterior->enlace=nuevo;
	}
}
void imprimirLista(struct recta* cabecera){
	struct recta* actual;
	actual=cabecera;
	int i=1;
	puts("RECTA\t X\t Y\tPENDIENTE\tRECTA");
	while (actual!=NULL){
		printf("%d\t", i);
		i++;
		printf("%.2lf\t",actual->punto.x);
		printf("%.2lf\t",actual->punto.y);
		printf("%.2lf\t\t",actual->pendiente);
		imprimirRecta(actual);
		printf("\n");
		actual=actual->enlace;
	}
}
double imprimirRecta(struct recta* rect){
	double d;
	d=rect->punto.y-rect->pendiente*rect->punto.x;//creo que es resta
	printf("y = %.2lfx + %.2lf", rect->pendiente,d);
	return d;
}
void encontrarInterseccion(struct recta* rect1, struct recta* rect2,double d1, double d2){
	double x,y1,y2,xValor;
	x=rect1->pendiente-rect2->pendiente;
	xValor=d2-d1;
	if (x==1){
		x=xValor;
	}
	else {
		if (x==-1){
			x=-xValor;
		}
		else {
			if (x>1){
				x=xValor/x;
			}
			else {
				x=xValor/(-x);
			}
		}
	}
	y1=rect1->pendiente*x+d1;
	y2=rect2->pendiente*x+d2;
	if (y1==y2){
		printf("Las rectas se intersectan en el punto (%.2lf,%.2lf)\n", x,y1);
	}
	else {
		puts ("Las rectas no se intersectan\n");
	}
}
