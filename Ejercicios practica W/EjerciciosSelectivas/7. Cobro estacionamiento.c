//cobro estacionamiento
#include <stdio.h>
int main (){
	int i, hora, cobro=0;
	puts("Horas");
	scanf("%i",&hora);
	for (i=1;i<=hora;i++){
		if (i<=2){
			cobro+=5; continue;
		}
		if (i<=5){
			cobro+=4; continue;
		}
		if (i<=10){
			cobro+=3; continue;
		}
		if (i>10){
			cobro+=2; continue;
		}
	}
	printf("El cobro total es de $%i",cobro);
	
	
	
	return 0;
}
