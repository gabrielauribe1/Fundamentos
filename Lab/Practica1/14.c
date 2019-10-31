#include<stdio.h>
void leerfecha(int *DD,int *MM, int *AA);
void imprimir(int DD, int MM, int AAAA);
int main (void)
{
  int DD, MM, AAAA;
  leerfecha(&DD, &MM, &AAAA);
  imprimir(DD,MM,AAAA);
}
void leerfecha(int *DD, int *MM, int *AAAA)
{
  printf("Introduzca la fecha en formato DD/MM/AAAA: \n");
  scanf("%d/%d/%d",DD,MM,AAAA);
}
void imprimir(int DD, int MM, int AAAA)
{
  if (MM==1,3,5,7,8,10 && DD==31)
  printf("La fecha del dia siguiente es 1/%d/%d \n ",MM+1, AAAA);
  if (MM==4,6,9,11 && DD==30)
    printf("La fecha del día siguiente es 1/%d/%d \n", MM+1, AAAA);
  if (AAAA%4==0 && MM==2 && DD==28)
    printf("La fecha del dia siguiente es 1/%d/%d \n", MM+1, AAAA);
  if (AAAA%4==0 && MM==2 && DD==29)
    printf("La fecha del dia siguiente es 1/%d/%d \n", MM+1, AAAA);
  if(MM==12 & DD==31)
    printf("La fecha del dia siguiente es 1/1/%d \n", AAAA+1);
  else if (DD<30)
    printf("La fecha del dia siguiente es %d/%d/%d \n", DD+1, MM, AAAA);
}
