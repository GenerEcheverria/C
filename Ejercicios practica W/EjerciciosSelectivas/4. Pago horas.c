//pago horas extra
#include<stdio.h>
int main (){
	int horas,pago; 
	do {
		puts("Numero de horas trabajadas (Maximo 12)");
		scanf("%i",&horas);
		system("cls");
	} while (horas>12 || horas<1);
	if (horas>8){
		pago=(8*150)+(horas-8)*300;
	}
	else {
		pago= horas*150;
	}
	printf("Pago: $%i",pago);
	return 0;
}
