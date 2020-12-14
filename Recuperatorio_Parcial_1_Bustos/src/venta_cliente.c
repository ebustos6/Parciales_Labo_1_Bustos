#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "venta_cliente.h"
#include "utn.h"

void cliente_hardcodear(Cliente array[], int size, int *id) {
	char nombre[4][25] = { "Juan Sosa", "Ana Rubio", "Pedro Duarte",
			"Sonia Rios" };
	char telefono[4][12] = { "3456-5689 ", "500-9924", "180-1897",
				"145-2587" };
	int i;

	for (i = 0; i < size; i++) {
		(*id)++;
		array[i].idCliente = *id;
		strcpy(array[i].nombre, nombre[i]);
		strcpy(array[i].telefono, telefono[i]);
		array[i].isEmpty = 0;
	}
}

int cliente_listado(Cliente array[], int size) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1)
				continue;
			else
				printf("\n%d | %12s | %s", array[i].idCliente,
						array[i].nombre, array[i].telefono);
		}
		retorno = 0;
	}
	return retorno;
}

int cliente_buscarID(Cliente array[], int size, int valorBuscado,
		int *posicion) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1)
				continue;
			else if (array[i].idCliente == valorBuscado) {
				retorno = 0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}

//////////////////////////////////////////////////////////////////////////////

int venta_inicializar(Venta array[], int size) {
	int retorno = -1;
	int i;
	if (array != NULL && size > 0) {
		for (i = 0; i < size; i++) {
			array[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int venta_buscarEmpty(Venta array[], int size, int *posicion) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0 && posicion != NULL) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1) {
				retorno = 0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}
