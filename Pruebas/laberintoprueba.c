#include<stdio.h>
#include<string.h>

int main (int argc, char const *argv[])
{
  FILE *f;
  f=fopen("mapa2.txt","r");
  if(f==NULL)
    printf("Error al abrir el mapa\n");
  else
    {
      while (!feof(f))
	{
      printf("%c", getc(f));
	}
    }
  
}
