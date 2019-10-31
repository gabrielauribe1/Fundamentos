#include<stdio.h>
void baset (int *base);
void alturat (int base,int *altura);
void superficiet (int base, int altura);
int main (void)
{
  int base, altura, area;
  baset(&base);
  alturat(base,&altura);
  superficiet(base,altura);
 
}
void baset (int *base)
{
 printf("Introduzca la base del triángulo: ");
  scanf("%d",base);
  if (base==0)
    printf("la base no puede ser 0");
}
void alturat (int base, int *altura)
{
 
 if (base!=0)
    {
    printf("Introduzca la altura del triángulo: ");
    scanf("%d",altura);
    if (altura==0)
    printf("la altura no puede ser 0");
    }
}
void superficiet (int base, int altura)
{
 if(altura!=0)
    printf("la superficie el triangulo es %d",(base*altura)/2);
}

