#include <stdio.h>
#include <string.h>
void leer (char frase[200]);
void imprime(char frase[200], char letras [26]);
int main(void)
{
  char frase[200], letras[26]="abcdefghijklmnopqrstuvwxyz";
  leer(frase);
  imprime(frase, letras);
}
void leer (char frase[200])
{
  printf("Introduce una frase: \n");
  gets(frase);
}
void imprime(char frase[200], char letras [26])
{
  char indicador;
  int i, j, cuenta;
  for(i=0; i<25; i++)
    {
      cuenta=0;
      for(j=0; j<strlen(frase); j++)
	{
	  if(letras[i]==frase[j])
	    cuenta=cuenta+1;
	  indicador=letras[i];
	}
      if(cuenta!=0)
	printf("La letra %c, se repite %d\n", indicador, cuenta);
    }
}
