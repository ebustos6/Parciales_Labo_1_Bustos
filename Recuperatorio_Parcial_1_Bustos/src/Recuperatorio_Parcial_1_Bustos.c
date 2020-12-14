/*
 ============================================================================
 Name        : Recuperatorio_Parcial_1_Bustos.c
 Author      : Emanuel Bustos
 Description : ABM Ventas, Recuperatorio 1er parcial.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "articulo_rubro.h"
#include "venta_cliente.h"
#include "utn.h"
#define SIZE_RUBRO 4
#define SIZE_CLIENTE 4
#define SIZE_ARTICULO 10
#define SIZE_VENTA 10


int main(void) {
	setbuf(stdout, NULL);
	int idRubro = 1000, idCliente = 0, idArticulo = 10000, idVenta = 20000, contArt = 0, contVta = 0, opcion;
	Rubro listaRubro[SIZE_RUBRO];
	Cliente listaCliente[SIZE_CLIENTE];
	Articulo listaArticulo[SIZE_ARTICULO];
	Venta listaVenta[SIZE_VENTA];

	rubro_hardcodear(listaRubro,SIZE_RUBRO,&idRubro);
	cliente_hardcodear(listaCliente,SIZE_CLIENTE,&idCliente);
	articulo_inicializar(listaArticulo,SIZE_ARTICULO);
	venta_inicializar(listaVenta,SIZE_VENTA);

	do{
		utn_getEntero(
					"\n***MENU PRINCIPAL***\n1.-ALTA ARTICULO\n2.-MODIFICAR ARTICULO\n3.-BAJA ARTICULO\n4.-LISTAR ARTICULOS\n5.-LISTAR RUBROS\n6.-LISTAR CLIENTES\n7.-ALTA VENTA\n8.-LISTAR VENTAS\n9.-INFORMES\n10.- SALIR\nSELECCIONE OPCION: ",
					"Error, la opcion seleccionada no es valida.", 1, 10, 2, &opcion);
		switch(opcion){
		case 1:
			controller_altaArticulo(listaArticulo,SIZE_ARTICULO,listaRubro,SIZE_RUBRO,&idArticulo,&contArt);
			break;
		case 2:
			controller_modificarArticulo(listaArticulo,SIZE_ARTICULO,listaRubro,SIZE_RUBRO,contArt);
			break;
		case 3:
			controller_bajaArticulo(listaArticulo,SIZE_ARTICULO,listaRubro,SIZE_RUBRO,&contArt);
			break;
		case 4:
			controller_listadoArticulo(listaArticulo,SIZE_ARTICULO,listaRubro,SIZE_RUBRO,contArt);
			break;
		case 5:
			rubro_listado(listaRubro, SIZE_RUBRO);
			break;
		case 6:
			cliente_listado(listaCliente, SIZE_CLIENTE);
			break;
		case 7:
			controller_altaVenta(listaVenta, SIZE_VENTA, &idVenta, listaCliente,
			SIZE_CLIENTE, listaArticulo, SIZE_ARTICULO, listaRubro, SIZE_RUBRO,
					contArt, &contVta);
			break;
		case 8:
			controller_listadoVenta(listaVenta, SIZE_VENTA, listaCliente,
			SIZE_CLIENTE, listaArticulo, SIZE_ARTICULO, contArt, contVta);
			break;
		case 9:
			controller_informes(listaVenta, SIZE_VENTA, listaCliente,
			SIZE_CLIENTE, listaArticulo, SIZE_ARTICULO, listaRubro,
			SIZE_RUBRO, contArt, contVta);
			break;
		}
	}while(opcion != 10);

	printf("\nRecuperatorio Primer Parcial Bustos Emanuel");

	return EXIT_SUCCESS;
}
