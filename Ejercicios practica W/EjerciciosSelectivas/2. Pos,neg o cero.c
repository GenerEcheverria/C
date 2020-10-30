//numero positivo,negativo o cero
#include<stdio.h>
int main (){
	int numero;
	puts("Escribe el numero");
	scanf("%i",&numero);
	if (numero>0){
		puts ("positivo");
	}
	else {
		if (numero<0) {
			puts("negativo");
		}
		else {
			puts("cero");
		}
	}
	return 0;
}
