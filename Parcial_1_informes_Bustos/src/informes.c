#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reparacion_servicio_cliente.h"
#include "electro_marca.h"
#include "utn.h"
#include "informes.h"

int electro_listar_2020(eElectro array[], int sizeElectro) {
	int retorno = -1;
	int i;

	for (i = 0; i < sizeElectro; i++) {
		if(array[i].isEmpty == 1){
			continue;
		}
		else if(array[i].modelo == 2020){
			electro_listar(array,i);
			retorno = 0;
		}
	}
	return retorno;
}

int electro_listar_marca(eElectro arrayElectro[], int sizeElectro, eMarca arrayMarca[], int sizeMarca){
	int retorno = -1;
	int aux;
	int i;

	marca_listado(arrayMarca, sizeMarca);
	utn_getEntero("\nIngrese el código de la marca a listar: ", "\nError", 1001, 1005, 2, &aux);
	for(i = 0;i < sizeElectro;i++){
		if(arrayElectro[i].isEmpty == 1){
			continue;
		}
		else if(arrayElectro[i].idMarca == aux){
			electro_listar(arrayElectro, i);
			retorno = 0;
		}
	}

	return retorno;
}

int electro_listar_reparaciones(eElectro arrayElectro[], int sizeElectro, eReparacion arrayReparacion[], int sizeReparacion){
	int retorno = -1;
	int aux;
	int pos;
	int i;

	electro_listado(arrayElectro, sizeElectro);
	utn_getEntero("\nIngrese el numero de serie del Electrodomestico: ","\nError",30000,89999,2,&aux);
	if(electro_buscarSerie(arrayElectro, sizeElectro, aux, &pos) == 0){
		for(i = 0; i < sizeReparacion; i++){
				if(arrayReparacion[i].isEmpty == 1){
					continue;
				}
				else if(arrayReparacion[i].serie == aux){
					reparacion_listar(arrayReparacion, i);
					retorno = 0;
				}
			}
	}
	else{
		printf("\nEl numero de serie ingresado no existe.");
	}

	return retorno;
}

int electro_listar_sinReparaciones(eElectro arrayElectro[], int sizeElectro, eReparacion arrayReparacion[], int sizeReparacion){
	int retorno = -1;
	int pos;
	int i;

	for(i = 0; i < sizeElectro; i++){
		if(arrayElectro[i].isEmpty == 0){
			if(reparacion_buscarSerie(arrayReparacion, sizeReparacion, arrayElectro[i].serie,&pos) == -1){
				electro_listar(arrayElectro, i);
				retorno = 0;
			}
		}
	}

	return retorno;
}

int electro_sumar_reparaciones(eElectro arrayElectro[], int sizeElectro, eReparacion arrayReparacion[], int sizeReparacion, eServicio arrayServicio[], int sizeServicio){
	int retorno = -1;
	int cont = 0;
	int aux;
	int posElectro;
	int posServicio;
	int i;

	electro_listado(arrayElectro, sizeElectro);
	utn_getEntero("\nIngrese la ID del electrodomestico: ", "\nError",1,sizeElectro,1,&aux);
	if(electro_buscarID(arrayElectro, sizeElectro, aux, &posElectro) == 0){
		retorno = 0;
		for(i = 0; i < sizeReparacion; i++){
			if(arrayReparacion[i].isEmpty == 0 && arrayReparacion[i].serie == arrayElectro[posElectro].serie){
				if(servicio_buscarID(arrayServicio, sizeServicio, arrayReparacion[i].idServicio, &posServicio) == 0){
					cont += arrayServicio[posServicio].precio;
					retorno = 1;
				}
			}
		}
	}
	else{
		cont = -1;
		printf("La ID ingresada no existe.");
	}

	if(cont >= 0){
		printf("\n La suma de las reparaciones es $%d", cont);
	}

	return retorno;
}

