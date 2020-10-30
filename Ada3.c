#include<stdio.h>
void funcion1 ();
void funcion2 ();
void funcion3 ();
int perfecto(int x);
int numero;
int main (){
	int opcion;
	do {
		puts("Escribe el numero de la funcion que deseas:\n 1. Determinar pares e impares\n 2.Primeros 3 numeros perfectos\n 3. Invertir digitos\n 4. Salir\n");
		scanf("%i",&opcion);
		system ("cls");
		switch (opcion) {
			case 1: funcion1(); break;
			case 2: funcion2(); break;
			case 3: funcion3(); break;
		}
	}while (opcion !=4);
	return 0;
}
void funcion1 (){
	int i;
	for (i=1;i<=10;i++){
		puts("Escribe el numero:");
		scanf("%i",&numero);
		
		if (numero%2==0){
			printf("%i es par\n",numero);
		}
		else {
			printf("%i es impar\n",numero);
		}
	}
}
void funcion2 (){
	int contadorPerfecto=0, i=2,j;
	while (contadorPerfecto<=2){
		if (perfecto (i)==i){
			printf("%i es perfecto\n", i);
			contadorPerfecto++;
		}
		i++;		
	}
}
int perfecto(int x){
	int suma=0,j;
	for (j=1;j<x;j++){
		if (x%j==0){
			suma+=j;
		}
	}
	return suma;
}
void funcion3 (){
	int digito;
	puts("Escribe el numero a invertir:");
	scanf("%i",&numero);
	while (numero>0){
		digito=numero%10;
		printf("%i",digito);
		numero-=digito;
		numero/=10;
	}
	puts("\n");
}
