//cronometro
#include<stdio.h>
#include <stdlib.h>
#include<windows.h>

int main(){
	int segundo=0;
	int minuto=0;
	int hora=0;
	
	system("pause ->NUL"); //detiene hasta que se presione una tecla. ->NUL oculta el mensaje
	
	for(;;) {
		if (segundo==60) { 
			minuto++;
			segundo = 0 ;
		}
		if (minuto==60) {
			hora++;
			minuto = 0;
		}
		printf("%02i:%02i:%02i \n", hora, minuto, segundo);
		sleep(1); //libreria windows.h?
		segundo++;
		system("cls"); //limpiar pantalla. Agregar #include <stdlib.h>
		
	}
	

	
	return 0;
}
