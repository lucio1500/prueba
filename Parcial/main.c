#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Inputs.h"
#include "Validations.h"
#include "ShowData.h"
#include "Estructura_EstructuraB.h"

#define T 3
#define TB 5

int main()
{
    int r; //Guarda el retorno de las funciones.
    int id=1000; //Es la id de la estructura.
    int id2=5000;
    int index; //Es el indice.
    int opcion;
    int flagOpcion=0;//Determina por que opciones paso el programa
//    int contadorInc=0;
//    float acumuladorPrecio=0;
//    float promedio;
    estructura listado[T];
    estructuraB listadoB[TB];


    inicializar(listadoB,TB);
    hardCodear(listadoB,TB);
    inicializarEstructura(listado,T);
    hardCodearEstructura(listado,T);



    do
    {
        showMenu();
        opcion=getInt(opcion,"Elija una opcion: ","Incorrecto, Ingrese el numero de la opcion que desea: ",0,10);
        switch(opcion)
        {
            case 1:
            index = buscarLibre(listado,T);
                if(index!=-1)
                {
                id=generateId(id);
                r=cargar(listado,T,index,id,listadoB,TB);
                flagOpcion=1;
                        if(r==-1)
                        {
                        printf("Error en la carga.");
                        }
                        else if(r==0)
                        {
                        printf("Carga Completada.");
                        }
                }
                else
                {
                printf("No hay mas espacio de carga.");
                }
            break;
            case 2:
                /*if(flagOpcion==1)
                {*/
                mostrarTodos(listado,T);
                id=validarId(listado,T,"Ingrese el numero de id del empleado que desea modificar", "Error id ingresada no valida, reingrese");
                r=modificar(listado,T,id);
                        if(r==-1)
                        {
                        printf("Error en la modificacion.");
                        }
                        else if(r==0)
                        {
                        printf("Modificacion Completa.");
                        }
                /*}
                else
                {
                printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n ");
                }*/
            break;
            case 3:
                if(flagOpcion==1)
                {
                mostrarTodos(listado,T);
                id=validarId(listado,T,"Ingrese el numero de id del empleado que desea eliminar", "Error id ingresada no valida, reingrese");
                r=eliminar(listado,T,id);
                        if(r==-1)
                        {
                        printf("Error en la baja.");
                        }
                        else if(r==0)
                        {
                        printf("Eliminacion Completa.");
                        }
                }
                else
                {
                printf("Para ingresar a esta opcion primero debe cargar al menos .\n ");
                }
            break;
            case 4:
                //if(flagOpcion==1)
                //{
                mostrarTodos(listado,T);
                /*}
                else
                {
                printf("Para ingresar a esta opcion primero debe cargar al menos .\n ");
                }*/
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            case 8:
            break;
            case 9:
            break;
        }

    }while(opcion!=10);


}
