/*ADA6
Gener Echeverria y Valeria Gonzalez
Fecha: 20/04/2020
Version: 1.0*/
#include <stdio.h>
#include<stdlib.h>
int comprobador (char cadena[]);
int main (){
	char expresion[50];
	int comprobar=0;
	puts("Escribe la expresion:");
	while (comprobar!=1){
		//gets(expresion);
		scanf("%s",&expresion);
		fflush(stdin);
		puts(expresion);
		comprobar=comprobador(expresion);
		if (comprobar==0) {
			puts("Vuelve a introducir la expresion"); continue;
		}
		printf("%s",expresion);
	}
	return 0;
}
int comprobador (char cadena[]){
	int i=0, j, comp=0, izquierda=0, derecha=0, aux=0;
	while (cadena[i]!='\0'){
		if (cadena[i]>=49 && cadena[i]<=57){
			comp=1;
			if (cadena[i+1]>=49 && cadena[i+1]<=57){
				comp=0; 
				printf("Error Lexico. %c%c es mayor a 9.\n", cadena[i], cadena[i+1]); break;
			}
		}
		if (cadena[i]==94 || cadena[i]==42 || cadena[i]==43 || cadena[i]==47 || cadena[i]==45 || cadena[i]==40 || cadena[i]==41){
			comp=1;//hhhhhhhhhhhhhhhhhhhhhhhhh
			if (cadena[i+1]==94 || cadena[i+1]==42 || cadena[i+1]==43 || cadena[i+1]==47 || cadena[i+1]==45) {
				comp=0;
				printf("Error Sintactico. Error en la secuencia %c%c.\n", cadena[i], cadena[i+1]); break;
			}
			
		}
		else {
			if (cadena[i]<49 || cadena[i]>57) {
				if (cadena[i]==46) {
					printf("Error Lexico. Error en la secuencia %c%c%c\n",cadena[i-1],cadena[i],cadena[i+1]);
					comp=0; break;
				}
				printf("Error Lexico. Error en el caracter %c\n", cadena[i]);
				comp=0; break;
			}
		}
		if (cadena [i] == 40) {
			j=i;
			while (cadena[j]!='\0') {
				j++;
				if (cadena [j-1]==40 && cadena[j]==41){
					comp=0;
					printf("Error Sintactico. Error en la secuencia %c%c\n",cadena[j-1],cadena[j]); break; 
				} 
				if (cadena[j-1]==40) {
					izquierda++;
				}
				if (cadena[j-1]==41) {
					derecha++;
				}
				j++;
			}
			if (aux==0){
				if (izquierda>derecha) {
					comp=0;
					puts("Error Sintactico. Falta un ')'"); break;
				}
				else {
					if (derecha>izquierda) {
						comp=0;
						puts("Error Sintactico. Falta un '('"); break;
					}
					else {
						aux=1;
					}
				}	
			}
		}
		i++;
	}
	return comp;
}

