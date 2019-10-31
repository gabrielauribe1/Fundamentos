#include<stdio.h>
#include<string.h>
int encuentra(char cadena[], char caracter);
int main(void)
{
  char frase[200];
  char letra;
  printf("Cuál es la frase: ");
  gets(frase);
  printf("Qué caracter buscas?: \n");
  scanf("%c", &letra);
  if(encuentra(frase,letra))
    printf("Esa letra esta si esta en la frase \n");
  else
    printf("Esa letra no esta en la frase \n");
}
int encuentra(char cadena[], char caracter)
{
  int i=0, encontrada=0;
  while((i<strlen(cadena))&&(caracter!=cadena[i]))
    i++;
  if(i<strlen(cadena))
    encontrada=1;
  else
    encontrada=0;
  return encontrada;
}
