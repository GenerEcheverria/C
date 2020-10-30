#include<stdio.h>
int numeroPerfecto (int x);
int main (){
	int opcion,i, contadorPerfecto=0,sum; 
	puts("Funciones:\n 1.Numeros pares e impares\n 2.Numero perfecto\n 3.Invertir numeros");
	scanf("%i",&opcion);
	switch(opcion){
		case 1 : for (i=1;i<=10;i++){
			int n;
			puts("Escribe el numero");
			scanf("%i",&n);
			if (n%2==0) {
				printf("%i es par\n",n);
			}
			else {
				printf("%i es impar\n",n);
			} break;
		}
		case 2: do {
			i=2;
			sum=numeroPerfecto (i);
			printf ("%i", sum);
			if (sum==i) {
				printf ("%i es perfecto\n", i);
				contadorPerfecto++;
			}		
			i++;			
		} while (contadorPerfecto<3); break;
		
	}
	
	
	
	return 0;
}
int numeroPerfecto(int x){
	int j,suma=0;
	for (j=1;j<=x-1;j++){
		if (x%j==0){
			suma+=j;
		}
	}
	return suma;
}
