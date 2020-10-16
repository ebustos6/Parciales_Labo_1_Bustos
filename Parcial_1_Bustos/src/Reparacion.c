/*
 * Reparacion.c
 *
 *  Created on: Oct 15, 2020
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Reparacion.h"
#include "Utn.h"

int reparacion_inicializar(eReparacion array[], int size)
{
	int retorno = -1;
	if (array != NULL && size > 0) {
		for (; size > 0; size--) {
			array[size - 1].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int reparacion_buscarEmpty(eReparacion array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


int reparacion_alta(eReparacion array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;

    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(reparacion_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idReparacion=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("Ingrese número de serie(1-8000): ","\nIntente nuevamente",1,sizeof(int),1,8000,1,&array[posicion].serie);
            utn_getUnsignedInt("Ingrese la Id del Servicio: ","\nIntente nuevamente",1,sizeof(int),1,4,1,&array[posicion].idServicio);
            utn_getUnsignedInt("Ingrese la fecha-dia: ","\nIntente nuevamente",1,sizeof(int),1,31,1,&array[posicion].fecha.dia);
            utn_getUnsignedInt("Ingrese la fecha-mes: ","\nIntente nuevamente",1,sizeof(int),1,12,1,&array[posicion].fecha.mes);
            utn_getUnsignedInt("Ingrese la fecha-año: ","\nIntente nuevamente",1,sizeof(int),1900,2020,1,&array[posicion].fecha.anio);
            retorno=0;
        }
    }
    return retorno;
}

int reparacion_listar(eReparacion array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n Nro de Serie:%d ID servicio:%d Fecha:%d/%d/%d",
                       array[i].serie,array[i].idServicio,array[i].fecha.dia,array[i].fecha.mes,array[i].fecha.anio);
        }
        retorno=0;
    }
    return retorno;
}
