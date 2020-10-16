/*
 * Electro.c
 *
 *  Created on: Oct 15, 2020
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Electro.h"
#include "Marca.h"
#include "Utn.h"


int electro_inicializar(eElectro array[], int size)
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

int electro_buscarEmpty(eElectro array[], int size, int* posicion)
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


int electro_alta(eElectro array[], int size, int* contadorID, eMarca arrayMarca[], int sizeMarca)
{
    int retorno=-1;
    int posicion;

    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(electro_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idElectro=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("Ingrese número de serie(1-8000): ","\nIntente nuevamente",1,sizeof(int),1,8000,1,&array[posicion].serie);
            marca_listar(arrayMarca, sizeMarca);
            utn_getUnsignedInt("Ingrese la Id de la marca del electrodomestico: ","\nIntente nuevamente",1,sizeof(int),1001,1005,1,&array[posicion].idMarca);
            utn_getUnsignedInt("Ingrese año de fabricacion(1900-2020): ","\nIntente nuevamente",1,sizeof(int),1900,2020,1,&array[posicion].modelo);
            retorno=0;
        }
    }
    return retorno;
}

int electro_buscarID(eElectro array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idElectro==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int electro_baja(eElectro array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(electro_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

int electro_listar(eElectro array[], int size)
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
                printf("\n ID:%d Nro de Serie:%d ID marca:%d Año:%d",
                       array[i].idElectro,array[i].serie,array[i].idMarca,array[i].modelo);
        }
        retorno=0;
    }
    return retorno;
}

int electro_modificar(eElectro array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(electro_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\n ID: %d\n serie: %d\n Id marca: %d\n Año: %d"
                     , array[posicion].idElectro,array[posicion].serie,array[posicion].idMarca,array[posicion].modelo);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].serie);
                        break;
                    case 'B':
                    	utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idMarca);
                        break;
                    case 'C':
                    	utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].modelo);
                    	break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}
