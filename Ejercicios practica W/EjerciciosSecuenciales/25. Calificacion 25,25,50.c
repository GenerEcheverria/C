//calificacion 25,25,50
#include<stdio.h>
#include<stdlib.h>
int main (){
	float examen1,examen2, examen3, total;
	puts("Calificacion del primer examen");
	scanf("%f",&examen1);
	puts("Calificacion del segundo examen");
	scanf("%f",&examen2);
	puts("Calificacion del tercer examen");
	scanf("%f",&examen3);
	total=examen1*.25+examen2*.25+examen3*.50;
	printf("Calificacion final: %.2f",total);
	system("pause");
	return 0;
}
