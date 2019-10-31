#include<stdio.h>

int main (void)
{
  int i, num, fact=1;

  printf("introduzca número para saber su factorial: ");
  scanf("%d", &num);

  for(i=1; i<=num; i++)
    fact=fact*i;

  printf("El resultado es %d \n", fact);

  return 0;
}
