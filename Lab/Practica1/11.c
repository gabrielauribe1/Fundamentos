#include<stdio.h>
void numeros (int *num, int *mayor);
void imprimir (int mayor);
int main (void)
{
  int num, mayor=0;
  numeros (&num,&mayor);
  imprimir (mayor);
}
void numeros (int *num, int *mayor)
{
  do
    {
  printf("Introduzca número, -99 para terminar: \n");
  scanf("%d",num);
  if (*num>=0)
    {
      if(*num>*mayor)
	*mayor=*num;
    }
    }
  while (*num!=-99);
}
void imprimir (int mayor)
{
  printf("el numero mayor es %d \n", mayor);
}

  
