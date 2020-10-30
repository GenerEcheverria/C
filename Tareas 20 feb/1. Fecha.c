#include<stdio.h>
#include<string.h>
void fecha1 (int dia, int mes, int anio);
void fecha2 (int dia, int mes, int anio);
int main(){
	int dia,mes,anio;
	puts("Escribe el dia: ");
	scanf("%i",&dia);
	puts("Escribe el mes: ");
	scanf("%i",&mes);
	puts("Escribe el anio: ");
	scanf("%i",&anio);
	fecha1(dia,mes,anio);
	fecha2(dia,mes,anio);
	return 0;
}
void fecha1 (int dia, int mes, int anio){
	int u,d;
	u=anio%10;
	anio=(anio-u)/10;
	d=anio%10;
	printf("%02i/%02i/%i%i\n",dia,mes,d,u);
}
void fecha2 (int dia, int mes, int anio){
	char fecha[20];
	char mesNombre [20];
	switch (mes){
		case 1: strcpy(mesNombre, "enero"); break;
		case 2: strcpy(mesNombre, "febrero"); break;
		case 3: strcpy(mesNombre, "marzo"); break;
		case 4: strcpy(mesNombre, "abril"); break;
		case 5: strcpy(mesNombre, "mayo"); break;
		case 6: strcpy(mesNombre, "junio"); break;
		case 7: strcpy(mesNombre, "julio"); break;
		case 8: strcpy(mesNombre, "agosto"); break;
		case 9: strcpy(mesNombre, "septiembre"); break;
		case 10: strcpy(mesNombre, "octubre"); break;
		case 11: strcpy(mesNombre, "noviembre"); break;
		case 12: strcpy(mesNombre, "diciembre"); break;
	}
	sprintf(fecha, "%02i/%s/%i\n", dia, mesNombre, anio);
	puts(fecha);
}
