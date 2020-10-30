#include<stdio.h>
int main(){
	float a;
	float b;
	
	printf("Escribe el primer numero ");
	scanf("%f",&a);
	
	printf("Escribe el segundo numero ");
	scanf("%f",&b);
	
	if (a==b) {
		printf ("Los numeros son iguales");
	}
	else {
		if (a>b) {
			printf("%.2f es mayor \n", a);
			printf("%.2f es menor \n", b);
		}
		else {
			printf("%.2f es mayor \n", b);
		    printf("%.2f es menor \n", a);
		}
	}
	
	return 0;
}
