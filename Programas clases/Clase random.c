#include<stdio.h>
 int suma (int *a, int b);
 int main (){
 	int a,b, sum;
 	scanf("%d",&a);
 	scanf("%d",&b);
 	sum=suma(&a,b);
 	printf("%d\n", sum);
 	printf("%d\n", a);
 	printf("%d\n", b);
 	return 0;
 }
int suma (int*a, int b){
	int sum;
	*a=*a+20;
	sum=*a+b;
	return sum;
}
