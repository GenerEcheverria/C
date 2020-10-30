//horas a minutos y segundos
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main (){
	float horas, minutos, segundos;
	double entero, decimal;
	puts("Cantidad de horas:");
	scanf("%f", &horas);
	minutos=horas*60;
	segundos=minutos*60;
	printf("%.2f minutos\n%.2f segundos\n",minutos, segundos);
	decimal=modf(minutos,&entero);
	decimal*=60;
	printf("%.0f:%.0f\n",entero,decimal);	
	system("pause");
	return 0;
}
