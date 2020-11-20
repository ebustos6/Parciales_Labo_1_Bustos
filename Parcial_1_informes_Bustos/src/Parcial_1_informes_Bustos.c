/*
 ============================================================================
 Name        : Parcial_1_informes_Bustos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "electro_marca.h"
#include "reparacion_servicio_cliente.h"
#include "informes.h"

#define T 40

int main(void) {
	setbuf(stdout, NULL);

	int opcion, contador = 1, rcont = 1, contadorIdElectro = 8,
			contadorIdReparacion = 8;
	eElectro listaDeElectro[T];
	eMarca listaDeMarca[T];
	eReparacion listaDeReparacion[T];
	eServicio listaDeServicio[T];
	eCliente listaDeCliente[T];
	eProcedencia listaDeProcedencia[T];

	electro_inicializar(listaDeElectro, T);
	marca_inicializar(listaDeMarca, T);
	reparacion_inicializar(listaDeReparacion, T);
	servicio_inicializar(listaDeServicio, T);
	cliente_inicializar(listaDeCliente, T);
	procedencia_inicializar(listaDeProcedencia, T);

	marca_hardcodear(listaDeMarca, 5);
	servicio_hardcodear(listaDeServicio, 4);
	cliente_hardcodear(listaDeCliente, 6);
	reparacion_hardcodear(listaDeReparacion, 8);
	electro_hardcodear(listaDeElectro, 8);
	procedencia_hardcodear(listaDeProcedencia, 4);

	do {
		utn_getEntero(
				"\n***Menu Principal***\n01.- Alta de Electrodomestico\n02.- Modificar Electrodomestico\n03.- Baja Electrodomestico\n04.- Listar Electrodomesticos\n05.- Listar Marcas\n06.- Listar Servicios\n07.- Alta Reparacion\n08.- Listar Reparaciones\n09.- Mostrar Electrodomesticos año 2020\n10.- Mostrar Electrodomesticos por Marca\n11.- Mostrar reparaciones a un electrodomestico\n12.- Listar electrodomesticos sin reparaciones\n13.- Importe total de las reparaciones de un electrodomestico\n14.- Servicio mas pedido\n15.- Mostrar recaudacion en una fecha\n16.- Mostrar electrodomesticos que hicieron garantia con fecha\n17.- Trabajos realizados a electrodomesticos modelo 2018\n18.- Facturacion total de mantenimientos\n19.- Marca con mas reparaciones\n20.- Electrodomesticos con reparacion en fecha determinada\n21.- Listar procedencia\n22.- Salir\nIngrese opcion:",
				"\nOpcion Incorrecta", 1, 22, 2, &opcion);

		switch (opcion) {
		case 1:
			if (electro_alta(listaDeElectro, T, &contadorIdElectro,
					listaDeMarca,
					T, listaDeProcedencia, T) == 0) {
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
				electro_listadoConProcedencia(listaDeElectro, T, listaDeProcedencia, T);
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
				reparacion_listado(listaDeReparacion, T);
			} else {
				if (contador > 0 && rcont <= 0) {
					printf("Debe dar de alta una reparacion primero.");
				} else if (contador <= 0) {
					printf("Debe dar de alta un electrodomestico primero");
				}
			}
			break;
		case 9:
			electro_listar_2020(listaDeElectro, T);
			break;
		case 10:
			electro_listar_marca(listaDeElectro, T, listaDeMarca, T);
			break;
		case 11:
			electro_listar_reparaciones(listaDeElectro, T, listaDeReparacion, T);
			break;
		case 12:
			electro_listar_sinReparaciones(listaDeElectro, T, listaDeReparacion, T);
			break;
		case 13:
			electro_sumar_reparaciones(listaDeElectro, T, listaDeReparacion, T, listaDeServicio, T);
			break;
		case 14:
			servicio_masPedido(listaDeReparacion, T, listaDeServicio);
			break;
		case 15:
			reparacion_recaudacionFecha(listaDeReparacion, T, listaDeServicio, T);
			break;
		case 16:
			electro_garantiaFecha(listaDeElectro, T, listaDeReparacion, T, listaDeServicio, T);
			break;
		case 17:
			reparacion_electro2018(listaDeReparacion, T, listaDeElectro, T);
			break;
		case 18:
			reparacion_sumaMantenimiento(listaDeReparacion, T, listaDeServicio, T);
			break;
		case 19:
			electro_masMarca(listaDeElectro, T, listaDeMarca, T, listaDeReparacion, T);
			break;
		case 20:
			electro_reparacion_fecha(listaDeElectro, T, listaDeReparacion, T);
			break;
		case 21:
			procedencia_listado(listaDeProcedencia, T);
			break;
		}
	} while (opcion != 22);
	printf("Parcial N°1 Emanuel Bustos");
	return EXIT_SUCCESS;
}
