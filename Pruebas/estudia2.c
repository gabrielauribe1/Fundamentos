#include<stdio.h>
#include<string.h>

int main ()
{
  long long int Binario[100];
  int num, opcion,acumulador,i;
  printf("Introduzca el numero que desee convertir: \n");
  scanf("%d", &num);
  printf("Introduzca la opcion de conversion:\n1.Base 2\n2.Base 8\n3.Base 16 \n");
  scanf("%d" , &opcion);
  switch(opcion)
    {
    case 1:
      for(i=0;num!=1;i++)
	{
      Binario[i]=num%2;
      num=num/2;
      acumulador++;
	}
      Binario[acumulador]=1;
      for(i=acumulador;i>=0;i--)
       printf("%lld",Binario[i]);
      printf("\n");
   
      break;
    case 2:
      printf("en base ocho es %o \n", num);
      break;
    case 3:
      printf("en base dieciseis es %X \n", num);
    }
}
