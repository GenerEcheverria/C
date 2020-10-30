/*ADA6
Gener Echeverria y Valeria Gonzalez
Fecha: 20/04/2020
Version: 1.0*/
#include<stdio.h>
#include<malloc.h>
#define MAX 100
#include<stdlib.h>
#include <string.h> 
#include <ctype.h> 
#include <math.h>
int comprobadorLexicos (char cadena[]);
int comprobadorSintacticos (char cadena[]);
typedef struct tipoNodo{
	struct tipoNodo *siguiente;
	char dato;
}tipoNodo;
typedef struct tipoNodo *ptrPila; //estructura tipo pila
typedef struct tipoNodo *ptrLista; //estructura tipo lista

void apilar(ptrLista*lista,char cad); //Agregar elementos a lista
void push(ptrPila*pila,char cad); //agregar elementos a pila
char desapilar(ptrPila*pila); //Elimina elementos de la pila 
int PrioridadInfija(char cad); //Prioridad de signos expresion infija
int prioridadPostfija(ptrPila*pila); //Prioridad de signos de la pila
void imprimirLista(ptrLista*lista);
void destruirPila(ptrPila*pila); //destruir pila

//----------
struct Pila { 
    int cima; 
    unsigned capacidad; 
    int* array; 
};  
struct Pila* crearPila(unsigned capacidad) { 
    struct Pila* pila = (struct Pila*) malloc(sizeof(struct Pila)); 
    if (!pila){
    	return NULL; 
    }
    pila->cima = -1; 
    pila->capacidad = capacidad; 
    pila->array = (int*) malloc(pila->capacidad * sizeof(int)); 
  
    if (!pila->array){
    	return NULL; 
    }
    return pila; 
} 
int estaVacia (struct Pila* pila);
char peek (struct Pila* pila);
char pop (struct Pila* pila);
void pushP (struct Pila*pila, char operador);
int evaluaPostfija(char* expresion);
//----------------
void datoLista(ptrLista*lista, char expresion);

void previa(ptrPila*pila){
 ptrPila p;
 p=*pila;
 printf("    »»»»»»»»»»\n");
 printf("    || Null ||\n");
 printf("    »»»»»»»»»»\n");
 while(p!=NULL){
  printf("    »»»»»»»»»»\n");
  if(p->dato<10){
   printf("    ||  %c ||\n",p->dato);
  }
  else{
   printf("    ||  %c ||\n",p->dato);
  }

  printf("    »»»»»»»»»»\n");
  p = p->siguiente;
 }
 printf("    »»»»»»»»»»\n");
 printf("    || PILA ||\n");
 printf("    »»»»»»»»»»\n");
}

void previa2(ptrLista*lista){
 ptrLista l;
 l=*lista;
 printf("    »»»»»»»»»»\n");
 printf("    || Null ||\n");
 printf("    »»»»»»»»»»\n");
 while(l!=NULL){
  printf("    »»»»»»»»»»\n");
  if((l->dato)>=97 && (l->dato)<=122)
  {
  	printf("    ||  %c ||\n",l->dato);
  } else{
   	printf("    ||  %c ||\n",l->dato);
}	 
  printf("    »»»»»»»»»»\n");
  l=l->siguiente;
 }
 printf("    »»»»»»»»»»\n");
 printf("    || LISTA ||\n");
 printf("    »»»»»»»»»»\n");
}

