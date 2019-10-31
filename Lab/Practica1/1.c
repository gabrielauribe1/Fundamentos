#include<stdio.h>
void solicitarnumero(int *num);
void evaluarnumero(int num, int *cont);
void imprimir(int cont);
int main (void)
{
  int num, cont=0;
    do
      {
	solicitarnumero(&num);
	evaluarnumero(num,&cont);
      }
	while(num!=0);
    imprimir(cont);
}

void solicitarnumero(int *num)
{
printf("introduzca numero, cero para terminar: ");
	scanf("%d",num);

}
void evaluarnumero(int num, int *cont)
{
if(num!=0)
	  {
	    printf("%d",num);
	    *cont=*cont+1;
	  }
}
void imprimir(int cont)
{
printf("se introdujeron %d numeros\n", cont);
}
