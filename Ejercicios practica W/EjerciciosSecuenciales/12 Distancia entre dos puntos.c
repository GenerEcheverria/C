//distancia entre dos puntos
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main (){
	float x1,y1,x2,y2, distancia;
	puts("Valor de x del primer punto");
	scanf("%f",&x1);
	puts("Valor de y del primer punto");
	scanf("%f",&y1);
	puts("Valor de x del segundo punto");
	scanf("%f",&x2);
	puts("Valor de y del segundo punto");
	scanf("%f",&y2);
	distancia=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	printf("La distancia entre (%.2f,%.2f) y (%.2f,%.2f) es %.2f\n", x1,y1,x2,y2,distancia);
	system("pause");
	return 0;
}
