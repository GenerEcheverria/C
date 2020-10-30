//Dias de la semana
#include<stdio.h>
int main () {
	int dia;
	printf("Escribe el numero correspondiente al dia de la semana: ");
	scanf("%i", &dia);
	switch(dia){
		case 1: printf("Lunes"); break;
		case 2: printf("Martes"); break;
		case 3: printf("Miercoles"); break;
		case 4: printf("Jueves"); break;
		case 5: printf("Viernes"); break;
		case 6: printf("Sabado"); break;
		case 7: printf("Domingo"); break;
		default: printf("Numero incorrecto");
	}
	
	
	return 0;
}
