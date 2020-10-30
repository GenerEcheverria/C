#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct  {
	char *nombre;
	int edad;
}trabajadores;
trabajadores *trab;
void vaciar(char temp[]);
void copiar(char temp[], int i);
int main (){
	char temp[50],aux;
	int cont=0,i,j;
	FILE *f;
	f=fopen("trabajadores.txt","r");
	while(!feof(f)){
		fgets(temp,50,f);
		cont++;
	}
	
	rewind(f);
	trab=(trabajadores*)malloc(cont*sizeof(trabajadores));
	for (i=0;!feof(f);i++){
		vaciar(temp);
		aux='0';
		for(j=0;aux!='-';j++){
			aux=fgetc(f);
			if (aux!='-'){
				temp[j]=aux;
			}
		}
		copiar(temp,i);
		fgets(temp,4,f);
		trab[i].edad = atoi(temp); //convierte numeros de string a entero
		printf("Nombre: %s    Edad: %i \n",trab[i].nombre,trab[i].edad);
	}
	return 0;
}
void vaciar(char temp[]){
	int i;
	for(i=0;i<50;i++){
		temp[i]='\0';
	}
}
void copiar(char temp[], int i){
	int N = strlen(temp)+1;//strlen cuenta los caracteres de temp sin \0
	trab[i].nombre=(char*)malloc(N*sizeof(char));
	strcpy(trab[i].nombre,temp);
}
