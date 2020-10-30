#include<stdio.h>
//bisiesto
int main () {
	int a;
	
	printf("Escribe el año: ");
	scanf("%i", &a);
	
	if (a%100==0) {
		if (a%400==0) {
			printf("%i es bisiesto", a);
		}
		else {
			printf("%i no es bisiesto", a);
		}
	}
	else {
		if (a%4==0) {
			printf("%i es bisiesto", a);
		}
		else {
			printf("%i no es bisiesto", a);
		}
	}
	printf("\n %d", sizeof(short)); //espacio de memoria
	
	return 0;
}
