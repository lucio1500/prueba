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
void inicializar(estructuraB listado[], int tam)
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
void hardCodear(estructuraB listado[], int tam)
{
    int id[4]={11,12,13,14};
    char nombre[4][30] = {"Juan","Maria","Ana","Pedro"};
    char localidad[4][30] = {"capital","mar del plata","palermo","avellaneda"};

    int i;

    for(i=0; i<tam; i++)
    {
      listado[i].id = id[i];
      strcpy(listado[i].nombre, nombre[i]);
      strcpy(listado[i].localidad, localidad[i]);
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
int buscarLibreB(estructuraB listado[], int tam)
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
int eliminarB(estructuraB listado[], int tam,int id)
{
    int i;

         for(i=0; i<tam;i++)
        {
            if(id == listado[i].id)
            {
            listado[i].estado=LIBRE;
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
int modificarB(estructuraB listado[], int tam, int id)
{
    int flag=-1;
    int opcion;
    int i;

    do
    {
    showModificarB();
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
                getStringOfLetters(listado[i].localidad,"Ingrese localidad: ","Error, Reingrese localidad: ");
                flag=0;
                break;
                }
            }
        break;
        case 3:
        break;
        case 4:
        break;
    }
    }while(opcion!=5);

    return flag;
}



/** \brief Permite crear una estructura.
 *
 * \param id int
 * \param
 * \return estructuraB La estructura creada
 *
 */
estructuraB crearB (int id)
{
    estructuraB miEstructura;

    miEstructura.id=id;
    getStringOfLetters(miEstructura.nombre,"Ingrese nombre: ","Error Reingrese un nombre valido: ");
    getStringOfLetters(miEstructura.localidad,"Ingrese localidad: ","Error: ");


    miEstructura.estado = OCUPADO;

    return miEstructura;

}

/** \brief guarda los datos ingresados por el usuario en una posicion del array estructura.
 *
 * \param listado[] estructuraB
 * \param tam int
 * \param index int
 * \param id int
 * \return int (-1) si hubo algun error o (0) si esta todo ok.0
 *
 */
int cargarB(estructuraB listado[], int tam,int index,int id)
{
    if(tam==0||index==-1)
    {
    return -1;
    }
    else
    {
    listado[index] = crearB(id);
    return 0;
    }

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
int getIdB(estructuraB listado[],int tam,char mensaje[], char mensajeError [])
{
    int indexId;
    int valueId;
    printf("%s ",mensaje);
    scanf("%d",&valueId);

    indexId=buscarEstructuraPorIdB(listado,tam,valueId);

     while(indexId != valueId)
    {
        printf("%s", mensajeError);
        scanf("%d", &valueId);
        indexId=buscarEstructuraPorIdB(listado,tam,valueId);
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
int buscarEstructuraPorIdB(estructuraB listado[], int tam,int id)
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
void mostrarB (estructuraB miEstructura)
{
  printf ("ID: %d   NOMBRE: %s              LOCALIDAD:  %s\n", miEstructura.id,
                                          miEstructura.nombre,
                                          miEstructura.localidad);
}


/** \brief Muestra todos los datos cargados en un array de tipo estructura.
 *
 * \param listado[] estructura
 * \param tam int
 * \return void
 *
 */
void mostrarTodosB(estructuraB listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            mostrarB(listado[i]);
        }
    }

}
