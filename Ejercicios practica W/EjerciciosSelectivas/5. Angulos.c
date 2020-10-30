//tipo de grado
#include<stdio.h>
int main (){
	float grado;
	puts("Introduce la medida del angulo");
	scanf("%f",&grado);
	if (grado==90){
		printf("El angulo de %.2f grados es recto",grado);
	}
	else {
		if (grado<90){
			printf("El angulo de %.2f grados es agudo",grado);
		}
		else {
			if (grado<180) {
				printf("El angulo de %.2f grados es agudo",grado);
			}
			else {
				if (grado == 180){
					printf("El angulo de %.2f grados es llano",grado);
				}
				else {
					printf("El angulo de %.2f grados es concavo",grado);
				}
			}
		}
	}	
	return 0;
}
