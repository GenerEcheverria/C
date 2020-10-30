/*Calculadora de matrices
Autores: Valeria Gonzalez y Gener Echeverria
Version: 2.0
fecha: 19/02/2020*/
#include<stdio.h> 
#define m 4
#define n 4
void sumaMatriz();
void multiplicacionEscalar();
void multiplicacionMatriz();
void transpuesta();
void inversa ();
void invierte(int tam, float matriz[m][m], float inv[m][m]);
void leerSistema(float matriz[m][n+1],int fila, int columna);
void imprimirSistema(float matriz[m][n+1], int fila, int columna);
void imprimirSistema2(float matriz[m][n+1], int fila, int columna);
void sistemaGauss();
void sistemaCramer();
void solucionSistema(float matriz2[m][n+1], int fila, int columna);
void determinante();
float n2 (float matriz[m][n]);
float n3(float matriz[m][n]);
float n4(float matriz[m][n]);
void tamanoMatriz(int *fila, int *columna);
void leerMatriz(float matriz[m][n],int fila, int columna);
void imprimirMatriz(float matriz[m][n], int fila, int columna);
int main (){
	int opcion=9;
	while (opcion!=0){
		puts("\t     |OPERACIONES CON MATRICES|\n");
		puts("--------------------------------------------------------\n");
		puts("| Escribe el numero de la funcion que deseas             |\n");
		puts("|  1.Suma de matrices                                    |\n");
		puts("|  2.Multiplicacion de matrices por una escalar          |\n");
		puts("|  3.Multiplicacion de matrices                          |\n");
		puts("|  4.Obtencion de la transpuesta de una matriz           |\n");
		puts("|  5.Inversa de una matriz (Gauss Jordan)                |\n");
		puts("|  6.Sistema de ecuaciones (Gauss Jordan)                |\n");
		puts("|  7.Determinante de una matriz                          |\n");
		puts("|  8.Sistema de ecuaciones (Cramer)                      |\n");
		puts("|  0.Salir                                               |\n");
		puts("--------------------------------------------------------\n");
		scanf("%d",&opcion);
		switch (opcion) {
			case 1: system("cls");sumaMatriz(); break;
			case 2: system("cls"); multiplicacionEscalar();break;
			case 3: system("cls");multiplicacionMatriz();break;
			case 4: system("cls"); transpuesta(); break;
			case 5: system("cls");inversa ();break;
			case 6: system("cls");sistemaGauss ();break;
			case 7: system("cls");determinante();break;
			case 8: system("cls");sistemaCramer();break;
		}
		system("cls");
	}
	return 0;
}
void sumaMatriz(){
	puts("\tSUMA DE MATRICES");
	float A[m][n];
	float B[m][n];
	int fila,columna,k,l;
	float suma;
	tamanoMatriz (&fila, &columna);
	puts("Matriz A");
	leerMatriz(A,fila,columna);
	puts("Matriz B");
	leerMatriz(B,fila,columna);
	puts("\tMatriz A\n");
	imprimirMatriz(A,fila,columna);
	puts("\tMatriz B\n");
	imprimirMatriz(B,fila,columna);
	puts("\n\tSuma de matrices A y B\n\n");
	for(k=1;k<=fila;k++)
	{
		for(l=1;l<=columna;l++)
		{
			suma=A[k][l]+B[k][l];
			printf("%.2f\t",suma);
		}
		printf("\n\n");
	}
	system("pause");
	system("cls");
}
void multiplicacionEscalar(){
	puts("\tMULTIPLICACION POR ESCALAR");
	float A[m][n];
	float escalar;
	int i,j,fila,columna;
	tamanoMatriz (&fila, &columna);
	leerMatriz(A,fila,columna);
	puts("Escribe el valor de la escalar:");
	scanf("%f",&escalar);
	for (i=1;i<=fila;i++){
		for (j=1;j<=columna;j++){
			A[i][j]=escalar*A[i][j];
		}
	}
	puts("\tMatriz\n");
	imprimirMatriz(A,fila,columna);
	printf("\n\n\tMatriz por %.1f\n\n",escalar);
	imprimirMatriz(A,fila,columna);
	system("pause");
}
void multiplicacionMatriz(){
	puts("\tMULTIPLICACION DE MATRICES\n");
	int fa,ca,cb,i,j,fb,o;
	float resp,mult,suma;
	float A[m][m], B[m][m],res[m][m];
	printf("Num. filas A: ");
	scanf("%d",&fa);
	printf("Num. columnas A: ");
	scanf("%d",&ca);
	printf("Num. columnas B: ");
	scanf("%d",&cb);
	fb=ca;
	leerMatriz(A,fa,ca);
	leerMatriz(B,fb,cb);
	puts("\tMatriz A\n");
	imprimirMatriz(A,fa,ca);
	puts("\tMatriz B\n");
	imprimirMatriz(B,fb,cb);
	for(i=1;i<=fa;i++){
		for(j=1;j<=cb;j++){
			suma=0;
			for(o=1;o<=fb;o++){  
				suma=suma+(A[i][o]*B[o][j]);
				res[i][j]=suma;
			}
		}
	}
	puts("\n\n\tMatriz resultante\n\n");
	imprimirMatriz(res,fa,fa);
	system("pause");
}
void transpuesta(){
	puts("\tMATRIZ TRANSPUESTA");
	float A[m][n];
	int i,j,fila,columna;
	tamanoMatriz (&fila, &columna);
	leerMatriz(A,fila,columna);
	puts("\tMatriz\n");
	imprimirMatriz(A,fila,columna);
	puts("\n\n\tTranspuesta\n\n");
	for (j=1;j<=columna;j++){
		for (i=1;i<=fila;i++){
			printf("%.1f\t", A[i][j]);
		}
		puts("\n");
	}
	system("pause");
}
void inversa () {
	int tamano;
 	float A[m][m],inversa[m][m];
 	puts("\t|MATRIZ INVERSA GAUSS JORDAN|\n");
 	puts("Tamano de la matriz");
 	scanf("%d",&tamano);
 	leerMatriz(A,tamano,tamano);
 	puts("\tMatriz\n");
 	imprimirMatriz(A,tamano,tamano);
 	invierte(tamano,A,inversa);
 	puts("\n\n\nLa inversa de la matriz es: \n\n");
 	imprimirMatriz(inversa,tamano,tamano);
 	system("pause");
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
void imprimirSistema2 (float matriz[m][n+1], int fila, int columna) {
	int i,j;
	for (i=1;i<=fila;i++){
		for (j=1;j<=columna;j++){
			if (j<columna){
				printf("%.2f X[%i]\t",matriz[i][j],j);
			}
			else {
				printf("= %.2f\t",matriz[i][j]);
			}
		}
		puts("\n");
	}
}
void determinante(){
	float A[m][n];
	int tamano;
	puts("\tDETERMINANTE DE UNA MATRIZ");
	puts("Escribe el tamano de la matriz");
	scanf("%d",&tamano);
	leerMatriz(A,tamano,tamano);
	puts("\tMatriz \n");
	imprimirMatriz(A,tamano,tamano);
	switch (tamano){
		case 2: printf("Determinate: %.2f\n",n2(A)); break;
		case 3: printf("Determinate: %.2f\n",n3(A)); break;
		case 4: printf("Determinate: %.2f\n",n4(A)); break;
	}
	system("pause");
}
float n2(float matriz[m][n]){
	int i,j;
	float mult,mult2,res;
	mult=mult2=1;
	for (i=1;i<=2;i++){
		for (j=1;j<=2;j++){
			if (i==j){
				mult*=matriz[i][j];
			}
			else{
				mult2*=matriz[i][j];
			}
		}
		res=mult-mult2;
	}
	return res;
}
float n3(float matriz[m][n]){
	float mult,mult2,res;
	mult=mult2=0;
	mult=(matriz[1][1]*matriz[2][2]*matriz[3][3])+(matriz[3][2]*matriz[2][1]*matriz[1][3])+(matriz[1][2]*matriz[3][1]*matriz[2][3]);
	mult2=(matriz[1][1]*matriz[3][2]*matriz[2][3])+(matriz[2][2]*matriz[3][1]*matriz[1][3])+(matriz[1][2]*matriz[3][3]*matriz[2][1]);
	res=mult-mult2;
	return res;
}
float n4(float matriz [m][n]){
	float resultado,sum=0;
	int i,j;
	float aux[m][n];
	for (i=1;i<=3;i++) {
		for (j=1;j<=3;j++){
			aux[i][j]=matriz[i+1][j+1];
		}
	}
	sum+=(matriz[1][1]*1*n3(aux));
	for (i=1;i<=3;i++) {
		for (j=1;j<=3;j++){
			if (i==1){
				aux[i][j]=matriz[i][j+1];
			}
			else {
				aux[i][j]=matriz[i+1][j+1];
			}
		}
	}
	sum+=(matriz[2][1]*-1*n3(aux));
	
	for (i=1;i<=3;i++) {
		for (j=1;j<=3;j++){
			if (i==3){
				aux[i][j]=matriz[i+1][j+1];
			}
			else {
				aux[i][j]=matriz[i][j+1];
			}
		}
	}
	sum+=(matriz[3][1]*1*n3(aux));
	
	for (i=1;i<=3;i++) {
		for (j=1;j<=3;j++){
			aux[i][j]=matriz[i][j+1];
		}
	}
	sum+=(matriz[4][1]*-1*n3(aux));
	return sum;
}
void sistemaCramer(){
	int tamano,i,j;
	float A[m][n+1],aux[m][n],aux2[m][n],aux3[m][n],aux4[m][n],determinanteA,determinanteI;
	puts("\tSISTEMA DE ECUACIONES (CRAMER)");
	puts("Escribe el numero de incognitas(2 o 3)");
	scanf("%d",&tamano);
	leerSistema(A,tamano,tamano+1);
	imprimirSistema2(A,tamano,tamano+1);
	for (i=1;i<=tamano;i++){
		for (j=1;j<=tamano;j++){
			aux[i][j]=aux2[i][j]=aux3[i][j]=aux4[i][j]=A[i][j];
		}
	}
	switch (tamano){
		case 2: determinanteA=n2(aux);break;
		case 3: determinanteA=n3(aux);break;
		//case 4: determinanteA=n4(aux);break;
	}
	if (tamano==2){
		for (i=1;i<=2;i++){
			aux[i][1]=A[i][3];
		}
		printf("X1 = %.2f\n",n2(aux)/determinanteA);
		for (i=1;i<=2;i++){
			aux2[i][2]=A[i][3];
		}
		printf("X2 = %.2f\n",n2(aux2)/determinanteA);
	}
	if (tamano==3){
		for (i=1;i<=3;i++){
			aux[i][1]=A[i][4];
		}
		printf("X1 = %.2f\n",n3(aux)/determinanteA);
		for (i=1;i<=3;i++){
			aux2[i][2]=A[i][4];
		}
		printf("X2 = %.2f\n",n3(aux2)/determinanteA);
		for (i=1;i<=3;i++){
			aux3[i][3]=A[i][4];
		}
		printf("X3 = %.2f\n",n3(aux3)/determinanteA);
	}
	/*if (tamano==4){
		for (i=1;i<=4;i++){
			aux[i][1]=A[i][5];
		}
		printf("X1 = %.2f\n",n4(aux)/determinanteA);
		for (i=1;i<=4;i++){
			aux2[i][2]=A[i][5];
		}
		printf("X2 = %.2f\n",n4(aux2)/determinanteA);
		for (i=1;i<=4;i++){
			aux3[i][3]=A[i][5];
		}
		printf("X3 = %.2f\n",n4(aux3)/determinanteA);
		for (i=1;i<=4;i++){
			aux4[i][4]=A[i][5];
		}
		printf("X4 = %.2f\n",n4(aux4)/determinanteA);*/
	system("pause");
}
void tamanoMatriz (int *fila, int *columna){
	puts("Fila de la matriz:");
	scanf("%d",fila);
	puts("Columna de la matriz:");
	scanf("%d",columna);
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

