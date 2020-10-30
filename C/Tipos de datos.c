//Tipos de variables
#include<stdio.h>
int main() {
	char b = 'F'; //1byte Rango: 0...255 %c
	short c = -15; //2bytes Rango: -128...127 %i
	int d = 1024; //2bytes Rango: -32768...32767 %i
	unsigned int e = 128; //2bytes  Rango: 0...65535 %i
	long f = 123456; //4bytes %li
	float g = 15.678; //4bytes %f
	double h = 123123.123123; //8bytes %lf  %.lf transforma a entero
	
	printf("El elemento es: %c",b);
	
	return 0;
}
