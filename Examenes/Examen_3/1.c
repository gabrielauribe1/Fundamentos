#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct defNumerosComplejos
{
  int reales;
  int imaginarios;
}tipo_complejo;

void LeerDatos(char argv[], char *tipoop, tipo_complejo numeros[]);
void Resta(tipo_complejo numeros[], tipo_complejo *total);
void Multiplicacion(tipo_complejo numeros[], tipo_complejo *total);
void Imprimirtotal(tipo_complejo *total);


int main (int argc, char *argv[])
{
  tipo_complejo numeros[2], total;
  char Archivo[100], tipoop;
  if(argc==3)
	    {
	      	LeerDatos(argv[1], numeros, &tipoop);
		if(tipoop=='+')
	    	Suma(numeros, &total);
	  	if(tipoop=='-')
	    	Resta(numeros, &total);
	  	if(tipoop=='x')
	    	Multiplicacion(numeros, &total);
	      	Imprimirtotal(total);
	    }
  else
    printf("Se introdujeron argumentos inválidos \n");
  strcpy(Archivo, agrv[2]);
  strcat(Archivo, ".txt");
  FILE *Archivoresulatdos;
  Archivosresultados= fopen(archivo, "at");
  fprintf(Archivoresultados, "%s = %d%+di", argv[1], total.reales, total.imaginarios);
    
}
void LeerDatos(char argv[], char *tipoop, tipo_complejo numeros[])
{
  sscanf(argv[1], "[%d%c%di]%c[%d%c%di]", &numeros[0].reales, &numeros[0).imaginarios, tipoop, &numeros[1].reales, &numeros[1].imaginarios);
}
void Suma(tipo_complejo numeros[], tipo_complejo *total)
{
  total->reales= numeros[0].reales+numeros[1].reales;
  total->imaginarios= numeros[0].imaginarios+numeros[1].imaginarios;
}
void Resta(tipo_complejo numeros[], tipo_complejo *total)
{
 total->reales= numeros[0].reales-numeros[1].reales;
 total->imaginarios= numeros[0].imaginarios-numeros[1].imaginarios;
}
void Multiplicacion(tipo_complejo numeros[], tipo_complejo *total)
{
  total->reales= (numeros[0].reales)*(numeros[1].reales);
  total->imaginarios=(numeros[0].imaginarios)*(numeros[1].imaginarios); 
}
void Imprimirtotal(tipo_complejo total)
{
  printf("El resultado es: %d+%di \n", total.reales, total.imaginarios);
}





  
    
    

  
