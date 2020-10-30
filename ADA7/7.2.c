/*ADA7
Ejercicio 2
Autor: Gener Echeverria
Fecha: 30/04/2020*/
#include<stdio.h>
#include<stdlib.h>
struct test { 
    int c[20]; 
	double d[15]; 
	char e[35];
}test;
struct prueba {
	int c[20];
	char e[35];
}prueba;
int main (){
	int i;
	printf("Tamano de test: %d bytes\n", sizeof(struct test));
	printf("tamano de c: %d bytes \n", sizeof(test.c));
	printf("tamano de d: %d bytes\n", sizeof(test.d));
	printf("tamano de e: %d bytes\n", sizeof(test.e));
	fflush(stdin);

	for (i=0; i<20;i++) {
		printf("Introduce c[%d]",i);
		scanf("%d", &prueba.c[i]);
		system("cls");
	}
	puts("Introduce e");
	fflush(stdin);
	gets(prueba.e);
	system("cls");
	for (i=0; i<20;i++) {

		printf("c[%d]= %d\n",i, prueba.c[i]);
	}
	puts(prueba.e);
	system("pause");
	return 0;
	
}
