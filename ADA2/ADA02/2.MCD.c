#include <stdio.h>
//Gener Echeverria y Valeria Gonzalez
int main () {
	int a;
	int b;
	int mayor;
	int menor;
	int resto=1;
	int aux;
	printf("Inserta el primer numero: ");
	scanf("%i",&a);
	printf("Inserta el segundo numero: ");
	scanf("%i",&b);
	if (a<b) {
		mayor=b;
		menor=a;
	} else {
		if (a>b) {
			mayor=a;
			menor=b;
			
		} 
	}
	while(resto!=0) {
		resto=mayor%menor;
		mayor=menor;
		aux=menor;
		menor=resto;
	}
	printf("El MCD es: %i",aux);
	return 0;
}
