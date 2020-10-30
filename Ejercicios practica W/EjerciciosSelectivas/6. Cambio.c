//producto y cambio
#include<stdio.h>
int main (){
	int telefono, cargador, estuche;
	float dinero, cambio;
	puts ("Cantidad de dinero disponible");
	scanf("%f",&dinero);
	telefono=dinero/1000;
	cambio=dinero-telefono*1000;
	printf("Puede comprar %i telefonos.\nSu cambio seria %.2f\n", telefono,cambio);
	puts("--------------------------\n");
	cargador=dinero/350;
	cambio=dinero-cargador*350;
	printf("Puede comprar %i cargadores.\nSu cambio seria %.2f\n", cargador,cambio);
	puts("--------------------------\n");
	estuche=dinero/200;
	cambio=dinero-estuche*200;
	printf("Puede comprar %i estuches.\nSu cambio seria %.2f\n", estuche,cambio);
	return 0;
}
