/*ADA5
Autor: Gener Echeverria
Fecha: 28/03/2020
Version 1.0 */
#include<stdio.h>
#include<stdlib.h>
//#include<string.h>
int compararCadenas(char cad1[], char cad2[]) ;
int encontrarCadena(char cad1[], char cad2[]);
int longitudCadena(char cad1[]);
void copiarCadenas(char cad1[], char cad2[]);
int encontrarCaracter(char cad1[], char car);
int esDigito (char car);
int esMayuscula (char car);
int esVocal (char car);
int esConsonante (char car);
void convertirMayusculas (char cad1[]);
int main (){
	int opcion=0;
	char cad1[100],cad2[100],car;
	system("color 0B");
	while (opcion!=11) {
		puts("\t\t\tADA5");
		puts(" __________________________________________________");
		puts("|1. Comparar dos cadenas                           |");
		puts("|2. Localizar la primera cadena en la segunda      |");
		puts("|3. Longitud de una cadena                         |");
		puts("|4. Copiar cadena                                  |");
		puts("|5. Encontrar caracter en cadena                   |");
		puts("|6. Verificar si un caracter es digito             |");
		puts("|7. Verificar si un caracter es una letra mayuscula|");
		puts("|8. Verificar si un caracter es una vocal          |");
		puts("|9. Verificar si un caracter es una consonante     |");
		puts("|10. Convertir una cadena a mayusculas             |");
		puts("|11. Salir                                         |");
		puts("|__________________________________________________|\n");
		puts("Elige la opcion que deseas");
		scanf("%d",&opcion);
		switch (opcion){
			case 1: system ("cls"); if (compararCadenas(cad1,cad2)==1)	puts("Las cadenas son iguales"); else puts("Las cadenas son diferentes"); break;
			case 2: system("cls"); if (encontrarCadena(cad1,cad2)==1) puts("La primera cadena SI se encuentra en la segunda"); else puts("La primera cadena NO se encuentra en la segunda"); break;
			case 3: system("cls"); printf("La longitud de la cadena es %d\n", longitudCadena(cad1)); break;
			case 4: system("cls"); copiarCadenas(cad1,cad2); break;
			case 5: system("cls"); encontrarCaracter(cad1,car); break;
			case 6: system("cls"); if (esDigito(car)==1) puts("Es un digito"); else puts("No es un digito"); break;
			case 7: system("cls"); if (esMayuscula(car)==1) puts("Es una letra mayuscula"); else puts("No es una letra mayuscula"); break;
			case 8: system("cls"); if (esVocal(car)==1) puts("Es una vocal"); else puts("No es una vocal"); break;
			case 9: system("cls"); if (esConsonante(car)==1) puts("Es una consonante"); else puts("No es una consonante"); break;
			case 10: system("cls"); convertirMayusculas(cad1); break; 
		}
		system("pause");
		system("cls");
	}
	return 0;
}
//strcat(uno,dos) unir cadenas
int compararCadenas(char cad1[], char cad2[]) {
	fflush(stdin);
	//strcmp(cadena,subcadena) si es igual a 0 son iguales
	int cont=1,i=0;
	puts("1. Comparar dos cadenas");
	puts("____________________________________\n");	
	puts("Escribe la primera cadena");
	gets(cad1);
	puts ("Escribe la segunda cadena");
	gets(cad2);
	while (cad1[i]!='\0') {
		if (cad1[i]!=cad2[i]){
			cont++;
		}
		i++;
	}
	printf("%\n", cont);
	return cont;
}
int encontrarCadena(char cad1[], char cad2[]) {
	int cont=1,i=0,j=0;
	//strstr(cadena,subcadena) es igual a 0 si la encuentra
	fflush(stdin);
	puts("2. Localizar la primera cadena en la segunda");
	puts("____________________________________\n");	
	puts("Escribe la primera cadena");
	gets(cad1);
	fflush(stdin);
	puts ("Escribe la segunda cadena");
	gets(cad2);
	while (cad2[i]!='\0'){
		if (cad1[j]!='\0') {
			if (cad1[j]==cad2[i]){
				cont=1;
				j++;
			}
			else {
				j=0;
				cont=0;
			}
		}
		else {
			break;
		}
		i++;
	}
	printf("%d\n", cont);
	return cont;
}
int longitudCadena(char cad1[]){
	fflush(stdin);
	int longitud=0;
	puts("\t3. Longitud de una cadena");
	puts("____________________________________\n");
	puts("Escribe la cadena\n");
	gets(cad1);
	while (cad1[longitud]!='\0'){
		longitud++;
	}
	return longitud;
}
void copiarCadenas(char cad1[], char cad2[]) {
	//strcpy(destino,fuente)
	fflush(stdin);
	int i=0;
	puts("\t4. Copiar cadena");
	puts("____________________________________\n");
	puts("Escribe la cadena 1");
	gets(cad1);
	while (cad1[i]!='\0'){
		cad2[i]=cad1[i];
		i++;
	}
	puts("\nCadena 2: ");
	puts(cad2);
}
int encontrarCaracter(char cad1[], char car){
	int i=0,lugar=0;
	puts("  5. Encontrar caracter en cadena");
	puts("____________________________________\n");
	fflush(stdin);
	puts("Escribe la cadena");
	gets(cad1);
	fflush(stdin);
	puts("Escribe el caracter");
	car=getchar();
	puts("Posicion:");
	while (cad1[i]!='\0') {
		if (cad1[i]==car){
			lugar=i+1;
			printf("%d\t",lugar);
		}
		i++;
	}
	if (lugar==0){
		printf("0");
	}
	printf("\n");
}
int esDigito (char car) {
	int resultado=0;
	puts("6. Verificar si un caracter es un digito");
	puts("____________________________________\n");
	fflush(stdin);
	puts("Escribe el caracter");
	car=getchar();
	if (car<=57 && car>=48) {
		resultado=1;
	}
	printf("%d\n", resultado);
	return resultado;
}
 int esMayuscula (char car) {
 	int resultado=0;
 	puts("7. Verificar si un caracter es una letra mayuscula");
	puts("____________________________________\n");
	fflush(stdin);
 	puts("Escribe el caracter");
	car=getchar();
	if (car<=90 && car>=65) {
		resultado=1;
	}
 	printf("%d\n", resultado);
 	return resultado;
 }
