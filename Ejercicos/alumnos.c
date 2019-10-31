#include<stdio.h>

int main (void)
{
  float suma=0, sumatotal=0, promedio, cal1, cal2, cal3;
  int i;
for(i=1; i<=20; i++)
  {
    printf("introduzca las 3 calificaciones del alumno %d: ", i);
    scanf("%f,%f,%f", &cal1, &cal2, &cal3);
    suma=cal1+cal2+cal3;
    promedio=suma/3;
    printf("el promedio total del alumno %d es %f \n",i,promedio);
    sumatotal=sumatotal+suma;
  }
 printf("el promedio total de grupo es %f \n", sumatotal/60);
}
