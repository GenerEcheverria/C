//litros de un cilindro
#include<stdio.h>
#include<stdlib.h>
#define PI 3.1416
float volumenCilindro(float altura, float area);
float volumenLitros (float volumenCilindro);
int main (){
	float altura, radio;
	puts("Altura del cilindro en cm:");
	scanf("%f",&altura);
	puts("radio de la base del cilindro en cm:");
	scanf("%f",&radio);
	printf("%.2f litros", volumenLitros(volumenCilindro(altura,radio)));
	
	
	return 0;
	system("pause");
}
float volumenCilindro(float altura, float radio){
	float volumen;
	volumen= PI*radio*radio*altura;
	return volumen;
}
float volumenLitros (float volumenCilindro){
	float litros;
	litros=volumenCilindro/1000;
	return litros;
}
