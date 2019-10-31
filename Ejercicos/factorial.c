#include<stdio.h>

int main (void)
{
  long int i, res=1, num;
  printf("Introduzca el numero: \n");
  scanf("%ld", &num);
  for(i=num; i>0; i--)
    res=res*i;
  printf("%ld \n", res);
}
