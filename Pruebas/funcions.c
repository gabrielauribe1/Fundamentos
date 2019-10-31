#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef struct Def_Biciestacion
{
  int ID_Biciestacion, CP, LugaresLlenos, LugaresDisponibles;
  char Nombre[200], CalleNumero[200], Ciudad[200];
  struct Def_Biciestacion *sig;
} TipoBiciestacion;

typedef struct Def_Bicicleta
{
  int ID_Bicicleta, ID_Biciestacion, RentasPasadas, Anio, Mes, Dia, DiaAnio, Hora, Minuto, Segundo;
  struct Def_Bicicleta *sig;
} TipoBicicleta;

typedef struct Def_Usuario
{
  int ID_Usuario, NumeroTarjeta, Flag;
  char Nombre[200], Password [200], CalleNumero [200];
  struct Def_Usuario *sig;
} TipoUsuario;

void Menu_Inicio (char *argv[], char Menu[100][100], int *Filas_Archivo);
void Imprimir (char Menu[100][100], int Filas_Archivo);
void Logo ();
void Encabezado ();
void Creditos ();
void Login ();
void MenuUsuario ();
void MenuAdmin (TipoUsuario *PrimerUsuario);
void AltaUsuario (TipoUsuario *PrimerUsuario);
void BorrarListaBiciestacion (TipoBiciestacion *PrimeraBiciestacion);
void BorrarListaBicicleta (TipoBicicleta *PrimeraBicicleta);
void BorrarListaUsuario (TipoUsuario *PrimerUsuario);

void InsertaFinUsuarios(TipoUsuario **PrimerUsuario, int Flag, char Nombre[200], char Password [200], int NumeroTarjeta, char CalleNumero [200]);
void InsertaFinBicicletas(TipoBicicleta **PrimeraBicicleta, int ID_Biciestacion, int RentasPasadas, int Anio, int Mes, int Dia, int DiaAnio, int Hora, int Minuto, int Segundo);
void InsertaFinBiciestaciones(TipoBiciestacion **PrimeraBiciestacion, int ID_Biciestacion, int CP, int LugaresLlenos, int LugaresDisponibles, char Nombre[200], char CalleNumero[200],char Ciudad[200]);
void CargarBase (int Numeracion [3], int *PrimeraEjecucion);

int main (int argc, char *argv[])
{
  TipoBiciestacion *PrimeraBiciestacion = NULL;
  TipoBicicleta *PrimeraBicicleta = NULL;
  TipoUsuario *PrimerUsuario = NULL;
  
  char Menu[100][100];
  int Filas_Archivo;
  
  if(argc==2)
    {
      
      // if(strcmp("-h",argv[1])==0)
      
      if(strcmp("-c",argv[1])==0)
	{
	  Creditos();
	}
      
      // if(strcmp("-usu",argv[1])==0)
      else
	{
	  printf ("Error: Intentó entrar a un modo de ejecución inválido.\n");
	  printf ("Para obtener info. sobre el uso del programa, ejecute el programa en modo de ayuda.\n");
	  printf ("(./bicirenta.exe -h)\n\n");
	}
    }
  else
    {
      if(argc==1)
	{
	  int Numeracion [3], PrimeraEjecucion;
	  CargarBase (Numeracion, &PrimeraEjecucion);
	  Login ();
	  MenuAdmin (PrimerUsuario);
	}
      if(argc!=1 && argc!=2)
	{
	  printf ("Error: Intentó entrar a un modo de ejecución inválido.\n");
	  printf ("Para obtener info. sobre el uso del programa, ejecute el programa en modo de ayuda.\n");
	  printf ("(./bicirenta.exe -h)\n\n");
	}
    }
  
  //Menu_Inicio(argv,Menu,&Filas_Archivo);
  //Imprimir(Menu, Filas_Archivo);
  
}

