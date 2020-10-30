/*ADA7
Ejercicio 3
Autor: Gener Echeverria
Fecha: 30/04/2020*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct temperaturas {
	float maxima;
	float minima;
} vector[10];
void guardar (struct temperaturas vector[10]);
void farenheit (struct temperaturas vector[10]);
int main (){
	guardar (vector);
	farenheit(vector);
	system("pause");
	return 0;
}
void guardar (struct temperaturas vector[10]){
	int i;
	srand(time(NULL));
	for (i=0;i<10;i++){
		vector[i].maxima=rand()%41;
		do {
			vector[i].minima=rand()%41;
		} while (vector[i].minima>=vector[i].maxima);
	}
}
void farenheit (struct temperaturas vector[10]){
	int i;
	float max, min;
	for (i=0;i<10;i++){
		max=vector[i].maxima*9/5+32;
		printf("Temperatura maxima [%d]: %.2f*F \n",i+1,max);
		min=vector[i].minima*9/5+32;
		printf("Temperatura minima [%d]: %.2f*F \n",i+1,min);
		puts("------------------------------");
	}
}
