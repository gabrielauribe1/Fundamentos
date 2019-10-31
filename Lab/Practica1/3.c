#include<stdio.h>
void leer(int *a, int *b, int *c, int *d);
void intercambia(int a, int b, int c, int d, int e);
int main (void)
{
  int a,b,c,d,e;
  leer(&a,&b,&c,&d);
  intercambia(a,b,c,d,e);
}
void leer(int *a, int *b, int *c, int *d)
{
  printf("introduzca 4 numeros separados por comas: ");
  scanf("%d,%d,%d,%d",a,b,c,d);
}
void intercambia(int a, int b, int c, int d, int e)
{
  if(a>=b)
    e=a;
  if(b>=c)
    e=b;
  if(c>=d)
    e=c;
  if(d>=a)
    e=d;
  printf("el numero mayor es %d \n",e);
}

