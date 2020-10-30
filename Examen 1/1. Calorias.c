//Peso ideal
//Gener Echeverria
//05/03/2020
#include<stdio.h>
float calcularPeso(float altura);
void calcularCaloriasPorGradoActividad(float peso);
int main (){
	float h,w, actividad;
	int la;
	puts("Escribe tu altura");
	scanf("%f",&h);
	w=calcularPeso(h);
	printf("Peso ideal=%.2f kg\n",w);
	calcularCaloriasPorGradoActividad(w);
	return 0;
}
float calcularPeso(float altura) {
	float peso;
	peso= altura*31;
	return peso;
}
void calcularCaloriasPorGradoActividad(float peso) {
	printf("Calorias por actividad:\n Muy ligera=%.1f cal\n Ligera=%.1f cal\n Moderada=%.1f cal\n Pesada=%.1f cal\n", peso*30*7,peso*32*7, peso*34*7, peso*37*7);
}
