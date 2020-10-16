/*
 * Electro.h
 *
 *  Created on: Oct 15, 2020
 *      Author: Administrator
 */

#ifndef ELECTRO_H_
#define ELECTRO_H_
#include "Marca.h"
#include "Utn.h"

typedef struct{
	int idElectro;
	int serie;
	int idMarca;
	int modelo;
	int isEmpty;
}eElectro;

#endif /* ELECTRO_H_ */

int electro_inicializar(eElectro array[], int size);
int electro_buscarEmpty(eElectro array[], int size, int* posicion);
int electro_alta(eElectro array[], int size, int* contadorID, eMarca arrayMarca[], int sizeMarca);
int electro_buscarID(eElectro array[], int size, int valorBuscado, int* posicion);
int electro_baja(eElectro array[], int sizeArray);
int electro_listar(eElectro array[], int size);
int electro_modificar(eElectro array[], int sizeArray);
