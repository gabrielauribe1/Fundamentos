#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Función utilizada que funciona como clear en la terminal.*/
void Borrar_Pantalla();
/*Función que permite buscar, abrir el archivo de texto plano, para poder guardar los caracteres que éste contiene en un arreglo multidimensional.*/
void Cargar_Guardar_Laberinto(char *argv[], char Laberinto[30][30], int *Filas_Limite);
/*Función utilizada para imprimir el mapa del laberinto cuantas veces sea necesario.*/
void Imprimir_Laberinto(char Laberinto[30][30], int Filas_Limite, int Alerta);
/*Función que permite encontrar las coordenas donde se ubica la entrada para que marque el punto de referencia de la E.*/
void Buscar_Coordenadas_Entrada(char Laberinto[30][30], int Filas_Limite, int *InicioX, int *InicioY);
/*Función que da solución al problema planteado, obtiene pasos optimos y caminos posibles, 100% recursivo.*/
void Resolver_Laberinto(char Laberinto[30][30],char Laberinto2[30][30],int argc, int Filas_Limite, int x, int y, int *Caminos, int *Pasos, int *Menor, int Alerta);
/*Función que imprime los resultados obtenidos de la función Resolver_Laberinto*/
void Desplegar_Resultados(char Laberinto2[30][30], int Filas_Limite, int Caminos, int Menor, int Alerta);

