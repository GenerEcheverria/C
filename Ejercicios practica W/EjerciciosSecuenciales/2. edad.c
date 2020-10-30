//Edad a partir de anio de nacimiento
#include<stdio.h>
#include<stdlib.h>
int edad(int nacimiento, int actual);
int main (){
	int nacimiento, actual;
	puts ("Anio de nacimiento :");
	scanf ("%d",&nacimiento);
	puts ("Anio actual :");
	scanf ("%d",&actual);
	printf("Tiene %d anios\n",edad (nacimiento, actual));
	system("pause");
	return 0;
}
int edad (int nacimiento, int actual){
	int edadAnios;
	edadAnios=actual-nacimiento;
	return edadAnios;	
}
