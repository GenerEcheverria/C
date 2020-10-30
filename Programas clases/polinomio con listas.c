#include<stdio.h>
#include<stdlib.h>
//usuario pone grado del polinomio
struct termino {
	int coeficiente;
	int exponente;
	struct termino* enlace;
};
struct termino* crearInicial(int coeficiente, int exponente);
void insertarNodo(struct termino*, int coeficiente, int exponente);
int potencia(int base, int exponente);
int sumaTerminos(struct termino*);
int main (){
	struct termino* cabecera;
	int grado,coef,expo;
	int i;
	puts("Escribe el grado del polinomio: ");
	scanf("%d", &grado);
	for (i=0;i<grado;i++){
		printf("Escribe el coeficiente del termino %d: ",i+1);
		scanf("%d",&coef);
		printf("Escribe el exponente del termino %d: ",i+1);
		scanf("%d",&expo);
		if (i==0){
			cabecera = crearInicial(coef, expo);
		}
		else{
			insertarNodo(cabecera,coef, expo);
		}
	}
	printf("El resultado es: %d",sumaTerminos(cabecera));
	return 0;

}
struct termino* crearInicial(int coeficiente, int exponente){
	struct termino* nuevo;
	nuevo = (struct termino*)malloc(sizeof(struct termino)); 
	nuevo -> coeficiente = coeficiente ; 
	nuevo -> exponente = exponente;
	nuevo -> enlace = NULL; 
	return nuevo;
}
void insertarNodo(struct termino* cabecera, int coeficiente, int exponente){
	struct termino* actual; 
	struct termino* anterior; 
	actual = cabecera;
	anterior = NULL;
	
	while (actual != NULL ){
		anterior =actual;
		actual = actual-> enlace;
	
	}
	struct termino* nuevo; 
	nuevo = (struct termino*)malloc(sizeof(struct termino)); 
	nuevo -> coeficiente = coeficiente ; 
	nuevo -> exponente = exponente;
	nuevo -> enlace = NULL; 
	anterior -> enlace = nuevo;
	return;
}
int potencia (int base,int exponente){
	int i,resu=1;
	for (i=1;i<=exponente;i++){
		resu*=base;
	}
	return resu;
}
int sumaTerminos(struct termino* cabecera){
	int x, resultado=0;
	puts("Escribe el valor de la incognita");
	scanf("%d",&x);
	int sum;
	struct termino* actual;
	actual = cabecera;
	while (actual != NULL){
		resultado+= actual->coeficiente*potencia(x,actual->exponente);
		actual = actual->enlace ;
	}
	return resultado;
}
