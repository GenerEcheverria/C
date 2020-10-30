#include <stdio.h>

struct complejo{
	float parteReal;
	float parteImaginaria;	
};


int main(int argc, char *argv[]) {

	struct complejo a;
	struct complejo b;
	struct complejo sumaab;
	struct complejo restaab;
	struct complejo multiplicacionab;
	struct complejo divisionab;
	puts("Introduce la parte Real del número complejo a");
	scanf("%f", &a.parteReal);
	puts("Introduce la parte Imaginaria del número complejo a");
	scanf("%f", &a.parteImaginaria);
	puts("Introduce la parte Real del número complejo b");
	scanf("%f", &b.parteReal);
	puts("Introduce la parte Imaginaria del número complejo b");
	scanf("%f", &b.parteImaginaria);
	
	sumaab.parteReal= a.parteReal + b.parteReal;
	sumaab.parteImaginaria= a.parteImaginaria + b.parteImaginaria;	
	restaab.parteReal= a.parteReal - b.parteReal;
	restaab.parteImaginaria= a.parteImaginaria - b.parteImaginaria;
	multiplicacionab.parteReal= a.parteReal * b.parteReal;
	multiplicacionab.parteImaginaria= a.parteImaginaria * b.parteImaginaria;	
	divisionab.parteReal= a.parteReal / b.parteReal;
	divisionab.parteImaginaria= a.parteImaginaria / b.parteImaginaria;	
	
	printf("Suma de a+b: (%.1f + %.1fi)\n",sumaab.parteReal, sumaab.parteImaginaria);
	printf("Resta de a+b: (%.1f + %.1fi)\n",restaab.parteReal, restaab.parteImaginaria);
	printf("Multiplicación de a+b: (%.1f + %.1fi)\n",multiplicacionab.parteReal,multiplicacionab.parteImaginaria);
	printf("División de a+b: (%.1f + %.1fi)\n",divisionab.parteReal, divisionab.parteImaginaria);
	return 0;
}

