#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main (){
	int a;
	srand(time(NULL));
	a=rand()%6;
	printf("%d",a);
	return 0;
}
