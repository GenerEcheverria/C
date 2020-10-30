//area triangulo
#include<stdio.h>
#include<stdlib.h>
float areaTriangulo (float base, float altura);
int main (){
	float base, altura;
	puts("Escribe la base:");
	scanf("%f",&base);
	puts("Escribe la altura:");
	scanf("%f",&altura);
	printf("El area del triangulo es %.2f\n",areaTriangulo(base,altura));
	return 0;
	system("pause");
}
float areaTriangulo (float base, float altura){
	float area;
	area=base*altura/2;
	return area;	
}
