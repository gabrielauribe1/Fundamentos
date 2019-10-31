#include<stdio.h>
#include<string.h>

typedef struct defAlumno /*se declara donde se desee usar*/
{
  char nombre[30];
  char cuenta[15];
  float cal1, cal2, cal3;
}tipoalumno;

void leer_datos(tipoalumno alumnos[5]);
void imprimir_datos(tipoalumno alumnos[5]);

int main (void)
{
  tipoalumno alumnos[5];
  leer_datos(alumnos);
  imprimir_datos(alumnos);
}
void leer_datos(tipoalumno alumnos[5])
{
  int i;
  for(i=0; i<5; i++)
    {
      __fpurge(stdin);
      printf("Introduzca el nombre del alumno %d:\n", i+1);
      gets(alumnos[i].nombre);
      printf("Introduzca la cuenta del alumno %d:\n", i+1);
      gets(alumnos[i].cuenta);
      printf("Introduzca las 3 calificaciones del alumno %d:\n", i+1);
      scanf("%f, %f, %f", &alumnos[i].cal1, &alumnos[i].cal2, &alumnos[i].cal3);
    }
}
void imprimir_datos(tipoalumno alumnos[5])
{
  int i;
  float suma=0, prom=0;
  for (i=0; i<5; i++)
    {
      suma=alumnos[i].cal1+alumnos[i].cal2+alumnos[i].cal3;
      prom=suma/3;
      printf("El nombre del alumno %d es: %s, la cuenta es: %s y el promedio es: %f \n",i+1, alumnos[i].nombre, alumnos[i].cuenta, prom);
    }
}

 

  