int main(){
	char cad[MAX],aux,aux2, expresion[MAX];
	int i, comprobar=0, k=0;
	ptrPila pila=NULL; ptrLista lista=NULL; //inicializacion vacia
	previa(&pila);
	puts("Expresion: ");
	while (comprobar!=1){
		gets(cad);
		fflush(stdin);
		puts(cad);
		comprobar=comprobadorLexicos(cad);
		if (comprobar==1) {
			comprobar=comprobadorSintacticos(cad);
		}
		if (comprobar==0) {
			puts("Vuelve a introducir la expresion"); continue;
		}
	}
		while(cad[i]!='\0')
			{
				if((cad[i]>=48 && cad[i]<=57) || (cad[i]>=97 && cad[i]<=122))
				{
					apilar(&lista,cad[i]);
					expresion[k]=cad[i];
					k++;
				}
				if(cad[i]=='(')
				{
					push(&pila,cad[i]);
				}
				if(cad[i]==')')
				{
					while(pila!=NULL && pila->dato!='(')
					{
						aux=desapilar(&pila);
						apilar(&lista,aux);
						expresion[k]=aux;
						k++;
					}
					if(pila->dato=='(')
					{
						desapilar(&pila);
					} else
					{
						puts("Error.");
					}	
				}
				if(cad[i]=='+'||cad[i]=='-'||cad[i]=='*'||cad[i]=='/' || cad[i]=='^' )
				{
					while(pila!=NULL && (prioridadPostfija(&pila)>=PrioridadInfija(cad[i])))
					{
						aux=desapilar(&pila);
						apilar(&lista,aux);
						expresion[k]=aux;
						k++;
					}
					push(&pila,cad[i]);
				}
				i++;
			}	
			while(pila!=NULL)
			{
				aux2=desapilar(&pila);
				apilar(&lista,aux2);
				expresion[k]=aux2;
				k++;
			}	
			
			
	previa(&pila);
	printf("\n");	
	previa2(&lista);
	printf("\n");
	imprimirLista(&lista);
	printf ("\nResultado de la expresion: %d\n", evaluaPostfija(expresion)); 
	return 0;
}

void apilar(ptrLista*lista,char cad)
{
	ptrLista nuevo,aux;
	aux=(ptrLista)malloc(sizeof(tipoNodo));
	nuevo=(ptrLista)malloc(sizeof(tipoNodo)); //se reserva memoria a ptrlista de tam. de tipoNodo
	nuevo->dato=cad;
	nuevo->siguiente=NULL;
	
	if(*lista==NULL)
	{
		
		*lista=nuevo;
	}
	else
	{
		aux=*lista;
		while(aux->siguiente!=NULL)
		{
			aux=aux->siguiente;
		}
		aux->siguiente=nuevo;
	}
}
void push(ptrPila*pila,char cad){
	ptrPila p;
	p=(ptrPila)malloc(sizeof(tipoNodo));
	p->dato=cad;
	p->siguiente=*pila;
	*pila=p;
}
char desapilar(ptrPila*pila)
{
	char i;
	ptrPila aux;
	i=(*pila)->dato;
	aux=*pila;
	*pila=(*pila)->siguiente;
	free(aux);
	return i;
}
int prioridadPostfija(ptrPila*pila){
	if((*pila)->dato=='(')
	{
		return 0;
	}
	if((*pila)->dato=='^')
	{
		return 3;
	}
	if((*pila)->dato=='*')
	{
		return 2;
	}
	if((*pila)->dato=='/')
	{
		return 2;
	}
	if((*pila)->dato=='+')
	{
		return 1;
	}
	if((*pila)->dato=='-')
	{
		return 1;
	}	
	
}
int PrioridadInfija(char cad){
	if(cad=='(')
	{
		return 5;
	}
	if(cad=='^')
	{
		return 4;
	}
	if(cad=='*')
	{
		return 2;
	}
	if(cad=='/')
	{
		return 2;
	}
	if(cad=='+')
	{
		return 1;
	}
	if(cad=='-')
	{
		return 1;
	}
}
void imprimirLista(ptrLista*lista){
	ptrPila aux;
	aux=*lista;
	if(lista!=NULL)
	{
		puts("Postfija: ");
		while(aux!=NULL)
		{
			printf("%c",aux->dato);
			aux=aux->siguiente;
		}
	}
}

