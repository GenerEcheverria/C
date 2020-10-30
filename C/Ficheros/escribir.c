#include<stdio.h>
void cambio(char aux[]);
int main (){
	int num;
	char aux[50];
	FILE *f;
	f=fopen("Nota.txt","a"); //w crea y destruye  la nota cada vez que se ejecuta
	scanf("%i",&num);
	puts("Cadena");
	fflush(stdin);
	fgets(aux,50,stdin);
	cambio(aux);
	rewind(f);
	fprintf(f,"%s\t",aux);
	fprintf(f,"%i\n",num);
	fclose(f);
	return 0;
}
void cambio(char aux[]){
	int i;
	for (i=0;i<50;i++){
		if (aux[i]=='\n'){
			aux[i]='\0';
		}
	}
}
