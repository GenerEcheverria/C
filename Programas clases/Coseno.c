//Coseno
#include<stdio.h>
float potencia (float b, int e);
int factorial (int n);
int main (){
	float coseno=1;
	float termino;
	int n, i;
	float x;
	printf("Dame el valor de n");
	scanf("%d",&n);
	printf("Dame el valor de x");
	scanf("%f",&x);
	for(i=1;i<=n;i++){
		termino=potencia(x,2*i)/factorial(2*i);
		if(i%2==0){
			coseno+=termino;
		}
		else{
			coseno-=termino;
		}
	}
	printf("f", termino);
	
	return 0;
}



float potencia (float b, int e){
	float pot=1;
	int i;
	for(i=1;i<=e;i++){
		pot*=b;
	}
	return pot;
}
int factorial (int n){
	int fact=1;
	i=1;
	for (i=1;i<=n;i++){
		fact*=i;
	}
	return fact;
}



