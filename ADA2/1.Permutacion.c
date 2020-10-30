//1 Permutacion
//Gener Echeverria y Valeria Gonzalez
#include<stdio.h>
#include<stdlib.h>
int factorial (int n);
int main(){
	int m,r,n,numerador,denominador,resultado;
	printf("Escribe el valor de m: ");
	scanf("%i",&m);
	printf("Escribe el valor de r: ");
	scanf("%i",&r);
	n=m;
	numerador= factorial(n);
	n=m-r;
	denominador= factorial(n);
	resultado=numerador/denominador;
	printf("El resultado es: %i\n",resultado);
	system ("pause");
	return 0;
}
int factorial (int n){
	int i, res=1;
	for (i=1;i<=n;i++) {
		res*=i;
	}
	return res;
}
