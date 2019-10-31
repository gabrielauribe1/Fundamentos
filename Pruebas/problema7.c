#include<stdio.h>
#include<string.h>

void leer(char frase[]);
void calcular(char frase[]);

int main (void)
{
  char frase[100];
  leer(frase);
  calcular(frase);
  printf("/n");
}
void leer(char frase[])
{
  printf("Introduzca la frase que desea eliminar el centro: \n");
  gets(frase);
}
void calcular(char frase[])
{
  int palabra=1, i;
  for(i=0; i<strlen(frase); i++)
  {
    if(frase[i]!=' ')
      {
	if(palabra!=2)
	  printf("%c", frase[i]);
      }
    else
      if(frase[i-1]!=' ')
	palabra++;
  }
}
