#include<stdio.h>
void sumar(int *sumapar, int *par , float *mediaimpar, int *impar);
void impresion (int par, int sumapar, float mediaimpar, int impar);
int main (void)
{
  int sumapar=0,par=0,impar=0;
  float mediaimpar;
  sumar (&sumapar, &par, &mediaimpar, &impar);
  impresion(par, sumapar, mediaimpar, impar);
}
void sumar (int *sumapar, int *par, float *mediaimpar, int *impar)
{
  int i;
  for(i=1; i<=10; i++)
    {
      if(i%2==0)
	{
	*par=*par+1;
	*sumapar=*sumapar+i;
	}
	else if (i%2!=0)
	 *mediaimpar=*mediaimpar+i;
	*impar=*impar+1;
    }
}
  void impresion(int par, int sumapar, float mediaimpar, int impar)
  {
    printf("Hay %d numeros pares \n",par);
    printf("Hay %d numeros impares \n", impar);
    printf("Suma de pares: %d \n",sumapar);
    printf("La media de los impares es: %f \n",mediaimpar/impar );
  }
  
