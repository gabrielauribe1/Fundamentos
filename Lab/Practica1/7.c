#include <stdio.h>
void valores ();
void intercambia ();
int main (void)
{
  int a, b, c, sup;
  valores ();
  intercambia();
  printf("los valores intercambiados son %d, %d, %d",a,b,c);
}
void valores ()
{
  int x,y,z;
  printf("Introduzca 3 valores separados por comas: ");
  scanf("%d,%d,%d",&x,&y,&z);

} 
void intercambia ()
{
  int a,b,c,sup;
  a=b;
  b=c;
  c=sup;
}

  
