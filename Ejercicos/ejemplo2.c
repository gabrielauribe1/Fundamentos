#include<stdio.h>
#define pi 3.141592
void mostrarmenu (void);
void cuadrado (float lado, float*area);
void circulo (float radio, float*area);
void rectangulo (float base, float altura, float*area);
void triangulo (float base, float altura, float*area);

int main (void)
{
  float resultado, lado1, lado2;
  int opcion;
  do
    {
  mostrarmenu ();
  scanf("%d",&opcion);
  switch (opcion)
  {
  case 1: printf("Introduzca el radio del circulo: ");
    scanf("%f", &lado1);
    circulo(lado1, &resultado);
    break;
  case 2: printf("Introduzca el lado del cuadrado: ");
    scanf("%f", &lado1);
    cuadrado(lado1, &resultado);
    break;
  case 3: printf("Introduzca la base y la altura del rectangulo: ");
    scanf("%f%f", &lado1, &lado2);
    rectangulo(lado1, lado2, &resultado);
    break;
  case 4: printf("Introduzca la base y altura del triangulo: ");
    scanf("%f%f", &lado1, &lado2);
    triangulo (lado1, lado2, &resultado);
    break;
  case 5: printf("gracias, adios \n");
    break;
  default:printf("opcion invalida \n");
    break;
  }
  printf("el area es: %f \n",resultado);
    }
  while(opcion !=5);
}
    void triangulo (float base, float altura, float*area)
    {
      *area=base*altura;
    }
    void mostrarmenu(void)
    {
    printf("Menu \n");
    printf("1. area del circulo \n");
    printf("2. area del cuadrado \n");
    printf("3. area del rectanculo \n");
    printf("4. area del triangulo \n");
    printf("5. salir \n");
    printf("opcion: ");
    }
    void circulo (float radio, float*area)
    {
      *area=pi*radio*radio;
    }
    void rectangulo (float base, float altura, float*area)
    {
      *area=base*altura;
    }
    void cuadrado (float lado, float*area)
    {
      *area=lado*lado;
	}
    
 
   
