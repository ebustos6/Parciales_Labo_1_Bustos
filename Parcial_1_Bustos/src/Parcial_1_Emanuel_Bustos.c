/*
 ============================================================================
 Name        : Parcial_1_Bustos.c
 Author      : Emanuel Bustos
 Version     : 2.0
 Description : ABM del 1er parcial, corregido, documentado, funcionando
 	 	 	   y con la estructura  eCliente agregada.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "electro_marca.h"
#include "reparacion_servicio_cliente.h"

#define T 20

int main(void) {
	setbuf(stdout, NULL);

	int opcion, contador = 0, rcont = 0, contadorIdElectro = 0,
			contadorIdReparacion = 0;
	eElectro listaDeElectro[T];
	eMarca listaDeMarca[T];
	eReparacion listaDeReparacion[T];
	eServicio listaDeServicio[T];
	eCliente listaDeCliente[T];

	electro_inicializar(listaDeElectro, T);
	marca_inicializar(listaDeMarca, T);
	reparacion_inicializar(listaDeReparacion, T);
	servicio_inicializar(listaDeServicio, T);
	cliente_inicializar(listaDeCliente, T);

	marca_hardcodear(listaDeMarca, 5);
	servicio_hardcodear(listaDeServicio, 4);
	cliente_hardcodear(listaDeCliente, 6);
	//reparacion_hardcodear(listaDeReparacion, 4);
	//electro_hardcodear(listaDeElectro, 4);

	do {
		utn_getEntero(
				"\n***Menu Principal***\n1.- Alta de Electrodomestico\n2.- Modificar Electrodomestico\n3.- Baja Electrodomestico\n4.- Listar Electrodomesticos\n5.- Listar Marcas\n6.- Listar Servicios\n7.- Alta Reparacion\n8.- Listar Reparaciones\n9.- Salir\nIngrese opcion:",
				"\nOpcion Incorrecta", 1, 9, 2, &opcion);

		switch (opcion) {
		case 1:
			if (electro_alta(listaDeElectro, T, &contadorIdElectro,
					listaDeMarca,
					T) == 0) {
				contador++;
			}
			break;
		case 2:
			if (contador > 0) {
				electro_modificar(listaDeElectro, T, listaDeMarca, T);
			} else {
				printf("Debe dar de alta un electrodomestico primero.");
			}
			break;
		case 3:
			if (contador > 0) {
				if (electro_baja(listaDeElectro, T) == 0) {
					contador--;
				}
			} else {
				printf("Debe dar de alta un electrodomestico primero.");
			}
			break;
		case 4:
			if (contador > 0) {
				electro_ordenar(listaDeElectro, T);
				electro_listado(listaDeElectro, T);
			} else {
				printf("Debe dar de alta un electrodomestico primero.");
			}
			break;
		case 5:
			marca_listado(listaDeMarca, T);
			break;
		case 6:
			servicio_listado(listaDeServicio, T);
			break;
		case 7:
			if (contador > 0) {
				if (reparacion_alta(listaDeReparacion, T, &contadorIdReparacion,
						listaDeElectro, T, listaDeServicio, T, listaDeCliente,
						T) == 0) {
					rcont++;
				}
			} else {
				printf("Debe dar de alta un electrodomestico primero.");
			}
			break;
		case 8:
			if (contador > 0 && rcont > 0) {
				//reparacion_listado(listaDeReparacion, T, listaDeServicio, T, listaDeCliente, T);
				reparacion_listar(listaDeReparacion, T);
			} else {
				if (contador > 0 && rcont <= 0) {
					printf("Debe dar de alta una reparacion primero.");
				} else if (contador <= 0) {
					printf("Debe dar de alta un electrodomestico primero");
				}
			}
			break;
		case 9:
			printf("Parcial N°1 Emanuel Bustos");
			break;
		}
	} while (opcion != 9);

	return EXIT_SUCCESS;
}
