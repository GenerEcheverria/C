#include<stdio.h>
#include<stdlib.h>
struct elemento {
	int dato;
	struct elemento* siguiente;
};
void push (int dato, struct elemento** pila){
	struct elemento* Elemento= (struct elemento*)malloc(sizeof(struct elemento));
	Elemento->dato=dato;
	Elemento->siguiente=*pila;
	(*pila)=Elemento;
}
void pop (struct elemento** pila) {
	if (*pila!=NULL) {
		printf("Elemento %d eliminado\n",(*pila)->dato);
		struct elemento* aux = *pila;
		*pila=(*pila)->siguiente;
		free(aux);
	}
	else {
		puts("Pila vacia");
	}
}
void top (struct elemento* pila) {
	if (pila !=NULL) {
		printf("%d\n",pila->dato);
	}
	else {
		puts("Esta vacia");
	}
}
int main (){
	struct elemento* cima = (struct elemento*)malloc(sizeof(struct elemento));
	cima->siguiente=NULL;
	push(5,&cima);
	push(3,&cima);
	top (cima);
	pop(&cima);
	top(cima);
	
	return 0;
}
