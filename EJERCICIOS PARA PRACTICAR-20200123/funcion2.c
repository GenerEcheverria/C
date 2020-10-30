#include<stdio.h>
#include<stdlib.h>
float potenciaPar(float x, float i);
float factorial (float i);
int main (){
	float x, n, resultado=1, numerador, denominador;
	int i;
	printf ("Escribe el valor de x: ");
	scanf("%f", &x);
	printf ("Escribe el valor de n: ");
	scanf("%f", &n);
	for (i=1;i<=n;i++){
		numerador= potenciaPar(x,i);
		denominador= factorial(i);
		if (i%2==0) {
			resultado+=(numerador/denominador);
		}
		else {
			resultado-=(numerador/denominador);
		}
	}
	printf("El resultado es: %.5f\n", resultado );
	system("pause");
	return 0;
}
float potenciaPar (float x, float i) {
	float num = 1;
	int a;
	for (a=1;a<=i;a++){
		num*=x*x;
	}
	return (num);
}
float factorial (float i) {
	float den=1;
	int b;
	for (b=1;b<=i;b++) {
		den*=b;
	}
	return (den);
}
