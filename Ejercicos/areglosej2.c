#include<stdio.h>
int main (void)
{
  int lista[100], a, i, j, temp, m; 
  printf("Indique cuantos numeros va a introducir: \n");
  scanf("%d", &i);
  printf("Introduzca los numeros: \n");
   for (a=0; a<i; a++)
    {
      scanf("%d", &lista[a]);
    }
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
   for(m=0; m<i; m++)
     {
       printf("numero [%d]: %d \n", m+1, lista[m]);
     }
   
}

     
