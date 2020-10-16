/*
 * Marca.c
 *
 *  Created on: Oct 15, 2020
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Marca.h"

int marca_inicializar(eMarca array[], int size)
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

void marca_hardcodear(eMarca array[], int size) {
	int idMarca[5] = { 1001, 1002, 1003, 1004, 1005 };
	char descripcion[5][20] = { "Whirlpool", "Sony", "Liliana", "Gafa", "Philips" };
	int i;

	for (i = 0; i < size; i++) {

		array[i].idMarca = idMarca[i];
		strcpy(array[i].descripcion, descripcion[i]);
		array[i].isEmpty = 0;
	}
}

int marca_listar(eMarca array[], int size)
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
                printf("\n ID: %d Descripcion: %s",
                       array[i].idMarca,array[i].descripcion);
        }
        retorno=0;
    }
    return retorno;
}
