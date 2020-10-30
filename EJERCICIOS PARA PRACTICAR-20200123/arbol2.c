#include<stdio.h>
#include<stdlib.h>
int main(){
	char gato='#';
	char mas='+';
	int fila, columna, f, c;
	printf("Escribe el nmero de filas: ");
	scanf("%i", &fila);
	printf("Escribe el nmero de columnas: ");
	scanf("%i", &columna);
	
	for (f=1;f<=fila;f++){
		if (f%2!=0) {
			for (c=1;c<=columna;c++) {
				if (c%2!=0){
					printf("%c",gato);
				}
				else { 
					printf("%c",mas);
				}
			}
			printf("\n");
		}
		else {
			for (c=1;c<=columna;c++) {
				if (c%2!=0){
					printf("%c",mas);
				}
				else { 
					printf("%c",gato);
				}
			}
			printf("\n");
		}	
	}
	system("pause");
	return 0;
}