int servicio_masPedido(eReparacion arrayReparacion[], int sizeReparacion, eServicio arrayServicio[]){
	int retorno = -1;
	int cont1 = 0;
	int cont2 = 0;
	int cont3 = 0;
	int cont4 = 0;
	int i;

	for(i = 0; i < sizeReparacion; i++){
		if(arrayReparacion[i].isEmpty == 0){
			retorno = 0;
			if(arrayReparacion[i].idServicio == arrayServicio[0].idServicio){
				cont1++;
			}
			else if(arrayReparacion[i].idServicio == arrayServicio[1].idServicio){
				cont2++;
			}
			else if(arrayReparacion[i].idServicio == arrayServicio[2].idServicio){
				cont3++;
			}
			else if(arrayReparacion[i].idServicio == arrayServicio[3].idServicio){
				cont4++;
			}
		}
	}

	if(cont1 > cont2 && cont1 > cont3 && cont1 > cont4){
		printf("\nEl servicio mas Pedido es %s, fue pedido un total de: %d veces.",arrayServicio[0].descripcion, cont1);
	}
	else if(cont2 > cont1 && cont2 > cont3 && cont2 > cont4){
			printf("\nEl servicio mas Pedido es %s, fue pedido un total de: %d veces.", arrayServicio[1].descripcion, cont2);
		}
	else if(cont3 > cont1 && cont3 > cont2 && cont3 > cont4){
				printf("\nEl servicio mas Pedido es %s, fue pedido un total de: %d veces.", arrayServicio[2].descripcion, cont3);
			}
	else if(cont4 > cont1 && cont4 > cont2 && cont4 > cont3){
				printf("\nEl servicio mas Pedido es %s, fue pedido un total de: %d veces.", arrayServicio[3].descripcion, cont4);
			}
	return retorno;
}

int reparacion_recaudacionFecha(eReparacion arrayReparacion[], int sizeReparacion, eServicio arrayServicio[], int sizeServicio){
	int retorno = -1;
	int cont = 0;
	int auxD;
	int auxM;
	int auxA;
	int pos;
	int i;

	utn_getEntero("\nIngrese dia: ", "\nError", 1, 31, 2, &auxD);
	utn_getEntero("Ingrese mes: ", "\nError", 1, 12, 2, &auxM);
	utn_getEntero("Ingrese año: ", "\nError", 1900, 2020, 2,&auxA);
	for(i = 0;i < sizeReparacion;i++){
		if(arrayReparacion[i].isEmpty == 0 && arrayReparacion[i].fecha.dia == auxD && arrayReparacion[i].fecha.mes == auxM && arrayReparacion[i].fecha.anio == auxA){
			if(servicio_buscarID(arrayServicio, sizeServicio, arrayReparacion[i].idServicio, &pos) == 0){
				cont += arrayServicio[pos].precio;
				retorno = 0;
			}
		}
	}

	if(retorno == 0){
		printf("\nLa recaudacion del dia %d/%d/%d es de $%d",auxD,auxM,auxA,cont);
	}
	else{
		printf("\nNo hubo recaudacion el dia seleccionado.");
	}
	return retorno;
}

int electro_garantiaFecha(eElectro arrayElectro[], int sizeElectro, eReparacion arrayReparacion[], int sizeReparacion, eServicio arrayServicio[], int sizeServicio){
	int retorno = -1;
	int i;
	int posR;
	int posS;


	for (i = 0; i < sizeElectro; i++){
		if(arrayElectro[i].isEmpty == 0){
			if(reparacion_buscarSerie(arrayReparacion, sizeReparacion, arrayElectro[i].serie, &posR) == 0){
				if(arrayElectro[i].serie == arrayReparacion[posR].serie && arrayReparacion[posR].idServicio == 20001){
					if(servicio_buscarID(arrayServicio, sizeServicio, arrayReparacion[posR].idServicio, &posS) == 0){
						if(arrayReparacion[posR].idServicio == arrayServicio[posS].idServicio){
							retorno = 0;
							printf("\nID:%d Nro de Serie:%d %10s fecha:%d/%d/%d", arrayElectro[i].idElectro, arrayElectro[i].serie, arrayServicio[posS].descripcion, arrayReparacion[posR].fecha.dia, arrayReparacion[posR].fecha.mes, arrayReparacion[posR].fecha.anio);
						}
					}
				}
			}
		}
	}

	return retorno;
}

int reparacion_electro2018(eReparacion arrayReparacion[], int sizeReparacion, eElectro arrayElectro[], int sizeElectro){
	int retorno = -1;
	int i;
	int pos;

	for(i = 0; i < sizeElectro; i++){
		if(arrayElectro[i].isEmpty == 0 && arrayElectro[i].modelo == 2018){
			if(reparacion_buscarSerie(arrayReparacion, sizeReparacion, arrayElectro[i].serie, &pos) == 0){
				reparacion_listar(arrayReparacion, pos);
				retorno = 0;
			}
		}
	}

	return retorno;
}

