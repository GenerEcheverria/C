//fibonacci
#include<stdio.h>
void fibonacci(int n);
int main(){
	int n,i;
	printf("Escribe el numero de terminos de Fibonacci: ");
	scanf("%d",&n);
	if (n<3){
		for(i=1;i<=n;i++){
			printf("%i\t", i-1);
		}
	}
	else {
		fibonacci(n);
	}
	return 0;
}
void fibonacci(int n){
	int fib,i;
	int a0=0,a1=1,a2;
	printf("%i\t%i\t",a0,a1);
	for (i=0;i<n-2;i++){
		a2=a0+a1;
		printf("%i\t", a2);
		a0=a1;
		a1=a2;
	}
}
