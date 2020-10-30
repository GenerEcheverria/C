//extra
#include<stdio.h>
#include<stdlib.h>
int main (){
	float x; //numero
	float n; //potencia
	float i; //contador
	float c; //contador 2
	float y=1; //resultado
	float numerador; 
	float denominador; 
	
	//entrada
	printf("Escribe el numero base: ");
	scanf("%f", &x);
	printf("Escribe la potencia: ");
	scanf("%f", &n);
	
	//proceso
	denominador = 1;
	for (i=1; i<=n; i++) {
		numerador=1;
		for (c=1;c<=i;c++) {
			numerador = numerador*x;
		}
		denominador=denominador*i;
		y = y + (numerador/denominador);
	}
	
	//salida
	printf("El resultado es %.2f \n", y);


	system("pause");
	return 0;
}	
