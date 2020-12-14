#ifndef ARTICULO_RUBRO_H_
#define ARTICULO_RUBRO_H_

typedef struct{
	int idRubro; //comienza en 1000
	char descripcion[30];  //max 30
	int isEmpty;  //0 ocupado 1 vacio
}Rubro;

typedef struct{
	int idArticulo;
	char articulo[30];
	char medida[12];
	float precio;
	int idRubro;
	int isEmpty;
}Articulo;

#endif /* ARTICULO_RUBRO_H_ */

/** \brief  Hardcodeo
* \param array
* \param size int Array length
*
*/
void rubro_hardcodear(Rubro array[], int size, int *id);

/** \brief Lista los elementos de un array
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int rubro_listado(Rubro array[], int size);

/** \brief Lista un elemento de un array
* \param array
* \param pos posicion dentro del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
void rubro_listar(Rubro array[], int pos);

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int rubro_buscarID(Rubro array[], int size, int valorBuscado,
		int *posicion);

/////////////////////////////////////////////////////////////////////

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int articulo_inicializar(Articulo array[], int size);

/** \brief Busca el primer lugar vacio en un array
* \param array
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int articulo_buscarEmpty(Articulo array[], int size, int *posicion);

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int articulo_buscarID(Articulo array[], int size, int valorBuscado,
		int *posicion);

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int articulo_alta(Articulo array[], int size, int *id,
		Rubro arrayRubro[], int sizeRubro);

/** \brief Lista los elementos de un array
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int articulo_listado(Articulo array[], int size, Rubro arrayRubro[], int sizeRubro);

/** \brief Lista un elemento de un array
* \param array
* \param pos posicion dentro del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
void articulo_listar(Articulo array[], int pos, Rubro arrayRubro[], int posRubro);

/** \brief Borra un elemento del array por ID
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int articulo_baja(Articulo array[], int size, Rubro arrayRubro[], int sizeRubro);

/** \brief Busca un elemento por ID y modifica sus campos
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int articulo_modificar(Articulo array[], int size, Rubro arrayRubro[],
		int sizeRubro);

/** \brief Ordena los elementos de un array
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int articulo_ordenar(Articulo array[], int size);
