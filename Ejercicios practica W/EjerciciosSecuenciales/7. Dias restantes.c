//dias para acabar el anio
#include<stdio.h>
#include<stdlib.h>
int main (){
	int dia, mes,restante, i;
	int anio [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	puts("Escribe el dia");
	scanf("%d",&dia);
	puts("Escribe el mes");
	scanf("%d",&mes);
	for (i=mes;i<=12;i++){
		restante+=anio[i-1];
	}
	restante-=dia;
	printf("%d dias restantes\n", restante);
	system("pause");
	return 0;
}
