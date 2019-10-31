#include<stdio.h>
int main (void)
{
  int lista[10], mayor, menor, i;
  float suma=0;
  printf("Introduzca 10 numeros enteros: \n");
  for (i=0; i<10; i++)
    {
      scanf("%d", &lista[i]);
    }
  mayor=lista[0];
  menor=lista[0];
  for (i=0; i<10; i++)
    {
      suma=suma+lista[i];
      if (lista [i]>mayor)
	mayor=lista[i];
      if (lista [i]<menor)
	menor=lista[i];
    }
  printf("La suma de los numeros es: %.2f \n",suma);
  printf ("El promedio de los numeros es: %f \n", suma/10);
  printf ("El mayor es: %d \n", mayor);
  printf ("El menor es: %d \n", menor);
}

