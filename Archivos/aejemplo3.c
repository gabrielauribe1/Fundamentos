#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main (void)
{
  char NombreArchivo[20];
  int a, b, c, i;
  FILE *Archivo;
  float R1, R2;

  printf("Dame el nombre del archivo de las ecuaciones: ");
  gets(NombreArchivo);
  Archivo = fopen(NombreArchivo, "rt");
  if(Archivo == NULL)
    {
      printf("No existe el archivo. Fin del programa");
      exit (0);
    }
  //for (i=0; i<=5; i++) no sabe de que tamaño es el archivo
  //while (!feof(Archivo)) te imprime uno extra
while(fscanf(Archivo, "%d, %d, %d", &a, &b, &c)==3)
    {
      // fscanf(Archivo, "%d, %d, %d",&a,&b,&c); no imprime todo
      R1 = (-b + sqrt(b*b-4*a*c))/(2*a);
      R2 = (-b - sqrt(b*b-4*a*c))/(2*a);
      printf("Para %dx^2%+dx%+d=0, R1 = %.2f, R2 = %.2f\n", a,b,c,R1,R2);
    }
  fclose(Archivo);
}

   

      
