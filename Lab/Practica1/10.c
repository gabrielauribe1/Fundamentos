#include<stdio.h>
void sumar(int *sumapar, int *sumaimpar);
void imprimir (int sumapar, int sumaimpar);
int main (void)
{
  int sumapar=0, sumaimpar=0;
  sumar(&sumapar,&sumaimpar);
  imprimir(sumapar,sumaimpar);
}
void sumar(int *sumapar, int *sumaimpar)
{
  int i;
  for(i=1; i<=200; i++)
    {
      if(i%2==0)
	*sumapar=*sumapar+i;
      else
	*sumaimpar=*sumaimpar+i;
    }
}
void imprimir (int sumapar, int sumaimpar)
{
  printf("la suma de los pares es %d \n",sumapar);
  printf("la suma de los impares es %d \n",sumaimpar);
}

  

  
