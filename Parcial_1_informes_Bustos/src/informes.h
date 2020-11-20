#include "electro_marca.h"
#include "reparacion_servicio_cliente.h"

#ifndef INFORMES_H_
#define INFORMES_H_

/** \brief lista todos los electrodomesticos modelo 2020
* \param array Electro
* \param size int Tamaño del array
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int electro_listar_2020(eElectro array[], int sizeElectro);

/** \brief pide una marca y lista los electrodomesticos que pertenecen a ella
* \param array Electro
* \param size int Tamaño del array Electro
* \param array Marca
* \param size int Tamaño del array Marca
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int electro_listar_marca(eElectro arrayElectro[], int sizeElectro, eMarca arrayMarca[], int sizeMarca);

/** \brief pide un electrodomestico y lista sus reparaciones
* \param array Electro
* \param size int Tamaño del array Electro
* \param array Reparacion
* \param size int Tamaño del array Reparacion
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int electro_listar_reparaciones(eElectro arrayElectro[], int sizeElectro, eReparacion arrayReparacion[], int sizeReparacion);

/** \brief lista los electrodomesticos sin reparaciones
* \param array Electro
* \param size int Tamaño del array Electro
* \param array Reparacion
* \param size int Tamaño del array Reparacion
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int electro_listar_sinReparaciones(eElectro arrayElectro[], int sizeElectro, eReparacion arrayReparacion[], int sizeReparacion);

/** \brief pide un electrodomestico y suma sus reparaciones
* \param array Electro
* \param size int Tamaño del array Electro
* \param array Reparacion
* \param size int Tamaño del array Reparacion
* \param array Servicio
* \param size int Tamaño del array Servicio
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int electro_sumar_reparaciones(eElectro arrayElectro[], int sizeElectro, eReparacion arrayReparacion[], int sizeReparacion, eServicio arrayServicio[], int sizeServicio);

/** \brief cuenta un servicio e informa cuantas veces aparece
* \param array Reparacion
* \param size int Tamaño del array Reparacion
* \param array Servicio
* \param size int Tamaño del array Servicio
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int servicio_masPedido(eReparacion arrayReparacion[], int sizeReparacion, eServicio arrayServicio[]);

/** \brief pide una fecha y suma los montos de las reparaciones de ese dia
* \param array Reparacion
* \param size int Tamaño del array Reparacion
* \param array Servicio
* \param size int Tamaño del array Servicio
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int reparacion_recaudacionFecha(eReparacion arrayReparacion[], int sizeReparacion, eServicio arrayServicio[], int sizeServicio);

/** \brief filtra y lista electrodomesticos segun fecha y garantia
* \param array Electro
* \param size int Tamaño del array Electro
* \param array Reparacion
* \param size int Tamaño del array Reparacion
* \param array Servicio
* \param size int Tamaño del array Servicio
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int electro_garantiaFecha(eElectro arrayElectro[], int sizeElectro, eReparacion arrayReparacion[], int sizeReparacion, eServicio arrayServicio[], int sizeServicio);

/** \brief lista reparaciones de eletrodomesticos modelo 2018
* \param array Reparacion
* \param size int Tamaño del array Reparacion
* \param array Electro
* \param size int Tamaño del array Electro
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int reparacion_electro2018(eReparacion arrayReparacion[], int sizeReparacion, eElectro arrayElectro[], int sizeElectro);

/** \brief filtra los mantenimientos y los suma
* \param array Reparacion
* \param size int Tamaño del array Reparacion
* \param array Servicio
* \param size int Tamaño del array Servicio
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int reparacion_sumaMantenimiento(eReparacion arrayReparacion[], int sizeReparacion, eServicio arrayServicio[], int sizeServicio);

/** \brief cuenta la cantidad de apariciones de una marca que tiene reparaciones y la informa
* \param array Electro
* \param size int Tamaño del array Electro
* \param array Marca
* \param size int Tamaño del array Marca
* \param array Reparacion
* \param size int Tamaño del array Reparacion
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int electro_masMarca(eElectro arrayElectro[], int sizeElectro, eMarca arrayMarca[], int sizeMarca, eReparacion arrayReparacion[], int sizeReparacion);

/** \brief pide una fecha y lista los electrodomesticos que tuvieron reparacion en esa fecha
* \param array Electro
* \param size int Tamaño del array Electro
* \param array Reparacion
* \param size int Tamaño del array Reparacion
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int electro_reparacion_fecha(eElectro arrayElectro[], int sizeElectro, eReparacion arrayReparacion[], int sizeReparacion);

#endif /* INFORMES_H_ */