int reparacion_sumaMantenimiento(eReparacion arrayReparacion[], int sizeReparacion, eServicio arrayServicio[], int sizeServicio){
	int retorno = -1;
	int cont = 0;
	int pos;
	int i;

	for(i = 0; i < sizeReparacion; i++){
		if(arrayReparacion[i].isEmpty == 0){
			if(servicio_buscarID(arrayServicio, sizeServicio, 20002, &pos) == 0){
				if(arrayReparacion[i].idServicio == arrayServicio[pos].idServicio){
					cont += arrayServicio[pos].precio;
					retorno = 0;
				}
			}
		}
	}

	if(retorno == 0){
		printf("\nLa suma total de los mantenimientos es de: $%d",cont);
	}

	return retorno;
}

int electro_masMarca(eElectro arrayElectro[], int sizeElectro, eMarca arrayMarca[], int sizeMarca, eReparacion arrayReparacion[], int sizeReparacion){
	int retorno = -1;
	int cont1 = 0;
	int cont2 = 0;
	int cont3 = 0;
	int cont4 = 0;
	int cont5 = 0;
	int pos;
	int i;

	for(i = 0; i < sizeElectro; i++){
		if(arrayElectro[i].isEmpty == 0){
			if(reparacion_buscarSerie(arrayReparacion, sizeReparacion, arrayElectro[i].serie, &pos) == 0){
				if(arrayElectro[i].serie == arrayReparacion[pos].serie && arrayReparacion[pos].idServicio == 20004){
					retorno = 0;
					if(arrayElectro[i].idMarca == arrayMarca[0].idMarca){
						cont1++;
					}
					else if(arrayElectro[i].idMarca == arrayMarca[1].idMarca){
						cont2++;
					}
					else if(arrayElectro[i].idMarca == arrayMarca[2].idMarca){
						cont3++;
					}
					else if(arrayElectro[i].idMarca == arrayMarca[3].idMarca){
						cont4++;
					}
					else if(arrayElectro[i].idMarca == arrayMarca[4].idMarca){
						cont5++;
					}
				}
			}
		}
	}


	if(cont1 > cont2 && cont1 > cont3 && cont1 > cont4 && cont1 > cont5){
		printf("\n La marca con mas refacciones es: %s",arrayMarca[0].descripcion);
	}
	else if(cont2 > cont1 && cont2 > cont3 && cont2 > cont4 && cont2 > cont5){
		printf("\n La marca con mas refacciones es: %s",arrayMarca[1].descripcion);
	}
	else if(cont3 > cont1 && cont3 > cont2 && cont3 > cont4 && cont3 > cont5){
		printf("\n La marca con mas refacciones es: %s",arrayMarca[2].descripcion);
	}
	else if(cont4 > cont1 && cont4 > cont2 && cont4 > cont3 && cont4 > cont5){
		printf("\n La marca con mas refacciones es: %s",arrayMarca[3].descripcion);
	}
	else if(cont5 > cont1 && cont5 > cont2 && cont5 > cont3 && cont5 > cont4){
		printf("\n La marca con mas refacciones es: %s",arrayMarca[4].descripcion);
	}

	return retorno;
}

int electro_reparacion_fecha(eElectro arrayElectro[], int sizeElectro, eReparacion arrayReparacion[], int sizeReparacion){
	int retorno = -1;
	int pos;
	int auxD;
	int auxM;
	int auxA;
	int i;

	utn_getEntero("\nIngrese dia: ", "\nError", 1, 31, 2, &auxD);
	utn_getEntero("Ingrese mes: ", "\nError", 1, 12, 2, &auxM);
	utn_getEntero("Ingrese año: ", "\nError", 1900, 2020, 2,&auxA);
	for (i = 0; i < sizeElectro; i++){
		if(arrayElectro[i].isEmpty == 0){
			if(reparacion_buscarSerie(arrayReparacion, sizeReparacion, arrayElectro[i].serie, &pos) == 0){
				if(arrayElectro[i].serie == arrayReparacion[pos].serie && arrayReparacion[pos].fecha.dia == auxD && arrayReparacion[pos].fecha.mes == auxM && arrayReparacion[pos].fecha.anio == auxA){
					electro_listar(arrayElectro, i);
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}
