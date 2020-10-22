#include "electro_marca.h"
#ifndef REPARACION_SERVICIO_CLIENTE_H_
#define REPARACION_SERVICIO_CLIENTE_H_

typedef struct {
	int dia;
	int mes;
	int anio;
} eFecha;

typedef struct {
	int idServicio;
	char descripcion[25];
	int precio;
	int isEmpty;
} eServicio;

typedef struct {
	int idCliente;
	char nombre[25];
	char apellido[25];
	int isEmpty;
} eCliente;

typedef struct {
	int idReparacion;
	int serie;
	int idServicio;
	int idCliente;
	eFecha fecha;
	int isEmpty;
} eReparacion;

#endif /* REPARACION_SERVICIO_CLIENTE_H_ */

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int reparacion_inicializar(eReparacion array[], int size);

/** \brief Busca el primer lugar vacio en un array
* \param array
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int reparacion_buscarEmpty(eReparacion array[], int size, int *posicion);

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int reparacion_alta(eReparacion array[], int size, int *contadorID,
		eElectro arrayElectro[], int sizeElectro, eServicio arrayServicio[],
		int sizeServicio, eCliente arrayCliente[], int sizeCliente);

/** \brief Lista los elementos de un array
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
//int reparacion_listado(eReparacion arrayReparacion[], int sizeReparacion,
		//eServicio arrayServicio[], int sizeServicio, eCliente arrayCliente[],
		//int sizeCliente);

/** \brief  Hardcodeo
* \param array
* \param size int Array length
*
*/
void reparacion_hardcodear(eReparacion array[], int size);

/** \brief Lista los elementos de un array
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int reparacion_listar(eReparacion array[], int size);

//------------------------------------------------------------------------------------------------------------------------

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int servicio_inicializar(eServicio array[], int size);

/** \brief  Hardcodeo
* \param array
* \param size int Array length
*
*/
void servicio_hardcodear(eServicio array[], int size);

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int servicio_buscarID(eServicio array[], int size, int valorBuscado,
		int *posicion);

/** \brief Lista los elementos de un array
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int servicio_listado(eServicio array[], int size);

//------------------------------------------------------------------------------------------------------------------------

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int cliente_inicializar(eCliente array[], int size);

/** \brief  Hardcodeo
* \param array
* \param size int Array length
*
*/
void cliente_hardcodear(eCliente array[], int size);

/** \brief Lista los elementos de un array
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int cliente_listado(eCliente array[], int size);

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int cliente_buscarID(eCliente array[], int size, int valorBuscado,
		int *posicion);
