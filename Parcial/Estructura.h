#define LIBRE 0
#define OCUPADO 1

typedef struct
{
  int id;//PK
  char nombre[20];
  float precio;
  int cantidad;
  int estado;
  int id2;//FK

} estructura;

void inicializarEstructura(estructura listado[], int tam);
void hardCodearEstructura(estructura listado[], int tam);

int buscarLibre(estructura listado[], int tam);
int eliminar(estructura listado[], int tam,int id);
int modificar(estructura listado[], int tam, int id);

int validarId(estructura listado[],int tam,char mensaje[], char mensajeError []);
int buscarEstructuraPorId(estructura listado[], int tam,int id);

void mostrarTodos(estructura listado[], int tam);



