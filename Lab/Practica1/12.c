#include<stdio.h>
void suma (void);
int main (void)
{
  suma ();
}
void suma (void)
{
  int i=1,num, suma=0; 
  while(i<=10)
  {
  printf("Introduzca un número \n");
  scanf("%d",&num);
  suma=suma+num;
  i++;
  }
  printf("la suma de los 10 numeros es %d \n",suma);
}

  
