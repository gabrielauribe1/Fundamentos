#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void insertainicio(tipodato **Inicio, int numero);
void insertafin(tipodato **Inicio, int numero);

int main ()
{
}

void insertainicio(tipodato **Inicio, int numero)
{
  tipodato *temp;
  temp=(tipodato *)malloc(sizeof(tipodato));
  temp->dato=numero;
  temp->ant=NULL;
  temp->sig=*Inicio;
  if(*Inicio!=NULL)
    (*Inicio)->ant=temp;
  *Inicio=temp;
}
void insertafin(tipodato **Inicio, int numero)
{
  tipodato temp, temp2;
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


