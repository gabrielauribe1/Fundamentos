#include<stdio.h>
void intercambia (int *a, int *b, int *c);
int main (void)
{
  int x,y,z;
  printf("Introduzca 3 valores separados por comas:  ");
  scanf("%d,%d,%d", &x, &y, &z);
  intercambia(&x,&y,&z);
  printf("Los valores intercambiados son: %d,%d,%d \n", x,y,z);
}
void intercambia (int *a, int *b, int *c)
{
  int tap;
  tap=*a;
  *a=*c;
  *c=*b;
  *b=tap;
}
