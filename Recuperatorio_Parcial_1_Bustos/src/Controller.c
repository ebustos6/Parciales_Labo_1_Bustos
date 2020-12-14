#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"

int controller_altaArticulo(Articulo arrayArticulo[], int sizeArticulo,
		Rubro arrayRubro[], int sizeRubro, int *id, int *contArt) {
	int retorno = -1;

	if (articulo_alta(arrayArticulo, sizeArticulo, id, arrayRubro, sizeRubro)
			== 0) {
		printf("El articulo se ha dado de alta exitosamente!");
		(*contArt)++;
		retorno = 0;
	}

	return retorno;
}

int controller_modificarArticulo(Articulo arrayArticulo[], int sizeArticulo,
		Rubro arrayRubro[], int sizeRubro, int contArt) {
	int retorno = -1;

	if (contArt > 0) {
		if (articulo_modificar(arrayArticulo, sizeArticulo, arrayRubro,
				sizeRubro) == 0) {
			printf("El articulo se ha modificado exitosamente!");
			retorno = 0;
		}
	} else {
		printf("\nDebe dar de alta un articulo antes de acceder a esta opcion!");
	}

	return retorno;
}

int controller_bajaArticulo(Articulo arrayArticulo[], int sizeArticulo,
		Rubro arrayRubro[], int sizeRubro, int *contArt) {
	int retorno = -1;

	if (*contArt > 0) {
		if (articulo_baja(arrayArticulo, sizeArticulo, arrayRubro, sizeRubro)
				== 0) {
			printf("El articulo se ha dado de baja exitosamente!");
			(*contArt)--;
			retorno = 0;
		}
	} else {
		printf(
				"\nDebe dar de alta un articulo antes de acceder a esta opcion!");
	}

	return retorno;
}

int controller_listadoArticulo(Articulo arrayArticulo[], int sizeArticulo,
		Rubro arrayRubro[], int sizeRubro, int contArt) {
	int retorno = -1;

	if (contArt > 0) {
		if(articulo_ordenar(arrayArticulo, sizeArticulo) == 0){
			printf("Se ha ordenado el listado exitosamente!");
		}
		articulo_listado(arrayArticulo, sizeArticulo, arrayRubro, sizeRubro);
		retorno = 0;
	} else {
		printf(
				"\nDebe dar de alta un articulo antes de acceder a esta opcion!");
	}

	return retorno;
}

int controller_altaVenta(Venta array[], int size, int *id,
		Cliente arrayCliente[], int sizeCliente, Articulo arrayArticulo[],
		int sizeArticulo, Rubro arrayRubro[], int sizeRubro, int contArt,
		int *contVta) {
	int retorno = -1;
	int posicion;
	int posCliente;
	int posArticulo;

	if (contArt > 0) {
		if (array != NULL && size > 0 && id != NULL && arrayCliente != NULL
				&& sizeCliente > 0 && arrayArticulo != NULL && sizeArticulo > 0
				&& arrayRubro != NULL && sizeRubro > 0) {
			if (venta_buscarEmpty(array, size, &posicion) == -1) {
				printf("\nNo hay lugares vacios");
			} else {
				(*id)++;
				(*contVta)++;
				array[posicion].idVenta = *id;
				array[posicion].isEmpty = 0;
				cliente_listado(arrayCliente, sizeCliente);
				do {
					utn_getEntero("\nIngrese ID del cliente: ",
							"\nIntente nuevamente.", 1, 4, 1,
							&array[posicion].idCliente);
				} while (cliente_buscarID(arrayCliente, sizeCliente,
						array[posicion].idCliente, &posCliente) != 0);
				articulo_listado(arrayArticulo, sizeArticulo, arrayRubro,
						sizeRubro);
				do {
					utn_getEntero("\nIngrese ID del articulo: ",
							"\nIntente nuevamente.", 10001, 19999, 1,
							&array[posicion].idArticulo);
				} while (articulo_buscarID(arrayArticulo, sizeArticulo,
						array[posicion].idArticulo, &posArticulo) != 0);
				utn_getEntero("\nIngrese la cantidad de articulos(1 - 1000): ",
						"\nIntente nuevamente.", 1, 1000, 1,
						&array[posicion].cantidad);
				array[posicion].precioTotal = arrayArticulo[posArticulo].precio
						* array[posicion].cantidad;
				utn_getEntero("Ingrese el dia: ", "\nIntente nuevamente.", 1,
						31, 1, &array[posicion].fecha.dia);
				utn_getEntero("Ingrese el mes: ", "\nIntente nuevamente.", 1,
						12, 1, &array[posicion].fecha.mes);
				utn_getEntero("Ingrese el año: ", "\nIntente nuevamente.", 1980,
						2020, 1, &array[posicion].fecha.anio);
				controller_listarVenta(array, posicion, arrayCliente,
						posCliente, arrayArticulo, posArticulo);
				retorno = 0;
			}
		}
	} else if (contArt == 0) {
		printf(
				"\nDebe dar de alta un articulo antes de acceder a esta opcion!");
	}

	if( retorno == 0){
		printf("La venta se ha dado de alta exitosamente!");
	}

	return retorno;
}

