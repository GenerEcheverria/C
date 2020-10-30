//Digitos pares
#include<stdio.h>

int main() {

	int digEntrada; //digito de entrada 
	int contDigito; //contador de digitos
	int aux; //auxiliar
	int n; //digito de entrada
	int i; //contador principal
	int contPares; //contador de pares
	
	//Entrada
	printf("Escribe un numero entero ");
	scanf("%i",&n);  
	
	//Proceso
	contDigito=0;
	digEntrada=n;
	
	while (n!=0) {
		contDigito++;
		aux = n%10; 
		n = (n-aux)/10; 
	}
	
	n=digEntrada;
	int V[contDigito];
	
	for(i=0;i<contDigito; i++){
		V[i]=n%10;
		n=(n-V[i])/10;
	}
	contPares=0;
	for (i=0;i<contDigito;i++){
		if (V[i]!=0) {
			if (V[i]%2==0) {
				contPares++;
			}
		}
	}

	//salida
	printf("Digitos pares: %i",contPares); 

	return 0;
}
