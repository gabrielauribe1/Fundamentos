

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct def_dato
{
  int dato;
  struct def_dato *sig;
} tipodato;

void Imprime (tipodato *Inicio);
void BorrarLista (tipodato *Inicio);
void Inserta (tipodato **Inicio, int numero);

int main (void)
{
  int valor;
  tipodato *Primero = NULL;
  printf ("Inserte numeros (letra para terminar)\n");
  while (scanf ("%d", &valor) == 1)
    Inserta (&Primero, valor);
  printf ("Los valores introducidos son: \n");
  Imprime (Primero);
  BorrarLista (Primero);
}

void Imprime (tipodato *Inicio)
{
  tipodato *tmp;
  tmp = Inicio;
  while (tmp != NULL)
    {
      printf ("%d\n", tmp -> dato);
      tmp = tmp -> sig;
    }
}

void BorrarLista (tipodato *Inicio)
{
  tipodato *tmp;
  tmp = Inicio;
  while (tmp != NULL)
    {
      Inicio = Inicio -> sig;
      free (tmp);
      tmp = Inicio;
    }
}

void Inserta (tipodato **Inicio, int numero)
{
  tipodato *tmp, *tmp2, *nuevo;
  nuevo = (tipodato *) malloc (sizeof (tipodato));
  nuevo -> dato = numero;
  tmp = *Inicio;
  while ((tmp != NULL) && (numero > tmp -> dato))
    tmp = tmp -> sig;
  if (tmp != NULL)
    {
      if (tmp != *Inicio)
	{
	  tmp2 = *Inicio;
	  while (tmp2 -> sig != tmp)
	    tmp2 = tmp2 -> sig;
	  nuevo -> sig = tmp;
	  tmp2 -> sig = nuevo;
	}
      else
	{
	  nuevo -> sig = *Inicio;
	  *Inicio = nuevo;
	}
    }
  else
    {
      if (*Inicio == NULL)
	{
	  nuevo -> sig = NULL;
	  *Inicio = nuevo;
	}
      else
	{
	  tmp = *Inicio;
	  while (tmp -> sig != NULL)
	    tmp = tmp -> sig;
	  tmp -> sig = nuevo;
	  nuevo -> sig = NULL;
	}
    }
}
