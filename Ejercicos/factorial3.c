#include<stdio.h>

int factorial(int num, long *res);

int main (void)
{
  int num;
  long res;
  printf("calculo recursivo del factorial de un numero. \n");
  printf("Introduzca un numero: \n");
  scanf("%d", &num);
  factorial(num, &res);
  printf("El factorial de %d = %ld \n", num,res);
}
int factorial(int num, long *res)
{
  printf("Entrada a Factorial: num=%d, *res = %ld\n", num, *res);
  if(num>1)
    factorial(num-1, res);
  else
    *res=1;
  *res*=num;
  printf("salida de factorial: num=%d, *res=%ld\n", num, *res);
}