int controller_listadoVenta(Venta array[], int size, Cliente arrayCliente[],
		int sizeCliente, Articulo arrayArticulo[], int sizeArticulo,
		int contArt, int contVta) {
	int retorno = -1;
	int posCliente, posArticulo;
	int i;
	if (contArt > 0 && contVta > 0) {
		if (array != NULL && size > 0 && arrayCliente != NULL && sizeCliente > 0
				&& arrayArticulo != NULL && sizeArticulo > 0) {
			for (i = 0; i < size; i++) {
				if (array[i].isEmpty == 0) {
					if (cliente_buscarID(arrayCliente, sizeCliente,
							array[i].idCliente, &posCliente) == 0) {
						if (articulo_buscarID(arrayArticulo, sizeArticulo,
								array[i].idArticulo, &posArticulo) == 0) {
							controller_listarVenta(array, i, arrayCliente,
									posCliente, arrayArticulo, posArticulo);
						}
					}
				}
			}
			retorno = 0;
		}
	} else if (contArt == 0) {
		printf(
				"\nDebe dar de alta un articulo antes de acceder a esta opcion!");

	} else if (contArt > 0 && contVta == 0) {
		printf("\nDebe dar de alta una venta antes de acceder a esta opcion!");
	}

	return retorno;
}

void controller_listarVenta(Venta array[], int pos, Cliente arrayCliente[],
		int posCliente, Articulo arrayArticulo[], int posArticulo) {
	printf("\n%5d | %12s | %15s | %5d | %7.2f | %d/%d/%d", array[pos].idVenta,
			arrayCliente[posCliente].nombre,
			arrayArticulo[posArticulo].articulo, array[pos].cantidad,
			array[pos].precioTotal, array[pos].fecha.dia, array[pos].fecha.mes,
			array[pos].fecha.anio);
}

int controller_listarArticulosRubro(Articulo array[], int size,
		Rubro arrayRubro[], int sizeRubro) {
	int retorno = -1;
	int aux;
	int pos;
	int i;

	rubro_listado(arrayRubro, sizeRubro);
	utn_getEntero("\nIngrese Id del rubro a buscar: ", "\nIntente nuevamente.",
			1001, 1004, 1, &aux);
	if (rubro_buscarID(arrayRubro, sizeRubro, aux, &pos) == 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 0) {
				if (array[i].idRubro == aux) {
					articulo_listar(array, i, arrayRubro, pos);
					retorno = 0;
				}
			}
		}
	} else {
		printf("\nNo existe el rubro ingresado.");
	}
	return retorno;
}

int controller_listarVentasCliente(Venta array[], int size,
		Cliente arrayCliente[], int sizeCliente, Articulo arrayArticulo[],
		int sizeArticulo) {
	int retorno = -1;
	int aux;
	int pos, posArticulo;
	int i;

	cliente_listado(arrayCliente, sizeCliente);
	utn_getEntero("\nIngrese Id del Cliente a buscar: ",
			"\nIntente nuevamente.", 1, 4, 1, &aux);
	if (cliente_buscarID(arrayCliente, sizeCliente, aux, &pos) == 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 0) {
				if (array[i].idCliente == aux) {
					articulo_buscarID(arrayArticulo, sizeArticulo,
							array[i].idArticulo, &posArticulo);
					controller_listarVenta(array, i, arrayCliente, pos,
							arrayArticulo, posArticulo);
					retorno = 0;
				}
			}
		}
	} else {
		printf("\nNo existe el Cliente ingresado.");
	}
	return retorno;
}