int esVocal (char car){
	int resultado=0;
	puts("8. Verificar si un caracter es una vocal");
	puts("____________________________________\n");
	fflush(stdin);
 	puts("Escribe el caracter");
	car=getchar();
	if (car==65 || car==69 || car==73 || car==79 || car==85 ||car==97 ||car==101 || car==105 || car==111 || car==117) {
		resultado=1;
	}
	printf("%d\n", resultado);
 	return resultado;
}
int esConsonante (char car) {
	int resultado=0;
	puts("9. Verificar si un caracter es una consonante");
	puts("____________________________________\n");
	fflush(stdin);
 	puts("Escribe el caracter");
	car=getchar();
	if ((car!=69 || car!=73 || car!=79 || car!=85||car!=101 || car!=105 || car!=111 || car!=117) && ((car>=66 && car<=90) || (car>= 98 && car<=122))) {
		resultado=1;
	}
	printf("%d\n", resultado);
 	return resultado;
}
void convertirMayusculas (char cad1[]){
	int i=0;
	puts("10. Convertir una cadena a mayusculas");
	puts("____________________________________\n");
	fflush(stdin);
	puts("Escribe la cadena");
	gets(cad1);
	while (cad1[i]!='\0') {
		if (cad1[i]>=97 && cad1[i]<=122){
			cad1[i]-=32;
		}
		i++;
	}
	puts(cad1);
}
