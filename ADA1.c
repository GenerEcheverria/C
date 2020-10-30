#include<stdio.h>
int main (){
	double a = 4.33;
	int b = 4;
	int c = 7;
	int d;
	double f;
	
	f = b/c;
	printf("%f\n", f);
	
	d = b/c;
	printf("%i\n", d);
	
	d= a*b/c;
	printf("%i\n", d);
	
	f=(a/b)*c;
	printf("%f\n", f);
	
	
	return 0;
}
