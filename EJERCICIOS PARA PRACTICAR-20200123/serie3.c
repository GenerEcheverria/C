//serie3
#include<stdio.h>
#include<stdlib.h>

int main () {
	float x;
	float n;
	float denominador;
	double resultado;
	int i;
	
	printf ("Escribe el valor de la base: ");
	scanf("%f", &x);
	printf ("Escribe el valor de la potencia: ");
	scanf("%f", &n);
	
	denominador=1;
	resultado=0;
	for (i=1;i<=n;i++) {
		denominador=denominador*x;
		resultado = resultado + (1/(i*denominador));
	}
	
	printf("El resultado es %.2lf \n", resultado);	
	
	system("pause");
	return 0;
}
