#include<stdio.h>
int factorial(int numero);
int main (void)
{
  int num;
  printf("Introduzca un numero: \n");
  scanf("%d", &num);
  printf("El factorial de %d es %d \n", num, factorial(num));
}
int factorial(int numero)
{
  if(numero>1)
    return numero*factorial(numero-1);
  else
    return 1;
}

				     
