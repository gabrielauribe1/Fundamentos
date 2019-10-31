#include<stdio.h>
#include<string.h>

void leerfrase(char frase[200]);
void mayusculasminusculas(char frase[200]);;
void espacios(char frase[200] );

int main (void)
{
  char frase[200];
  leerfrase(frase);
  mayusculasminusculas(frase);
  espacios(frase);
}
void leerfrase(char frase[200])
{
  printf("Introduzca la frase: \n");
  gets(frase);
}
void mayusculasminusculas(char frase[200])
{
  int i, sumamin=0, sumamay=0;
  for(i=0; i<strlen(frase); i++)
    {
      if(frase[i]>='a' && frase[i]<='z')
	sumamin=sumamin+1;
      if(frase[i]>='A' && frase[i]<='Z')
	sumamay=sumamay+1;
    }
  printf("La suma de las minusculas es: %d \n",sumamin);
  printf("La suma de las mayusculas es: %d\n",sumamay);
}
void espacios(char frase[200] )
{
  int i, sumaletras=0, sumaesp=0;
  for(i=0; i<strlen(frase); i++)
    {
      if(frase[i]==' ')
	sumaesp=sumaesp+1;
    }
  sumaletras=strlen(frase)-sumaesp;
  printf("la suma de los espacios es: %d \n", sumaesp);
  printf("el total de letras es: %d \n", sumaletras);
  printf("El total de palabras es: %d \n", sumaesp+1);
}
