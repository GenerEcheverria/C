//serie4
#include<stdlib.h>
#include<stdio.h>

int main () {
	float x;
	float n;
	float numerador;
	float resultado;
	int i;
	
	printf ("Escribe el valor de la base: ");
	scanf("%f", &x);
	printf ("Escribe el valor de la potencia: ");
	scanf("%f", &n);
	
	numerador=1;
	for (i=1;i<=n;i++) {
		numerador=numerador*x;
		if (i%2==0) {
			resultado=resultado-(numerador/i);
		}
		else {
			resultado=resultado+(numerador/i);
		}
	}
	
	printf("El resultado es %.2f \n", resultado);	
	
	
	system("pause");
	return 0;
}
