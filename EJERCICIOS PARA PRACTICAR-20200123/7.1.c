//Ejercicio 7
#include<stdio.h>
#include<stdlib.h>

int main (){
	float temperatura;
	float resultado;
	float a0;
	float a1;
	float sumx;
	float sumfx;
	float sumxx;
	float sumfxx;
	float sumx2;
	
	printf ("Escribe el valor de la temperatura ");
	scanf("%f", &temperatura);
	
	sumx=20.5+32.7+51+73.2+95.7; 
	sumfx=765+826+873+942+1032; 
	
	sumxx= 20.5*20.5+32.7*32.7+51*51+73.2*73.2+95.7*95.7; 
	sumfxx=20.5*765+32.7*826+51*873+73.2*942+95.7*1032; 
	
	sumx2=sumx*sumx; 
	
	a0= (sumfx*sumxx-sumx*sumfxx)/(5*sumxx-sumx2);
	a1= (5*sumfxx-sumx*sumfx)/(5*sumxx-sumx2);
	
	
	resultado=a0+a1*temperatura;
	
	printf("La resistencia es %.2f \n", resultado);
	
	system("pause");
	return 0;
}
