#include<stdio.h>
void leernum (int *num, int *potencia);
void elevar (int num, int potencia, int *resultado);
int main (void)
{
  int num, potencia, resultado;
  leernum(&num,&potencia);
  elevar(num,potencia,&resultado);
  printf("El resultado de la potencia es %d \n",resultado);
}
void leernum (int *num, int *potencia)
{
  printf("Introduzca el número que desea elevar: \n");
  scanf("%d", num);
  printf("Introduzca la potencia: \n");
  scanf("%d", potencia);
}
void elevar (int num, int potencia, int *resultado)
{
  int a=1, i=1;
  while (i<=potencia)
    {
      a*=num;
      i++;
    }
  *resultado =a;
}
