#include <stdio.h>

struct test { 
	int i[20]; 
	float d[15]; 
	char c[35];
};



int main(int argc, char *argv[]) {

	struct test instanciaTest;
	printf("Tamaño en bytes de una instancia de test es: %d\n", sizeof(instanciaTest));
	
	for(int j=0; j<20; j++){
		printf("Introduce el valor del elemento %d del miembro i de la estructura:",j+1);
		scanf("%d", &instanciaTest.i[j]);
	}	
	for(int j=0; j<15; j++){
		printf("Introduce el valor del elemento %d del miembro d de la estructura:",j+1);
		scanf("%f", &instanciaTest.d[j]);
	}		
	puts("Introduce el valor del elemento c de la estructura:");
	fflush(stdin);
	gets(instanciaTest.c);

	for(int j=0; j<20; j++){
		printf("El valor del elemento %d del miembro i de la estructura es: %d \n",j+1,instanciaTest.i[j]);
	}	
	for(int j=0; j<15; j++){
		printf("El valor del elemento %d del miembro d de la estructura es: %f \n",j+1,instanciaTest.d[j]);
	}
	printf("El valor del elemento c de la estructura es: %s \n",instanciaTest.c);
	
	return 0;
}

