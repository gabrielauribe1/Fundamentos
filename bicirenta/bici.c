#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef struct Def_Biciestacion
{
  int ID_Biciestacion, CP, LugaresLlenos, LugaresDisponibles, Activo;
  char Nombre[200], CalleNumero[200], Ciudad[200];
  struct Def_Biciestacion *sig;
} TipoBiciestacion;

typedef struct Def_Bicicleta
{
  int ID_Bicicleta, ID_Biciestacion, RentasPasadas, Activo;
  char Timestamp [200];
  struct Def_Bicicleta *sig;
} TipoBicicleta;

typedef struct Def_Usuario
{
  int ID_Usuario, Flag, TieneBici, Activo, Multas,ID_Bicicleta;
  long int NumeroTarjeta;
  char Nombre[200], Password [200], CalleNumero [200];
  struct Def_Usuario *sig;
} TipoUsuario;

void Logo (); //Esta función imprime el logo de Ecobici, se utiliza en "Login" y en "Créditos".
void Encabezado (); //Esta función limpia la pantalla e imprime el encabezado de "Ecobici", se utiliza en "MenuAdmin", "MenuUsuario" y en las funciones que imprimen listados de datos en la base de datos
void Creditos (); //Esta función limpia la pantalla e imprime los créditos del sistema.
void MostrarAyuda(); //Esta función muestra un breve manual de ayuda al usuario.
void ListaActivos(TipoUsuario *PrimerUsuario);
void ListaBiciestacionesActivas(TipoBiciestacion *PrimeraBiciestacion);
void Login (TipoUsuario *PrimerUsuario, int *Alerta, int *TipoUsu, int *ID_Sesion); //Esta función recibe usuario y contraseña, y si los encuentra en la base de datos, lleva al usuario al respectivo menú y a las funciones del menú les manda el ID del usuario que se logueó.
void MenuUsuario(TipoBiciestacion *PrimeraBiciestacion, TipoBicicleta *PrimeraBicicleta, TipoUsuario *PrimerUsuario, int ID_Sesion); //Esta función imprime el menú principal del usuario y lo redirige a sus respectivas funciones.
void MenuAdmin (TipoBiciestacion *PrimeraBiciestacion, TipoBicicleta *PrimeraBicicleta, TipoUsuario *PrimerUsuario, int Numeracion [3], int ID_Sesion);
void RentarBicicleta(TipoBiciestacion *PrimeraBiciestacion, TipoBicicleta *PrimeraBicicleta, TipoUsuario *PrimerUsuario,TipoBiciestacion NuevaBiciestacion, int ID_Usuario, int *ErrorRentar);
void EstacionarBicicleta(TipoBiciestacion *PrimeraBiciestacion, TipoBicicleta *PrimeraBicicleta, TipoUsuario *PrimerUsuario,TipoBiciestacion NuevaBiciestacion, int ID_Usuario, int *ErrorEstacionar);
void MostrarSaldo(TipoUsuario *PrimerUsuario, int ID_Usuario);
void CompararHoras(TipoUsuario *PrimerUsuario, TipoBicicleta *PrimeraBicicleta);
void BorrarListaBiciestacion (TipoBiciestacion *PrimeraBiciestacion);
void BorrarListaBicicleta (TipoBicicleta *PrimeraBicicleta);
void BorrarListaUsuario (TipoUsuario *PrimerUsuario);
void AltaBiciestaciones (TipoBiciestacion **PrimeraBiciestacion,TipoBiciestacion NuevaBiciestacion, int Numeracion [3], int ID_Sesion);
void BajaBiciestaciones (TipoBiciestacion **PrimeraBiciestacion, int IDBaja, int *Encontro, int ID_Sesion);
void AltaBicicletas(TipoBicicleta **PrimeraBicicleta,TipoBiciestacion *PrimeraBiciestacion, TipoBicicleta NuevaBicicleta, int Numeracion [3],int *Verificado, int ID_Sesion);
void BajaBicicletas (TipoBicicleta **PrimeraBicicleta, int IDBaja, int *Encontro, int ID_Sesion);
void ReasignarBicicletas(TipoBiciestacion *PrimeraBiciestacion,TipoBicicleta *PrimeraBicicleta,TipoBicicleta NuevaBicicleta,TipoBiciestacion NuevaBiciestacion,int *Verificar_Reasignacion, int ID_Sesion);
void AltaUsuario (TipoUsuario **PrimerUsuario, TipoUsuario NuevoUsuario, int Numeracion [3], int ID_Sesion);
void AltaPrimerUsuario (TipoUsuario **PrimerUsuario, int *PrimeraEjecucion, int Numeracion [3]); //Esta funcion da de alta al primer usuario como administrador.
void BajaUsuario (TipoUsuario **PrimerUsuario, int IDBaja, int *Encontro, int ID_Sesion);
void CargarBase (int Numeracion [3], int *PrimeraEjecucion, TipoBiciestacion **PrimeraBiciestacion, TipoBicicleta **PrimeraBicicleta, TipoUsuario **PrimerUsuario);
void GuardarDatos(TipoBiciestacion *PrimeraBiciestacion, TipoBicicleta *PrimeraBicicleta, TipoUsuario *PrimerUsuario, int Numeracion[3]);
void Timestamp(char Timestamp[200]); //Esta función obtiene la fecha y hora actual y las guarda en una cadena de salida
void GuardarEnBitacora (int ID_Sesion, char CodigoDeAccion [200],  int InformacionAdicional, int InformacionAdicional2); //Esta función actualiza la bitacora cada un administrador: Inicia / Cierra sesión, Da de Alta / Baja: Biciestaciones, Bicicletas y Usuarios y Reasigna una bicicleta.
{

void Timestamp(char Timestamp[200]) //Esta función obtiene la fecha y hora actual y las guarda en una cadena de salida
{
  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(Timestamp,200, "%Y%m%d-%H:%M:%S", timeinfo);
}

int main (int argc, char *argv[]) //Función principal.
{
  int InformacionAdicional, InformacionAdicional2;
  char CodigoDeAccion [200];
  
  TipoBiciestacion *PrimeraBiciestacion = NULL;
  TipoBicicleta *PrimeraBicicleta = NULL;
  TipoUsuario *PrimerUsuario = NULL;
  
  char Enter;
  int Numeracion [3], PrimeraEjecucion = 0, RepetirLogin, Flag, TipoUsu, ID_Sesion, SeLogueo;
  
  if(argc==2)
    {
      
      if(strcmp("-h",argv[1])==0)
	{
	  MostrarAyuda ();
	}
      if(strcmp("-c",argv[1])==0)
	{
	  Creditos();
	}
      if(strcmp("-usu",argv[1])==0)
	{
	  CargarBase (Numeracion, &PrimeraEjecucion, &PrimeraBiciestacion, &PrimeraBicicleta, &PrimerUsuario);
	  ListaActivos (PrimerUsuario);
	}
      if(strcmp("-c",argv[1])!=0 && strcmp("-usu",argv[1])!=0 && strcmp("-h",argv[1])!=0)
	{
	  printf ("\n");
	  printf ("Error: Intentó entrar a un modo de ejecución inválido.\n");
	  printf ("Para obtener info. sobre el uso del programa, ejecute el programa en modo de ayuda.\n");
	  printf ("(./bicirenta.exe -h)\n\n");
	}
    }
  else
    {
      if(argc==1)
	{
	  CargarBase (Numeracion, &PrimeraEjecucion, &PrimeraBiciestacion, &PrimeraBicicleta, &PrimerUsuario);
	  RepetirLogin = 0;
	  do
	    {
	      SeLogueo = 0;
	      if (PrimeraEjecucion == 1)
		{
		  AltaPrimerUsuario (&PrimerUsuario, &PrimeraEjecucion, Numeracion);
		}
	      Login (PrimerUsuario, &Flag, &TipoUsu, &ID_Sesion);
	      if (Flag==0 && TipoUsu==1)
		{
		  InformacionAdicional = ID_Sesion;
		  strcpy (CodigoDeAccion, "Login");
		  InformacionAdicional2 = 0;
		  GuardarEnBitacora (ID_Sesion, CodigoDeAccion, InformacionAdicional, InformacionAdicional2);
		  MenuAdmin (PrimeraBiciestacion, PrimeraBicicleta, PrimerUsuario, Numeracion, ID_Sesion);
		  SeLogueo = 1;
		}
	      if (Flag==0 && TipoUsu==0)
		{
		  MenuUsuario (PrimeraBiciestacion, PrimeraBicicleta, PrimerUsuario, ID_Sesion);
		  SeLogueo = 1;
		}
	      else
		{
		  if (SeLogueo == 0)
		    {
		      printf("Error de autenticación, el usuario o contraseña no son correctos.\n");
		      printf ("Ingrese cualquier caracter para reintentar...\n\n");
		      __fpurge (stdin);
		      scanf (" %c", &Enter);
		    }
		}
	    }
	  while (RepetirLogin == 0);
	}
      if(argc!=1 && argc!=2)
	{
	  printf ("\n");
	  printf ("Error: Intentó entrar a un modo de ejecución inválido.\n");
	  printf ("Para obtener info. sobre el uso del programa, ejecute el programa en modo de ayuda.\n");
	  printf ("(./bicirenta.exe -h)\n\n");
	}
    }  
}

void Logo() //Esta función imprime el logo de Ecobici, se utiliza en "Login" y en "Créditos".
{
  system ("sleep 0.04");
  printf ("          ███████╗ ██████╗ ██████╗ ██████╗ ██╗ ██████╗██╗\n");
  system ("sleep 0.04");
  printf ("    ,__o  ██╔════╝██╔════╝██╔═══██╗██╔══██╗██║██╔════╝██║    ,__o \n");
  system ("sleep 0.04");
  printf ("  _-/_<,  █████╗  ██║     ██║   ██║██████╔╝██║██║     ██║  _-/_<, \n");
  system ("sleep 0.04");
  printf (" (*)/'(*) ██╔══╝  ██║     ██║   ██║██╔══██╗██║██║     ██║ (*)/'(*)\n");
  system ("sleep 0.04");
  printf ("          ███████╗╚██████╗╚██████╔╝██████╔╝██║╚██████╗██║\n");
  system ("sleep 0.04");
  printf ("          ╚══════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═╝ ╚═════╝╚═╝\n");
  system ("sleep 0.04");
}

void Encabezado() //Esta función limpia la pantalla e imprime el encabezado de "Ecobici", se utiliza en "MenuAdmin", "MenuUsuario" y en las funciones que imprimen listados de datos en la base de datos
{
  system ("clear");
  printf (" _____         _   _     _ \n");
  printf ("|   __|___ ___| |_|_|___|_|\n");
  printf ("|   __|  _| . | . | |  _| |\n");
  printf ("|_____|___|___|___|_|___|_|\n");
  printf ("__________________________________________________________________________\n\n");
}

void Creditos() //Esta función limpia la pantalla e imprime los créditos del sistema.
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

void MostrarAyuda() //Esta función muestra un breve manual de ayuda al usuario.
{
  char Enter;
  system ("clear");
  printf("\n");
  Logo();
  printf("\n");
  printf("Menú de ayuda para el usuario: \n\n");
  printf("1. ¿Cómo iniciar sesión?\n");
  printf ("__________________________________________________________________________\n\n");
  printf("- Primero se debe de verificar si el usuario esta dado de alta por el administrador.\n");
  printf("- Sí el usuario no esta dado de alta, el programa marcará error y no existirá el usuario. Se deberá contactar a un administrador para darse de alta.\n");
  printf("- Se debe ingresar un usuario y una contraseña válida. Esto deplegrá el menú de opciones que tiene el usuario.\n\n");
  printf ("Ingrese cualquier caracter para continuar...\n\n");
  __fpurge (stdin);
  scanf (" %c", &Enter);
  printf ("\n");
  printf("2. ¿Cómo rentar una bicicleta? \n");
  printf ("__________________________________________________________________________\n\n");
  printf("- Se debe indicar la opción 1. Rentar una Bicicleta.\n");
  printf("- Se debe identificar el nombre de la Biciestación donde se encuentra, o donde desea rentar la bicicleta.\n");
  printf("- El programa le dira conforme al nombre de la Biciestación si puede rentar una bicicleta o no.\n");
  printf("- Es indispensable que usted no tenga en posesión una bicicleta, de lo contrario el programa no lo dejará rentar una bicicleta.\n\n");
  printf ("Ingrese cualquier caracter para continuar...\n\n");
  __fpurge (stdin);
  scanf (" %c", &Enter);
  printf ("\n");
  printf("3. ¿Cómo estacionar una bicicleta?\n");
  printf ("__________________________________________________________________________\n\n");
  printf("- Se debe iniciar sesión nuevamente e indicar la opción 2. Estacionar una Bicicleta.\n");
  printf("- Se debe identificar el nombre de la Biciestación donde se donde desea estacionar la bicicleta.\n");
  printf("- Esta opción despelgará conforme al nombre de la Biciestación, si hay lugares disponibles para estacionar la bicicleta o si debe esatcionarla en otro lugar.\n\n");
  printf ("Ingrese cualquier caracter para continuar...\n\n");
  __fpurge (stdin);
  scanf (" %c", &Enter);
  printf ("\n");
  printf("4. ¿Cómo consultar mis multas?\n");
  printf ("__________________________________________________________________________\n\n");
  printf("- Para verificar las multas se debe dar a la opción 3. Mostrar Saldo.\n");
  printf("- En la opción de mostrar saldo se desplegará si existe alguna multa o hay algún pago pendiente que impida la renta de la bicicleta.\n\n");
  printf ("Ingrese cualquier caracter para continuar...\n\n");
  __fpurge (stdin);
  scanf (" %c", &Enter);
  printf ("\n");
  printf("5. ¿Cómo cerrar sesión?\n");
  printf ("__________________________________________________________________________\n\n");
  printf("- Para salir del programa se debe de indicar la opción 4. Logout.\n");
  printf ("Ingrese cualquier caracter para continuar...\n\n");
  __fpurge (stdin);
  scanf (" %c", &Enter);
  printf("\n"); 
}

void Login (TipoUsuario *PrimerUsuario, int *Alerta, int *TipoUsu, int *ID_Sesion) //Esta función recibe usuario y contraseña, y si los encuentra en la base de datos, lleva al usuario al respectivo menú y a las funciones del menú les manda el ID del usuario que se logueó.
{
  TipoUsuario *Verificar; //Temporal con el que recorreremos la lista de los usuarios
  char Usuario[200], Contrasena[200]; //Temporales donde guardaremos usuario y contraseña para compararlos con los datos de la lista
  Verificar = PrimerUsuario; //Nos colocamos al inicio de la lista
  system ("clear");
  printf ("Bienvenido, usuario de:\n\n");
  Logo ();
  printf ("\n\n");
  printf ("Usuario: ");
  scanf (" %[^\n]", Usuario);
  printf ("\n");
  printf ("Contraseña: ");
  scanf (" %[^\n]", Contrasena);
  printf ("\n");
  *Alerta = 1; //Igualamos la flag a 1 para que pueda entrar al while
  while (Verificar != NULL && *Alerta == 1) //Recorreremos hasta que se acabe la lista o se encuentre la coincidencia (en ese caso, la flag será 0)
    {
      *Alerta = 0; //No hay errores de momento
      if ((strcmp (Verificar -> Nombre, Usuario)) != 0) //Comparamos usuario con el nombre que hay en el temporal
	*Alerta = 1; //Si no es, igualamos la flag a 1
      if ((strcmp (Verificar -> Password, Contrasena)) != 0) //Lo mismo para la contraseña
	*Alerta = 1;
      if (Verificar -> Activo == 0) //Si el usuario esta inactivo, también igualamos la flag a 1
	*Alerta = 1;
      if (*Alerta == 0) //Si la flag es 0 (no se modificó), no hubo errores, entonces se encontró la coincidencia
	{
	  *ID_Sesion = Verificar -> ID_Usuario; //Llevamos los datos del ID y del estatus administrativo hacia el Main para trabajarlos
	  *TipoUsu = Verificar -> Flag;
	}
      Verificar = Verificar -> sig; //Avanzamos en la lista
    }
}

void MenuUsuario(TipoBiciestacion *PrimeraBiciestacion, TipoBicicleta *PrimeraBicicleta, TipoUsuario *PrimerUsuario, int ID_Sesion) //Esta función imprime el menú principal del usuario y lo redirige a sus respectivas funciones.
{
  TipoBiciestacion NuevaBiciestacion;
  int Seleccion, Repetir = 1, ErrorLectura, ErrorRentar,ErrorEstacionar;
  char Enter;
  do {
    Encabezado ();
    system ("sleep 0.04");
    printf ("Bienvenido al menu principal, eliga una opción:\n\n");
    system ("sleep 0.04");
    printf ("1.- Rentar una bicicleta\n");
    system ("sleep 0.04");
    printf ("2.- Estacionar una bicicleta\n");
    system ("sleep 0.04");
    printf ("3.- Mostrar saldo (multas pendientes)\n");
    system ("sleep 0.04");
    printf ("4.- Logout\n\n");
    system ("sleep 0.04");
    printf ("Su selección: ");
    __fpurge (stdin);
    scanf (" %d", &Seleccion);
    switch (Seleccion)
      {
      case 1:
	Encabezado();
	ErrorLectura=0;
	ErrorRentar=0;
	printf("Ingrese el nombre de la biciestación: ");
	if((scanf(" %[^\n]",NuevaBiciestacion.Nombre)) != 1)
	  ErrorLectura=1;
	printf ("\n");
	if(ErrorLectura==0)
	  {
	    RentarBicicleta(PrimeraBiciestacion,PrimeraBicicleta,PrimerUsuario,NuevaBiciestacion,ID_Sesion,&ErrorRentar);
	    if(ErrorRentar==1)
	      {
		printf("La renta ha sido exitosa, recuerde devolverla a tiempo [30 minutos máximo].\n\n");
		printf ("Ingrese cualquier caracter para continuar...\n\n");
		__fpurge (stdin);
		scanf (" %c", &Enter);
	      }
	    if(ErrorRentar==2)
	      {
		printf("Error, no existe biciestacion.\n\n");
		printf ("Ingrese cualquier caracter para reintentar...\n\n");
		__fpurge (stdin);
		scanf (" %c", &Enter);
	      }
	    if(ErrorRentar==3)
	      {
		printf("Error, usted ya rentó una bicicleta.\n\n");
		printf ("Ingrese cualquier caracter para reintentar...\n\n");
		__fpurge (stdin);
		scanf (" %c", &Enter);
	      }
	    if(ErrorRentar==4)
	      {
		printf("Error, no hay bicicletas disponibles en esta estación.\n\n");
		printf ("Ingrese cualquier caracter para reintentar...\n\n");
		__fpurge (stdin);
		scanf (" %c", &Enter);
	      }
	    if(ErrorRentar==5)
	      {
		printf("Error, no hay bicicletas registradas en esta biciestaciones.\n\n");
		printf ("Ingrese cualquier caracter para reintentar...\n\n");
		__fpurge (stdin);
		scanf (" %c", &Enter);
	      }
	  }
	else
	  {
	    printf("Error, no se leyó bien el nombre la biciestacion\n\n");
	    printf ("Ingrese cualquier caracter para reintentar...\n\n");
	    __fpurge (stdin);
	    scanf (" %c", &Enter);
	  }
	break;
      case 2:
	Encabezado();
	ErrorLectura=0;
	ErrorEstacionar=0;
	printf("Ingrese el nombre de la biciestación a estacionar: ");
	if((scanf(" %[^\n]",NuevaBiciestacion.Nombre)) != 1)
	  ErrorLectura=1;
	printf ("\n");
	if(ErrorLectura==0)
	  {
	    EstacionarBicicleta(PrimeraBiciestacion,PrimeraBicicleta,PrimerUsuario,NuevaBiciestacion,ID_Sesion,&ErrorEstacionar);
	    if(ErrorEstacionar==1)
	      {
		printf("Gracias por entregar la bicicleta\n\n");
		printf ("Ingrese cualquier caracter para continuar...\n\n");
		__fpurge (stdin);
		scanf (" %c", &Enter);
	      }
	    if(ErrorEstacionar==2)
	      {
		printf("Error, no existe biciestacion.\n\n");
		printf ("Ingrese cualquier caracter para reintentar...\n\n");
		__fpurge (stdin);
		scanf (" %c", &Enter);
	      }
	    if(ErrorEstacionar==3)
	      {
		printf("Error, usted no tiene una bicicleta rentada.\n\n");
		printf ("Ingrese cualquier caracter para reintentar...\n\n");
		__fpurge (stdin);
		scanf (" %c", &Enter);
	      }
	    if(ErrorEstacionar==4)
	      {
		printf("Error, no hay lugares disponibles en esta estación.\n\n");
		printf ("Ingrese cualquier caracter para reintentar...\n\n");
		__fpurge (stdin);
		scanf (" %c", &Enter);
	      }
	  }
	else
	  {
	    printf("Error, no se leyó bien el nombre la biciestacion");
	    printf ("Ingrese cualquier caracter para reintentar...\n\n");
	    __fpurge (stdin);
	    scanf (" %c", &Enter);
	  }
	break;
      case 3:
	Encabezado();
	MostrarSaldo(PrimerUsuario,ID_Sesion);
	printf ("Ingrese cualquier caracter para continuar...\n\n");
	__fpurge (stdin);
	scanf (" %c", &Enter);
	break;
      case 4:
	Repetir = 0;
	break;
      default:
	printf ("\n");
	printf ("Ha seleccionado una opción invalida.\n");
        printf ("Para obtener info. sobre el uso del programa, ejecutelo en modo de ayuda.\n");
	printf ("(./bicirenta.exe -h)\n\n");
	printf ("Ingrese cualquier caracter para reintentar...\n");
	__fpurge (stdin);
	scanf (" %c", &Enter);
      }
  }
  while (Repetir == 1);
}

void MenuAdmin (TipoBiciestacion *PrimeraBiciestacion, TipoBicicleta *PrimeraBicicleta, TipoUsuario *PrimerUsuario, int Numeracion [3], int ID_Sesion)
{
  TipoBiciestacion NuevaBiciestacion;
  TipoUsuario NuevoUsuario;
  TipoBicicleta NuevaBicicleta;
  int Seleccion, Repetir, IDBaja, Encontro, ErrorLectura, VerificarID_Biciestacion,Verificar_Reasignacion, InformacionAdicional, InformacionAdicional2;
  char CodigoDeAccion [200];
  Repetir = 1;
  
  char Enter;
  do {
    Encabezado ();
    system ("sleep 0.04");
    printf ("Bienvenido al modo administrador, eliga una opción:\n\n");
    system ("sleep 0.04");
    printf ("1.- Dar de alta una biciestación\n");
    system ("sleep 0.04");
    printf ("2.- Dar de baja una biciestación\n");
    system ("sleep 0.04");
    printf ("3.- Dar de alta una bicicleta\n");
    system ("sleep 0.04");
    printf ("4.- Dar de baja una bicicleta\n");
    system ("sleep 0.04");
    printf ("5.- Reasignar una bicicleta\n");
    system ("sleep 0.04");
    printf ("6.- Imprimir informe de Biciestacion(es)\n");
    system ("sleep 0.04");
    printf ("7.- Dar de alta un usuario\n");
    system ("sleep 0.04");
    printf ("8.- Dar de baja un usuario\n");
    system ("sleep 0.04");
    printf ("9.- Logout\n");
    system ("sleep 0.04");
    printf ("10.- Actualizar bases de datos y salir del programa\n\n");
    system ("sleep 0.04");
    printf ("Su selección: ");
    __fpurge (stdin);
    scanf (" %d", &Seleccion);
    switch (Seleccion)
      {
      case 1:
	Encabezado ();
	ErrorLectura = 0;
	printf ("Registro de una nueva biciestación:\n\n");
	printf ("Ingrese los datos siguientes:\n");
	printf ("Escribe el nombre de la biciestacion: ");
	if ((scanf(" %[^\n]",NuevaBiciestacion.Nombre)) == 0)
	  ErrorLectura = 1;
	printf ("Ingresa el nombre de la ciudad: ");
	if ((scanf(" %[^\n]",NuevaBiciestacion.Ciudad)) == 0)
	  ErrorLectura = 1;
	printf ("Calle y Número de la biciestación: ");
        if ((scanf(" %[^\n]",NuevaBiciestacion.CalleNumero)) == 0)
	  ErrorLectura = 1;
	printf ("Ingrese el codigo postal: ");
	if ((scanf (" %d", &NuevaBiciestacion.CP)) == 0)
	  ErrorLectura = 1;
	printf ("Cuantos lugares disponibles hay?: ");
	__fpurge (stdin);
	if ((scanf(" %d", &NuevaBiciestacion.LugaresDisponibles)) == 0)
	  ErrorLectura = 1;
	printf("\n");
	if (ErrorLectura == 0)
	  {
	    printf ("Datos correctos. Estos son los datos que se guardaran:\n");
	    printf("Nombre de la biciestación: %s\n",NuevaBiciestacion.Nombre);
	    printf("Ciudad de la biciestación: %s\n",NuevaBiciestacion.Ciudad);
	    printf("Calle y Número de la biciestación: %s\n",NuevaBiciestacion.CalleNumero);
	    printf("Código postal de la biciestación: %d\n",NuevaBiciestacion.CP);
	    printf("Capacidad de la biciestación: %d lugares\n",NuevaBiciestacion.LugaresDisponibles);
	    printf ("Ingrese cualquier caracter para guardar los datos...\n\n");
	    __fpurge (stdin);
	    scanf (" %c", &Enter);
	    AltaBiciestaciones(&PrimeraBiciestacion,NuevaBiciestacion,Numeracion, ID_Sesion);
	  }
	else
	  {
	    printf ("Hubo un error de lectura, por lo que no se pudieron guardar los datos\n");
	    printf ("Ingrese cualquier caracter para continuar...\n\n");
	    __fpurge (stdin);
	    scanf (" %c", &Enter);
	  }
	break;
      case 2:
	Encabezado();
	printf("Cual es el ID de la Biciestación que desea dar de baja: \n\n");
	scanf(" %d",&IDBaja);
	BajaBiciestaciones(&PrimeraBiciestacion,IDBaja,&Encontro, ID_Sesion);
	printf ("\n");
	if (Encontro==0)
	  {
	    printf("No se encontró el ID de la Biciestación, intente de nuevo\n");
	  }
	if (Encontro==1)
	  {
	    printf ("La Biciestación con el ID: %d se ha eliminado\n", IDBaja);
	  }
	if (Encontro == 2)
	  {
	    printf ("Este ID pertenece a una Biciestación eliminada, se continuará sin realizar cambios\n\n");
	  }
	if (Encontro == 3)
	  {
	    printf ("Esta Biciestación cuenta con Bicicletas actualmente, reasigne las mismas antes de darla de baja\n\n");
	  }
	printf ("Ingrese cualquier caracter para continuar...\n\n");
	__fpurge (stdin);
	scanf (" %c", &Enter);
	break;
      case 3:
	Encabezado ();
	VerificarID_Biciestacion = 0;
	ErrorLectura = 0;
	printf ("Registro de una nueva bicicleta:\n\n");
	printf ("Ingrese los datos siguientes:\n");
	printf ("ID de la Biciestacion donde se dará de alta la nueva bicicleta: ");
	if ((scanf(" %d", &NuevaBicicleta.ID_Biciestacion)) != 1)
	  ErrorLectura = 1;
	printf ("\n");
	if (ErrorLectura == 0)
	  {
	    AltaBicicletas (&PrimeraBicicleta,PrimeraBiciestacion,NuevaBicicleta, Numeracion,&VerificarID_Biciestacion, ID_Sesion);
	    if(VerificarID_Biciestacion==1)
	      {
		printf ("Datos correctos. Estos son los datos que se guardaran:\n");
		printf ("ID de Biciestación a la que pertenece: %d\n\n", NuevaBicicleta.ID_Biciestacion); 
		printf ("Ingrese cualquier caracter para guardar los datos...\n\n");
		__fpurge (stdin);
		scanf (" %c", &Enter);
	      }
	    else
	      {
		printf("Error, no se pudo registrar la bicicleta, verifica el numero de lugares disponibles en la biciestación o si existe el ID.\n\n");
		printf ("Ingrese cualquier caracter para continuar...\n\n");
		__fpurge (stdin);
		scanf (" %c", &Enter);
	      }
	    
	  }
	else
	  {
	    printf ("Hubo un error de lectura, por lo que no se pudieron guardar los datos\n");
	    printf ("Ingrese cualquier caracter para continuar...\n\n");
	    __fpurge(stdin);
	    scanf (" %c", &Enter);
	  }
	break;
      case 4:
	Encabezado();
	printf("Cual es el ID de la bicicleta que desea dar de baja: \n");
	scanf(" %d",&IDBaja);
	BajaBicicletas(&PrimeraBicicleta,IDBaja,&Encontro, ID_Sesion);
	printf ("\n");
	if(Encontro == 0)
	  {
	    printf("No se encontró el ID de la Bicicleta, intente de nuevo\n\n");
	  }
	if (Encontro == 1)
	  {
	    printf ("La bicicleta con el ID: %d se ha eliminado\n\n", IDBaja);
	  }
	if (Encontro == 2)
	  {
	    printf ("Este ID pertenece a una Bicicleta eliminada, se continuará sin realizar cambios\n\n");
	  }
	if (Encontro == 3)
	  {
	    printf ("Esta bibicleta está en uso, por lo que no pudo ser eliminada\n\n");
	  }
	printf ("Ingrese cualquier caracter para continuar...\n\n");
	__fpurge (stdin);
	scanf (" %c", &Enter);
	break;
      case 5:
	Encabezado();
	Verificar_Reasignacion = 0;
	printf("Ingrese el ID de la bicicleta a reasignar: ");
	scanf(" %d",&NuevaBicicleta.ID_Bicicleta);
	printf ("\n");
	printf("Ingrese el ID de la biciestación donde desea reasignarla: ");
	scanf(" %d",&NuevaBiciestacion.ID_Biciestacion);
	printf ("\n");
	ReasignarBicicletas(PrimeraBiciestacion,PrimeraBicicleta,NuevaBicicleta,NuevaBiciestacion,&Verificar_Reasignacion, ID_Sesion);
	if(Verificar_Reasignacion == 0)
	  printf("Error, se trató de mover la bicicleta a biciestacion en la que se encuentra :(\n\n");
	if(Verificar_Reasignacion==1)
	  printf("Se realizo con éxito la operación, la bicicleta con ID: %d se reasignó a la biciestacion: %d.\n\n",NuevaBicicleta.ID_Bicicleta,NuevaBiciestacion.ID_Biciestacion);
	if(Verificar_Reasignacion==2)
	  printf("Error, no hay lugares disponibles en la biciestacion a reasignar :(\n\n");
	if(Verificar_Reasignacion==3)
	  printf("Error, no se encontró la biciestacion :(\n\n");
	if(Verificar_Reasignacion==4)
	  printf("Error, la bicicleta se encuentra ocupada :(\n\n");
	if(Verificar_Reasignacion==5)
	  printf("Error, no se encontró la bicicleta en la base de datos :(\n\n");
        printf ("Ingrese cualquier caracter para continuar...\n\n");
	__fpurge (stdin);
	scanf (" %c", &Enter);
	break;
      case 6:
	ListaBiciestacionesActivas(PrimeraBiciestacion);
	break;
      case 7:
	Encabezado ();
	ErrorLectura = 0;
	printf ("Registro de un nuevo usuario:\n\n");
	printf ("Ingrese los datos siguientes:\n");
	printf ("Nombre completo del nuevo usuario: ");
	if ((scanf(" %[^\n]", NuevoUsuario.Nombre)) == 0)
	  ErrorLectura = 1;
	printf ("Contraseña del nuevo usuario: ");
        if ((scanf(" %[^\n]", NuevoUsuario.Password)) == 0)
	  ErrorLectura = 1;
	printf ("Numero de tarjeta de credito del nuevo usuario: ");
	if ((scanf (" %ld", &NuevoUsuario.NumeroTarjeta)) == 0)
	  ErrorLectura = 1;
	printf ("Direccion del nuevo usuario: ");
	if ((scanf(" %[^\n]", NuevoUsuario.CalleNumero)) == 0)
	  ErrorLectura = 1;
	printf ("Estatus administrativo ('1' Para administradores, '0' Para usuarios): ");
	scanf (" %d", &NuevoUsuario.Flag);
	if (NuevoUsuario.Flag != 0 && NuevoUsuario.Flag != 1)
	  ErrorLectura = 1;
	printf ("\n");
	if (ErrorLectura == 0)
	  {
	    printf ("Datos correctos. Estos son los datos que se guardaran:\n");
	    printf ("Nombre: %s\n", NuevoUsuario.Nombre);
	    printf ("Contraseña: %s\n", NuevoUsuario.Password);
	    printf ("Numero de tarjeta de credito: %ld\n", NuevoUsuario.NumeroTarjeta);
	    printf ("Dirección: %s\n", NuevoUsuario.CalleNumero);
	    if (NuevoUsuario.Flag == 0)
	      printf ("Estatus administrativo: Usuario\n");
	    if (NuevoUsuario.Flag == 1)
	      printf ("Estatus administrativo: Administrador\n");
	    printf ("Ingrese cualquier caracter para guardar los datos...\n\n");
	    __fpurge (stdin);
	    scanf (" %c", &Enter);
	    AltaUsuario (&PrimerUsuario, NuevoUsuario, Numeracion, ID_Sesion);
	  }
	if (ErrorLectura == 1)
	  {
	    printf ("Hubo un error de lectura, por lo que no se pudieron guardar los datos\n\n");
	    printf ("Ingrese cualquier caracter para continuar: \n\n");
	    __fpurge(stdin);
	    scanf (" %c", &Enter);
	  }
	break;
      case 8:
	Encabezado();
	printf("¿Cual es el ID del usuario a dar de baja?\n\n");
	__fpurge (stdin);
	scanf(" %d",&IDBaja);
	BajaUsuario(&PrimerUsuario,IDBaja,&Encontro, ID_Sesion);
	printf ("\n");
	if(Encontro==0)
	  {
	    printf("No se encontró el ID el usuario, intente de nuevo\n");
	  }
	if (Encontro==1)
	  {
	    printf ("El usuario con el ID: %d se ha eliminado\n", IDBaja);
	  }
	if (Encontro == 2)
	  {
	    printf ("Este ID pertenece a un Usuario eliminado, se continuará sin realizar cambios\n");
	  }
	if (Encontro == 3)
	  {
	    printf ("El usuarió que intentó eliminar está en posesión de una bicicleta, por lo que no pudo ser eliminado\n");
	  }
	printf ("\n"); 
	printf ("Ingrese cualquier caracter para continuar...\n\n");
	__fpurge (stdin);
	scanf (" %c", &Enter);
	break;
      case 9:
	Repetir = 0;
	InformacionAdicional = ID_Sesion;
	strcpy (CodigoDeAccion, "Logout");
	InformacionAdicional2 = 0;
	GuardarEnBitacora (ID_Sesion, CodigoDeAccion, InformacionAdicional, InformacionAdicional2);
	break;
      case 10:
	Repetir = 0;
	InformacionAdicional = ID_Sesion;
	strcpy (CodigoDeAccion, "Logout");
	InformacionAdicional2 = 0;
	GuardarEnBitacora (ID_Sesion, CodigoDeAccion, InformacionAdicional, InformacionAdicional2);
	GuardarDatos(PrimeraBiciestacion, PrimeraBicicleta, PrimerUsuario, Numeracion);
	break;
      default:
	printf ("\n");
	printf ("Ha seleccionado una opción invalida.\n");
        printf ("Para obtener info. sobre el uso del programa, ejecutelo en modo de ayuda.\n");
	printf ("(./bicirenta.exe -h)\n\n");
	printf ("Ingrese cualquier caracter para reintentar...\n\n");
	__fpurge (stdin);
	scanf (" %c", &Enter);
      }
  }
  while (Repetir == 1);
}

void RentarBicicleta(TipoBiciestacion *PrimeraBiciestacion, TipoBicicleta *PrimeraBicicleta, TipoUsuario *PrimerUsuario,TipoBiciestacion NuevaBiciestacion, int ID_Usuario, int *ErrorRentar)
{
  while(PrimerUsuario!=NULL && *ErrorRentar!=1)
    {
      if(PrimerUsuario->ID_Usuario==ID_Usuario) //Reconocer ID de Usuario.
	{
	  if(PrimerUsuario->TieneBici==0) // Comprueba si el usuario tiene una bicicleta rentada.
	    {
	      while(PrimeraBiciestacion!=NULL && *ErrorRentar!=1) //Hasta encontrar NULL
		{
		  if((strcmp(PrimeraBiciestacion->Nombre,NuevaBiciestacion.Nombre))==0) //Saber si la biciestacion existe
		    {
		      if(PrimeraBiciestacion->LugaresLlenos>0) //Hay bicicletas
			{
			  while(PrimeraBicicleta!=NULL && *ErrorRentar!=1)
			    {
			      if(PrimeraBicicleta->ID_Biciestacion==PrimeraBiciestacion->ID_Biciestacion) // Bicicletas que coinciden con la Biciestacion. 
				{
				  if(PrimeraBicicleta->Activo==1) // Verifica que la bicicleta esté activa
				    {
				      if((strcmp("NULL",PrimeraBicicleta->Timestamp))==0) //La bicicleta está disponible para rentar
					{
					  *ErrorRentar=1;
					  PrimerUsuario->TieneBici=1;
					  PrimerUsuario -> ID_Bicicleta = PrimeraBicicleta -> ID_Bicicleta;
					  PrimeraBicicleta->RentasPasadas+=1;
					  PrimeraBiciestacion->LugaresDisponibles+=1;
					  PrimeraBiciestacion->LugaresLlenos-=1;
					  time_t rawtime;
					  struct tm *timeinfo;
					  time(&rawtime);
					  timeinfo = localtime(&rawtime);
					  strftime(PrimeraBicicleta->Timestamp,200,"%Y%m%d-%H:%M:%S",timeinfo);
					}
				    }
				}
			      PrimeraBicicleta=PrimeraBicicleta->sig;
			    }
			  if (*ErrorRentar != 1)
			    {
			      *ErrorRentar = 4; //Acabo de recorrer, pero la biciestacion no tiene lugares, se devuelve el Error 4.
			    }
			}
		      else
			*ErrorRentar = 4; //Acabo de recorrer, pero la biciestacion no tiene lugares, se devuelve el Error 4.
		    }
		  else // No existe biciestacion
		    {
		      *ErrorRentar=2;
		    }
		  PrimeraBiciestacion=PrimeraBiciestacion->sig;
		}
	    }
	  else // No tiene ninguna bicicleta rentada.
	    {
	      *ErrorRentar=3;
	    }

	}
      PrimerUsuario=PrimerUsuario->sig;
    }
    
}

void EstacionarBicicleta(TipoBiciestacion *PrimeraBiciestacion, TipoBicicleta *PrimeraBicicleta, TipoUsuario *PrimerUsuario,TipoBiciestacion NuevaBiciestacion, int ID_Usuario, int *ErrorEstacionar)
{
  while(PrimerUsuario!=NULL && *ErrorEstacionar!=1)
    {
      if(PrimerUsuario->ID_Usuario==ID_Usuario) //Reconocer ID de Usuario.
	{
	  if(PrimerUsuario->TieneBici==1) // Comprueba si el usuario tiene una bicicleta rentada.
	    {
	      while(PrimeraBiciestacion!=NULL && *ErrorEstacionar!=1) //Hasta encontrar NULL
		{
		  if((strcmp(PrimeraBiciestacion->Nombre,NuevaBiciestacion.Nombre))==0) //Saber si la biciestacion existe
		    {
		      if(PrimeraBiciestacion->LugaresDisponibles>0) //Hay lugares vacios para estacionar
			{
			  while(PrimeraBicicleta!=NULL && *ErrorEstacionar!=1)
			    {
			      if(PrimeraBicicleta -> ID_Bicicleta == PrimerUsuario -> ID_Bicicleta) // Si coincide el ID de la bici del usuario con alguna de la lista. 
				{      		     					
				  *ErrorEstacionar=1; // Éxito total
				  PrimerUsuario->TieneBici=0;
				  PrimerUsuario->ID_Bicicleta=0;
				  PrimeraBicicleta->ID_Biciestacion=PrimeraBiciestacion->ID_Biciestacion;
				  PrimeraBiciestacion->LugaresDisponibles-=1;
				  PrimeraBiciestacion->LugaresLlenos+=1;
				  CompararHoras(PrimerUsuario,PrimeraBicicleta);
				  strcpy(PrimeraBicicleta->Timestamp,"NULL");									  
				}
			      PrimeraBicicleta=PrimeraBicicleta->sig;
			    }
			  if (*ErrorEstacionar != 1)
			    {
			      *ErrorEstacionar=4; //Acabo de recorrer las bicicletas pero no rentó ninguna con exito, se devuelve el Error 4.
			    }
			}
		      else
			*ErrorEstacionar=5; //La biciestación no tiene ninguna bicicleta registrada, se devuelve el Error 5.
		    }
		  else // No existe biciestacion
		    {
		      *ErrorEstacionar=2;
		    }
		  PrimeraBiciestacion=PrimeraBiciestacion->sig;
		}
	    }
	  else // No tiene una bicicleta rentada.
	    {
	      *ErrorEstacionar=3;
	    }

	}
      PrimerUsuario=PrimerUsuario->sig;
    }
}
void MostrarSaldo(TipoUsuario *PrimerUsuario, int ID_Sesion)
{
  while(PrimerUsuario!=NULL)
    {
      if(PrimerUsuario->ID_Usuario==ID_Sesion)
	{
	  printf("Número de multas: %d\n\n", PrimerUsuario->Multas);
	}
      PrimerUsuario=PrimerUsuario->sig;
    }
}
void CompararHoras(TipoUsuario *PrimerUsuario, TipoBicicleta *PrimeraBicicleta)
{
  char FechaActualTemp[200];
  int HoraActual,HoraBicicleta, MinutoActual, MinutoBicicleta, SegundoActual, SegundoBicicleta,FechaBicicleta,FechaActual,SegundosActualTotal,SegundosBicicletaTotal, DiferenciaSegundos;
  time_t rawtime;
  struct tm *timeinfo;
  
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(FechaActualTemp,200,"%Y%m%d",timeinfo);
  sscanf(FechaActualTemp,"%d",&FechaActual);
  HoraActual=timeinfo->tm_hour;
  MinutoActual=timeinfo->tm_min;
  SegundoActual=timeinfo->tm_sec;
  sscanf(PrimeraBicicleta->Timestamp,"%d-%d:%d:%d",&FechaBicicleta,&HoraBicicleta,&MinutoBicicleta,&SegundoBicicleta);
  SegundosActualTotal=(HoraActual*3600)+(MinutoActual*60)+(SegundoActual);
  SegundosBicicletaTotal=(HoraBicicleta*3600)+(MinutoBicicleta*60)+(SegundoBicicleta);
  DiferenciaSegundos = (86400 - SegundosBicicletaTotal) + (SegundosActualTotal);
  if(FechaActual>FechaBicicleta+1)
    {
      PrimerUsuario->Multas+=1;
      printf("Se le aplico una multa por entrega tardia\n\n");
    }
  else
    {
      if(SegundosActualTotal > SegundosBicicletaTotal)
	{
	  if (SegundosActualTotal > SegundosBicicletaTotal + 1800)
	    {
	      PrimerUsuario->Multas+=1;
	      printf("Se le aplico una multa por entrega tardia\n\n");
	    }
	  else
	    {
	      printf("No se le ha aplicado multa\n\n");
	    }
	}
      else
	{
	  if (DiferenciaSegundos > 1800)
	    {
	      PrimerUsuario->Multas+=1;
	      printf("Se le aplico una multa por entrega tardia\n\n");
	    }
	  else
	    {
	      printf("No se le ha aplicado multa\n\n");
	    }
	}
    }
 
  
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

void AltaBiciestaciones(TipoBiciestacion **PrimeraBiciestacion, TipoBiciestacion NuevaBiciestacion, int Numeracion [3], int ID_Sesion)
{
  char CodigoDeAccion [200];
  int InformacionAdicional, InformacionAdicional2;
  TipoBiciestacion *nuevo, *temp;
  nuevo = (TipoBiciestacion *)malloc(sizeof(TipoBiciestacion));
  nuevo -> ID_Biciestacion = Numeracion [0];
  InformacionAdicional = Numeracion [0];
  Numeracion [0] ++;
  nuevo -> CP = NuevaBiciestacion.CP;
  nuevo -> LugaresLlenos= 0;
  nuevo -> LugaresDisponibles = NuevaBiciestacion.LugaresDisponibles;
  strcpy (nuevo -> Nombre, NuevaBiciestacion.Nombre);
  strcpy (nuevo->CalleNumero, NuevaBiciestacion.CalleNumero);
  strcpy (nuevo->Ciudad, NuevaBiciestacion.Ciudad);
  nuevo -> Activo = 1;
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
  strcpy (CodigoDeAccion, "101");
  InformacionAdicional2 = 0;
  GuardarEnBitacora (ID_Sesion, CodigoDeAccion, InformacionAdicional, InformacionAdicional2);
}

void BajaBiciestaciones (TipoBiciestacion **PrimeraBiciestacion, int IDBaja, int *Encontro, int ID_Sesion)
{
  int InformacionAdicional, InformacionAdicional2;
  char CodigoDeAccion [200];
  TipoBiciestacion *actual;
  actual = *PrimeraBiciestacion;
  while (actual != NULL && actual -> ID_Biciestacion != IDBaja) //Recorre la lista de Biciestaciones hasta salirse o encontrar la coincidencia
    {
      actual = actual -> sig;
    }
  if (actual == NULL) //Si no la encontró
    *Encontro = 0; //Mandamos error 0 a Encontró
  else //Si la encontró
    {
      if (actual -> Activo == 1) //Si está activa
	{
	  if (actual -> LugaresLlenos == 0) //Si no tiene bicis
	    {
	      actual -> Activo = 0; //La da de baja y mandamos 1 a Encontró
	      *Encontro = 1;
	      InformacionAdicional = actual -> ID_Biciestacion;
	      strcpy (CodigoDeAccion, "102");
	      InformacionAdicional2 = 0;
	      GuardarEnBitacora (ID_Sesion, CodigoDeAccion, InformacionAdicional, InformacionAdicional2);
	    }
	  else //Si tiene bicis
	    {
	      *Encontro = 3; //Mandamos error 3 a Encontró
	    }
	}
      else //Si no está activa
	*Encontro = 2; //Mandamos error 2 a Encontró
    }
}

void AltaBicicletas(TipoBicicleta **PrimeraBicicleta,TipoBiciestacion *PrimeraBiciestacion, TipoBicicleta NuevaBicicleta, int Numeracion [3], int *Verificado, int ID_Sesion)
{
  int InformacionAdicional, InformacionAdicional2;
  char CodigoDeAccion [200];
  TipoBicicleta *nuevo, *temp;
  nuevo = (TipoBicicleta *)malloc(sizeof(TipoBicicleta));
  nuevo -> ID_Bicicleta = Numeracion [1];
  InformacionAdicional = Numeracion [1];
  nuevo -> ID_Biciestacion = NuevaBicicleta.ID_Biciestacion;
  nuevo -> RentasPasadas = 0;
  nuevo -> Activo = 1;
  *Verificado = 0;
  strcpy (nuevo -> Timestamp, "NULL");
  while(PrimeraBiciestacion!=NULL && *Verificado!=1)
    {
      if(PrimeraBiciestacion-> ID_Biciestacion==nuevo->ID_Biciestacion)
	{
	  if(PrimeraBiciestacion->Activo==1)
	    {
	      if(PrimeraBiciestacion->LugaresDisponibles > 0)
		{
		  {
		    PrimeraBiciestacion->LugaresLlenos+=1;
		    PrimeraBiciestacion->LugaresDisponibles-=1;
		    *Verificado=1;
		    Numeracion [1] ++;
		    strcpy (CodigoDeAccion, "201");
		    InformacionAdicional2 = 0;
		    GuardarEnBitacora (ID_Sesion, CodigoDeAccion, InformacionAdicional, InformacionAdicional2);
		  }
		}
	    }
	}
      PrimeraBiciestacion=PrimeraBiciestacion->sig;
    }
  if(*Verificado==1)
    {
      nuevo -> sig = NULL;
      if (*PrimeraBicicleta!=NULL)
	{
	  temp=*PrimeraBicicleta;
	  while(temp->sig!=NULL)
	    temp=temp->sig;
	  temp->sig=nuevo;
	}
      else
	{
	  *PrimeraBicicleta=nuevo;
	}
    }
}

void BajaBicicletas (TipoBicicleta **PrimeraBicicleta, int IDBaja, int *Encontro, int ID_Sesion)
{
  int InformacionAdicional, InformacionAdicional2;
  char CodigoDeAccion [200];
  TipoBicicleta *actual;
  actual = *PrimeraBicicleta;
  while (actual != NULL && actual -> ID_Bicicleta != IDBaja)
    {
      actual = actual -> sig;
    }
  if (actual == NULL) //Si no logra encontrar la bicicleta
    {
      *Encontro = 0; //Regresamos error 0 en Encontro
    }
  else //Si encuentra la bicicleta
    {
      if (actual -> Activo == 1) //Si la bicicleta está activa
	{
	  if (strcmp ("NULL", actual -> Timestamp) == 0) //Si no está ocupada
	    {
	      actual -> Activo = 0; //Se desactiva y regresamos 1 en Encontro
	      *Encontro = 1;
	      InformacionAdicional = actual -> ID_Bicicleta;
	      strcpy (CodigoDeAccion, "202");
	      InformacionAdicional2 = 0;
	      GuardarEnBitacora (ID_Sesion, CodigoDeAccion, InformacionAdicional, InformacionAdicional2);
	    }
	  else //Si está ocupada
	    {
	      *Encontro = 3; //Regresamos error 3 en Encontro
	    }
	}
      else //Si la bicicleta no está activa
	{
	  *Encontro = 2; //Regresamos error 2 en Encontro
	}
    }
}

void ReasignarBicicletas(TipoBiciestacion *PrimeraBiciestacion,TipoBicicleta *PrimeraBicicleta,TipoBicicleta NuevaBicicleta, TipoBiciestacion NuevaBiciestacion, int *Verificar_Reasignacion, int ID_Sesion)
{
  char CodigoDeAccion [200];
  TipoBiciestacion *TempBiciestacion;
  int IDTemp_Biciestacion, Entro = 0, InformacionAdicional, InformacionAdicional2;
  TempBiciestacion=PrimeraBiciestacion;
  
  while (PrimeraBicicleta!=NULL)
    {
      Entro=1;
      if(PrimeraBicicleta->ID_Bicicleta==NuevaBicicleta.ID_Bicicleta) //Encuentra si el ID de la Bicicleta se encuentra en la lista dinámica.
	{
	  if((strcmp("NULL",PrimeraBicicleta->Timestamp))==0) //Comprueba si la bicicleta está ocupada.
	    {
	      if(PrimeraBicicleta->ID_Biciestacion==NuevaBiciestacion.ID_Biciestacion) //La Bicicleta se encuentra en la misma biciestacion a cambiar.
		{
		  *Verificar_Reasignacion=0;
		}
	      else
		{
		  while(PrimeraBiciestacion!=NULL && *Verificar_Reasignacion != 1)
		    {
		      if(PrimeraBiciestacion->ID_Biciestacion==NuevaBiciestacion.ID_Biciestacion) // Comprueba si el ID de Biciestacion ingresado existe en la lista dinámica.
			{
			  if(PrimeraBiciestacion->LugaresDisponibles>0) //Si hay lugares disponibles
			    {
			      PrimeraBiciestacion->LugaresLlenos+=1;
			      PrimeraBiciestacion->LugaresDisponibles-=1;
			      IDTemp_Biciestacion=PrimeraBicicleta->ID_Biciestacion;
			      while(TempBiciestacion!=NULL)
				{
				  if(TempBiciestacion->ID_Biciestacion==IDTemp_Biciestacion)
				    {
				      InformacionAdicional = PrimeraBicicleta -> ID_Bicicleta;
				      InformacionAdicional2 = TempBiciestacion -> ID_Biciestacion;
				      strcpy (CodigoDeAccion, "203");
				      GuardarEnBitacora (ID_Sesion, CodigoDeAccion, InformacionAdicional, InformacionAdicional2);
				      TempBiciestacion->LugaresLlenos-=1;
				      TempBiciestacion->LugaresDisponibles+=1;
				    }
				  TempBiciestacion=TempBiciestacion->sig;
				}
			      PrimeraBicicleta->ID_Biciestacion = NuevaBiciestacion.ID_Biciestacion;
			      *Verificar_Reasignacion=1;
			    }
			  else // Si no hay lugares.
			    *Verificar_Reasignacion=2; 
			}
		      else //No se encontró la biciestacion 
			*Verificar_Reasignacion=3;
		      PrimeraBiciestacion = PrimeraBiciestacion->sig;  //Avanza en lista Biciestacion.
		    }
		}
	    }
	  else 
	    *Verificar_Reasignacion=4; // Esta ocupada la bicicleta.
	}
      else 
	*Verificar_Reasignacion=5; //No se encontró el ID de la bicicleta.
      PrimeraBicicleta=PrimeraBicicleta->sig;
    }
  if(PrimeraBicicleta==NULL && Entro==0)
    {
      printf ("If 7\n");
      system ("sleep 1");
      *Verificar_Reasignacion=5; //No se encontró el ID de la bicicleta.
    } 
}

void AltaUsuario(TipoUsuario **PrimerUsuario, TipoUsuario NuevoUsuario, int Numeracion [3], int ID_Sesion) //Inserta el usuario que envie el menú del administrador hasta el final de la lista dinámica de usuarios
{
  int InformacionAdicional, InformacionAdicional2;
  char CodigoDeAccion [200];
  TipoUsuario *nuevo, *temp;
  nuevo = (TipoUsuario *)malloc(sizeof(TipoUsuario));
  nuevo -> ID_Usuario = Numeracion [2];
  InformacionAdicional = Numeracion [2];
  Numeracion [2] ++;
  nuevo -> TieneBici = 0;
  nuevo -> Activo = 1;
  nuevo -> Multas = 0;
  strcpy (nuevo -> Nombre, NuevoUsuario.Nombre);
  strcpy (nuevo -> Password, NuevoUsuario.Password);
  nuevo -> NumeroTarjeta = NuevoUsuario.NumeroTarjeta;
  strcpy (nuevo->CalleNumero, NuevoUsuario.CalleNumero);
  nuevo -> Flag = NuevoUsuario.Flag;
  nuevo -> ID_Bicicleta = 0;
  nuevo -> sig = NULL;
  if (*PrimerUsuario != NULL)
    {
      temp = *PrimerUsuario;
      while (temp -> sig != NULL)
	temp = temp -> sig;
      temp -> sig = nuevo;
    }
  else
    *PrimerUsuario = nuevo;
  strcpy (CodigoDeAccion, "301");
  InformacionAdicional2 = 0;
  GuardarEnBitacora (ID_Sesion, CodigoDeAccion, InformacionAdicional, InformacionAdicional2);
}

void BajaUsuario (TipoUsuario **PrimerUsuario, int IDBaja, int *Encontro, int ID_Sesion)
{
  int InformacionAdicional, InformacionAdicional2;
  char CodigoDeAccion [200];
  TipoUsuario *actual;
  actual = *PrimerUsuario;
  while (actual != NULL && actual -> ID_Usuario != IDBaja)
    {
      actual = actual -> sig;
    }
  if (actual == NULL)
    *Encontro = 0;
  else
    {
      if (actual -> Activo == 1)
	{
	  if (actual -> TieneBici == 0)
	    {
	      actual -> Activo = 0;
	      *Encontro = 1;
	      InformacionAdicional = actual -> ID_Usuario;
	      strcpy (CodigoDeAccion, "302");
	      InformacionAdicional2 = 0;
	      GuardarEnBitacora (ID_Sesion, CodigoDeAccion, InformacionAdicional, InformacionAdicional2);
	    }
	  else
	    {
	      *Encontro = 3;
	    }
	}
      else
	*Encontro = 2;
    }
}

void CargarBase (int Numeracion [3], int *PrimeraEjecucion, TipoBiciestacion **PrimeraBiciestacion, TipoBicicleta **PrimeraBicicleta, TipoUsuario **PrimerUsuario)
{
  int i, NuevoID_Biciestacion, NuevoID_Bicicleta, NuevoID_Usuario;
  char Enter, CargaUsuario[500];
  FILE *ArchivoNumeracion, *ArchivoBiciestacion, *ArchivoBicicleta, *ArchivoUsuario;
  TipoBiciestacion *tempbiciestacion, *nuevabiciestacion;
  TipoBicicleta *tempbicicleta, *nuevabicicleta;
  TipoUsuario *tempusuario, *nuevousuario;
  ArchivoNumeracion = fopen ("Numeracion.eco", "rt");
  ArchivoBiciestacion = fopen ("Biciestacion.eco", "rt");
  ArchivoBicicleta = fopen ("Bicicleta.eco", "rt");
  ArchivoUsuario = fopen ("Usuario.eco", "rt");
  if (ArchivoNumeracion == NULL || ArchivoBiciestacion == NULL || ArchivoBicicleta == NULL || ArchivoUsuario == NULL || (fscanf (ArchivoNumeracion, "%d, %d, %d", &Numeracion [0], &Numeracion [1], &Numeracion [2])) != 3)
    {
      system ("clear");
      printf ("No se encontraron todos los archivos necesarios para la ejecución del programa, al continuar se creará una nueva base de datos\n");
      printf ("Si es la primera vez que ejecuta el sistema, presione Enter\n\n");
      printf ("Ingrese cualquier caracter para continuar, ingrese 'S' para salir sin guardar cambios...\n");
      __fpurge (stdin);
      scanf (" %c", &Enter);
      if (Enter == 's' || Enter == 'S')
	{
	  printf ("Saliendo sin guardar cambios...\n");
	  system ("sleep 1");
	  exit (0);
	}
      else
	{
	  ArchivoNumeracion = fopen ("Numeracion.eco", "wt");
	  ArchivoBiciestacion = fopen ("Biciestacion.eco", "wt");
	  ArchivoBicicleta = fopen ("Bicicleta.eco", "wt");
	  ArchivoUsuario = fopen ("Usuario.eco", "wt");
	  fclose(ArchivoNumeracion);
	  fclose(ArchivoBiciestacion);
	  fclose(ArchivoBicicleta);
	  fclose(ArchivoUsuario);
	  *PrimeraEjecucion = 1; //Indica que se van a crear nuevas bases de datos
	  for (i = 0; i < 3; i ++) //Llena el arreglo que guarda los IDs con unos, ya que todo lo que se guarde va a ser el primero de cada base
	    Numeracion [i] = 1;
	}
    }
  else
    {
      fclose(ArchivoNumeracion);
      fclose(ArchivoBiciestacion);
      fclose(ArchivoBicicleta);
      fclose(ArchivoUsuario);
      ArchivoNumeracion = fopen ("Numeracion.eco", "rt");
      ArchivoBiciestacion = fopen ("Biciestacion.eco", "rt");
      ArchivoBicicleta = fopen ("Bicicleta.eco", "rt");
      ArchivoUsuario = fopen ("Usuario.eco", "rt");
      
      fscanf (ArchivoNumeracion, "%d, %d, %d", &Numeracion [0], &Numeracion [1], &Numeracion [2]);
      
      while ((fscanf (ArchivoUsuario, " %d", &NuevoID_Usuario)) == 1)
	{
	  nuevousuario = (TipoUsuario *)malloc(sizeof(TipoUsuario));
	  nuevousuario -> ID_Usuario = NuevoID_Usuario;
	  fscanf (ArchivoUsuario, " %d", &nuevousuario -> TieneBici);
	  fscanf (ArchivoUsuario, " %d", &nuevousuario -> Activo);
	  fscanf (ArchivoUsuario, " %d", &nuevousuario -> Multas);
	  fscanf (ArchivoUsuario, " %[^\n]", nuevousuario -> Nombre);
	  fscanf (ArchivoUsuario, " %[^\n]", nuevousuario -> Password);
	  fscanf (ArchivoUsuario, " %li", &nuevousuario -> NumeroTarjeta);
	  fscanf (ArchivoUsuario, " %[^\n]", nuevousuario -> CalleNumero);
	  fscanf (ArchivoUsuario, " %d", &nuevousuario -> Flag);
	  fscanf (ArchivoUsuario, " %d", &nuevousuario -> ID_Bicicleta);
	  nuevousuario -> sig = NULL;
	  if (*PrimerUsuario != NULL)
	    {
	      tempusuario = *PrimerUsuario;
	      while (tempusuario -> sig != NULL)
		tempusuario = tempusuario -> sig;
	      tempusuario -> sig = nuevousuario;
	    }
	  else
	    {
	      *PrimerUsuario = nuevousuario;
	    }
	}

      while ((fscanf (ArchivoBiciestacion, " %d", &NuevoID_Biciestacion)) == 1)
	{
	  nuevabiciestacion = (TipoBiciestacion *)malloc(sizeof(TipoBiciestacion));
	  nuevabiciestacion -> ID_Biciestacion = NuevoID_Biciestacion;
	  fscanf (ArchivoBiciestacion, " %d", &nuevabiciestacion -> Activo);
	  fscanf (ArchivoBiciestacion, " %[^\n]", nuevabiciestacion -> Nombre);
	  fscanf (ArchivoBiciestacion, " %[^\n]", nuevabiciestacion -> Ciudad);
	  fscanf (ArchivoBiciestacion, " %d", &nuevabiciestacion -> CP);
	  fscanf (ArchivoBiciestacion, " %[^\n]", nuevabiciestacion -> CalleNumero);
	  fscanf (ArchivoBiciestacion, " %d", &nuevabiciestacion -> LugaresDisponibles);
	  fscanf (ArchivoBiciestacion, " %d", &nuevabiciestacion -> LugaresLlenos);	  
	  nuevabiciestacion -> sig = NULL;
	  if (*PrimeraBiciestacion != NULL)
	    {
	      tempbiciestacion = *PrimeraBiciestacion;
	      while (tempbiciestacion -> sig != NULL)
		tempbiciestacion = tempbiciestacion -> sig;
	      tempbiciestacion -> sig = nuevabiciestacion;
	    }
	  else
	    {
	      *PrimeraBiciestacion = nuevabiciestacion;
	    }
	}

      while ((fscanf (ArchivoBicicleta, " %d", &NuevoID_Bicicleta)) == 1)
	{
	  nuevabicicleta = (TipoBicicleta *)malloc(sizeof(TipoBicicleta));
	  nuevabicicleta -> ID_Bicicleta = NuevoID_Bicicleta;
	  fscanf (ArchivoBicicleta, " %d", &nuevabicicleta -> ID_Biciestacion);
	  fscanf (ArchivoBicicleta, " %d", &nuevabicicleta -> RentasPasadas);
	  fscanf (ArchivoBicicleta, " %[^\n]", nuevabicicleta -> Timestamp);
	  fscanf (ArchivoBicicleta, " %d", &nuevabicicleta -> Activo);
	  nuevabicicleta -> sig = NULL;
	  if (*PrimeraBicicleta != NULL)
	    {
	      tempbicicleta = *PrimeraBicicleta;
	      while (tempbicicleta -> sig != NULL)
		tempbicicleta = tempbicicleta -> sig;
	      tempbicicleta -> sig = nuevabicicleta;
	    }
	  else
	    {
	      *PrimeraBicicleta = nuevabicicleta;
	    }
	}
      
      fclose(ArchivoNumeracion);
      fclose(ArchivoBiciestacion);
      fclose(ArchivoBicicleta);
      fclose(ArchivoUsuario);
    }
}

void ListaActivos(TipoUsuario *PrimerUsuario)
{
  TipoUsuario *temp;
  temp = PrimerUsuario;
  Encabezado ();
  printf ("Estos son los usuarios activos:\n\n");
  while (temp != NULL)
    {
      if(temp -> Activo == 1)
	{
	  printf ("ID de usuario: %d\n", temp -> ID_Usuario);
	  printf ("Nombre completo del usuario: %s\n", temp -> Nombre);
	  printf ("Contraseña del usuario: %s\n", temp -> Password);
	  printf ("Tarjeta de crédito: %ld\n", temp -> NumeroTarjeta);
	  printf ("Dirección: %s\n", temp -> CalleNumero);
	  printf("Numero de multas: %d\n",temp-> Multas);
	  if (temp -> TieneBici == 0)
	    printf ("Estado de renta: Sin bicicletas\n");
	  else
	    printf ("Estado de renta: En posesión de una bicicleta\n");
	  if(temp->ID_Bicicleta!=0)
	    printf("Bicicleta en posesión: %d\n",temp->ID_Bicicleta);
	  if (temp -> Flag == 0)
	    printf ("Tipo de usuario: Usuario (Sin privilegios)\n");
	  else
	    printf ("Tipo de usuario: Administrador (Con privilegios)\n");
	  printf ("__________________________________________________________________________\n\n");
	  system ("sleep 0.2");
	}
      temp = temp -> sig;
    }
}

void ListaBiciestacionesActivas(TipoBiciestacion *PrimeraBiciestacion)
{
  char Enter;
  TipoBiciestacion *temp;
  temp = PrimeraBiciestacion;
  Encabezado ();
  printf ("Estas son las Biciestaciones activas:\n\n");
  while (temp != NULL)
    {
      if(temp -> Activo == 1)
	{
	  printf ("ID de la Biciestacion: %d\n", temp -> ID_Biciestacion);
	  system ("sleep 0.04");
	  printf ("Nombre completo de la Biciestación : %s\n", temp -> Nombre);
	  system ("sleep 0.04");
	  printf ("Calle y Número: %s\n", temp -> CalleNumero);
	  system ("sleep 0.04");
	  printf ("Ciudad: %s\n", temp -> Ciudad);
	  system ("sleep 0.04");
	  printf ("Código Postal: %d\n", temp -> CP);
	  system ("sleep 0.04");
	  printf ("Lugares Llenos: %d\n", temp -> LugaresLlenos);
	  system ("sleep 0.04");
	  printf ("Lugares Disponibles: %d\n", temp -> LugaresDisponibles);
	  system ("sleep 0.04");
	  printf ("__________________________________________________________________________\n\n");
	  system ("sleep 0.04");
	}
      temp = temp -> sig;
    }
  printf ("Ingrese cualquier caracter para continuar...\n\n");
  __fpurge (stdin);
  scanf (" %c", &Enter);
}

void GuardarDatos(TipoBiciestacion *PrimeraBiciestacion, TipoBicicleta *PrimeraBicicleta, TipoUsuario *PrimerUsuario, int Numeracion[3])
{
  FILE *ArchivoNumeracion, *ArchivoBiciestacion, *ArchivoBicicleta, *ArchivoUsuario;
  ArchivoNumeracion = fopen ("Numeracion.eco", "wt");
  ArchivoBiciestacion = fopen("Biciestacion.eco", "wt");
  ArchivoBicicleta = fopen ("Bicicleta.eco", "wt");
  ArchivoUsuario = fopen ("Usuario.eco", "wt");
  fprintf (ArchivoNumeracion, "%d, %d, %d\n", Numeracion [0], Numeracion [1], Numeracion [2]);
  while(PrimeraBiciestacion != NULL)
    {
      fprintf(ArchivoBiciestacion, "%d\n%d\n%s\n%s\n%d\n%s\n%d\n%d\n", PrimeraBiciestacion -> ID_Biciestacion, PrimeraBiciestacion -> Activo, PrimeraBiciestacion -> Nombre, PrimeraBiciestacion -> Ciudad, PrimeraBiciestacion -> CP, PrimeraBiciestacion -> CalleNumero, PrimeraBiciestacion -> LugaresDisponibles, PrimeraBiciestacion -> LugaresLlenos);
      PrimeraBiciestacion=PrimeraBiciestacion->sig;
    }
  while (PrimeraBicicleta != NULL)
    {
      fprintf (ArchivoBicicleta, "%d\n%d\n%d\n%s\n%d\n", PrimeraBicicleta -> ID_Bicicleta, PrimeraBicicleta -> ID_Biciestacion, PrimeraBicicleta -> RentasPasadas, PrimeraBicicleta -> Timestamp, PrimeraBicicleta -> Activo);
      PrimeraBicicleta = PrimeraBicicleta -> sig;
    }
  while (PrimerUsuario != NULL)
    {
      fprintf(ArchivoUsuario,"%d\n%d\n%d\n%d\n%s\n%s\n%ld\n%s\n%d\n%d\n", PrimerUsuario->ID_Usuario, PrimerUsuario->TieneBici, PrimerUsuario -> Activo,PrimerUsuario->Multas, PrimerUsuario->Nombre, PrimerUsuario->Password, PrimerUsuario->NumeroTarjeta,PrimerUsuario->CalleNumero, PrimerUsuario->Flag, PrimerUsuario->ID_Bicicleta);
      PrimerUsuario=PrimerUsuario->sig;
    }
  BorrarListaBiciestacion (PrimeraBiciestacion);
  BorrarListaBicicleta (PrimeraBicicleta);
  BorrarListaUsuario(PrimerUsuario);
  fclose (ArchivoBiciestacion);
  fclose (ArchivoBicicleta);
  fclose (ArchivoUsuario);
  fclose (ArchivoNumeracion);
  system ("clear");
  printf ("\n");
  system ("sleep 0.04");
  printf ("La base de datos se ha guardado correctamente\n\n");
  system ("sleep 0.04");
  printf ("¡Hasta pronto!\n\n");
  system ("sleep 0.04");
  exit (0);
}

void AltaPrimerUsuario (TipoUsuario **PrimerUsuario, int *PrimeraEjecucion, int Numeracion [3]) //Esta funcion da de alta al primer usuario como administrador.
{
  TipoUsuario NuevoUsuario;
  int ErrorLectura, ID_Sesion;
  char Enter;
  system ("clear");
  printf ("\n");
  Logo ();
  printf ("\n");
  system ("sleep 0.75");
  printf ("¡Bienvenido!\n\n");
  system ("sleep 0.75");
  printf ("Hemos detectado que es la primera vez que se ejecuta el sistema en este equipo\n\n");
  system ("sleep 0.75");
  printf ("Para el correcto funcionamiento del programa requerimos que registre al primer administrador\n\n");
  system ("sleep 0.75");
  printf ("Ingrese cualquier caracter para continuar...\n\n");
  __fpurge (stdin);
  scanf (" %c", &Enter);
  do
    {
      Encabezado ();
      ErrorLectura = 0;
      printf ("Registro de un nuevo usuario:\n\n");
      printf ("Ingrese los datos siguientes:\n");
      printf ("Nombre completo del nuevo usuario: ");
      if ((scanf(" %[^\n]", NuevoUsuario.Nombre)) == 0)
	ErrorLectura = 1;
      printf ("Contraseña del nuevo usuario: ");
      if ((scanf(" %[^\n]", NuevoUsuario.Password)) == 0)
	ErrorLectura = 1;
      printf ("Numero de tarjeta de credito del nuevo usuario: ");
      if ((scanf (" %ld", &NuevoUsuario.NumeroTarjeta)) == 0)
	ErrorLectura = 1;
      printf ("Direccion del nuevo usuario: ");
      if ((scanf(" %[^\n]", NuevoUsuario.CalleNumero)) == 0)
	ErrorLectura = 1;
      printf ("Estatus administrativo ('1' Para administradores, '0' Para usuarios): 1 (Valor no modificable por primera ejecución\n");
      NuevoUsuario.Flag = 1;
      printf ("\n");
      if (ErrorLectura == 0)
	{
	  printf ("Datos correctos. Estos son los datos que se guardaran:\n");
	  printf ("Nombre: %s\n", NuevoUsuario.Nombre);
	  printf ("Contraseña: %s\n", NuevoUsuario.Password);
	  printf ("Numero de tarjeta de credito: %ld\n", NuevoUsuario.NumeroTarjeta);
	  printf ("Dirección: %s\n", NuevoUsuario.CalleNumero);
	  if (NuevoUsuario.Flag == 0)
	    printf ("Estatus administrativo: Usuario\n");
	  if (NuevoUsuario.Flag == 1)
	    printf ("Estatus administrativo: Administrador\n");
	  printf ("Ingrese cualquier caracter para guardar los datos...\n");
	  scanf (" %c", &Enter);
	  ID_Sesion = 1;
	  AltaUsuario (PrimerUsuario, NuevoUsuario, Numeracion, ID_Sesion);
	}
      if (ErrorLectura == 1)
	{
	  printf ("Hubo un error de lectura, por lo que no se pudieron guardar los datos\n");
	  printf ("Ingrese cualquier caracter para reintentar...\n\n");
	  __fpurge(stdin);
	  scanf (" %c", &Enter);
	}
    }
  while (ErrorLectura == 1);
  *PrimeraEjecucion = 0;
}

void GuardarEnBitacora (int ID_Sesion, char CodigoDeAccion [200], int InformacionAdicional, int InformacionAdicional2) //Esta función actualiza la bitacora cada un administrador: Inicia / Cierra sesión, Da de Alta / Baja: Biciestaciones, Bicicletas y Usuarios y Reasigna una bicicleta.
{
  FILE *ArchivoBitacora;
  time_t rawtime;
  struct tm *timeinfo;
  char HoraSistema [200];
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(HoraSistema,200,"%Y%m%d-%H:%M:%S",timeinfo);
  ArchivoBitacora = fopen ("Bitacora.txt", "at");
  if (InformacionAdicional2 == 0)
    {
      if ((strcmp ("Login", CodigoDeAccion)) == 0)
	{
	  fprintf (ArchivoBitacora, "%s %s %d\n", HoraSistema, CodigoDeAccion, ID_Sesion);
	}
      else
	{
	  fprintf (ArchivoBitacora, "%s %s %d\n", HoraSistema, CodigoDeAccion, InformacionAdicional);
	}
    }
  else
    {
      fprintf (ArchivoBitacora, "%s %s %d %d\n", HoraSistema, CodigoDeAccion, InformacionAdicional, InformacionAdicional2);
    }
  fclose (ArchivoBitacora);
}





