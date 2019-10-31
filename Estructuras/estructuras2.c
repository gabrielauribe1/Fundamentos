#include<stdio.h>
#include<string.h>

typedef struct coordenadas
{
  int x, y;
 
}tipocoordenadas;

void leer_coordenadas(tipocoordenadas *p1, tipocoordenadas p2*);

int main (void)
{
  tipocoordenadas punto1, punto2;
  leer_coordenadas(coordenadas);
  imprimir_formula(coordenadas);
}
void leer_coordenadas(tipocoordenadas p1*, tipocoordenadas p2*)
{
      printf("Introduzca las coordenadas del punto 1 (x,y):\n");
      scanf("%d,%d", p1->x, p1->y);
      printf("Introduzca las coordenadas del punto 2 (x,y):\n");
      scanf("%d,%d", p2->x, p2->y);
     
    }
}
void imprimir_formula(tipocoordenadas coordenadas)
{
}


  

      

   
