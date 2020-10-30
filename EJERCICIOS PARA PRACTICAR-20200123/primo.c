//primo
#include<stdio.h>
int main (){
	int n,i, contador=0;
	puts("Escribe un numero");
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		if (n%i==0){
			contador++;
		}
	}
	if (contador==2){
		puts("Es primo");
	}
	else {
		puts("No es primo");
	}
}
