#include<stdio.h>
#include<string.h>

void leer(char linea[]);
void guardaimprime(char linea[], char linea2[]);
int main (void)
{
  char linea[200], linea2[200];
  leer (linea);
  printf("La frase es: \n");
  puts(linea);
  guardaimprime(linea, linea2);
}
void leer(char linea[])
{
  printf("Introduzca una frase de hasta 199 caracteres \n");
  gets (linea);
}
void guardaimprime(char linea[], char linea2[])
{
  int i;
   for (i=strlen(linea)-1; i>=0;i--)
     gets(linea[i]);
   strcpy(linea2[i], linea[i]);
   printf ("%c", linea2[i]);
   printf("\n");
}

