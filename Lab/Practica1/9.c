#include<stdio.h>
void leerchar (char *a, char *b);
int main (void)
{
  char a,b;
  leerchar (&a,&b);;
}
void leerchar (char *a, char *b)
{
  printf("Introduzca letra 1: ");
  scanf("%c",a);
  if((*a>= 'a' && *a<= 'z')||(*a>='A' && *a<= 'Z'))
    {
      printf("Introduzca letra 2: ");
      __fpurge(stdin);
      scanf("%c",b);
      if((*b>= 'a' && *b<= 'z')||(*b>='A' && *b<= 'Z'))
	{
	if (*b>*a)
	  printf("Están en orden\n");
	  else
	    printf("No están en orden\n");
	}
    }
}

 
