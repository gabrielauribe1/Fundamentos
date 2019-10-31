#include<stdio.h>
#include<stdlib.h>

typedef struct defdato
{
  int dato;
  struct defdato*sig;
} tipodato;

void InsertaInicio(tipodato **Inicio, int numero);
void InsertaFin(tipodato **Inicio, int numero);
void Promedio(tipodato *Inicio);
void Imprime(tipodato *Inicio);
void Buscar(tipodato *Inicio, int num);
void BorrarLista(tipodato *Inicio);

int main (void)
{
  tipodato *primero=NULL;
  int valor, num;
 
  printf("Inserte numeros (letra para terminar)\n");
  while(scanf("%d", &valor)==1)
    InsertaFin(&primero, valor);
  // InsertaInicio(&primero, valor);
  Imprime(primero);
  Promedio(primero);
   printf("Dame el numero que quieras buscar:\n");
  __fpurge(stdin);
  scanf("%d", &num);
  Buscar(primero, num);
  BorrarLista(primero);
}
/*void InsertaInicio(tipodato **Inicio, int numero)
{
  tipodato *temp;
  temp=(tipodato *) malloc(sizeof(tipodato));
  temp->dato=numero;
  temp->sig = *Inicio;
  *Inicio=temp;
}
*/
void InsertaFin(tipodato **Inicio, int numero)
{
  tipodato *temp, *temp2;
  temp=(tipodato *) malloc(sizeof(tipodato));
  temp->dato=numero;
  temp->sig=NULL;
  if(*Inicio!=NULL)
    {
      temp2=*Inicio;
      while(temp2->sig!=NULL)
	temp2=temp2->sig;
      temp2->sig=temp;
    }
  else
    *Inicio=temp;
}

void Imprime(tipodato *Inicio)
{
  printf("Los valores introducidos son:\n");
  tipodato *temp;
  temp=Inicio;
  while(temp!=NULL)
    {
      printf("%d\n",temp->dato);
      temp=temp->sig;
    }
}
void Promedio(tipodato *Inicio)
{
  int suma=0, cuenta=0;
  float prom=0;
  tipodato *temp;
  temp=Inicio;
  while(temp!=NULL)
    {
    cuenta++;
    suma=suma+temp->dato;
    temp=temp->sig;
    }
  prom=suma/cuenta;
  printf("La suma es: %d\n", suma);
  printf("La cuenta es: %d\n", cuenta);
  printf("El promedio es: %.2f\n", prom);
}
void Buscar(tipodato *Inicio, int num)
{
  tipodato *temp;
  int c=0;
  temp=Inicio;
  while(temp!=NULL)
    {
      if(temp->dato==num)
      c++;
      temp=temp->sig;
    }
  
  if(c==0)
    printf("No existe el numero en la lista\n");
  else
    printf("El numero si esta en la lista\n");
}
void BorrarLista(tipodato *Inicio)
{		 
tipodato *temp;
  temp=Inicio;
  while(temp!=NULL)
    {
      Inicio=Inicio->sig;
      free(temp);
      temp=Inicio;
    }
}



