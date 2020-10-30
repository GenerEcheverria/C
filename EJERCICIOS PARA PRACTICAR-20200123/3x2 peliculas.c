#include<stdio.h>
int main (){
	int i;
	float pelicula1, pelicula2, pelicula3, aux, pago;
	puts("Precio de la pelicula 1");
	scanf("%f",&pelicula1);
	puts("Precio de la pelicula 2");
	scanf("%f",&pelicula2);
	puts("Precio de la pelicula 3");
	scanf("%f",&pelicula3);
	for (i=1;i<=2;i++){
		if (pelicula3>pelicula2){
			aux=pelicula2;
			pelicula2=pelicula3;;
			pelicula3=aux;
		}
		if (pelicula2>pelicula1){
			aux=pelicula1;
			pelicula1=pelicula2;
			pelicula2=aux;
		}
	}
	pago=pelicula3+pelicula2;
	printf("Pago=$%.2f",pago);
	return 0;
}
