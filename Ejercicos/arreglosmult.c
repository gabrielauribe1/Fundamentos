#include<stdio.h>
void leercals (float cals[10][3]);
void imprimircals (float cals [10][3]);
int main(void)
{
  float grupo[10][3];
  leercals(grupo);
  imprimircals(grupo);
}
void leercals (float cals[10][3])
{
  int i,j;
  for(i=0;i<10;i++)
    {
      printf("Introduzca las calificaciones del alumno %d \n", i+1);
      for (j=0; j<3; j++);
      {
	printf("calificación %d: ", j+1);
	scanf("%f",&cals[i][j]);
      }
    }
}
void imprimircals (float cals [10][3])
{
  int i,j;
  for(i=0; i<10; i++)
    {
      printf("Las calificaciones del alumno %d son: ", i+1);
      for (j=0; i<3; j++)
	printf("%f \t", cals[i][j]);
      printf("\n");
    }
}
