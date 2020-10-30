#include <stdio.h>

int main(int argc, char *argv[]) {

struct complejo{
float parteReal;
float parteImaginaria;
};

struct alumno{  
int matricula;
float calificacion;
struct complejo numComplejo;
};

struct alumno a;

struct alumno* aptAlumno;
aptAlumno = &a;

printf("matricula: ");
//scanf("%d", &a.matricula);
scanf("%d", &aptAlumno->matricula);

printf("calificacion: ");
//scanf("%f", &a.calificacion);
scanf("%f", &aptAlumno->calificacion);

printf("Parte Real: ");
scanf("%f", &aptAlumno->numComplejo.parteReal);
printf("Parte Imaginaria: ");
scanf("%f", &aptAlumno->numComplejo.parteImaginaria);
printf("Complejo: (%.1f + %.1fi)",aptAlumno->numComplejo.parteReal, aptAlumno->numComplejo.parteImaginaria);
return 0;
}
#include <stdio.h>

int main(int argc, char *argv[]) {

struct complejo{
float parteReal;
float parteImaginaria;
};

struct alumno{  
int matricula;
float calificacion;
struct complejo numComplejo;
};

struct alumno a;

printf("matricula: ");
scanf("%d", &a.matricula);
printf("calificacion: ");
scanf("%f", &a.calificacion);
printf("Parte Real: ");
scanf("%f", &a.numComplejo.parteReal);
printf("Parte Imaginaria: ");
scanf("%f", &a.numComplejo.parteImaginaria);
printf("Complejo: (%.1f + %.1fi)",a.numComplejo.parteReal, a.numComplejo.parteImaginaria);
return 0;
}
