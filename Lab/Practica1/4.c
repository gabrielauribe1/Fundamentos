#include<stdio.h>
void pedirnum (int *num);
void dividirimprimir (int num, int *a);
int main (void)
{
  int num, a=0;
  pedirnum(&num);
  dividirimprimir (num,&a);
}
void pedirnum (int *num)
{
  printf("Introduzca un mumero: ");
  scanf("%d",num);
}
void dividirimprimir (int num, int *a)
{
  int i;
  for (i=1; i<=num; i++)
    {
      if (num%i==0)
	*a++;
    }
  if (*a<=2)
    printf("el numero es primo \n");
  else
    {
      printf("el numero no es primo \n");
    }
}


  
