//area region circular
#include<stdio.h>
#include<stdlib.h>
#define pi 3.1416
float area (float r);
int main (){
	float radio1,radio2, region;
	puts("Escribe el radio del circulo interno:");
	scanf("%f",&radio1);
	puts("Escribe el radio del circulo externo:");
	scanf("%f",&radio2);
	//region=area(radio2)-area(radio1);
	printf("El area de la region circular es %.2f\n",area(radio2)-area(radio1));
	system("pause");
	return 0;
}
float area (float r){
	float ar;
	ar=pi*r*r;
	return ar;
}
