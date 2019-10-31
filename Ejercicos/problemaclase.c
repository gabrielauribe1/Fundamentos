#include<stdio.h>
void main (void)
{
  float numero, mayor=-1;
    do
      {
	printf("Introduzca un numero positivo (negativo para terminar)");
	scanf("%f", &numero);
	if(numero>mayor)
	  mayor=numero;
      }
    while(numero>=0);
  printf("el mayor fue %f \n", mayor);
}
