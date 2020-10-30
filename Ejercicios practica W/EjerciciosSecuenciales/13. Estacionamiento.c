//cobro estacionamiento
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main (){
	double decimal, entero, costo, horas, total;
	puts("Escribe el costo por hora");
	scanf("%lf",&costo);
	puts("Total de horas");
	scanf("%lf",&horas);
	decimal= modf( horas, &entero);
	total = entero * costo;
	if (decimal>0) {
		total += costo;
	}
	printf("Total a pagar: $%.2lf\n", total);	
	system("pause");
	return 0;
}
