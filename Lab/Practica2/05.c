#include<stdio.h>
#include<string.h>

void leer(char frase1[]);
void quitarespacio(char frase2[]);
void invertir(char frase2[], char frase3[]);

int main(void)
{
  char frase1[100], frase2[100],frase3[100];
  leer(frase1);
  quitarespacio(frase1);
  invertir(frase1,frase2);
  puts(frase1);
  puts(frase2);
  if(strcmp(frase1,frase2)==0)
  printf("Es palindromo \n");
  else 
  printf("No es palindromo \n");
}
void leer(char frase1[])
{
  printf("Introduzca la frase que desee definir como palíndromo: ");
  gets(frase1);
}
void quitarespacio(char frase2[])
{
  int i, j;
  for(i=0; i<strlen(frase2)-1; i++)
    {
      if(frase2[i]==' ')
	{
	  for(j=i+1;j<strlen(frase2)-1; j++)
	    frase2[j-1]=frase2[j];
	}
    }
  frase2[i+1]='\0';
}
void invertir(char frase3[], char frase4[])
{
  int i,cuenta=0;
  for(i=strlen(frase3)-1; i>=0;i--)
    {
      frase4[cuenta]=frase3[i];
      cuenta++;
    }
  frase4[strlen(frase3)]='\0';
}