/*void Menu_Inicio(char *argv[], char Menu[100][100], int *Filas_Archivo)
{
  FILE *Archivo;; 
  int x=0,y=0;
  Archivo=fopen("Menu.txt","rt")
  if(Archivo==NULL) 
  {
    printf("Error, no se encontró el archivo\n");
    exit(0);
  }
  else
    {
      while (!feof(Archivo)) 
	{
	  Menu[y][x]=getc(Archivo);
	  if(Menu[y][x]=='\n')
	    {
	      x=-1;
	      y++;
	    }
	  x++;
	}
      *Filas_Archivo=y; /*Guarda el número de filas que tenga el mapa seleccionado.
    }
  fclose(Archivo); /*Cierra el archivo de texto plano.
}
void Imprimir(char Menu[100][100], int Filas_Archivo)
{
  system("clear"); /*En esta funcón se imprime el mapa, que también se ocupa en la de recusión para que el camino se imprima en el mapa inicial
  int x,y;
  for(y=0;y<Filas_Archivo;y++){
    for(x=0;Menu[y][x]!='\n';x++)
      printf("%c",Menu[y][x]); /*Imprime el mapa caracter por caracter
    printf("\n"); /*Da un salto de linea por cada /n que encuentre.
  }
}*/

void Logo()
{
  system ("sleep 0.1");
  printf ("          ███████╗ ██████╗ ██████╗ ██████╗ ██╗ ██████╗██╗\n");
  system ("sleep 0.1");
  printf ("    ,__o  ██╔════╝██╔════╝██╔═══██╗██╔══██╗██║██╔════╝██║    ,__o \n");
  system ("sleep 0.1");
  printf ("  _-/_<,  █████╗  ██║     ██║   ██║██████╔╝██║██║     ██║  _-/_<, \n");
  system ("sleep 0.1");
  printf (" (*)/'(*) ██╔══╝  ██║     ██║   ██║██╔══██╗██║██║     ██║ (*)/'(*)\n");
  system ("sleep 0.1");
  printf ("          ███████╗╚██████╗╚██████╔╝██████╔╝██║╚██████╗██║\n");
  system ("sleep 0.1");
  printf ("          ╚══════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═╝ ╚═════╝╚═╝\n");
  system ("sleep 0.1");
}

void Encabezado()
{
  system ("clear");
  printf (" _____         _   _     _ \n");
  printf ("|   __|___ ___| |_|_|___|_|\n");
  printf ("|   __|  _| . | . | |  _| |\n");
  printf ("|_____|___|___|___|_|___|_|\n");
  printf ("__________________________________________________________________________\n\n");
}

void Creditos()
{
  system ("clear");
  system ("sleep 0.5");
  printf ("Créditos del sistema de:\n\n");
  system ("sleep 0.5");
  Logo ();
  printf ("\n");
  printf ("Desarrolladores del Sistema:\n\n");
  system ("sleep 0.5");
  printf ("   > César Mauricio Arellano Velásquez\n");
  system ("sleep 0.5");
  printf ("   > Raúl González Portillo\n");
  system ("sleep 0.5");
  printf ("   > María Gabriela Uribe García-Cacho\n\n");
  system ("sleep 0.5");
}

void Login()
{
  system ("clear");
  printf ("Bienvenido, usuario de:\n\n");
  Logo ();
  printf ("Usuario: \n");
  printf ("Contraseña: ");
  printf ("\n");
}

void MenuUsuario()
{
  int Seleccion, Repetir = 1;
  char Enter;
  do {
    Encabezado ();
    printf ("Bienvenido al menu principal, eliga una opción:\n\n");
    printf ("1.- Rentar una bicicleta\n");
    printf ("2.- Estacionar una bicicleta\n");
    printf ("3.- Mostrar saldo (multas pendientes)\n");
    printf ("4.- Logout\n\n");
    printf ("Su selección: ");
    __fpurge (stdin);
    scanf ("%d", &Seleccion);
    switch (Seleccion)
      {
      case 1:
	break;
      case 2:
	break;
      case 3:
	break;
      case 4:
	Repetir = 0;
	break;
      default:
	printf ("\n");
	printf ("Ha seleccionado una opción invalida.\n");
        printf ("Para obtener info. sobre el uso del programa, ejecutelo en modo de ayuda.\n");
	printf ("(./bicirenta.exe -h)\n\n");
	printf ("Presione Enter para reintentar...\n");
	__fpurge (stdin);
	scanf ("%c", &Enter);
      }
  }
  while (Repetir == 1);
}

