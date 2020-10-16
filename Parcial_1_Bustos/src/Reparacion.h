/*
 * Reparacion.h
 *
 *  Created on: Oct 15, 2020
 *      Author: Administrator
 */

#ifndef REPARACION_H_
#define REPARACION_H_

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int idReparacion;
	int serie;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eReparacion;

#endif /* REPARACION_H_ */

int reparacion_inicializar(eReparacion array[], int size);
int reparacion_buscarEmpty(eReparacion array[], int size, int* posicion);
int reparacion_alta(eReparacion array[], int size, int* contadorID);
int reparacion_listar(eReparacion array[], int size);
