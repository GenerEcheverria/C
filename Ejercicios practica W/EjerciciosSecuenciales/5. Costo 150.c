//venta
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n, costo;
	float envio, total;
	puts("Numero de articulos");
	scanf("%d", &n);
	costo=n*150;
	envio=costo*.20;
	total = costo+envio;
	printf("Costo de %d productos: $%d\nCosto de envio: $%.2f\nCosto total: $%.2f\n", n,costo,envio,total);
	system("pause");
	return 0;
}
