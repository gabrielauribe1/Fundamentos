#include<stdio.h>
#include<string.h>

void leer(char frase[]);
void mayusculas(char frase[]);
void minusculas (char frase[]);
int main (void)
{
    char frase[200];
    leer(frase);
    mayusculas(frase);
    minusculas(frase);
}
void leer(char frase[])
{
    printf("Introduzca frase: ");
    gets(frase);
}
void minusculas(char frase[])
{
     int i;
    for(i=0; frase[i]!='\0'; i++)
    {
        if(frase[i]>='A' && frase[i]<='Z')
        {
          printf("%c", frase[i]-'A'+'a');  
        }
        else
        {
            printf("%c", frase[i]);
        }
    }
    printf("\n");
}
void mayusculas(char frase[])
{
    int i;
    for(i=0; frase[i]!='\0'; i++)
    {
        if(frase[i]>='a' && frase[i]<='z')
        {
            printf("%c", frase[i]-'a'+'A'); 
        }
        else
        {
            printf("%c", frase[i]);
        }
    }
    printf("\n");
}
