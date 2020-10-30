#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct temperatura {    
	float temperaturaMaxima;
	float temperaturaMinima; 
}; 


void leerDatos(struct temperatura[],int); 
void convertirGradosFarenheit(struct temperatura[],int);

int main(int argc, char *argv[]) {

	struct temperatura vectorTemperaturas[2]; //crear el vector de temperaturas
	leerDatos(vectorTemperaturas,2); // Función para asignar valores aleatorios al vector
	convertirGradosFarenheit(vectorTemperaturas,2); //Función para convertir a grados Farenheit

	return 0;
}

void leerDatos(struct temperatura vectorTemperaturas[], int n){
	float temp1;
	float temp2;
	for(int i=0; i<n; i++){
		temp1 = rand() % 41;
		temp2 = rand() % 41;
		if (temp1>=temp2){
			vectorTemperaturas[i].temperaturaMaxima = temp1;
			vectorTemperaturas[i].temperaturaMinima = temp2;	
		}else{
			vectorTemperaturas[i].temperaturaMaxima = temp2;
			vectorTemperaturas[i].temperaturaMinima = temp1;			
		}
	}	
	return;
}

void convertirGradosFarenheit(struct temperatura vectorTemperaturas[], int n){
	float farenheitTempMaxima;
	float farenheitTempMinima;

	for (int i=0; i<n; i++){
		//Convirtiendo la temperatura a grados Farenheit ºF = ºC*9/5+32
		farenheitTempMaxima = vectorTemperaturas[i].temperaturaMaxima*(9/5) + 32;
		farenheitTempMinima = vectorTemperaturas[i].temperaturaMinima*(9/5) + 32;
		printf("Temperatura Máxima: Celsius (%f), Farenheit (%f)\n",
			   vectorTemperaturas[i].temperaturaMaxima, farenheitTempMaxima);
		printf("Temperatura Míxima: Celsius (%f), Farenheit (%f)\n",
			   vectorTemperaturas[i].temperaturaMinima, farenheitTempMinima);
	}	
	return;
}
