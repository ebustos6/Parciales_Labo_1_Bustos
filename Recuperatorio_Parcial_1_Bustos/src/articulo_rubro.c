#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "articulo_rubro.h"
#include "utn.h"

void rubro_hardcodear(Rubro array[], int size, int *id) {
	char descripcion[4][30] = { "CUIDADO DE ROPA", "LIMPIEZA Y DESINFECCION",
			"CUIDADO PERSONAL E HIGIENE", "CUIDADO DEL AUTOMOTOR" };
	int i;

	for (i = 0; i < size; i++) {
		(*id)++;
		array[i].idRubro = *id;
		strcpy(array[i].descripcion, descripcion[i]);
		array[i].isEmpty = 0;
	}
}

int rubro_listado(Rubro array[], int size) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 0)
				rubro_listar(array, i);
		}
		retorno = 0;
	}
	return retorno;
}

void rubro_listar(Rubro array[], int pos) {
	printf("\n%d | %15s", array[pos].idRubro, array[pos].descripcion);
}

int rubro_buscarID(Rubro array[], int size, int valorBuscado, int *posicion) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1)
				continue;
			else if (array[i].idRubro == valorBuscado) {
				retorno = 0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}

///////////////////////////////////////////////////////////////////////////////////

int articulo_inicializar(Articulo array[], int size) {
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

int articulo_buscarEmpty(Articulo array[], int size, int *posicion) {
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

int articulo_buscarID(Articulo array[], int size, int valorBuscado,
		int *posicion) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1)
				continue;
			else if (array[i].idArticulo == valorBuscado) {
				retorno = 0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}

int articulo_alta(Articulo array[], int size, int *id, Rubro arrayRubro[],
		int sizeRubro) {
	int retorno = -1;
	int posicion;
	int posRubro;

	if (array != NULL && size > 0 && id != NULL) {
		if (articulo_buscarEmpty(array, size, &posicion) == -1) {
			printf("\nNo hay lugares vacios");
		} else {
			(*id)++;
			array[posicion].idArticulo = *id;
			array[posicion].isEmpty = 0;
			utn_getCadena("\nIngrese descripcion del articulo: ",
					"\nIntente nuevamente.", 1, 30, 1,
					array[posicion].articulo);
			utn_getCadena("\nIngrese la medida del articulo: ",
					"\nIntente nuevamente.", 1, 30, 1, array[posicion].medida);
			utn_getFlotante("\nIngrese el precio del articulo: ",
					"\nIntente nuevamente.", 1, 20000, 1,
					&array[posicion].precio);
			rubro_listado(arrayRubro, sizeRubro);
			do {
				utn_getEntero("\nSeleccione el servicio deseado: ",
						"\nIntente nuevamente.", 1001, 1004, 1,
						&array[posicion].idRubro);
			} while (rubro_buscarID(arrayRubro, sizeRubro,
					array[posicion].idRubro, &posRubro) != 0);
			articulo_listar(array, posicion, arrayRubro, posRubro);
			retorno = 0;
		}
	}
	return retorno;
}

int articulo_listado(Articulo array[], int size, Rubro arrayRubro[],
		int sizeRubro) {
	int retorno = -1;
	int pos;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 0) {
				if (rubro_buscarID(arrayRubro, sizeRubro, array[i].idRubro,
						&pos) == 0) {
					articulo_listar(array, i, arrayRubro, pos);
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

void articulo_listar(Articulo array[], int pos, Rubro arrayRubro[],
		int posRubro) {
	printf("\n%5d | %15s | %6s | %7.2f | %15s", array[pos].idArticulo,
			array[pos].articulo, array[pos].medida, array[pos].precio,
			arrayRubro[posRubro].descripcion);
}

int articulo_baja(Articulo array[], int size, Rubro arrayRubro[], int sizeRubro) {
	int retorno = -1;
	int posicion;
	int id;
	if (array != NULL && size > 0) {
		articulo_listado(array, size, arrayRubro, sizeRubro);
		utn_getEntero("\nIngrese la ID a dar de baja: ", "\nError", 10001,
				19999, 1, &id);
		if (articulo_buscarID(array, size, id, &posicion) == -1) {
			printf("\nEl ID ingresado no es válido");
		} else {
			array[posicion].isEmpty = 1;
			retorno = 0;
		}
	}
	return retorno;
}

int articulo_modificar(Articulo array[], int size, Rubro arrayRubro[],
		int sizeRubro) {
	int retorno = -1;
	int posicion;
	int posRubro;
	int id;
	int opcion;
	if (array != NULL && size > 0) {
		articulo_listado(array, size, arrayRubro, sizeRubro);
		utn_getEntero("\nIngrese el ID del articulo a modificar: ", "\nError",
				10001, 19999, 1, &id);
		if (articulo_buscarID(array, size, id, &posicion) == -1) {
			printf("\nNo existe este ID");
		} else {
			rubro_buscarID(arrayRubro, sizeRubro, array[posicion].idRubro,
					&posRubro);
			articulo_listar(array, posicion, arrayRubro, posRubro);
			utn_getEntero("\nModificar: \n1.- Medida \n2.- Precio \n3.- Salir\nIngrese opcion: ",
					"\nError", 1, 3, 1, &opcion);
			switch (opcion) {
			case 1:
				utn_getCadena("\nIngrese nueva medida: ", "\nError", 1, 30, 1,
						array[posicion].medida);
				articulo_listar(array, posicion, arrayRubro, posRubro);
				break;
			case 2:
				utn_getFlotante("\nIngrese nuevo precio: ", "\nError", 1, 20000,
						1, &array[posicion].precio);
				articulo_listar(array, posicion, arrayRubro, posRubro);
				break;
			case 3:
				printf("Volviendo al Menu Principal!");
				break;
			default:
				printf("\nOpcion no válida");
				retorno = 0;
			}
		}
	}
	return retorno;
}

int articulo_ordenar(Articulo array[], int size) {
	int i;
	int j;
	int retorno = -1;
	Articulo aux;

	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (array[i].idRubro > array[j].idRubro) {
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				retorno = 0;
			} else if (array[i].idRubro == array[j].idRubro) {
				if (strcmp(array[i].articulo, array[j].articulo) < 0) {
					aux = array[i];
					array[i] = array[j];
					array[j] = aux;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
