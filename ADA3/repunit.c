#include<stdio.h>
#include<stdlib.h>
int main(){
	long int n, num=1, digito;
	printf("Escribe un numero: ");
	scanf("%i",&n);
	num=n;
	while (num!=0){
		digito=num%10;
		if (digito!=1){
			printf("%i no es un numero Repunit\n",n);
			break;
		}
		num=(num-digito)/10;
		if (num==0){
			printf("%i si es un numero Repunit\n",n);
			break;
		}
	}
	system("pause");
	return 0;
}
