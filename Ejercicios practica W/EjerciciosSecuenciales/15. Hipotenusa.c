//hipotenusa
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main (){
	float a,b,c;
	puts("Valor del primer cateto");
	scanf ("%f",&a);
	puts("Valor del segundo cateto");
	scanf ("%f",&b);
	c=sqrt(a*a+b*b);
	printf("La hipotenusa vale %.2f\n", c);
	system("pause");
	return 0;
}
