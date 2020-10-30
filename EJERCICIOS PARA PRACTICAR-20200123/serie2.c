//serie2
#include<stdio.h>
#include<stdlib.h>
int main (){
	float x;
	float n;
	float numerador;
	float denominador;
	float resultado;
	int i; 
	
	printf ("Escribe el valor de la base: ");
	scanf("%f", &x);
	printf ("Escribe el valor de la potencia: ");
	scanf("%f", &n);
	
	numerador=denominador=resultado=1;
	for(i=1;i<=n;i++) {
		numerador=numerador*x*x;
		denominador=denominador*i;
		if (i%2==0) {
			resultado=resultado+(numerador/denominador);
		}
		else {
			resultado=resultado-(numerador/denominador);
		}
	}
	
	printf("El resultado es %.2f \n", resultado);	
	
	system("pause");
	return 0;
}
