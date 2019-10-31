#include<stdio.h>
int main (void)
{
  int i, suma, numero;
  suma=0;
  for(i=1; i<=10; i++)
    {
      printf("Introduzca numero: ");
      scanf("%d",&numero);
      suma=suma+numero;
    }
  printf("la suma de los numeros es: %d \n",suma);
}

    
