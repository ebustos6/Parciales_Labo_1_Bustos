/*
 * Servicio.h
 *
 *  Created on: Oct 15, 2020
 *      Author: Administrator
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{
	int idServicio;
	char descripcion[25];
	int precio;
	int isEmpty;
}eServicio;

#endif /* SERVICIO_H_ */

int servicio_inicializar(eServicio array[], int size);
void servicio_hardcodear(eServicio array[], int size);
int servicio_listar(eServicio array[], int size);
