#include<stdio.h>
#include<string.h>

void leer(char frase[]);
void centro(char frase[]);

int main (void)
{
    char frase[200];
    leer(frase);
    centro(frase);
    printf("\n");
}
void leer(char frase[])
{
    printf("Introduzca la frase de la que desee eliminar lo del centro: \n");
    gets(frase);
}
void centro(char frase[])
{
  int i,j;
    for(i=0; frase[i]!=' '; i++)
    printf("%c", frase[i]);
    printf(" ");
    for(i=strlen(frase)-1; i>=0; i--)
    {
        if(frase[i]==' ')
        {
            for(j=i+1; frase[j]!='\0';j++)
            printf("%c", frase[j]);
	}
    }

}
