#include<stdio.h>
#include<string.h>

void pedirtemp(int *t);
void calcular(float temp[], int t);
int main(void)
{
   float temp[100];
   int t;
   pedirtemp(&t);
   calcular(temp,t);
}
void pedirtemp(int *t)
{
     do
     {
     printf("Introduzca el número de temperaturas que va a ingresar (mayor a 5, memor a 100):\n");
     scanf("%d", t);
     } 
     while(*t<5 || *t>100);
}
void calcular(float temp[], int t)
{
  int i, cuenta=0, cuenta2;
   float media;
   for(i=0; i<t;i++)
     {
       printf("Introduzca la temperatura %d \n", i+1);
       scanf("%f", &temp[i]);
       cuenta=cuenta+temp[i];
     }
   media=cuenta/t;
   cuenta2=0;
       for(int j=0; j<t; j++)
       {
           if(temp[j]>=media)
           cuenta2= cuenta2+1;
       }
   printf("La media es: %f \n", media);
   printf("Cantidades mayor o igual a la media: %d \n", cuenta2);
}
