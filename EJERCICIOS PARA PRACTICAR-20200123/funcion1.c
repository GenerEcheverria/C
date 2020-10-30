//Exponencial
#include<stdio.h>
#include<stdlib.h>
float potencia(float base, float i);
float factorial (float i);
int main (){
	float i, base, exponente, resultado =1;
	printf("Escribe el valor de x: ");
	scanf("%f", &base);
	printf("Escribe el valor de n: ");
	scanf("%f", &exponente);
	
	for (i=1;i<=exponente;i++) {
		resultado += (potencia(base,i)/factorial(i));
	}
	printf("El resultado es: %.5f\n", resultado );
	system("pause");
	return 0;
}

float potencia(float base,float i) {
	float a, pot =1;
	for (a=1;a<=i;a++) {
		pot*=base;
	}
	return (pot);	
}
float factorial (float i) {
	float b, fact=1;
	for (b=1;b<=i;b++) {
		fact*=b;
	}
	return (fact);
}
	
