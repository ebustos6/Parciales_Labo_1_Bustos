#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "electro_marca.h"
#include "utn.h"

int electro_inicializar(eElectro array[], int size) {
	int retorno = -1;
	if (array != NULL && size > 0) {
		for (; size > 0; size--) {
			array[size - 1].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int electro_buscarEmpty(eElectro array[], int size, int *posicion) {
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

int electro_alta(eElectro array[], int size, int *contadorID,
		eMarca arrayMarca[], int sizeMarca, eProcedencia arrayProcedencia[], int sizeProcedencia) {
	int retorno = -1;
	int posicion;

	if (array != NULL && size > 0 && contadorID != NULL) {
		if (electro_buscarEmpty(array, size, &posicion) == -1) {
			printf("\nNo hay lugares vacios");
		} else {
			(*contadorID)++;
			array[posicion].idElectro = *contadorID;
			array[posicion].isEmpty = 0;
			utn_getEntero("Ingrese número de serie(30000-89999): ",
					"\nIntente nuevamente", 30000, 89999, 1,
					&array[posicion].serie);
			marca_listado(arrayMarca, sizeMarca);
			utn_getEntero("\nIngrese la Id de la marca del electrodomestico: ",
					"\nIntente nuevamente", 1001, 1005, 1,
					&array[posicion].idMarca);
			procedencia_listado(arrayProcedencia, sizeProcedencia);
			utn_getEntero("\nIngrese la Id de la Procedencia: ",
								"\nIntente nuevamente", 1, 4, 1,
								&array[posicion].idProcedencia);
			utn_getEntero("Ingrese año de fabricacion(1900-2020): ",
					"\nIntente nuevamente", 1900, 2020, 1,
					&array[posicion].modelo);
			retorno = 0;
		}
	}
	return retorno;
}

int electro_buscarSerie(eElectro array[], int size, int valorBuscado,
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

int electro_buscarID(eElectro array[], int size, int valorBuscado,
		int *posicion) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1)
				continue;
			else if (array[i].idElectro == valorBuscado) {
				retorno = 0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}

int electro_baja(eElectro array[], int sizeArray) {
	int retorno = -1;
	int posicion;
	int id;
	if (array != NULL && sizeArray > 0) {
		electro_listado(array, sizeArray);
		utn_getEntero("\nIngrese la ID a dar de baja: ", "\nError", 1,
				sizeArray, 1, &id);
		if (electro_buscarID(array, sizeArray, id, &posicion) == -1) {
			printf("\nEl ID ingresado no es válido");
		} else {
			array[posicion].isEmpty = 1;
			retorno = 0;
		}
	}
	return retorno;
}

void electro_listar(eElectro array[], int pos){
	printf("\n %d Nro de Serie:%d ID marca:%d Año:%d", array[pos].idElectro,
							array[pos].serie, array[pos].idMarca, array[pos].modelo);
}



int electro_listado(eElectro array[], int size) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1)
				continue;
			else
				electro_listar(array,i);
		}
		retorno = 0;
	}
	return retorno;
}

int electro_modificar(eElectro array[], int sizeArray, eMarca arrayMarca[],
		int sizeMarca) {
	int retorno = -1;
	int posicion;
	int id;
	int opcion;
	if (array != NULL && sizeArray > 0) {
		electro_listado(array, sizeArray);
		utn_getEntero("\nIngrese el número de electrodomestico a modificar: ",
				"\nError", 1, sizeArray, 1, &id);
		if (electro_buscarID(array, sizeArray, id, &posicion) == -1) {
			printf("\nNo existe este ID");
		} else {
			do {
				printf("\n%d\n serie: %d\n Id marca: %d\n Año: %d", posicion,
						array[posicion].serie, array[posicion].idMarca,
						array[posicion].modelo);
				utn_getEntero(
						"\nModificar: \n1.- Nro de serie \n2.- Marca \n3.- Modelo \n4.- Salir",
						"\nError", 1, 4, 1, &opcion);
				switch (opcion) {
				case 1:
					utn_getEntero("\nIngrese nuevo nro de serie(30000-89999): ",
							"\nError", 30000, 89999, 1, &array[posicion].serie);
					break;
				case 2:
					marca_listado(arrayMarca, sizeMarca);
					utn_getEntero("\nSeleccione la marca que desea cambiar: ",
							"\nError", 1001, 1005, 1, &array[posicion].idMarca);
					break;
				case 3:
					utn_getEntero("\nIngrese nuevo año: ", "\nError", 1900,
							2020, 1, &array[posicion].modelo);
					break;
				case 4:
					printf("Volviendo a Menu Principal!");
					break;
				default:
					printf("\nOpcion no válida");
				}
			} while (opcion != 4);
			retorno = 0;
		}
	}
	return retorno;
}

