#include<stdio.h>
void inserta (int lista[], int numero, int *insertados);
void imprime (int lista[], int insertados);
int main (void)
{
  int numeros[100], valor, porintroducir, insertados=0, i;
  do
    {
  printf("Cuantos numeros quieres introducir (maximo 100): \n");
  scanf("%d", &porintroducir);
  if(porintroducir>100)
    printf("Te dije que solo hasta 100");
    }
  while(porintroducir>100);
  for (i=0; i<porintroducir; i++)
    {
      printf("Cual es el numero?: \n");
      scanf("%d", &valor);
      inserta (numeros,valor, &insertados);
    }
  imprime(numeros, insertados);
}
void inserta (int lista[], int numero, int *insertados)
{
  int i, j;
  i=0;
  while((i< *insertados)&&(numero>lista[i]))
    i++;
  if (i< *insertados)
    {
      for (j= *insertados; j>i; j--)
	lista[j]=lista[j-1];
      lista[i]=numero;
      (*insertados)++;
    }
  else
    {
      lista[i]=numero;
      (*insertados)++;
    }
}
void imprime (int lista[], int insertados)
{
  int i;
  for(i=0; i<insertados; i++)
    {
      printf("%d \n", lista[i]);
    }
}
