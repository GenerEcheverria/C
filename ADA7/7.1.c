/*ADA7
Ejercicio 1
Autor: Gener Echeverria
Fecha: 30/04/2020*/
#include<stdio.h>
struct complejo {
	float parteReal;
	float parteImaginaria;
} primerNumero, segundoNumero;
struct resultados{
	float sumaReal;
	float sumaImaginaria;
	float restaReal;
	float restaImaginaria;
	float multiplicacionReal;
	float multiplicacionImaginaria;
	float divisionReal;
	float divisionImaginaria;
} resu;
int main (){
	float denominador;
	puts("Parte real del primer numero");
	scanf("%f",&primerNumero.parteReal);
	puts("Parte imaginaria del primer numero");
	scanf("%f",&primerNumero.parteImaginaria);
	puts("Parte real del segundo numero");
	scanf("%f",&segundoNumero.parteReal);
	puts("Parte imaginaria del segundo numero");
	scanf("%f",&segundoNumero.parteImaginaria);
	resu.sumaReal=primerNumero.parteReal+segundoNumero.parteReal;
	resu.sumaImaginaria=primerNumero.parteImaginaria+segundoNumero.parteImaginaria;
	resu.restaReal=primerNumero.parteReal-segundoNumero.parteReal;
	resu.restaImaginaria=primerNumero.parteImaginaria-segundoNumero.parteImaginaria;
	resu.multiplicacionReal=primerNumero.parteReal*segundoNumero.parteReal-primerNumero.parteImaginaria*segundoNumero.parteImaginaria;
	resu.multiplicacionImaginaria=primerNumero.parteReal*segundoNumero.parteImaginaria+primerNumero.parteImaginaria*segundoNumero.parteReal;
	denominador= segundoNumero.parteReal*segundoNumero.parteReal+segundoNumero.parteImaginaria*segundoNumero.parteImaginaria;
	resu.divisionReal=(primerNumero.parteReal*segundoNumero.parteReal-primerNumero.parteImaginaria*(-segundoNumero.parteImaginaria))/denominador;
	resu.divisionImaginaria=(primerNumero.parteReal*(-segundoNumero.parteImaginaria)+primerNumero.parteImaginaria*segundoNumero.parteReal)/denominador;
	printf("La suma es %.1f + %.1fi\n",resu.sumaReal,resu.sumaImaginaria);
	printf("La resta es %.1f + %.1fi\n",resu.restaReal,resu.restaImaginaria);
	printf("La multiplicacion es %.1f + %.1fi\n",resu.multiplicacionReal,resu.multiplicacionImaginaria);
	printf("La division es %.1f + %.1fi\n",resu.divisionReal,resu.divisionImaginaria);
	system("pause");
	
	return 0;
}
