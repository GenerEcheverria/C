//NumeroNarcisista

#include<stdio.h>

int main() {
	int suma; //suma de las potencias
	int digEntrada; //digito de entrada
	int contDigito; //Contador de digitos
	int aux;
	int n; //digito de entrada
	int x; //almacena contador de digito
	int potencia; //digito elevado a la potencia 
	int i; //contador 1
	int i2; //contador 2
	
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
	x=contDigito;
	suma=0;
	for (i=0;i<contDigito;i++){
		potencia = 1;
		for(i2=0; i2<contDigito; i2++){   
			potencia=potencia*V[i];
		}
		suma=suma+potencia;
	}
	//Salida
	if (suma==digEntrada) {
		printf("%i es un numero narcisista", digEntrada);
	}
	else {
		printf("%i no es un numero narcisista", digEntrada);
	}
	
	return 0;
}
