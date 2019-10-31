#include<stdio.h>

void pideordena (int lista[], int a, int i);
void imprime (int lista[], int i);
int main (void)
{
  int i, a, lista[100];
      printf("Indique cuántos números va a introducir: \n");
      scanf("%d", &i);
      printf("Introduzca los numeros: \n");
      for (a=0; a<i; a++)
    {
      scanf("%d", &lista[a]);
    }
      pideordena (lista, a, i);
      imprime(lista, i);
}
void pideordena (int lista[], int a, int i)
{
  int temp, j;
   for (a=0; a<i; a++)
     {
       for (j=a+1; j<i; j++)
	 {
	   if (lista [a]>lista[j])
	     {
	       temp=lista[a];
	       lista[a]=lista[j];
	       lista [j]=temp;
	     }
	 }
     }
}
void imprime (int lista[], int i)
{
  int m;
   for(m=0; m<i; m++)
     {
       printf("numero [%d]: %d \n", m+1, lista[m]);
     }
}

