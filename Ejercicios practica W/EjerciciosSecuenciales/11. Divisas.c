//divisas 29 de feb 2020
#include<stdio.h>
#include<stdlib.h>
int main (){
	float pesos,dolares,euros, yuanes;
	puts("Escribe la cantidad de pesos a convertir");
	scanf("%f",&pesos);
	dolares=pesos*.051;
	euros=pesos*.046;
	yuanes=pesos*.36;
	printf("%.2f pesos equivale a:\n %.2f dolares\n%.2f euros\n%.2f yuanes",pesos, dolares, euros, yuanes);
	system("pause");
	return 0;
}
