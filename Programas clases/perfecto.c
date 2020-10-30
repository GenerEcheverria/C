//Numero perfecto

#include<stdio.h>

int main() {
	
	int N; //N: Numero
	int suma; //suma: suma de los divisores
	int i; 	 //i: contador 
	
	suma = 0;
	//Entrada
	printf("Escribe un numero entero ");
	scanf("%i",&N);  //leer dato 
	//Proceso
	for(i=1;i<N;i++){ //inicializa contador; condicion; incremento
		if (N % i == 0){
			suma += i; 
		}
	}
	//Salida
	if (suma == N) {
		printf("%i es numero perfecto", N);
	}
	else {
		printf("%i no es numero perfecto", N);
	}
	
	return 0;
}

