#include<stdio.h>
void temperaturas (float lista[]);
void imprimir (float lista[]);
int main (void)
{
  float lista [24];
  temperaturas(lista);
  imprimir(lista);
}
void temperaturas (float lista[])
{
  int i;
  printf("Introduzca las 24 temperaturas, una por cada hora: \n");
  for (i=0; i<24; i++)
    {
      scanf("%f", &lista[i]);
    }
}
void imprimir (float lista[])
{
  int i;
  float suma=0, mayor, menor;
  mayor=lista[0];
  menor=lista[0];
  for (i=0; i<24; i++)
    {
  suma=suma+lista[i];
  if (lista[i]>mayor)
    mayor=lista[i];
  if (lista[i]<menor)
    menor=lista[i];
    }
  printf("La suma de las temperaturas es: %.2f \n", suma);
  printf("El promedio de las temperaturas es : %.2f \n", suma/24);
  printf("La temperatura mayor es: %.2f \n", mayor);
  printf("La temperatura menor es: %.2f \n", menor);
}
