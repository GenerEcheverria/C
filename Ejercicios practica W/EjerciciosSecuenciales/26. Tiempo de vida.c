//dias que ha vivido
#include<stdio.h>
#include<stdlib.h>
int main (){
	float dia, mes,anio, diaFecha,mesFecha,anioFecha, diaPersona, mesPersona, anioPersona, totalMeses, totalSemana, totalDia,totalHora;
	puts("Fecha actual: dd/mm/aaaa");
	scanf("%f/%f/%f",&diaFecha,&mesFecha,&anioFecha);
	puts("Fecha de nacimiento: dd/mm/aaaa");
	scanf("%f/%f/%f",&diaPersona,&mesPersona,&anioPersona);
	dia=diaFecha-diaPersona;
	mes=mesFecha-mesPersona;
	anio=anioFecha-anioPersona;
	totalMeses= anio*12+mes+dia/30;
	totalSemana=anio*52+mes*4.3+dia/7;
	totalDia=anio*365+mes*30+dia;
	totalHora=totalDia*24;
	printf("Total de meses:%.2f\nTotal de semanas:%.2f\nTotal de dias:%.2f\nTotal de horas:%.2f\n",totalMeses,totalSemana,totalDia,totalHora);
	system ("pause");
	return 0;
}
