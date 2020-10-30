#include<stdio.h>
#include<stdlib.h>
int main () {
	char simbolo='*';
	int fila;
	int columna;
	int f;
	int c;
	int espacio;

	printf("Escribe el número de filas: ");
	scanf("%i", &fila);
	columna=fila;
	for (f=1;f<=fila; f++) {
		espacio=0;
		while (espacio!=f) {
			printf(" ");
			espacio++;
		}
		for (c=1;c<=columna; c++){
  			printf("%c", simbolo);
  		}
  		columna--;
  		printf("\n");
	}
	
	system("pause");
	return 0;
}
