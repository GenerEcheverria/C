/*ADA7
Ejercicio 3
Autor: Gener Echeverria
Fecha: 30/04/2020*/
#include<stdio.h>
#include<stdlib.h>
struct punto { 
	double x;
	double y;
}punto;  
struct recta { 
     struct punto p;
	 double m; 
}recta;
void guardar(struct recta vector[5]);
double imprimirRecta(struct recta vector [5], int k);
void encontrarInterseccion(struct recta vector[5], int k, int l, double d1, double d2);
int main (){
	int i,j;
	double d1,d2;
	struct recta vector[5];
	guardar (vector);
	system("cls");
	for (i=0;i<5;i++){
		for (j=0;j<5;j++) {
			if ((i==0&&j==1)||(i==0&&j==2)||(i==0&&j==3)||(i==0&&j==4)||(i==1&&j==2)||(i==1&&j==3)||(i==1&&j==4)||(i==2&&j==3)||(i==2&&j==4)||(i==3&&j==4) ){
				puts("------------------------------");
				d1=imprimirRecta(vector,i);
				d2=imprimirRecta(vector,j);
				if (vector[i].m==vector[j].m) {
					puts ("Las rectas son paralelas\n\n");
				}
				else {
					encontrarInterseccion(vector,i,j,d1,d2);
				}
				
			}
		}
	}

	return 0;
}
void guardar(struct recta vector[5]){
    int i;
    for(i=0;i<5;i++){
        printf("Escribe el valor de X de la recta %d: \n",i+1);
        scanf("%lf",&vector[i].p.x);
        printf("Escribe el valor de Y de la recta %d: \n",i+1);
        scanf("%lf",&vector[i].p.y);
        printf("Escribe el valor de la pendiente m de la recta %d: \n",i+1);
        scanf("%lf",&vector[i].m);
    }
}
double imprimirRecta(struct recta vector [5], int k){
    double d;
    d=vector[k].p.y+vector[k].m*vector[k].p.x;
    printf("Recta %d: y = %.1lfx + %.1lf\n",k+1,vector[k].m,d);
    return d;
}
void encontrarInterseccion(struct recta vector[5], int k, int l, double d1, double d2) {
	double x, y1,y2, xValor;
	x=vector[k].m-vector[l].m;
	xValor=d2-d1;
	if (x!=1) {
		if (x<1){
			x=-xValor/x;		
		}
		else {
			x=xValor/x;
		}
	}
	else {
		if (x<1) {
			x=-xValor;
		}
		else {
			x=xValor;
		}
	}
	y1=vector[k].m*x+d1;
	y2=vector[l].m*x+d2;
	if (y1==y2){
		printf("Las graficas se intersectan en el punto (%.2lf,%.2lf)\n\n", x,y1);
	}
	else {
		puts ("Las rectas no se intersectan\n");
	}
}
