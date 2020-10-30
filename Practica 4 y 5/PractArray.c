#include<stdio.h>
#include<stdlib.h>
int textoToEntero(char numero []);
int potencia (int digito, int i, int lugar);
int main (){
	char num [50];
	puts("Escribe el numero");
	fflush(stdin);
	gets(num);
	printf("Numero: %d",textoToEntero(num));
	return 0;
}
int textoToEntero(char numero []){
	int i=0, lugar=0, Numero, digito;
	for (i=0;numero[i]!='\0';i++){
		lugar++;
	}
	for (i=0;i<lugar;i++){
		digito=numero[i]-'0';
		Numero+=potencia(digito,i,lugar);
	}
	return Numero;
}
int potencia (int digito, int i, int lugar){
	int j,pot=1;
	for (j=0;j<lugar-1-i;j++){
		pot*=10;
	}
	pot*=digito;
	return pot;
}
