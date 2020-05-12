#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Inputs.h"
#include "Validations.h"
#include "ShowData.h"
#include "Estructura.h"
#include "Estructura2.h"


/** \brief inicializa un array de tipo estructura
 *
 * \param listado[] estructura
 * \param tam int
 * \return void
 *
 */
void inicializarEstructura(estructura listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
    listado[i].estado = LIBRE;
    }
}


/** \brief harcodea un array de tipo estructura
 *
 * \param listado[] estructura
 * \param tam int
 * \return void
 *
 */
void hardCodearEstructura(estructura listado[], int tam)
{
  int id[10]={1,2,3,4,5,6,7,8,9,10};
  char nombre[10][15] = {"Mesa","Cable","Jabon","Foto","Fruta","Agua","Platos","Teclado","Mouse","Mouseonitor"};
  float precio[10]={10,4,9,8,7,8,100,500,800,1900};
  int cantidad[10]={5,8,6,9,10,5,7,10,56,10};
  int proveedor[10] = {11,11,12,12,12,12,13,13,13,13};
  int i;

  for(i=0; i<tam; i++)
  {
      listado[i].id = id[i];
      strcpy(listado[i].nombre, nombre[i]);
      listado[i].precio = precio[i];
      listado[i].cantidad = cantidad[i];
      listado[i].id2 = proveedor[i];
      listado[i].estado = OCUPADO;
  }

}


/** \brief Busca un espacio libre en un array de tipo estructura
 *
 * \param listado[] estructura
 * \param tam int
 * \return int En caso de encontrarlo devuelve el indice del espacio libre o (-1) si no hay mas espacio.
 *
 */
int buscarLibre(estructura listado[], int tam)
{
  int i;
  int index = -1;

  for(i=0; i<tam; i++)
  {
      if(listado[i].estado==LIBRE)
      {
          index =  i;
          break;
      }
  }
  return index;

}


/** \brief Elimina de manera lógica una estructura recibiendo como parámetro su Id.
 *
 * \param listado[] estructura
 * \param tam int
 * \param id int
 * \return int (0) si esta todo ok o (-1) si hubo algun error.
 *
 */
int eliminar(estructura listado[], int tam,int id)
{
    int i;

         for(i=0; i<tam;i++)
        {
            if(id == listado[i].id)
            {
            listado[i].estado=LIBRE;
            return 0;
            break;
            }
        }
    return -1;
}



/** \brief Permite modificar los campos de la estructura
 *
 * \param listado[] estructura
 * \param tam int
 * \param id int
 * \return int (0) si esta todo ok o (-1) si hubo algun error.
 *
 */
int modificar(estructura listado[], int tam, int id)
{
    int flag=-1;
    int opcion;
    int i;

    do
    {
    showModificar();
    opcion=getInt(opcion,"Elija una opcion: ","Incorrecto, Ingrese el numero de la opcion que desea: ",1,5);
        switch(opcion)
        {
        case 1:
            for(i=0; i<tam;i++)
            {
                if(id == listado[i].id)
                {
                getStringOfLetters(listado[i].nombre,"Ingrese nombre: ","Error Reingrese un nombre valido: ");
                flag=0;
                break;
                }
            }
        break;
        case 2:
            for(i=0; i<tam;i++)
            {
                if(id == listado[i].id)
                {
                listado[i].precio=getFloat(listado[i].precio,"Ingrese salario: ","Error, reingrese salario: ",0,10000);
                flag=0;
                break;
                }
            }
        break;
        case 3:
            for(i=0; i<tam;i++)
            {
                if(id == listado[i].id)
                {
                listado[i].cantidad=getInt(listado[i].cantidad,"Ingrese sector: ","Error, reingrese sector: ",-1,1000);
                flag=0;
                break;
                }
            }
        break;
        case 4:
        break;
    }
    }while(opcion!=5);

    return flag;
}


/** \brief Pide una id al usuario y valida su existencia.
 *
 * \param listado[] estructura
 * \param tam int
 * \param mensaje[] char
 * \param [] char mensajeError
 * \return int Devuelve el valor de la id.
 *
 */
int validarId(estructura listado[],int tam,char mensaje[], char mensajeError [])
{
    int indexId;
    int valueId;
    printf("%s ",mensaje);
    scanf("%d",&valueId);

    indexId=buscarEstructuraPorId(listado,tam,valueId);

     while(indexId != valueId)
    {
        printf("%s", mensajeError);
        scanf("%d", &valueId);
        indexId=buscarEstructuraPorId(listado,tam,valueId);
    }

    return valueId;
}

/** \brief Verifica que la id recibida exista en el array de tipo estructura.
 *
 * \param listado[] estructura
 * \param tam int
 * \param id int
 * \return int Devuelve el valor de la id.
 *
 */
int buscarEstructuraPorId(estructura listado[], int tam,int id)
{
    int i;
    int index = -1;


    for (i = 0; i < tam; i++)
    {
        if(listado[i].id==id)
        {
            index = listado[i].id;
            break;
        }
    }

    return index;
}



/** \brief Muestra por pantalla un dato del tipo estructura.
 *
 * \param
 * \param
 * \return
 *
 */
void mostrar (estructura miEstructura)
{
  printf ("ID: %d   NOMBRE: %s              PRECIO:  %f           CANTIDAD:  %d         IDPROVEEDOR:  %d \n", miEstructura.id,
                                          miEstructura.nombre,
                                          miEstructura.precio,
                                          miEstructura.cantidad,
                                          miEstructura.id2);
}

/** \brief Muestra todos los datos cargados en un array de tipo estructura.
 *
 * \param listado[] estructura
 * \param tam int
 * \return void
 *
 */
void mostrarTodos(estructura listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            mostrar(listado[i]);
        }
    }

}