void MenuAdmin (TipoUsuario *PrimerUsuario)
{
  int Seleccion, Repetir = 1;
  char Enter;
  do {
    Encabezado ();
    printf ("Bienvenido al modo administrador, eliga una opción:\n\n");
    printf ("1.- Dar de alta una biciestación\n");
    printf ("2.- Dar de baja una biciestación\n");
    printf ("3.- Dar de alta una bicicleta\n");
    printf ("4.- Dar de baja una bicicleta\n");
    printf ("5.- Reasignar una bicicleta\n");
    printf ("6.- Imprimir informe de estacion(es)\n");
    printf ("7.- Dar de alta un usuario\n");
    printf ("8.- Dar de baja un usuario\n");
    printf ("9.- Logout\n");
    printf ("10.- Actualizar bases de datos y salir del programa\n\n");
    printf ("Su selección: ");
    __fpurge (stdin);
    scanf ("%d", &Seleccion);
    switch (Seleccion)
      {
      case 1:
	break;
      case 2:
	break;
      case 3:
	break;
      case 4:
	break;
      case 5:
	break;
      case 6:
	break;
      case 7:
	AltaUsuario(PrimerUsuario);
	break;
      case 8:
	break;
      case 9:
	Repetir = 0;
	break;
      case 10:
	break;
      default:
	printf ("\n");
	printf ("Ha seleccionado una opción invalida.\n");
        printf ("Para obtener info. sobre el uso del programa, ejecutelo en modo de ayuda.\n");
	printf ("(./bicirenta.exe -h)\n\n");
	printf ("Presione Enter para reintentar...\n");
	__fpurge (stdin);
	scanf ("%c", &Enter);
      }
  }
  while (Repetir == 1);
}

void AltaUsuario (TipoUsuario *PrimerUsuario)
{
  int Flag, NumeroTarjeta;
  char Nombre[200], Password [200], CalleNumero [200], Enter;
  Encabezado ();
  printf ("Registro de un nuevo usuario:\n\n");
  printf ("Ingrese los datos siguientes:\n");
  printf ("Nombre completo del nuevo usuario: ");
  __fpurge (stdin);
  gets (Nombre);
  printf ("Contraseña del nuevo usuario: ");
  __fpurge (stdin);
  gets (Password);
  printf ("Numero de tarjeta de credito del nuevo usuario: ");
  __fpurge (stdin);
  scanf ("%d", &NumeroTarjeta);
  printf ("Direccion del nuevo usuario: ");
  __fpurge (stdin);
  gets(CalleNumero);
  printf ("Estatus administrativo ('1' Para administradores, '0' Para usuarios): ");
  __fpurge (stdin);
  scanf ("%d", &Flag);
  printf ("\n");
  printf ("Datos correctos. Estos son los datos que se guardaran:\n");
  printf ("Nombre: %s\n", Nombre);
  printf ("Contraseña: %s\n", Password);
  printf ("Numero de tarjeta de credito: %d\n", NumeroTarjeta);
  printf ("Dirección: %s\n", CalleNumero);
  if (Flag == 0)
    printf ("Estatus administrativo: Usuario\n");
  if (Flag == 1)
    printf ("Estatus administrativo: Administrador\n");
  printf ("Presione Enter para guardar los datos...\n");
  __fpurge (stdin);
  scanf ("%c", &Enter);
  InsertaFinUsuarios (&PrimerUsuario, Flag, Nombre, Password, NumeroTarjeta, CalleNumero);
}

void BorrarListaBiciestacion(TipoBiciestacion *PrimeraBiciestacion)
{
  TipoBiciestacion *temp;
  temp = PrimeraBiciestacion;
  while (temp != NULL)
    {
      PrimeraBiciestacion = PrimeraBiciestacion -> sig;
      free (temp);
      temp = PrimeraBiciestacion;
    }
}

void BorrarListaBicicleta(TipoBicicleta *PrimeraBicicleta)
{
  TipoBicicleta *temp;
  temp = PrimeraBicicleta;
  while (temp != NULL)
    {
      PrimeraBicicleta = PrimeraBicicleta -> sig;
      free (temp);
      temp = PrimeraBicicleta;
    }
}

