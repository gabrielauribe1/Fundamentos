#include<stdio.h>

void pedirnum(int *decimal, int *opcion);
void convertir(int decimal, int opcion);
int main (void)

{
  int decimal, opcion;
  pedirnum(&decimal, &opcion);
  convertir(decimal, opcion);
  printf("\n");
}
void pedirnum(int *decimal, int *opcion)
{
  printf("Introduzca el numero en decimal que desee cambiar: \n");
  scanf("%d", decimal);
  printf("Seleccione la opcion de conversión:\n1.Binario\n2.Base 3\n3.Base 4\n4.Base 5\n5.Base 6\n6.Base 7\n7.Base 8\n8.Base 9\n9.Base 11\n10.Base 12\n11.Base 13\n12.Base 14\n13.Base 15\n14.Base 16\n");
  scanf("%d",  opcion);
}
void convertir(int decimal, int opcion)
{
  int i=0, bin[20], acum=0;
  switch(opcion)
    {
    case 1: 
      do
	{
	  bin[i]=decimal%2;
	  decimal=decimal/2;
	  i++;
	}
      while(decimal!=1);
      bin[i]=1;
      acum=i;
      for(i=acum; i>=0; i--)
	printf("%d", bin[i]);
      break;
    case 2:
      do
	{
	  bin[i]=decimal%3;
	  decimal=decimal/3;
	  i++;
	}
      while(decimal>2);
      bin[i]=2;
      acum=i;
      for(i=acum; i>=0; i--)
	printf("%d", bin[i]);
      break;
    case 3:
      do
	{
	  bin[i]=decimal%4;
	  decimal=decimal/4;
	  i++;
	}
      while(decimal!=1);
      bin[i]=1;
      acum=i;
      for(i=acum; i>=0; i--)
	printf("%d", bin[i]);
      break;
    case 4:
      do
	{
	  bin[i]=decimal%5;
	  decimal=decimal/5;
	  i++;
	}
      while(decimal>4);
      bin[i]=1;
      acum=i;
      for(i=acum; i>=0; i--)
	printf("%d", bin[i]);
      break;
    case 5:
      do
	{
	  bin[i]=decimal%6;
	  decimal=decimal/6;
	  i++;
	}
      while(decimal>5);
      bin[i]=1;
      acum=i;
      for(i=acum; i>=0; i--)
	printf("%d", bin[i]);
      break;
    case 6:
      do
	{
	  bin[i]=decimal%7;
	  decimal=decimal/7;
	  i++;
	}
      while(decimal>6);
      bin[i]=6;
      acum=i;
      for(i=acum; i>=0; i--)
	printf("%d", bin[i]);
      break;
    case 7:
      printf("%o", decimal);
      break;
    case 8:
      do
	{
	  bin[i]=decimal%9;
	  decimal=decimal/9;
	  i++;
	}
      while(decimal>8);
      bin[i]=8;
      acum=i;
      for(i=acum; i>=0; i--)
	printf("%d", bin[i]);
      break;
    case 9:
      do
	{
	  bin[i]=decimal%11;
	  decimal=decimal/11;
	  i++;
	}
      while(decimal>10);
      bin[i]=1;
      acum=i;
      for(i=acum; i>=0; i--)
	printf("%d", bin[i]);
      break;
    case 10:
      do
	{
	  bin[i]=decimal%12;
	  decimal=decimal/12;
	  i++;
	}
      while(decimal>11);
      bin[i]=1;
      acum=i;
      for(i=acum; i>=0; i--)
	printf("%d", bin[i]);
      break;
    case 11:
      do
	{
	  bin[i]=decimal%13;
	  decimal=decimal/13;
	  i++;
	}
      while(decimal>12);
      bin[i]=1;
      acum=i;
      for(i=acum; i>=0; i--)
	printf("%d", bin[i]);
      break;
    case 12:
      do
	{
	  bin[i]=decimal%14;
	  decimal=decimal/14;
	  i++;
	}
      while(decimal>13);
      bin[i]=1;
      acum=i;
      for(i=acum; i>=0; i--)
	printf("%d", bin[i]);
      break;
    case 13:
      do
	{
	  bin[i]=decimal%15;
	  decimal=decimal/15;
	  i++;
	}
      while(decimal>14);
      bin[i]=1;
      acum=i;
      for(i=acum; i>=0; i--)
	printf("%d", bin[i]);
      break;
    case 14:
      printf("%X", decimal);
    }
}
