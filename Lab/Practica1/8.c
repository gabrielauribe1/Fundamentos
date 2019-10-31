#include<stdio.h>
void introducirletra (void);
int main (void)
{
  introducirletra ();
}
void introducirletra (void)
{
  char l;
  printf("Introduzca letra: ");
  scanf("%c",&l);
  if(l>='a' && l<='z')
    printf("la letra es minuscula \n");
  else if (l>='A' && l<='Z')
    printf("la letra es mayuscula \n");
  else
    printf("Se debe escribir una letra \n");
}

    
