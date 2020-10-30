//Collatz
#include<stdio.h>
int main (){
	int n;
	puts("Escribe un numero");
	scanf("%i",&n);
	while (n!=1){
		if (n%2==0){
			n/=2;
		}
		else {
			n=n*3+1;
		}
		printf("%i\t",n);
	}
	return 0;
}
