#include<stdio.h>
#include<string.h>

void leer(char linea[]);
void imprime(char linea[]);
void imprime2(char *linea);
int main (void)
{
  char frase[200];
  leer (frase);
  printf("La frase es: \n");
  puts(frase);
  imprime(frase);
  imprime2(frase);
}
void leer(char linea[])
{
  printf("Introduzca una frase de hasta 199 caracteres \n");
  gets (linea);
}
void imprime(char linea[])
{
  int i;
  for(i=0;i<strlen(linea);i++)
    printf("%c", linea[i]);
}
void imprime2(char *linea)
{
  while(*linea!='\0')
    {
      printf("%c", *linea);
      linea++;
    }
  printf("\n");
}


							  
