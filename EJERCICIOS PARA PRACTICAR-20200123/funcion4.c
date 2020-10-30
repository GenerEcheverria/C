#include<stdlib.h>
#include<stdio.h>
float potencia (float x, float i);
int main (){
	float x, n, resultado, numerador;
	int i;
	printf ("Escribe el valor de la base: ");
	scanf("%f", &x);
	printf ("Escribe el valor de la potencia: ");
	scanf("%f", &n);
	for (i=1;i<=n;i++){
		numerador = potencia(x,i);
		if (i%2==0) {
			resultado-=(numerador/i);
		}
		else {
			resultado+=(numerador/i);
		}
		
	}
	printf("El resultado es %.5f \n", resultado);	
	system("pause");
	return 0;
}
float potencia(float x, float i){
	int a;
	float num=1;
	for (a=1;a<=i;a++){
		num*=x;
	}
	return num;
}
