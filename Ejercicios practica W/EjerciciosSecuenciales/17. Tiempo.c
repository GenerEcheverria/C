//tiempo 
#include<stdio.h>
#include<stdlib.h>
int main (){
	float velocidad, distancia, tiempo;
	puts("Velocidad en km/h");
	scanf("%f", &velocidad);
	puts("Distancia en km");
	scanf("%f", &distancia);
	tiempo=velocidad/distancia;
	printf("Recorrera %.2f km en %.2f horas\n", distancia, tiempo);
	system ("pause");
	return 0;
}
