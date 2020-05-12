#include "Estructura.h"
#include "Estructura2.h"

typedef struct
{
 int cantidadA;
 int id2;
}estructura_estructuraB;

estructura crear (int id, estructuraB listadoB[],int tamB);
int cargar(estructura listado[], int tam,int index,int id,estructuraB listadoB[],int tamB);

void mostrarTodosLosBconA(estructura lista[], int size, estructuraB listaB[], int sizeB);
void cantidadA(estructura lista[], int size,int sizeB, estructura_estructuraB auxEstructura_estructuraB[]);
