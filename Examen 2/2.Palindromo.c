//Gener Echeverria
//24/06/2020
#include<stdio.h>
#include<stdlib.h>

int esPalindromo(char cadena[]);
int main (){
	char cad[50];
	puts("Escribe la cadena");
	fflush(stdin);
	gets (cad);
	if (esPalindromo(cad)==1){
		printf("%d\tLa cadena es un palindromo",esPalindromo(cad));
	}
	else {
		printf("%d\tLa cadena no es un palindromo",esPalindromo(cad));
	}
	
	return 0;
}
int esPalindromo(char cadena[]){
	int i,letras=0, resultado=1;
	for (i=0;cadena[i]!='\0';i++){
		letras++;
	}

	for (i=0;i<letras;i++){
		if (cadena[i]!=cadena[letras-1-i]){
			resultado=0;
		}
	}
	return resultado;
}
