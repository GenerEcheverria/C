#include<stdio.h>
#include<stdlib.h>
int main () {
	float segundos, kilometros, vueltas;
	puts("Escribe el numero de segundos");
	scanf("%f",&segundos);
	kilometros=300000*segundos;
	vueltas=kilometros/3571.3;
	printf ("Kilometros recorridos: %.2f\n Vueltas recorridas: %.2f\n", kilometros,vueltas);	
	system("pause");
	return 0;
}
