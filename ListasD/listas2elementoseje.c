#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct defdato
{
  int dato;
  struct defdato *sig;
  struct defdato *ant;
}tipodato;

void insertafin(tipodato **Inicio, int numero);
void imprime(tipodato *Inicio);
void borrar(tipodato *Inicio);

int main()
{
  tipodato *Inicio=NULL;
  int numero;
  printf("Inserte numeros (letra para terminar)\n");
  while(scanf("%d", &numero)==1)
    insertafin(&Inicio, numero);
  imprime(Inicio);
  borrar(Inicio);
}
void insertafin(tipodato **Inicio, int numero)
{
  tipodato *temp, *temp2;
  temp=(tipodato *)malloc(sizeof(tipodato));
  temp->dato=numero;
  temp->sig=NULL;
  if(*Inicio!=NULL)
    {
      temp2=*Inicio;
      while(temp2->sig!=NULL)
	temp2=temp2->sig;
      temp2->sig=temp;
      temp->ant=temp2;
    }
  else
    {
      temp->ant=NULL;
      *Inicio=temp;
    }
}
void imprime(tipodato *Inicio)
{
  printf("Los valores introducidos al revés  son:\n");
  tipodato *temp;
  temp->sig=NULL;
  while(temp!=NULL)
    {
      printf("%d\n",temp->dato);
      temp=temp->ant;
    }
}
void borrar(tipodato *Inicio)
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





