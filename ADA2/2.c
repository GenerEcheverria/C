//2 Euclides
#include<stdio.h>
#include<stdlib.h>
int main (){
	int primerNumero, segundoNumero, dividendo, divisor,resto=1, cociente, resultado,aux;
	printf("Escribe el valor del primer numero: ");
	scanf("%i",&primerNumero);
	printf("Escribe el valor del segundo numero: ");
	scanf("%i",&segundoNumero);
	if (primerNumero>segundoNumero){
		dividendo=primerNumero;
		divisor=segundoNumero;
	}
	else {
		dividendo=segundoNumero;
		divisor=primerNumero;
	}
	while(resto!=0){
		resto=dividendo%divisor;
		dividendo=divisor;
		aux=divisor;
		divisor=resto;
	}
	printf("El MCD es: %i \n",aux);
	system("pause");
	return 0;
}

