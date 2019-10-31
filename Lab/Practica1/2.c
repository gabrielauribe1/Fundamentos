#include<stdio.h>
void serie (int *cont);
int main (void)
{
    int cont=0;
  serie (&cont);
}
void serie (int *cont)
{
  int i;
    for(i=3;i<=99;i+=3)
    *cont=*cont+i;
  printf("La suma de la series de 3...99 es: %d\n",*cont);
}
