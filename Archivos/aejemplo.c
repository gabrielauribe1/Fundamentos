#include<stdio.h>

main()
{
  FILE *Archivo;
  char Frase[200], Nombre[200];
  printf("Como quiere que se llame su archivo?: \n");
  gets(Nombre);
  Archivo = fopen(Nombre, "at");
  printf("Dame tu frase favorita: \n");
  gets(Frase);
  fprintf(Archivo, "Tu frase favorita es: %s \n", Frase);
  fclose(Archivo);
}
