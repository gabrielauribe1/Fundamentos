#include<stdio.h>
#include<string.h>

void leer(char frase[]);
void ordenar(char frase[]);
int main (void)
{
    char frase[100];
    leer(frase);
    ordenar(frase);
}
void leer(char frase[])
{
    printf("Introduzca la frase que desee invertir: \n"),
    gets(frase);
}
void ordenar(char frase[])
{
    int i, j, a;
    for(i=strlen(frase); i>=0; i--)
    {
    if(frase[i]==' ')
    {
    for(j=i+1; frase[j]!= '\0' && frase[j]!=' '; j++)
    printf("%c", frase[j]);
    printf(" ");
    }
    }
    for(a=0; frase[a]!=' ' && frase[a]!='\0'; a++)
    printf("%c", frase[a]);
    printf("\n");
}

