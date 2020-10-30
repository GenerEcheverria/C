//costo por km
#include<stdio.h>
#include<stdlib.h>
int main (){
	float precio,km,total;
	puts("Precio por km");
	scanf("%f",&precio);
	puts("km recorridos");
	scanf("%f",&km);
	total=precio*km;
	printf("Total a pagar: $%.2f\n",total);
	system("pause");
	return 0;
}