int controller_sumarVentasArticulo(Venta array[], int size,
		Articulo arrayArticulo[], int sizeArticulo, Rubro arrayRubro[],
		int sizeRubro) {
	int retorno = -1;
	int aux;
	int pos;
	int cont = 0;
	int i;

	articulo_listado(arrayArticulo, sizeArticulo, arrayRubro, sizeRubro);
	utn_getEntero("\nIngrese Id del Articulo a buscar: ",
			"\nIntente nuevamente.", 10001, 19999, 1, &aux);
	if (articulo_buscarID(arrayArticulo, sizeArticulo, aux, &pos) == 0) {
		retorno = 0;
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 0) {
				if (array[i].idArticulo == arrayArticulo[pos].idArticulo) {
					cont += (arrayArticulo[pos].precio * array[i].cantidad);
					retorno = 1;
				}
			}
		}
	} else {
		printf("\nNo existe el articulo buscado.");
	}

	if (retorno == 1) {
		printf("\nEl importe total de las ventas del articulo '%s' es de $%d",
				arrayArticulo[pos].articulo, cont);
	} else if (retorno == 0) {
		printf("\nNo hay ventas sobre el articulo seleccionado.");
	}
	return retorno;
}

int controller_sumarVentasCliente(Venta array[], int size,
		Cliente arrayCliente[], int sizeCliente, Articulo arrayArticulo[],
		int sizeArticulo) {
	int retorno = -1;
	int aux;
	int pos, posArticulo;
	int cont = 0;
	int i;

	cliente_listado(arrayCliente, sizeCliente);
	utn_getEntero("\nIngrese Id del Cliente a buscar: ",
			"\nIntente nuevamente.", 1, 4, 1, &aux);
	if (cliente_buscarID(arrayCliente, sizeCliente, aux, &pos) == 0) {
		retorno = 0;
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 0) {
				if (array[i].idCliente == arrayCliente[pos].idCliente) {
					if (articulo_buscarID(arrayArticulo, sizeArticulo,
							array[i].idArticulo, &posArticulo) == 0) {
						cont += (arrayArticulo[posArticulo].precio
								* array[i].cantidad);
						retorno = 1;
					}
				}
			}
		}
	} else {
		printf("\nNo existe el Cliente buscado.");
	}

	if (retorno == 1) {
		printf("\nEl importe total de las ventas al cliente '%s' es de $%d",
				arrayCliente[pos].nombre, cont);
	} else if (retorno == 0) {
		printf("\nNo hay ventas sobre el articulo seleccionado.");
	}
	return retorno;
}

int controller_informes(Venta arrayVenta[], int sizeVenta,
		Cliente arrayCliente[], int sizeCliente, Articulo arrayArticulo[],
		int sizeArticulo, Rubro arrayRubro[], int sizeRubro, int contArt,
		int contVta) {
	int retorno = -1;
	int opcion;

	if (contArt > 0 && contVta > 0) {
		retorno = 0;
		utn_getEntero(
				"\n***MENU INFORMES***\n1.-ARTICULOS DE UN RUBRO\n2.-VENTAS EFECTUADAS A UN CLIENTE\n3.-TOTAL DE LAS VENTAS DE UN ARTICULO\n4.-TOTAL DE LAS VENTAS A UN CLIENTE\n5.-SALIR\nSELECCIONE OPCION: ",
				"\nError, la opcion seleccionada no es valida.", 1, 5, 2,
				&opcion);
		switch (opcion) {
		case 1:
			controller_listarArticulosRubro(arrayArticulo, sizeArticulo,
					arrayRubro, sizeRubro);
			break;
		case 2:
			controller_listarVentasCliente(arrayVenta, sizeVenta, arrayCliente,
					sizeCliente, arrayArticulo, sizeArticulo);
			break;
		case 3:
			controller_sumarVentasArticulo(arrayVenta, sizeVenta, arrayArticulo,
					sizeArticulo, arrayRubro, sizeRubro);
			break;
		case 4:
			controller_sumarVentasCliente(arrayVenta, sizeVenta, arrayCliente,
					sizeCliente, arrayArticulo, sizeArticulo);
			break;
		case 5:
			printf("\nVolviendo a Menu Principal!");
			break;
		}
	} else if (contArt == 0) {
		printf(
				"\nDebe dar de alta un articulo antes de acceder a esta opcion!");

	} else if (contArt > 0 && contVta == 0) {
		printf("\nDebe dar de alta una venta antes de acceder a esta opcion!");
	}

	return retorno;
}