int main(int argc, char *argv[])
{
  char Laberinto[30][30], Laberinto2[30][30];
  int Filas_Laberinto,CEX,CEY,Caminos=0,Puntos=0,Menor=0,Alerta=1;
  if((argc==2 && (strcmp("-pasos",argv[1])!=0))|| (argc==3 && (strcmp("-pasos",argv[2])==0))){
    Cargar_Guardar_Laberinto(argv,Laberinto,&Filas_Laberinto);
    printf("Laberinto Sin Resolver:\n");
    Imprimir_Laberinto(Laberinto,Filas_Laberinto,Alerta);
    Buscar_Coordenadas_Entrada(Laberinto,Filas_Laberinto,&CEX,&CEY);	
    printf("Coordenada de Entrada en X: %d\n",CEX+1);
    printf("Coordenada de Entrada en Y: %d\n",CEY+1);
    printf("Presione Enter para resolver el laberinto \n");
    Alerta=0;
    getchar();
    Borrar_Pantalla();
    Resolver_Laberinto(Laberinto,Laberinto2,argc,Filas_Laberinto,CEX,CEY,&Caminos,&Puntos,&Menor,Alerta);	
    Alerta=1;
    Borrar_Pantalla();
    Desplegar_Resultados(Laberinto2,Filas_Laberinto,Caminos,Menor,Alerta);
  }
  else
    printf("Error, opción incorrecta.\n");
  return 0;
}
void Borrar_Pantalla()
{
  system("clear");/*En esta función se borra la pantalla para que no se imprima el mapa cada vez que se avance un paso*/
}
void Cargar_Guardar_Laberinto(char *argv[], char Laberinto[30][30], int *Filas_Limite) 
{
  FILE *Mapa; 
  int x=0,y=0;
  Mapa=fopen(argv[1],"rt");/*Esta función busca y abre el archivo introducido en la terminal, y lo marca en modo lectura*/
  if(Mapa==NULL) /* Si no se encuentra el mapa, esta sentencia, termina el programa.*/
    {
      printf("Error, no se encontró el mapa\n");
      exit(0);
    }
  else
    {
      while (!feof(Mapa)) /*Este ciclo imprime hasta que encuentre el final de los caracteres y almacena el mapa en un arreglo bidimensional.*/
	{
	  Laberinto[y][x]=getc(Mapa);
	  if(Laberinto[y][x]=='\n')
	    {
	      x=-1;
	      y++;
	    }
	  x++;
	}
      *Filas_Limite=y; /*Guarda el número de filas que tenga el mapa seleccionado.*/
    }
  fclose(Mapa); /*Cierra el archivo de texto plano.*/
}
void Imprimir_Laberinto(char Laberinto[30][30],int Filas_Limite,int Alerta)
{
  if(Alerta!=1)	
    Borrar_Pantalla(); /*En esta funcón se imprime el mapa, que también se ocupa en la de recusión para que el camino se imprima en el mapa inicial*/ 
  int x,y;
  for(y=0;y<Filas_Limite;y++){
    for(x=0;Laberinto[y][x]!='\n';x++)
      printf("%c",Laberinto[y][x]); /*Imprime el mapa caracter por caracter*/
    printf("\n"); /*Da un salto de linea por cada /n que encuentre.*/
  }
}
void Buscar_Coordenadas_Entrada(char Laberinto[30][30], int Filas_Limite, int *InicioX, int *InicioY)
{
  int x,y;
  for(y=0;y<Filas_Limite;y++)/*Esta función define la coordenada en x y en y de donde se encuentra la entrada del mapa para dar inicio*/
    {
      for(x=0;Laberinto[y][x]!='\n';x++)
	{
	  if(Laberinto[y][x]=='E')
	    {
	      *InicioX=x; /*Guarda las coordenas en X de Entrada.*/
	      *InicioY=y; /*Guarda las coordenas en Y de Entrada.*/
	    }
	}
    }
}
void Resolver_Laberinto(char Laberinto[30][30],char Laberinto2[30][30],int argc, int Filas_Limite, int x, int y, int *Caminos, int *Pasos, int *Menor, int Alerta)
{
  /*Aqui se definen los caminos posibles y los pasos del camino más óptimo, a través de un contador y condicionando cuando se encuentra la salida*/
  if(Laberinto[y][x+1] == 'S' || Laberinto[y][x-1] == 'S' || Laberinto[y+1][x] == 'S' ||Laberinto[y-1][x] == 'S' )
    {
      *Caminos+=1;
      /*Esta condición permite saber cuales son los pasos del camino mas óptimo*/
      if(*Pasos<*Menor || *Caminos == 1)
	{
	  *Menor=*Pasos;
	  /*Estos ciclos guardan en un arreglo bidimensional el camino más óptimo*/
	  for(int y=0;y<Filas_Limite;y++)
	    {
	      for(int x=0;Laberinto[y][x]!='\n';x++)
		{
		  if(Laberinto[y][x+1]=='\n')
		    {
		      Laberinto2[y][x]='*';
		      Laberinto2[y][x+1]='\n';
		    }
     		  else
		    Laberinto2[y][x]=Laberinto[y][x];
		}
	    }
	}
    }
  /* Está condición permite la resolución del laberinto a través de condciones que imprimen el laberinto y almancena puntos (pasos) en coordenadas específicas para ir caminando.*/
  if(Laberinto[y][x]!='S'){
    if(argc==3) // Imprime solo si tiene el argumento -p.
      {
	Imprimir_Laberinto(Laberinto,Filas_Limite,Alerta);
	system("sleep 0.1"); /*Ralentiza las impresiones a pantalla en 0.1 seg.*/
      }
    
    if(Laberinto [y][x+1]!='S' && Laberinto[y][x+1]!='*' && Laberinto[y][x+1] != '.'&& Laberinto[y][x+1] != 'E') /*En esta condición el punto camina hacia la derecha*/
      {
	Laberinto[y][x+1]='.';
	*Pasos+=1;
	Resolver_Laberinto(Laberinto,Laberinto2,argc,Filas_Limite, x+1, y,Caminos,Pasos,Menor,Alerta);
      }
  
    if(Laberinto [y-1][x]!='S' && Laberinto[y-1][x]!='*' && Laberinto[y-1][x] != '.'&& Laberinto[y-1][x] != 'E') /*En esta condición el punto camina hacia arriba*/
      { 
	Laberinto[y-1][x]='.';
	*Pasos+=1;
	Resolver_Laberinto(Laberinto,Laberinto2,argc,Filas_Limite, x, y-1,Caminos,Pasos,Menor,Alerta);
      }
    
    if(Laberinto[y][x-1]!='S' && Laberinto[y][x-1]!='*' && Laberinto[y][x-1] != '.' && Laberinto[y][x-1] != 'E')/*En esta condición el punto camina hacia la izquierda*/
      {
	Laberinto[y][x-1]='.';
	*Pasos+=1;
	Resolver_Laberinto(Laberinto,Laberinto2,argc,Filas_Limite,x-1,y,Caminos,Pasos,Menor,Alerta);
      }

    if(Laberinto [y+1][x]!='S' && Laberinto[y+1][x]!='*' && Laberinto[y+1][x] != '.' && Laberinto[y+1][x] != 'E')/*En esta condición el punto camina hacia abajo*/
      {
	Laberinto[y+1][x]='.';
	*Pasos+=1; // Aumenta pasos dados.
	Resolver_Laberinto(Laberinto,Laberinto2,argc,Filas_Limite, x, y+1,Caminos,Pasos,Menor,Alerta); 
      }

    /*Esta condición  define el camino cuando es distinto a la entrada y se restan los pasos que no llevan al camino óptimo. Esta condición también hace que si no se encuentra una salida, el punto se vuelva a regresar a la entrada*/
    if(Laberinto[y][x] != 'E')
      {
	Laberinto[y][x]=' '; /*Marca Espacios.*/
	*Pasos-=1; /*Resta los pasos dados*/
      }
    if(argc==3)
      {
	Imprimir_Laberinto(Laberinto,Filas_Limite,Alerta);
	system("sleep 0.1"); /*Ralentiza las impresiones a pantalla en 0.1 seg.*/
      }
  }    
}
//Imprime Resultados
void Desplegar_Resultados(char Laberinto2[30][30], int Filas_Limite, int Caminos, int Menor, int Alerta)
{
  printf("Laberinto Resuelto:\n");
  Imprimir_Laberinto(Laberinto2,Filas_Limite,Alerta);
  printf("Camino óptimo: %d pasos.\n",Menor);
  printf("Se encontraron %d camino(s) de salida\n",Caminos);
}



