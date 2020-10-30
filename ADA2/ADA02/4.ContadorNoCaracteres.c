//4 Caracteres
//Gener Echeverria y Valeria Gonzalez
#include<stdio.h>
#include<stdlib.h>
int main (){
	int i=0,x=0;
	char texto[100];
	printf("Escribe el texto: ");
	gets(texto);
	while (texto[i]!='\0') {
		if ((texto[i]>=33&&texto[i]<=64)||(texto[i]>=91&&texto[i]<=96)||(texto[i]>=123&&texto[i]<=127)) {
			x++;
		}
		i++;
	}
	printf("Numero de caracteres que no son letras: %i\n",x);
	system("pause");
	return 0;
}
