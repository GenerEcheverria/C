#include<stdio.h>
#include<stdlib.h>
int factorPrimo( int n);
int main () {
	int n;
	puts ("Escribe un numero");
	scanf ("%i",&n);
	puts ("Factores primos: ");
	factoresPrimos(n);
	puts ("\n");
	system("pause");
	return 0;
}
int factoresPrimos (int n) {
	int a=1,b=1, fac, i=2;
	while (n!=1) {
		if (n % i == 0) {
			n/=i;
			a=i;
			i--;
  		}
		if (a!=b) {
			printf("%i\t",a);
		}
		b=a;
		i++;
	}
	return fac;
}
