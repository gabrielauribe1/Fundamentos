#include<stdio.h>
#include<string.h>

void leerlab(char lab[10][30]);
void analizar(char lab[10][30],int *iniciox,int *inicioy);
int resolver(char lab[10][30],int x, int y, int *cont,int *rest);
int main (void)
{
  char lab[10][30];
  int posicionx=0,posiciony=0;
  int cont=0,rest=0,pasos;
 
  strcpy(lab[0], "******************************");
  strcpy(lab[1], "**E          *****************");
  strcpy(lab[2], "****** ***********************");
  strcpy(lab[3], "****** ***********************");
  strcpy(lab[4], "****** ***********************");
  strcpy(lab[5], "****** ***********************");
  strcpy(lab[6], "****** ***********************");
  strcpy(lab[7], "****** ***********************");
  strcpy(lab[8], "******     S *****************");
  strcpy(lab[9], "******************************");

  leerlab(lab);
  analizar(lab,&posicionx,&posiciony);
  
  resolver(lab,posicionx,posiciony+1,&cont,&rest);
  printf("%d",cont-rest);

}
void leerlab(char lab[10][30])
{
  int x,y;
 
for(x=0;x<10;x++){
    for(y=0;y<30;y++)
      printf("%c",lab[x][y]);
    printf("\n");
  }
}
void analizar(char lab[10][30],int *iniciox, int *inicioy)
{
  int x,y;
  for(x=0;x<10;x++){
    for(y=0;y<30;y++){
      if(lab[x][y]=='E'){
	*iniciox=x;
	*inicioy=y;
      }
    }
  }
 printf("%d,%d",*iniciox,*inicioy);
    printf("\n");
  
}

int resolver(char lab[10][30],int x, int y,int *cont,int *rest){
  lab[x][y]='.';
system("clear"); 
  leerlab(lab);
getchar();


  if(x==0 || y==0 || x=='\0' || y== 30-1){ // estamos al borde
    return 1; //encuentra la salida
  }
  //alternativas posibles
  if(lab [x-1][y]==' '){ // hacia arriba
    if(resolver(lab,x-1,y,cont,rest)==1)
      {
      *cont+=1;
      return 1;
      }
  }
  if(lab [x][y+1]==' '){
    if(resolver(lab,x,y+1,cont,rest)==1) // hacia la derecha
      {
	*cont+=1;
      return 1;
      }
  }
   if(lab [x+1][y]==' '){
     if(resolver(lab,x+1,y,cont,rest)==1) //hacia abajo
       {
	 *cont+=1;
       return 1;
       }
  }
   if(lab [x][y-1]==' '){ //hacia la izquierda
     if(resolver(lab,x,y-1,cont,rest)==1){
	*cont+=1;
	return 1;
     }
  }
   lab[x][y]=' '; // ya no hay salida
   *rest-=1;
    return 0;

}
