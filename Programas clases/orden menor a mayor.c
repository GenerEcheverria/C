#include<stdio.h>
#include<stdlib.h>
void mayor (int *, int *, int*);
int main (){
	int a,b,c;
	puts("Escribe el valor de a");
	scanf("%d",&a);
	puts("Escribe el valor de b");
	scanf("%d",&b);
	puts("Escribe el valor de c");
	scanf("%d",&c);
	mayor(&a,&b,&c);
	printf("a vale: %d\n",a);
	printf("b vale: %d\n",b);
	printf("c vale: %d\n",c);
	system("pause");
	return 0;
}
void mayor (int *a, int *b, int*c){
	int i,aux;
	for (i=1;i<=2;i++){
		if (*c<*b){
			aux=*b;
			*b=*c;
			*c=aux;
		}
		if (*b<*a){
			aux=*a;
			*a=*b;
			*b=aux;
		}
	}
}
