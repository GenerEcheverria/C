#include <stdio.h>

int compararCadenas(char cad1[], char cad2[]);
int longitudCadena(char cad[]);
void copiarCadenas(char cad1[], char cad2[]);
int encontrarCaracter(char cad[], char car);
int esDigito(char car);
int esMayuscula(char car);
int esVocal(char car);
int esConsonante(char car);
void convertirMayusculas(char cad[]);

int main(int argc, char *argv[]) {
	char cad1[50];
	char cad2[50];
	char cad[50];
	char car;
	
	/*Comparar cadenas*/
	puts("Introducir la primera cadena: ");
	gets(cad1);
	puts("Introducir la segunda cadena: ");
	gets(cad2);
	printf("%d",compararCadenas(cad1,cad2));
	
	/*Longitud de una cadena*/
/*	puts("Introducir la cadena: ");*/
/*	gets(cad);*/
/*	printf("%d",longitudCadena(cad));		*/
	
	
	/*Copiar cadenas*/
/*	puts("Introducir la cadena: ");*/
/*	gets(cad1);*/
/*	copiarCadenas(cad1,cad2);*/
/*	puts(cad2);*/
	
	/*Encontrar Caracter*/
/*	puts("Introducir la cadena: ");*/
/*	gets(cad);*/
/*	puts("Introducir el caracter: ");*/
/*	car = getchar();*/
/*	printf("%d", encontrarCaracter(cad,car));*/
	
	/*Verificar si un caracter es un dígito*/
/*	puts("Introducir el caracter: ");*/
/*	car = getchar();*/
/*	printf("%d", esDigito(car));	*/
	
	/*Verificar si un caracter es una letra mayúscula*/
/*	puts("Introducir el caracter: ");*/
/*	car = getchar();*/
/*	printf("%d", esMayuscula(car));	*/

	/*Verificar si un caracter es una letra mayúscula*/
/*	puts("Introducir el caracter: ");*/
/*	car = getchar();*/
/*	printf("%d", esVocal(car));	*/

	/*Verificar si un caracter es una letra mayúscula*/
/*	puts("Introducir el caracter: ");*/
/*	car = getchar();*/
/*	printf("%d", esConsonante(car));	*/

	/*Convertir a Mayúsculas*/
/*	puts("Introducir la cadena: ");*/
/*	gets(cad);*/
/*	convertirMayusculas(cad);*/
/*	puts(cad);*/
	
	return 0;
}

int compararCadenas(char cad1[], char cad2[]){
	int i=0;
	
	/*Se comparan cada par de caracteres de ambas cadenas mientras hayan caracteres
	en alguna cadena*/
	while ((cad1[i]!= '\0') && (cad2[i]!= '\0')){
		if (cad1[i]!=cad2[i]) //Si al comparar dos caracteres No son iguales se retorna 0 y se termina la función
			return 0;
		else
			i++;
	}
	if (cad1[i]== '\0' && cad2[i]== '\0') //¿Las cadenas comparadas son de la misma longitud?
		return 1;
	else
		return 0;
}

int longitudCadena(char cad[]){
	int i=0;	
	
	while (cad[i]!= '\0')
		i++;
	
	return i;
}

void copiarCadenas(char cad1[], char cad2[]){
	int i=0;	
	
	while (cad1[i]!= '\0'){
		cad2[i]=cad1[i];
		i++;
	}
	cad2[i]='\0';
	return;
}

int encontrarCaracter(char cad[], char car){
	int i=0;	
	
	while (cad[i]!= '\0'){
		if (cad[i]==car){
			return i+1;
		}
		i++;	
	}
	return 0;
}

int esDigito(char car){
	if (car>=48 && car<=57){
		return 1;
	}else{
		return 0;
	}
}

int esMayuscula(char car){
	if (car>=65 && car<=90){
		return 1;
	}else{
		return 0;
	}	
}

int esVocal(char car){
	if (car==65 || car==69|| car==73 || car==79|| car==85|| car==97 || car==101|| car==105 || car==111 || car==117){
		return 1;
	}else{
		return 0;
	}		
}

int esConsonante(char car){
	if ((car>=66 && car<=68)|| (car>=70 && car<=72) || (car>=74 && car<=78)
		|| (car>=80 && car<=84) || (car>=86 && car<=90)
		|| (car>=98 && car<=100)|| (car>=102 && car<=104) || (car>=106 && car<=110)
		|| (car>=112 && car<=116) || (car>=118 && car<=122))
	{
		return 1;
	}else{
		return 0;
	}		
}


void convertirMayusculas(char cad[]){
	int i=0;	
	
	while (cad[i]!= '\0'){
		switch (cad[i]){
		case 'á':
			cad[i]='A';
			break;
		case 'é':
			cad[i]='E';
			break;
		case 'í':
			cad[i]='I';
			break;
		case 'ó':
			cad[i]='O';
			break;
		case 'ú':
			cad[i]='U';
			break;
		default:
			if (cad[i]>= 97 && cad[i]<=122)
				cad[i]=cad[i]-32;
		}
		i++;	
	}
	return;	
}
