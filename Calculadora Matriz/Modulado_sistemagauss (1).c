#include <stdio.h>
#define m 4
#define n 4
void leerSistema(float matriz[m][n+1],int fila, int columna);
void imprimirSistema(float matriz[m][n+1], int fila, int columna);
void sistemaGauss();
void solucionSistema(float matriz2[m][n+1], int fila, int columna);
int main (){
	sistemaGauss();
	return 0;
}
void sistemaGauss(){
	float a[m][n+1],resul[m][n+1];
	int incognitas=3;
	leerSistema(a,incognitas,incognitas+1);

	float pivote,aux1,aux2;
	int i,j,r,s;
	pivote=a[1][1];
	aux1=a[2][1];
	aux2=a[3][1];
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=4;j++)
		{
			resul[1][j]=a[1][j]/pivote;

			resul[i+1][j]=(aux1*(-1)*resul[1][j])+a[i+1][j];
		}
		aux1=aux2;
		
	}

	pivote=resul[2][2];
	aux1=resul[1][2];
	aux2=resul[3][2];
	for(r=1;r<=4;r++)
	{
			resul[2][r]=resul[2][r]/pivote;
			resul[1][r]=(aux1*(-1)*resul[2][r])+resul[1][r];	
			resul[3][r]=(aux2*(-1)*resul[2][r])+resul[3][r];
	}
	
	pivote=resul[3][3];
	aux1=resul[1][3];
	aux2=resul[2][3];
	for(s=2;s<=4;s++)
	{
		resul[3][s]=resul[3][s]/pivote;

		resul[1][s]=(aux1*(-1)*resul[3][s])+resul[1][s];
		resul[2][s]=(aux2*(-1)*resul[3][s])+resul[2][s];
	}
	
	imprimirSistema(resul,incognitas,incognitas+1);
	system("pause");
}

void leerSistema(float matriz[m][n+1], int fila, int columna){
	int i,j,k,l;
	for (i=1;i<=fila;i++){
		for (j=1;j<=columna;j++){
			matriz[i][j+1]= 0;
		}
	}
	for (i=1;i<=fila;i++){
		for (j=1;j<=columna;j++){
			for(k=1;k<=fila;k++) {
				for (l=1;l<=columna;l++){
					printf("%.1f\t",matriz[k][l]);
				}
				puts("\n");
			}
			if (j<columna){
				printf("\nIntroduce el coeficiente de X[%d] de la ecuacion [%d]:",j,i);
			    scanf("%f",&matriz[i][j]);
			}
			else {
				printf("\nIntroduce el termino independiente de la ecuacion [%d]:",i);
				scanf("%f",&matriz[i][j]);
			}
			system("cls");
		}
	}
}
void imprimirSistema (float matriz[m][n+1], int fila, int columna) {
	int x;
	for(x=1;x<=3;x++)
	{
		printf("x%d: %.2f\t",x,matriz[x][4]);
		printf("\n");
	}

}
