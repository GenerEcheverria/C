//aX2 + bX + c   
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void formulaGeneral(float a, float b, float c);
int main (){
	float a,b,c;
	puts ("Dame el valor de a");
	scanf("%f",&a);
	puts ("Dame el valor de b");
	scanf("%f",&b);
	puts ("Dame el valor de c");
	scanf("%f",&c);
	formulaGeneral(a,b,c);
	system("pause");
	return 0;
}
void formulaGeneral(float a, float b,float c){
	float x1,x2,aux;
	aux=b*b-(4*a*c);
	if (aux<0){
		printf("x1 = (%.1f+sqrt(%.2f))/%.2f\n", -b, aux,2*a );
		printf("x2 = (%.1f-sqrt(%.2f))/%.2f", -b, aux,2*a );
	}
	else {
		x1=(-b+sqrt(b*b-(4*a*c)))/2*a;
		x2=(-b-sqrt(b*b-(4*a*c)))/2*a;
		printf("El valor de x1 es: %.2f\nEl valor de x2 es %.2f\n", x1,x2);
	}
}

