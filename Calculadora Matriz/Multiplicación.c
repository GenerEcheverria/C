#include <stdio.h>
//mult. matrices

int main(){
	int fa,ca,cb,i,j,k,l,fb;
	int m,n,o,p,q;
	float resp,mult,suma;
	printf("Num. filas A: ");
	scanf("%d",&fa);
	printf("Num. columnas A: ");
	scanf("%d",&ca);
	printf("Num. columnas B: ");
	scanf("%d",&cb);
	fb=ca;
	float A[fa][ca], B[fb][cb],res[fa][cb];
	for(i=0;i<fa;i++)
	{
		for(j=0;j<ca;j++)
		{
			printf("Matriz A [%d][%d]: ",i+1,j+1);
			scanf("%f",&A[i][j]);
			

		}	
	}
	printf("\n");
	for(k=0;k<fb;k++)
	{
		for(l=0;l<cb;l++)
		{
			printf("Matriz B [%d][%d]: ",k+1,l+1);
			scanf("%f",&B[k][l]);
			
		}
	}
	
	for(m=0;m<fa;m++)
	{
		
		for(n=0;n<cb;n++)
		{
			suma=0;
			for(o=0;o<fb;o++)
			{  
				suma=suma+(A[m][o]*B[o][n]);
				res[m][n]=suma;
			}
		}
	}
	for(p=0;p<fa;p++)
	{
		for(q=0;q<cb;q++)
		{
			printf("%.2f\t",res[p][q]);
		}
		printf("\n");
	}
	
	return 0;
}

