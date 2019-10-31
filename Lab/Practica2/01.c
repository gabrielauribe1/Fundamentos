#include<stdio.h>
void calcula (int num[100][2]);
void imprime (int num [100][2]);
int main(void)
{
  int num[100][2];
  calcula(num);
  imprime(num);
}
void calcula (int num[100][2])
{
  int i, j=1;
  for (i=0;i<100;i++)
    {
    num[i][1]=j*j;
    j++;
    }
}
void imprime (int num[100][2])
{
  int i;
  for(i=0;i<100;i++)
    {
       printf("El cuadrado del numero %d", i+1);
       printf(" es:  %d \n",num[i][1]);
    }
}
