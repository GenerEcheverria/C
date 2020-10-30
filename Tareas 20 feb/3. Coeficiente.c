//Coeficiente binomio
#include<stdio.h>
#include<stdlib.h>
float factorial (int x);
int main (){
	int m,n;
	float coeficiente;
	puts("Escribe el valor de m: ");
	scanf("%i", &m);
	puts("Escribe el valor de n: ");
	scanf("%i", &n);
	coeficiente= factorial(m)/(factorial(n)*factorial(m-n));
	printf("El valor del coeficiente es: %.2f\n", coeficiente);
	system("pause");
	return 0;
}
float factorial (int x){
	int i;
	float fact=1;
	for (i=x;i>1;i--){
		fact*=i;
	}
	return fact;
}
