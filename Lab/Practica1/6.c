#include<stdio.h>
void pesoeimprimir();
int main (void)
{
  pesoeimprimir();
 }
void pesoeimprimir ()
{
  float lb, kg, gr;
  printf("Introduzca peso en libras: \n");
  scanf ("%f",&lb);
  kg=0.0453592;
  gr=453.592;
  printf("Su peso en kilogramos es de %f \n", lb*kg);
  printf("Su peso en gramos es de %f \n", lb*gr);
}
