#include<stdio.h>
#include<stdlib.h>
float den(float i, float x);
int main (){
	float x,n,denominador,resultado;
	int i;
	printf ("Escribe el valor de la base: ");
	scanf("%f", &x);
	printf ("Escribe el valor de la potencia: ");
	scanf("%f", &n);
	denominador=0;
	resultado=0;
	for (i=1;i<=n;i++) {
		denominador=den(i,x);
		resultado += (1/denominador);
	}
	printf("El resultado es: %.5f\n", resultado );
	system("pause");
	return 0;
}
float den (float i, float x) {
	float potencia=1;
	int a;
	for (a=1;a<=i;a++){
		potencia*=x;
	}
	potencia*=i;
	return potencia;
}
