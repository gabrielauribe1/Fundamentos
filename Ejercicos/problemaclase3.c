#include<stdio.h>
#include<math.h>
int main (void)
{
  float a,b,c,resultado1,resultado2;
  char l;
  do
    {
      printf("Introduzca variables a,b,c: ");
      scanf("%f%f%f",&a,&b,&c);
      if(a!=0 && ((b*b)-(4*a*c)>=0))
	{
	  resultado1=(-b+(sqrt((b*b)-(4*a*c)))/ (2*a));
	  resultado2=(-b-(sqrt((b*b)-(4*a*c)))/ (2*a));
	   printf("Los resultados de las raices fueron %f  %f \n", resultado1, resultado2);
	}
      else
	{
	  printf("la raiz es compleja y a debe de ser distinto a 0 \n");
	}
      printf("si desea repetir teclee 's' o 'S' \n");
      __fpurge(stdin);
      // scanf("%c", &l);
      l=getchar();
    }
      while(l=='s' || l=='S');
}

    



	  
  
