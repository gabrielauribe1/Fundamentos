#include<stdio.h>
#include<string.h>

void leerfrase(char frase[]);
void imprimir(char frase[]);
int main(void)
{
    char frase[100];
    leerfrase(frase);
    imprimir(frase);
}
void leerfrase(char frase[])
{
    printf("Introduzca la frase que desea desplegar al imprimir, menor a 100 caracteres:  \n");
    gets(frase);
}
void imprimir(char frase[])
{
    int i;
    for(i=0;i<strlen(frase); i++)
    {
printf("%c", frase[i]);
    if(frase[i]==' ')
    printf("\n");
    }
}
