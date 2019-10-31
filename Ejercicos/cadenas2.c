#include<stdio.h>
#include<string.h>

void leer(char linea[]);
void imprime(char linea[]);
int main (void)
{
  char frase[200];
  leer (frase);
  printf("La frase es: \n");
  puts(frase);
  imprime(frase);
}
void leer(char linea[])
{
  printf("Introduzca una frase de hasta 199 caracteres \n");
  gets (linea);
}
void imprime(char linea[])
{
  int i;
  printf("la frase al revés es: \n");
  for (i=strlen(linea)-1; i>=0;i--)
    printf ("%c", linea[i]);
  printf("\n");
}

