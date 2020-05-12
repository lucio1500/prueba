#include "Estructura_EstructuraB.h"

estructura crear (int id, estructuraB listadoB[],int tamB)
{
    estructura miEstructura;

    miEstructura.id=id;
    getStringOfLetters(miEstructura.nombre,"Ingrese nombre: ","Error Reingrese un nombre valido: ");
    miEstructura.precio=getFloat(miEstructura.precio,"Ingrese precio: ","Error, reingrese precio: ",0,10000);
    miEstructura.cantidad=getInt(miEstructura.cantidad,"Ingrese cantidad: ","Error, reingrese cantidad: ",-1,1000);


    miEstructura.estado = OCUPADO;

    mostrarTodosB(listadoB,tamB);
    miEstructura.id2=getIdB(listadoB,tamB,"Ingrese Id de la estructura B: ","Error, reingrese Id");

    return miEstructura;

}

int cargar(estructura listado[], int tam,int index,int id,estructuraB listadoB[],int tamB)
{
    if(tam==0||index==-1)
    {
    return -1;
    }
    else
    {
    listado[index] = crear(id,listadoB,tamB);
    return 0;
    }
}


void mostrarTodosAB(estructura lista[], int size, estructuraB listaB[], int sizeB)
{
    int i;//EstructuraB
    int j;//Estructura
    int flag;
    for(i=0; i<sizeB; i++)
    {
        flag=0;
        printf("Estructura B: %s\n", listaB[i].nombre);
        for(j=0; j<size; j++)
        {
             if(lista[j].id2 == listaB[i].id  &&  lista[j].estado==OCUPADO)
             {
                  mostrar(lista[j]);
                  flag=1;
             }
        }
        if(flag==0)
        {
        printf("No tiene productos.");
        }
    }
}


void mostrarTodosLosBconA(estructura lista[], int size, estructuraB listaB[], int sizeB)
{
    int i;//estructura b
    int j;//estructura
    int flag;
    for(i=0; i<sizeB; i++)
    {
        flag=0;
        printf("Proveedor: %s\n", listaB[i].nombre);
        for(j=0; j<size; j++)
        {
             if(lista[j].id2 == listaB[i].id  &&  lista[j].estado==OCUPADO)
             {
                  mostrar(lista[j]);
                  flag=1;
             }
        }
        if(flag==0)
        {
        printf("No tiene productos.");
        }
    }
}


void mostrarProveedorConMasProductos(estructura lista[], int size, estructuraB listaB[], int sizeB)
{
    estructura_estructuraB auxEstructura_estructuraB[sizeB];
    int i;
    int j;
    int maximo;

    InicializarAB(listaB,sizeB,auxEstructura_estructuraB);

    /********************************************/

    cantidadA(lista,size,sizeB,auxEstructura_estructuraB);

     /********************************************/
    maximo=calcularMax(lista,size,listaB,sizeB,auxEstructura_estructuraB);

     /********************************************/
    printf("\n ESTRUCTURA: %d\n", maximo);
    for(i=0;i<sizeB;i++)
    {
        if(auxEstructura_estructuraB[i].cantidadA == maximo)
        {
           for(j=0;j<sizeB; j++)
           {
               if(auxEstructura_estructuraB[i].id2 == listaB[j].id)
               {
                   printf("ESTRUCTURA B: %s\n", listaB[j].nombre);
               }
           }
        }
    }



}


void InicializarAB(estructuraB listaB[], int sizeB,estructura_estructuraB auxEstructura_estructuraB[])
{
    int i;
    int j;
    for(i=0; i<sizeB; i++)
    {
        auxEstructura_estructuraB[i].id2 = listaB[i].id;
        auxEstructura_estructuraB[i].cantidadA = 0;
    }
}

void cantidadA(estructura lista[], int size,int sizeB, estructura_estructuraB auxEstructura_estructuraB[])
{
    int i;
    int j;

    for(i=0; i<sizeB; i++)
    {
        for(j=0; j<size; j++)
        {
            if(lista[j].estado==OCUPADO && auxEstructura_estructuraB[i].id2 == lista[j].id2)
            {
                auxEstructura_estructuraB[i].cantidadA++;
            }
        }
    }
}

int calcularMax(int sizeB,estructura_estructuraB auxEstructura_estructuraB[])
{
    int maximo;
    int i;
     for(i=0; i<sizeB; i++)
     {
         if(i==0 || auxEstructura_estructuraB[i].cantidadA>maximo)
         {
             maximo = auxEstructura_estructuraB[i].cantidadA;
         }
     }
    return maximo;
}
