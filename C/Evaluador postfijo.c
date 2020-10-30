#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
#include <math.h>
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
void push (struct Pila*pila, char operador);
int evaluaPostfija(char* expresion);
int main() { 
    char expresion[] = "25^"; 
    printf ("Resultado de la expresion: %d", evaluaPostfija(expresion)); 
    return 0; 
} 
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
void push(struct Pila* pila, char operador) { 
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
        	push(pila, expresion[i] - '0'); 
        }
        else{ 
            int operando1 = pop(pila); 
            int operando2 = pop(pila); 
            switch (expresion[i]) 
            { 
            case '+': push(pila, operando2 + operando1); break; 
            case '-': push(pila, operando2 - operando1); break; 
            case '*': push(pila, operando2 * operando1); break; 
            case '/': push(pila, operando2/operando1); break; 
            case '^': push(pila, pow(operando2,operando1));break;
            } 
        } 
    } 
    return pop(pila); 
} 
