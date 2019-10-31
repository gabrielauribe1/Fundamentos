#include <stdio.h>
#include<string.h>

void leer(char frase[]);
void mayuscula(char frase[]);
void mayuscula2(char frase[]);

int main(void)
{
    char frase[200];
    leer(frase);
    mayuscula(frase);
    mayuscula2(frase);
    printf("\n");
}
void leer(char frase[])
{
    printf("Introduzca la frase: \n");
    gets(frase);
}
void mayuscula(char frase[])
{
        if(frase[0]>='a' && frase[0]<='z')
            printf("%c", frase[0]-'a'+'A');
        else
        printf("%c", frase[0]);
}
void mayuscula2(char frase[])
{
    int i;
    for(i=1; i<strlen(frase);i++)
    {
        if((frase[i+1]==' '||frase[i-1]==' ' || frase[i+1]=='\0') &&(frase[i]>='a' && frase[i]<='z'))
        {
            printf("%c",frase[i]-'a'+'A');
        }
        else
        {
            printf("%c", frase[i]);
        }
    }
}

