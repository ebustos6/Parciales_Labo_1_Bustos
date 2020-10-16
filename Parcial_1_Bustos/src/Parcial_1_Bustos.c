/*
 ============================================================================
 Name        : Parcial_1_Bustos.c
 Author      : Emanuel Bustos
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utn.h"
#include "Electro.h"
#include "Marca.h"
#include "Reparacion.h"
#include "Servicio.h"
#define T 20

int main(void) {
	setbuf(stdout, NULL);

	int opcion, contadorIdReparacion = 0, contadorIdElectro = 0;
	eElectro listaDeElectro[T];
	eMarca listaDeMarca[T];
	eReparacion listaDeReparacion[T];
	eServicio listaDeServicio[T];

	electro_inicializar(listaDeElectro, T);
	marca_inicializar(listaDeMarca, T);
	reparacion_inicializar(listaDeReparacion, T);
	servicio_inicializar(listaDeServicio, T);

	marca_hardcodear(listaDeMarca, 5);
	servicio_hardcodear(listaDeServicio, 4);

	do {
		utn_getUnsignedInt(
				"\n***Menu Principal***\n1.- Alta de Electrodomestico\n2.- Modificar Electrodomestico\n3.- Baja Electrodomestico\n4.- Listar Electrodomesticos\n5.- Listar Marcas\n6.- Listar Servicios\n7.- Alta Reparacion\n8.- Listar Reparaciones\nIngrese opcion:",
				"\nOpcion Incorrecta", 1, sizeof(int), 1, 9, 2, &opcion);

		switch (opcion) {
		case 1:
			electro_alta(listaDeElectro,T,&contadorIdElectro,listaDeMarca,T);
			break;
		case 2:
			electro_modificar(listaDeElectro,T);
			break;
		case 3:
			electro_baja(listaDeElectro, T);
			break;
		case 4:
			electro_listar(listaDeElectro, T);
			break;
		case 5:
			marca_listar(listaDeMarca,T);
			break;
		case 6:
			servicio_listar(listaDeServicio,T);
			break;
		case 7:
			reparacion_alta(listaDeReparacion,T,&contadorIdReparacion);
			break;
		case 8:
			reparacion_listar(listaDeReparacion,T);
			break;
		}
	} while (opcion != 9);

	return EXIT_SUCCESS;
}
