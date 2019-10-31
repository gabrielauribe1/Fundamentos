#include<stdio.h>
void funcion (int *a, int *b, int *c);
int main (void)
{
  int a,b,c;
  for(b=1; b<=20; b++)
    {
  funcion(&a,&b,&c);
    }
 
}
void funcion (int *a, int *b, int *c)
{
  for((*a)=1; (*a)<=10; (*a)++)
    {
      *c=(*b)*(*a);
      printf("%d * %d = %d\n",*b,*a,*c);
    }
}



  
 
