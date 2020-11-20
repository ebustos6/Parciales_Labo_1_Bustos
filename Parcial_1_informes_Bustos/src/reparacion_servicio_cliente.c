#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reparacion_servicio_cliente.h"
#include "electro_marca.h"
#include "utn.h"

int reparacion_inicializar(eReparacion array[], int size) {
	int retorno = -1;
	if (array != NULL && size > 0) {
		for (; size > 0; size--) {
			array[size - 1].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int reparacion_buscarEmpty(eReparacion array[], int size, int *posicion) {
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

int reparacion_alta(eReparacion array[], int size, int *contadorID,
		eElectro arrayElectro[], int sizeElectro, eServicio arrayServicio[],
		int sizeServicio, eCliente arrayCliente[], int sizeCliente) {
	int retorno = -1;
	int posicion;

	if (array != NULL && size > 0 && contadorID != NULL) {
		if (reparacion_buscarEmpty(array, size, &posicion) == -1) {
			printf("\nNo hay lugares vacios");
		} else {
			(*contadorID)++;
			array[posicion].idReparacion = *contadorID;
			array[posicion].isEmpty = 0;
			electro_listado(arrayElectro, sizeElectro);
			do{
			utn_getEntero("\nIngrese número de serie(30000-89999): ",
					"\nIntente nuevamente.", 30000, 89999, 1,
					&array[posicion].serie);
			}while(electro_buscarSerie(arrayElectro, sizeElectro, array[posicion].serie, &posicion) != 0);
			//array[posicion].serie = serie;
			servicio_listado(arrayServicio, sizeServicio);
			do{
			utn_getEntero("\nSeleccione el servicio deseado: ",
					"\nIntente nuevamente.", 20001, 20004, 1,
					&array[posicion].idServicio);
			}while(servicio_buscarID(arrayServicio, sizeServicio, array[posicion].idServicio, &posicion) != 0);
			//array[posicion].idServicio = idServicio;
			cliente_listado(arrayCliente, sizeCliente);
			utn_getEntero("\nIngrese la Id del Cliente(3001-3006): ",
					"\nIntente nuevamente.", 3001, 3006, 1,
					&array[posicion].idServicio);
			utn_getEntero("Ingrese el dia: ", "\nIntente nuevamente.", 1,
					31, 1, &array[posicion].fecha.dia);
			utn_getEntero("Ingrese el mes: ", "\nIntente nuevamente.", 1,
					12, 1, &array[posicion].fecha.mes);
			utn_getEntero("Ingrese el año: ", "\nIntente nuevamente.",
					1900, 2020, 1, &array[posicion].fecha.anio);
			retorno = 0;
		}
	}
	return retorno;
}


void reparacion_hardcodear(eReparacion array[], int size) {
	int idReparacion[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int serie[8] = { 34567, 44556, 76551, 89997, 34567, 34567, 69027, 56789 };
	int idServicio[8] = { 20001, 20002, 20003, 20004, 20003, 20004, 20001, 20001 };
	int idCliente[8] = { 3001, 3002, 3003, 3004, 3001, 3001, 3006, 3002 };
	eFecha fecha[8] = {{10,5,1999},{7,3,1990},{5,7,1997},{18,2,2000},{1,12,2019},{18,2,2000},{19,4,2020},{22,6,2018}};
	int i;

	for (i = 0; i < size; i++) {

		array[i].idReparacion = idReparacion[i];
		array[i].serie = serie[i];
		array[i].idServicio = idServicio[i];
		array[i].idCliente = idCliente[i];
		array[i].fecha = fecha[i];
		array[i].isEmpty = 0;
	}
}

void reparacion_listar(eReparacion array[], int pos){
	printf("\nID: %d Nro de Serie: %d ID servicio: %d Fecha: %d/%d/%d",
							array[pos].idReparacion, array[pos].serie,
							array[pos].idServicio, array[pos].fecha.dia,
							array[pos].fecha.mes, array[pos].fecha.anio);
}

int reparacion_listado(eReparacion array[], int size) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1)
				continue;
			else
				reparacion_listar(array, i);
		}
		retorno = 0;
	}
	return retorno;
}

int reparacion_buscarSerie(eReparacion array[], int size, int valorBuscado,
		int *posicion) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1)
				continue;
			else if (array[i].serie == valorBuscado) {
				retorno = 0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}

//------------------------------------------------------------------------------------------------------------------------

int servicio_inicializar(eServicio array[], int size) {
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
	int idServicio[4] = { 20001, 20002, 20003, 20004 };
	char descripcion[4][25] = { "Garantia", "Mantenimiento", "Repuestos",
			"Refaccion" };
	int precio[4] = { 250, 500, 400, 600 };
	int i;

	for (i = 0; i < size; i++) {

		array[i].idServicio = idServicio[i];
		strcpy(array[i].descripcion, descripcion[i]);
		array[i].precio = precio[i];
		array[i].isEmpty = 0;
	}
}

int servicio_buscarID(eServicio array[], int size, int valorBuscado,
		int *posicion) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1)
				continue;
			else if (array[i].idServicio == valorBuscado) {
				retorno = 0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}

int servicio_listado(eServicio array[], int size) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1)
				continue;
			else
				printf("\nID: %d Precio:$%d \tServicio: %s", array[i].idServicio, array[i].precio,
						array[i].descripcion);
		}
		retorno = 0;
	}
	return retorno;
}

//------------------------------------------------------------------------------------------------------------------------

int cliente_inicializar(eCliente array[], int size) {
	int retorno = -1;
	if (array != NULL && size > 0) {
		for (; size > 0; size--) {
			array[size - 1].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

void cliente_hardcodear(eCliente array[], int size) {
	int idCliente[6] = { 3001, 3002, 3003, 3004, 3005, 3006 };
	char nombre[6][25] = { "Ivana", "Alberto", "Antonio", "Nicolas", "Luciano",
			"Bruno" };
	char apellido[6][25] = { "Gallardo", "Bustos", "Contrera", "Cataneo",
			"Minozzi", "Minozzi" };
	int i;

	for (i = 0; i < size; i++) {

		array[i].idCliente = idCliente[i];
		strcpy(array[i].nombre, nombre[i]);
		strcpy(array[i].apellido, apellido[i]);
		array[i].isEmpty = 0;
	}
}

int cliente_listado(eCliente array[], int size) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1)
				continue;
			else
				printf("\nID: %d	Nombre: %s			Apellido: %s", array[i].idCliente, array[i].nombre,
						array[i].apellido);
		}
		retorno = 0;
	}
	return retorno;
}

int cliente_buscarID(eCliente array[], int size, int valorBuscado,
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
