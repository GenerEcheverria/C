//3 Triangulo
//Gener Echeverria y Valeria Gonzalez
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n=1,i,a,x;
	printf("Escribe el numero de filas: ");
	scanf("%i",&n);
	for(i=1;i<=n;i++){
		x=1;
		for (a=1;a<=i;a++) {
			printf("%i",x);
			x++;
			if (x>9){
				x=0;
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
