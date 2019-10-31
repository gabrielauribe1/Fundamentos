#include<stdio.h>
#include<stdlib.h>

typedef struct defdato
{
int dato;
struct defdato*sig;
} tipodato;

void InsertaMedio(tipodato **Inicio, int valor);
void Imprime(tipodato *Inicio);

int main(void)
{
tipodato *primero=NULL;
int valor;
do
  {
printf("Inserte el numero que desee agregar:\n");
__fpurge(stdin);
scanf("%d",&valor);
InsertaMedio(&primero, valor);
}
 while(valor==1);
Imprime(primero);
}
void InsertaMedio(tipodato **Inicio, int valor)
{
tipodato *temp, *temp2, *nuevo;
nuevo=(tipodato *) malloc(sizeof(tipodato));
nuevo->dato=valor;
temp=*Inicio;

while((temp!=NULL)&&(valor>temp->dato))
  temp=temp->sig;

if(temp!=NULL)
  {
temp2=*Inicio;
while(temp2->sig!=temp)
  temp2=temp2->sig;
nuevo->sig=temp;
temp2->sig=nuevo;
}
 else
   {//inserta inicio
nuevo->sig=*Inicio;
*Inicio=nuevo;
}
if(temp!=*Inicio)
  {
temp2=*Inicio;
while(temp2->sig!=temp)
  temp2=temp2->sig;
nuevo->sig=temp;
temp2->sig=nuevo;
}
 else //inserta fin
   {
if (*Inicio==NULL)
  {
nuevo->sig=NULL;
*Inicio=nuevo;
}
 else
   {
temp=*Inicio;
while(temp->sig!=NULL)
  temp=temp->sig;
temp->sig=nuevo;
nuevo->sig=NULL;
}
}
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
