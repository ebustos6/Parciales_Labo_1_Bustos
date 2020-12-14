#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "venta_cliente.h"
#include "articulo_rubro.h"
#include "utn.h"

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int controller_altaArticulo(Articulo arrayArticulo[], int sizeArticulo,
		Rubro arrayRubro[], int sizeRubro, int *id, int *contArt);

/** \brief Busca un elemento por ID y modifica sus campos
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int controller_modificarArticulo(Articulo arrayArticulo[], int sizeArticulo,
		Rubro arrayRubro[], int sizeRubro, int contArt);

/** \brief Borra un elemento del array por ID
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int controller_bajaArticulo(Articulo arrayArticulo[], int sizeArticulo,
		Rubro arrayRubro[], int sizeRubro, int *contArt);

/** \brief Lista y ordena los elementos de un array
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int controller_listadoArticulo(Articulo arrayArticulo[], int sizeArticulo,
		Rubro arrayRubro[], int sizeRubro, int contArt);

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int controller_altaVenta(Venta array[], int size, int *id,
		Cliente arrayCliente[], int sizeCliente, Articulo arrayArticulo[],
		int sizeArticulo, Rubro arrayRubro[], int sizeRubro, int contArt,
		int *contVta);

/** \brief Lista los elementos de un array
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int controller_listadoVenta(Venta array[], int size, Cliente arrayCliente[],
		int sizeCliente, Articulo arrayArticulo[], int sizeArticulo,
		int contArt, int contVta);

/** \brief Lista un elemento de un array
* \param array
* \param pos posicion dentro del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
void controller_listarVenta(Venta array[], int pos, Cliente arrayCliente[],
		int posCliente, Articulo arrayArticulo[], int posArticulo);

/** \brief Lista los elementos de un array con un criterio determinado
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int controller_listarArticulosRubro(Articulo array[], int size,
		Rubro arrayRubro[], int sizeRubro);

/** \brief Lista los elementos de un array con un criterio determinado
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int controller_listarVentasCliente(Venta array[], int size,
		Cliente arrayCliente[], int sizeCliente, Articulo arrayArticulo[],
		int sizeArticulo);

/** \brief Suma los elementos de un array con un criterio determinado
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int controller_sumarVentasArticulo(Venta array[], int size,
		Articulo arrayArticulo[], int sizeArticulo, Rubro arrayRubro[],
		int sizeRubro);

/** \brief Suma los elementos de un array con un criterio determinado
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int controller_sumarVentasCliente(Venta array[], int size,
		Cliente arrayCliente[], int sizeCliente, Articulo arrayArticulo[],
		int sizeArticulo);

/** \brief Llama a todas las funciones de los informes
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int controller_informes(Venta arrayVenta[], int sizeVenta,
		Cliente arrayCliente[], int sizeCliente, Articulo arrayArticulo[],
		int sizeArticulo, Rubro arrayRubro[], int sizeRubro, int contArt,
		int contVta);

#endif /* CONTROLLER_H_ */
