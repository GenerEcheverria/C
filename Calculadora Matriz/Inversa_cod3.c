#include <stdio.h>
#define m 4
#define n 4
void inversa ();
void invierte(int tam, float matriz[m][m], float inv[m][m]);
void leerMatriz(float matriz[m][m],int fila, int columna);
void imprimirMatriz(float matriz[m][m], int fila, int columna);

int main (){
	inversa();
	return 0;
}
void inversa () {
	int tamano;
 	float A[m][m],inversa[m][m];
 	puts("\t|MATRIZ INVERSA GAUSS JORDAN|\n");
 	puts("Tamano de la matriz");
 	scanf("%d",&tamano);
 	leerMatriz(A,tamano,tamano);
 	invierte(tamano,A,inversa);
 	printf("\n\n\nLa inversa de la matriz es: \n\n");
 	imprimirMatriz(inversa,tamano,tamano);
}
void imprimirMatriz (float matriz[m][m], int fila, int columna) {
	int i,j;
	for (i=1;i<=fila;i++){
		for (j=1;j<=columna;j++){
			printf("%.2f\t",matriz[i][j]);
		}
		puts("\n");
	}
}
void leerMatriz(float matriz[m][m], int fila, int columna){
	int i,j,k,l;
	for (i=1;i<=fila;i++){
		for (j=1;j<=columna;j++){
			matriz[i][j]= 0;
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
			printf("\nIntroduce el valor de la posicion [%d][%d]:",i,j);
			scanf("%f",&matriz[i][j]);
			system("cls");
		}
	}
	puts("\tMATRIZ\n\n");
	for(k=1;k<=fila;k++) {
		for (l=1;l<=columna;l++){
			printf("%.1f\t",matriz[k][l]);
		}
		puts("\n");
	}
}

void invierte(int tam, float matriz[m][m], float inv[m][m]){
	int NoCero,columna,C1,C2,a;
 	float Aux,V1,V2;
 	for(C1=1;C1<=tam;C1++) {
 		for(C2=1;C2<=tam;C2++) {
 			if (C1==C2) {
 				inv[C1][C2]=1;
 			}
 			else {
 				inv[C1][C2]=0;	
 			}
 		}
 	}
 	for(columna=1;columna<=tam;columna++){
 		NoCero=0;a=columna;
		while(NoCero==0){
			if((matriz[a][columna]>0.0000001)||((matriz[a][columna]<-0.0000001))){
    			NoCero=1;
			}
			else {
				a++;
			}
		}
  		Aux=matriz[a][columna];
  		for(C1=1;C1<=tam;C1++){
		  	   V1=matriz[a][C1]; 
			   matriz[a][C1]=matriz[columna][C1];
			   matriz[columna][C1]=V1/Aux;
			   V2=inv[a][C1];
			   inv[a][C1]=inv[columna][C1];
			   inv[columna][C1]=V2/Aux;
		 }
		for(C2=columna+1;C2<=tam;C2++){
			V1=matriz[C2][columna];
			for(C1=1;C1<=tam;C1++){
			    matriz[C2][C1]=matriz[C2][C1]-V1*matriz[columna][C1];
                inv[C2][C1]=inv[C2][C1]-V1*inv[columna][C1];
			}
 		}
	}
	for(columna=tam;columna>=1;columna--) {
		for(C1=(columna-1);C1>=1;C1--) {
			V1=matriz[C1][columna]; 
			for(C2=1;C2<=tam;C2++){
			      matriz[C1][C2]=matriz[C1][C2]-V1*matriz[columna][C2];
				  inv[C1][C2]=inv[C1][C2]-V1*inv[columna][C2];
			}
		}
	}
}

