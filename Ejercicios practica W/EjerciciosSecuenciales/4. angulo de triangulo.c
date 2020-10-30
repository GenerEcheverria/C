//tercer angulo de un triangulo 
#include<stdio.h>
#include<stdlib.h>
#define PI 3.1416
int main (){
	float angulo1, angulo2, angulo3, rad;
	puts("Medida del primer angulo");
	scanf("%f", &angulo1);
	puts("Medida del segundo angulo");
	scanf("%f", &angulo2);
	angulo3=180-angulo1-angulo2;
	rad=angulo3*PI/180;
	printf("El tercer angulo mide %.2f grados y %.4f radianes\n", angulo3,rad);
	system ("pause");
	return 0;
}
