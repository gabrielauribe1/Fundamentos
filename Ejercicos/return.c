#include<stdio.h>
#include<string.h>

int separa(char frase[], char Palabras[30][30]);
void imprime(char Palabras[30][30], int num);

int main (void)
{
  char linea[200], palabras[30][30];
  int numpalabras;
  printf("Introduzca un texto: \n");
  gets(linea);
  imprime(palabras, separa(linea,palabras));
  return 1;
}
int separa(char frase[], char palabras[30][30])
{
  int i, j=0, k=0;
  for(i=0; i<strlen(frase); i++)
    {
      if(frase[i]!=' ')
	{
	  palabras[k][j]=frase[i];
	  j++;
	}
      else
	if(frase[i-1]!=' ')
	  {
	    palabras[k][j]='\0';
	    k++;
	    j=0;
	  }
    }
  palabras[k][j]='\0';
  k++;
  return k;
}
void imprime(char palabras[30][30], int num)
{
  int i;
  for(i=0;i<num; i++)
    puts(palabras[i]);
}


	
