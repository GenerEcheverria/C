//Ejercicio 7
#include<stdio.h>
#include<stdlib.h>

int main (){
	float temperatura;
	float resultado;
	float a0;
	float a1;
	
	printf ("Escribe el valor de la temperatura ");
	scanf("%f", &temperatura);
	
	a0=((4438*18594)-(2731*254932.5))/(5*18594.23-74583.61);
	a1=(5*254932.5-(2731*7458361))/(5*18594.23-74583.61);
	
	resultado=a0+a1*temperatura;
	
	printf("La resistencia es %.2f \n", resultado);
	
	system("pause");
	return 0;
}
