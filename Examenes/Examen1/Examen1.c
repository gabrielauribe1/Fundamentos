#include<stdio.h>
void numeros (int *num);
void digitos (int num, int a, int *sum);
void suma (int a, int sum, int *dig);

int main (void)
{
  int num, sum=0, dig=0, a;
  numeros (&num);
  digitos (num,a, &sum);
  suma (a, sum, &dig);
}
void numeros (int *num)
{
do
{
printf("Introduzca un numero: ");
scanf("%d", num);
if(*num<0)
printf("*Introduzca un numero que sea positivo  \n");
}
while (num<0);
}
void digitos (int num, int a, int *sum)
{
  for (a=1; a<num; a++)
    *sum=*sum+a;
}
void suma (int a, int sum, int *dig)
{
  *dig=*dig+a++;
  printf("Los digitos introducidos son %d, la suma de los digitos es %d \n", sum, *dig);
}

