//valor absoluto
#include<stdio.h>
int main (){
	int n,m;
	puts("Escribe el numero");
	scanf("%i",&n);
	if (n>=0){
		printf("|%i|=%i",n,n);
	}
	else {
		m=-1*n;
		printf("|%i|=%i",n,m);
	}
	
	return 0;
}
