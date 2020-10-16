/*
 * Marca.h
 *
 *  Created on: Oct 15, 2020
 *      Author: Administrator
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct{
	int idMarca;
	char descripcion[20];
	int isEmpty;
}eMarca;

#endif /* MARCA_H_ */

int marca_inicializar(eMarca array[], int size);
void marca_hardcodear(eMarca array[], int size);
int marca_listar(eMarca array[], int size);
