//5 metodo de la secante
//Gener Echeverria y Valeria Gonzazlez
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float XnMas1 (float x1, float x0);
float errorRelativo (float x1, float x2);
float errorA(float x1, float x2);
int main (){
	float x0,x1,x2, Ea, Er=2;
	int i=0;
	printf("Para f(x)=x2-4\n");
	printf("Dame el valor de x0: ");
	scanf("%f",&x0);
	printf("Dame el valor de x1: ");
	scanf("%f",&x1);
	while (Er>1) {
		x2=XnMas1(x1,x0);
		Ea=errorA(x1,x2);
		Er=errorRelativo(x1,x2);
		printf("i=%i    x(%i)=%.4f    x(%i)=%.4f    x(%i)=%.4f    Ea=%.4f    Er=%.2f \n",i,i,x0,i+1,x1,i+2,x2, Ea, Er);
		x0=x1;
		x1=x2;
		i++;
	}
	printf("Se termina el proceso iterativo con la encontrada de la raiz para X(%i): %.4f \n",i+1,x2);
	
	system("pause");
	return 0;
}
float XnMas1 (float x1, float x0){
	float x2, resXnMas1, numerador,denominador;
	numerador= x1-x0;
	denominador= (x1*x1-4)-(x0*x0-4);
	x2= x1-(numerador/denominador*(x1*x1-4));
	return x2;
}
float errorRelativo (float x1, float x2){
	float error;
	error= (x1-x2)/x2;
	error= fabs(error)*100;
	return error;
}
float errorA(float x1, float x2){
	float numerador;
	numerador=x1-x2;
	numerador= fabs(numerador);
	return numerador;
}
