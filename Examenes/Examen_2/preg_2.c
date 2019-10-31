#include<stdio.h>
#include<string.h>

void leetiempodepistas(float disco[], int num);
void calcula_hh_mm_ss(float disco [], int num);
void calcula_mm_ss(float disco [], int num);
void despliegatiempo(float disco [], int num);

int main(void)
{
  float disco[10];
  int num;
  printf("Introduzca el numero de pistas del disco (máximo 10): \n");
  scanf("%d",&num);
  leetiempodepistas(disco, num);
  calcula_hh_mm_ss(disco, num);
  calcula_mm_ss(disco, num);
  despliegatiempo(disco, num);
}
void leetiempodepistas(float disco[], int num)
{
  int i;
  for(i=0; i<num; i++)
    {
    printf("Introduzca el tiempo en formato mm.ss de la pista %d: \n", i+1);
    scanf("%f", &disco[i]);
    }
}
void calcula_hh_mm_ss(float disco[], int num)
{
   float suma=0;
   int hh=0, i;
   for(i=0; i<num; i++)
    {
      suma=suma+disco[i];
    }
   hh=suma/60;
   printf("en formato hh.mm.ss el disco en total dura: %d.%.2f \n", hh, suma);
}
void calcula_mm_ss(float disco[], int num)
{
  float suma=0;
  int i;
  for(i=0; i<num; i++)
    {
      suma=suma+disco[i];
    }
  printf("en formato mm.ss el disco en total dura %.2f \n", suma);
}
void despliegatiempo(float disco [], int num )
{
  int i;
  float horastot=0, mintot=0, segtot=0, suma=0;
  for(i=0; i<num; i++)
    {
      suma=suma+disco[i];
    }
  horastot=suma/60;
  mintot=suma;
  segtot=suma*60;
  printf("El total de horas es %.2f \n", horastot);
  printf("El total de minutos es %.2f \n", mintot);
  printf("El total de segundos es %.2f \n", segtot);
}

		     
     
