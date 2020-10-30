#include<stdio.h>
int main (){
	char aux;
	char aux2[50];
	FILE *f;
	f = fopen("Puntuaciones.txt","r");
	if (f==NULL){
		printf("No se ha podido abrir el fichero");
	}
	while(aux!=EOF){
		aux=fgetc(f);
		printf("%c",aux);
	}
	printf("\n");
	fclose(f);
	
	f = fopen("Puntuaciones.txt","r");
	while(!feof(f)){
		fgets(aux2,50,f);
		printf("%s",aux2);
	}
	printf("\n");
	fclose(f);
	return 0;
}
