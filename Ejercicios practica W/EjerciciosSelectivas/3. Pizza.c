//pizza
#include<stdio.h>
#include<windows.h>
int main (){
	int numero;
	do {
		puts("Escoge: \n1.Pasta\n2.Pizza\n3.Panini\n4.Ensalada");
		scanf("%i",&numero);
		system ("cls");
	} while (numero<1 || numero>4);	
	switch (numero){
		case 1: puts ("Pasta"); break;
		case 2: puts ("Pizza"); break;
		case 3: puts ("Panini"); break;
		case 4: puts ("Ensalada"); break;
	}
	return 0;
}
