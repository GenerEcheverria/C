//serie
//Gener Echeverria
//05/03/2020
#include<stdio.h>
float calcularPotencia(float base, int exponente); 
int calcularFactorial (int numero); 
float calcularSerie(float x, int n);
int main (){
	float x;
	int n;
	puts ("Escribe el valor de x");
	scanf("%f",&x);
	puts ("Escribe el valor de n");
	scanf("%i",&n);
	printf("El valor de y es %.2f",calcularSerie(x,n));
	return 0;
}
float calcularSerie(float x, int n){
	float y=1;
	int i;
	for (i=1;i<=n;i++) {
		if (i%2==0){
			y-=i*calcularPotencia(x,i)/calcularFactorial(i);
		}
		else {
			y+=i*calcularPotencia(x,i)/calcularFactorial(i);
			
		}
	}
	return y;
}
float calcularPotencia(float base, int exponente){
	int i;
	float expo=1;
	for (i=1;i<=exponente;i++){
		expo*=base;
	}
	return expo;
}
int calcularFactorial (int numero){
	int i;
	int fact=1;
	for (i=1;i<=numero;i++){
		fact*=i;
	}
	return fact;
}
