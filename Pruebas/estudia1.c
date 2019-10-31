#include<stdio.h>
#include<string.h>

void letras(char frase[]);
void contarmaymin (char frase[]);

int main (void)
{
  char frase[100];
  contarmaymin(frase);
  letras(frase);
}
void contarmaymin (char frase[])
{
  int i, espacios=0, may=0, min=0,longitud;
  printf("Introduzca la frase que desee analizar: \n");
  gets(frase);
  longitud=strlen(frase);
  for(i=0;i<=strlen(frase); i++)
    {
      if(frase[i]==' ')
	espacios=espacios+1;
      if(frase[i]>='A' && frase[i]<='Z')
	may=may+1;
      if(frase[i]>='a' && frase[i]<='z')
	min=min+1;
    }
  printf("La longitud de la frase es: %d \n",longitud );
  printf("El numero de espacios es: %d \n", espacios);
  printf("El numrto de minusculas es: %d \n", min);
  printf("El numero de mayusculas es: %d \n", may);
}
void letras(char frase[])
{
  int i, j, acumulador;
  char letra;
  char abc[52]= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(i=0;i<52;i++)
    {
      acumulador=0;
      for(j=0;j<strlen(frase);j++)
	{
	  if(frase[j]==abc[i])
	    {
	  acumulador+=1;
	  letra=abc[i];
	    }
	}
      if(acumulador!=0){
      printf("la letra %c se repite %d veces\n", letra, acumulador);
      }
    }
  
}

