//calificacio
#include<stdio.h>
int main (){
	float cal1,cal2,cal3,cal4,promedio;
	char nombre[40];
	puts("Nombre");
	gets(nombre);
	puts("Calificacion primer parcial");
	scanf("%f",&cal1);
	puts("Calificacion segundo parcial");
	scanf("%f",&cal2);
	puts("Calificacion tercer parcial");
	scanf("%f",&cal3);
	puts("Calificacion cuarto parcial");
	scanf("%f",&cal4);
	promedio=(cal1+cal2+cal3+cal4)/4;
	puts(nombre);
	printf("Promedio: %.2f\n", promedio);
	if (promedio>=70) {
		puts("Aprobado");
	}
	else{
		puts("Reprobado");
	}
	return 0;
}
