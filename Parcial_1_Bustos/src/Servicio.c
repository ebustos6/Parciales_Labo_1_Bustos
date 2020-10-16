/*
 * Servicio.c
 *
 *  Created on: Oct 15, 2020
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicio.h"

int servicio_inicializar(eServicio array[], int size)
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

void servicio_hardcodear(eServicio array[], int size) {
	int idServicio[4] = { 1001, 1002, 1003, 1004 };
	char descripcion[4][25] = { "Garantia", "Mantenimiento", "Repuestos", "Refaccion" };
	int precio[4] = { 250, 500, 400, 600 };
	int i;

	for (i = 0; i < size; i++) {

		array[i].idServicio = idServicio[i];
		strcpy(array[i].descripcion, descripcion[i]);
		array[i].precio = precio[i];
		array[i].isEmpty = 0;
	}
}

int servicio_listar(eServicio array[], int size)
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
                printf("\nPrecio:$%d \tServicio: %s",
                       array[i].precio,array[i].descripcion);
        }
        retorno=0;
    }
    return retorno;
}