void electro_hardcodear(eElectro array[], int size) {
	int idElectro[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int serie[8] = { 89997, 34567, 76551, 44556, 55532, 33331, 69027, 56789 };
	int idMarca[8] = { 1001, 1003, 1002, 1001, 1004, 1001, 1005, 1004 };
	int idProcedencia[8] = { 1, 1, 2, 3, 4, 1, 2, 3};
	int modelo[8] = { 1999, 2002, 2002, 1991, 2020, 1990, 2020, 2018 };
	int i;

	for (i = 0; i < size; i++) {

		array[i].idElectro = idElectro[i];
		array[i].serie = serie[i];
		array[i].idMarca = idMarca[i];
		array[i].idProcedencia = idProcedencia[i];
		array[i].modelo = modelo[i];
		array[i].isEmpty = 0;
	}
}

int electro_ordenar(eElectro array[], int size) {
	int i;
	int j;
	int retorno = -1;
	eElectro aux;

	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (array[i].modelo > array[j].modelo) {
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				retorno = 0;
			} else if (array[i].modelo == array[j].modelo) {
				if (array[i].serie < array[j].serie) {
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

int electro_buscarModelo(eElectro array[], int size, int valorBuscado,
		int *posicion) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1)
				continue;
			else if (array[i].modelo == valorBuscado) {
				retorno = 0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}

int electro_listadoConProcedencia(eElectro arrayElectro[], int sizeElectro, eProcedencia arrayProcedencia[], int sizeProcedencia){
	int retorno = -1;
	int pos;
	int i;

	for(i = 0; i < sizeElectro; i++){
		if(arrayElectro[i].isEmpty == 0){
			if(procedencia_buscarID(arrayProcedencia, sizeProcedencia, arrayElectro[i].idProcedencia, &pos) == 0){
				if(arrayElectro[i].idProcedencia == arrayProcedencia[pos].idProcedencia){
					electro_listarProcedencia(arrayElectro, i, arrayProcedencia, pos);
					retorno = 0;
				}
			}
		}
	}


	return retorno;
}

void electro_listarProcedencia(eElectro arrayElectro[], int posE, eProcedencia arrayProcedencia[], int posP){
	printf("\n %d Nro de Serie:%d ID marca:%d Año:%d Procedencia:%s", arrayElectro[posE].idElectro,
			arrayElectro[posE].serie, arrayElectro[posE].idMarca, arrayElectro[posE].modelo, arrayProcedencia[posP].nombrePais);
}

//------------------------------------------------------------------------------------------------------------------------

int marca_inicializar(eMarca array[], int size) {
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
	char descripcion[5][20] = { "Whirlpool", "Sony", "Liliana", "Gafa",
			"Philips" };
	int i;

	for (i = 0; i < size; i++) {

		array[i].idMarca = idMarca[i];
		strcpy(array[i].descripcion, descripcion[i]);
		array[i].isEmpty = 0;
	}
}

void marca_listar(eMarca array[], int pos){
	printf("\nID: %d %s", array[pos].idMarca, array[pos].descripcion);
}

int marca_listado(eMarca array[], int size) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1)
				continue;
			else
				marca_listar(array,i);
		}
		retorno = 0;
	}
	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int procedencia_inicializar(eProcedencia array[], int size) {
	int retorno = -1;
	if (array != NULL && size > 0) {
		for (; size > 0; size--) {
			array[size - 1].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}


void procedencia_hardcodear(eProcedencia array[], int size) {
	int idProcedencia[4] = { 1, 2, 3, 4 };
	char nombrePais[4][20] = { "Argentina", "China", "Taiwan", "EEUU" };
	int i;

	for (i = 0; i < size; i++) {

		array[i].idProcedencia = idProcedencia[i];
		strcpy(array[i].nombrePais, nombrePais[i]);
		array[i].isEmpty = 0;
	}
}

void procedencia_listar(eProcedencia array[], int pos){
	printf("\nID: %d %s", array[pos].idProcedencia, array[pos].nombrePais);
}

int procedencia_listado(eProcedencia arrayProcedencia[], int size) {
	int retorno = -1;
	int i;

	for (i = 0; i < size; i++){
		if(arrayProcedencia[i].isEmpty == 0){
			procedencia_listar(arrayProcedencia, i);
			retorno = 0;
		}
	}

	return retorno;
}

int procedencia_buscarID(eProcedencia array[], int size, int valorBuscado,
		int *posicion) {
	int retorno = -1;
	int i;
	if (array != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == 1)
				continue;
			else if (array[i].idProcedencia == valorBuscado) {
				retorno = 0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}
