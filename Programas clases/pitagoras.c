#include<stdio.h>
int main() {
	int a;
	int b;
	int c;
	
	printf("Valor del primer cateto: ");
	scanf("%i", &a);
	printf("Valor del segundo cateto: ");
	scanf("%i", &b);
	printf("Valor de la hipotenusa ");
	scanf("%i", &c);
	
	if (a*a+b*b==c*c) {
		printf("Si se cumple la ecuacion de Pitagoras");
	}
	else {
		printf("No se cumple la ecuacion de Pitagoras");
	}
	
	
	
	
	return 0;
}
