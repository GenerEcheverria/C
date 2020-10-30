//area del triangulo
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float pe (float a, float b, float c);
float area (float p, float a, float b, float c);
int main (){
	float p,a,b,c;
	puts("Escribe el valor de a: ");
	scanf("%f",&a);
	puts("Escribe el valor de b: ");
	scanf("%f",&b);
	puts("Escribe el valor de c: ");
	scanf("%f",&c);
	p=pe(a,b,c);
	printf("El resultado es %.2f\n", area (p,a,b,c));
	system("pause");
	return 0;
}
float pe (float a, float b, float c){
	float p;
	p=(a+b+c)/2;	
	return p;
}
float area(float p, float a,float b, float c){
	float ar;
	ar=sqrt(p*(p-a)*(p-b)*(p-c));
	return ar;
}