void BorrarListaUsuario(TipoUsuario *PrimerUsuario)
{
  TipoUsuario *temp;
  temp = PrimerUsuario;
  while (temp != NULL)
    {
      PrimerUsuario = PrimerUsuario -> sig;
      free (temp);
      temp = PrimerUsuario;
    }
}

void InsertaFinUsuarios(TipoUsuario **PrimerUsuario, int Flag, char Nombre[200], char Password [200], int NumeroTarjeta, char CalleNumero [200])
{
  TipoUsuario *nuevo, *temp;
  nuevo = (TipoUsuario *)malloc(sizeof(TipoUsuario));
  strcpy (nuevo -> Nombre, Nombre);
  strcpy (nuevo -> Password, Password);
  nuevo -> NumeroTarjeta = NumeroTarjeta;
  strcpy (nuevo->CalleNumero, CalleNumero);
  nuevo -> Flag = Flag;
  nuevo -> sig = NULL;
  if (*PrimerUsuario!=NULL)
    {
      temp=*PrimerUsuario;
      while(temp->sig!=NULL)
	temp=temp->sig;
      temp->sig=nuevo;
    }
  else
    *PrimerUsuario=nuevo;
}
void InsertaFinBicicletas(TipoBicicleta **PrimeraBicicleta, int ID_Biciestacion, int RentasPasadas, int Anio, int Mes, int Dia, int DiaAnio, int Hora, int Minuto, int Segundo)
{
   TipoBicicleta *nuevo, *temp;
  nuevo = (TipoBicicleta *)malloc(sizeof(TipoBicicleta));
  nuevo -> ID_Biciestacion, ID_Biciestacion;
  nuevo -> RentasPasadas, RentasPasadas;
  nuevo -> Anio, Anio;
  nuevo -> Mes, Mes;
  nuevo -> Dia, Dia;
  nuevo -> DiaAnio, DiaAnio;
  nuevo -> Hora, Hora;
  nuevo -> Minuto, Minuto;
  nuevo -> Segundo, Segundo;
  nuevo -> sig = NULL;
  if (*PrimeraBicicleta!=NULL)
    {
      temp=*PrimeraBicicleta;
      while(temp->sig!=NULL)
	temp=temp->sig;
      temp->sig=nuevo;
    }
  else
    *PrimeraBicicleta=nuevo;
}
void InsertaFinBiciestaciones(TipoBiciestacion **PrimeraBiciestacion, int ID_Biciestacion, int CP, int LugaresLlenos, int LugaresDisponibles, char Nombre[200], char CalleNumero[200],char Ciudad[200])
{
   TipoBiciestacion *nuevo, *temp;
  nuevo = (TipoBiciestacion *)malloc(sizeof(TipoBiciestacion));
  nuevo -> ID_Biciestacion = ID_Biciestacion;
  nuevo -> CP = CP;
  nuevo -> LugaresLlenos= LugaresLlenos;
  nuevo -> LugaresDisponibles = LugaresDisponibles;
  strcpy (nuevo -> Nombre, Nombre);
  strcpy (nuevo->CalleNumero, CalleNumero);
  strcpy (nuevo->Ciudad, Ciudad);
  nuevo -> sig = NULL;
  if (*PrimeraBiciestacion!=NULL)
    {
      temp=*PrimeraBiciestacion;
      while(temp->sig!=NULL)
	temp=temp->sig;
      temp->sig=nuevo;
    }
  else
    *PrimeraBiciestacion=nuevo;
}


void CargarBase (int Numeracion [3], int *PrimeraEjecucion)
{
  char Enter;
  FILE *Archivo;
  Archivo = fopen ("Numeracion", "rt");
  if (Archivo == NULL)
    {
      printf ("No se encontraron todos los archivos necesarios para la ejecución del programa, al continuar se creará una nueva base de datos\n");
      printf ("Presione Enter para crear la base, ingrese 'S' para salir sin guardar cambios...\n");
      __fpurge (stdin);
      scanf ("%c", &Enter);
      if (Enter == 's' || Enter == 'S')
	{
	  printf ("Saliendo...\n");
	  system ("sleep 2");
	}
    }
}
