//suma primeros n naturales
#include<stdio.h>
#include<stdlib.h>
int main (){
	int n,i,suma=0;
	puts("Escribe el valor de n");
	scanf("%i",&n);
	for (i=1;i<=n;i++){
		suma+=i;
	}
	printf("La suma de los primeros %i numeros naturales es %i\n",n,suma);
	system("pause");
	return 0;
}
