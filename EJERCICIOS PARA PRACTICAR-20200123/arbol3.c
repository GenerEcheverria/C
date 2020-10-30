#include<stdio.h>
#include<stdlib.h>
int main (){
	char mas='+';
	int fila,columna,f,c;
	
	printf("Escribe el número de filas: ");
	scanf("%i", &fila);
	printf("Escribe el número de columnas: ");
	scanf("%i", &columna);
	
	for(f=1;f<=fila;f++){
		if ((f==1)||(f==fila)){
			for (c=1;c<=columna;c++){
				printf("%c",mas);
			}
			printf("\n");
		}
		else {
			for (c=1;c<=columna;c++){
				if ((c==1)||(c==columna)) {
					printf("%c",mas);
				}
				else {
					printf(" ");	
				}
			}
			printf("\n");
		}
		
	}
	
	system("pause");
	return 0;
}
