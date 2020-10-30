#include <stdio.h>
//suma de matrices

int main(){
	float suma,b;
	int i=0,j=0,k,l,m,n,f,c;
	printf("Num. columnas: ");
	scanf("%d",&f);
	printf("Num. filas: ");
	scanf("%d",&c);
	
	float A[f][c],B[f][c];
	
	for(i=0;i<f;i++)
	{
		for(j=0;j<c;j++)
		{
			
			printf("Matriz A [%d][%d]: ",i,j);
			scanf("%f",&A[i][j]);
			
			printf("%.2f\t",A[i][j]);
			printf("\n");
			
		
			
		}
		printf("\n");
	}
	for(m=0;m<f;m++)
	{
		for(n=0;n<c;n++)
		{
			printf("Matriz B [%d][%d]: ",i,j);
			scanf("%f",&B[m][n]);
			printf("%.2f\t",B[m][n]);
		}
		printf("\n");
	}
	
	for(k=0;k<f;k++)
	{
		for(l=0;l<c;l++)
		{
			suma=A[k][l]+B[k][l];
			printf("%.2f\t",suma);
		}
		printf("\n");
	}
	
	
	return 0;
}
