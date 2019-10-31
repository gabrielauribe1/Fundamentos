#include<stdio.h>
#include<string.h>

void invierteguarda(char cadena[], char cadena2[], int i);

int main(void)
{
  char cadena[200], cadena2[200];
  int i;
  printf("Dame una frase: \n");
  gets(cadena);
  i=strlen(cadena)-1;
  printf("Tu frase invertida es: \n");
  invierteguarda(cadena, cadena2, i);
  cadena2[i+1]='\0';
  puts(cadena2);
}
void invierteguarda(char cadena[], char cadena2[], int i)
{
  if(*cadena!='\0')
    {
      invierteguarda(cadena+1, cadena2, i-1);
      cadena2[i]=*cadena;
    }
}


