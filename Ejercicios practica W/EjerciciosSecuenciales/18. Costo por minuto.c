//costo por llamada 
#include<stdio.h>
#include<stdlib.h>
int main (){
	float tiempo, total, precio;
	puts("Tiempo en minutos");
	scanf ("%f",&tiempo);
	puts ("Precio por minutos");
	scanf("%f",&precio);
	total=tiempo*precio;
	printf("Total a pagar: %.2f\n", total);
	system("pause");
	return 0;
}