void destruirPila(ptrPila*pila){
	free((*pila)->siguiente);
	free(*pila);
	*pila=NULL;	
}
int comprobadorLexicos(char cadena[]){
	int i=0, j, comp=0, izquierda=0, derecha=0, aux=0;
	while (cadena[i]!='\0'){
		if (cadena[i]>=48 && cadena[i]<=57){
			comp=1;
			if (cadena[i+1]>=48 && cadena[i+1]<=57){
				comp=0; 
				printf("Error Lexico. %c%c es mayor a 9.\n", cadena[i], cadena[i+1]); break;
			}
		}
		if (cadena[i]!=94 && cadena[i]!=42 && cadena[i]!=43 && cadena[i]!=47 && cadena[i]!=45 && cadena[i]!=40 && cadena[i]!=41 && cadena[i]!=120){
			if (cadena[i]<48 || cadena[i]>57) {
				if (cadena[i]==46) {
					printf("Error Lexico. Error en la secuencia %c%c%c\n",cadena[i-1],cadena[i],cadena[i+1]);
					comp=0; break;
				}
				printf("Error Lexico. Error en el caracter %c\n", cadena[i]);
				comp=0; break;
			}
			
		}		
		i++;
	}
	return comp;
}
int comprobadorSintacticos (char cadena[]) {
	int i=0, j, comp=1, izquierda=0, derecha=0, aux=0;
	while (cadena[i]!='\0') {
		if (cadena[i]==94 || cadena[i]==42 || cadena[i]==43 || cadena[i]==47 || cadena[i]==45 ){
			comp=1;
			if (cadena[i+1]==94 || cadena[i+1]==42 || cadena[i+1]==43 || cadena[i+1]==47 || cadena[i+1]==45) {
				comp=0;
				printf("Error Sintactico. Error en la secuencia %c%c.\n", cadena[i], cadena[i+1]); break;
			}
			
		}
		if (cadena [i] == 40) {
			j=i;
			while (cadena[j]!='\0') {
				j++;
				if (cadena [j-1]==40 && cadena[j]==41){
					comp=0;
					printf("Error Sintactico. Error en la secuencia %c%c\n",cadena[j-1],cadena[j]); break; 
				} 
				if (cadena[j-1]==40) {
					izquierda++;
				}
				if (cadena[j-1]==41) {
					derecha++;
				}
				j++;
			}
			if (aux==0){
				if (izquierda>derecha) {
					comp=0;
					puts("Error Sintactico. Falta un ')'"); break;
				}
				else {
					if (derecha>izquierda) {
						comp=0;
						puts("Error Sintactico. Falta un '('"); break;
					}
					else {
						aux=1;
					}
				}	
			}
		}
		if (cadena[i]==41){
			j=0;
			while (cadena[j]!='\0') {
				if (cadena[j]==40){
					izquierda++;
				}
				if (cadena[j]!=41) {
					derecha++;
				}
				j++;
			}
			if (aux==0){
				if (izquierda>derecha) {
					comp=0;
					puts("Error Sintactico. Falta un ')'"); break;
				}
				else {
					if (derecha>izquierda) {
						comp=0;
						puts("Error Sintactico. Falta un '('"); break;
					}
					else {
						aux=1;
					}
				}	
			}
		}
		i++;
	}
	return comp;
}
//------
int estaVacia(struct Pila* pila){ 
    return pila->cima == -1 ; 
} 
char peek(struct Pila* pila){ 
    return pila->array[pila->cima]; 
} 
char pop(struct Pila* pila){ 
    if (!estaVacia(pila)) 
        return pila->array[pila->cima--] ; 
    return '$'; 
} 
void pushP(struct Pila* pila, char operador) { 
    pila->array[++pila->cima] = operador; 
} 
int evaluaPostfija(char* expresion){ 
    struct Pila* pila = crearPila(strlen(expresion)); 
    int i; 
    if (!pila){
    	return -1; 
    } 
    for (i = 0; expresion[i]; ++i){ 
        if (isdigit(expresion[i])) {
        	pushP(pila, expresion[i] - '0'); 
        }
        else{ 
            int operando1 = pop(pila); 
            int operando2 = pop(pila); 
            switch (expresion[i]) 
            { 
            case '+': pushP(pila, operando2 + operando1); break; 
            case '-': pushP(pila, operando2 - operando1); break; 
            case '*': pushP(pila, operando2 * operando1); break; 
            case '/': pushP(pila, operando2/operando1); break; 
            case '^': pushP(pila, pow(operando2,operando1));break;
            } 
        } 
    } 
    return pop(pila); 
} 
