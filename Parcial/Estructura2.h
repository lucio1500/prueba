#define LIBRE 0
#define OCUPADO 1

typedef struct
{
  int id;//PK
  char nombre[20];
  char localidad[20];
  int estado;

} estructuraB;

void inicializar(estructuraB listado[], int tam);
void hardCodear(estructuraB listado[], int tam);

int buscarLibreB(estructuraB listado[], int tam);
int eliminarB(estructuraB listado[], int tam,int id);
int modificarB(estructuraB listado[], int tam, int id);

estructuraB crearB (int id);
int cargarB(estructuraB listado[], int tam,int index,int id);

int getIdB(estructuraB listado[],int tam,char mensaje[], char mensajeError []);
int buscarEstructuraPorIdB(estructuraB listado[], int tam,int id);


void mostrarB(estructuraB miEstructura);
void mostrarTodosB(estructuraB listado[], int tam);
