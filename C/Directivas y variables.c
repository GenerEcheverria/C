//Directivas del procesador y variables 
#include<stdio.h> //libreria 

#define PI 3.1416 //macro

int y = 5; //variable global

int main(){
	
	int x = 10; //variable local

	int suma = 0;
	suma = PI + x; 
	printf("La suma es %i",suma); //enteros
	
	float sumad = 0;
	sumad = PI + x; 
	printf("La suma es %f",sumad); //decimales
	printf("La suma es %.2f",sumad); //numero de decimales 
	
	return 0;
}
