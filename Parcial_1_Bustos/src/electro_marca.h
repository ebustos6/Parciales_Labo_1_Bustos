#ifndef ELECTRO_MARCA_H_
#define ELECTRO_MARCA_H_

typedef struct {
	int idMarca;
	char descripcion[20];
	int isEmpty;
} eMarca;

typedef struct {
	int idElectro;
	int serie;
	int idMarca;
	int modelo;
	int isEmpty;
} eElectro;

#endif /* ELECTRO_MARCA_H_ */

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int electro_inicializar(eElectro array[], int size);

/** \brief Busca el primer lugar vacio en un array
* \param array
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int electro_buscarEmpty(eElectro array[], int size, int *posicion);

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int electro_alta(eElectro array[], int size, int *contadorID,
		eMarca arrayMarca[], int sizeMarca);

/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int electro_buscarSerie(eElectro array[], int size, int valorBuscado,
		int *posicion);

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int electro_buscarID(eElectro array[], int size, int valorBuscado,
		int *posicion);

/** \brief Borra un elemento del array por ID
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int electro_baja(eElectro array[], int sizeArray);

/** \brief Lista los elementos de un array
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int electro_listado(eElectro array[], int size);

/** \brief Busca un elemento por ID y modifica sus campos
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int electro_modificar(eElectro array[], int sizeArray, eMarca arrayMarca[],
		int sizeMarca);

/** \brief  Hardcodeo
* \param array
* \param size int Array length
*
*/
void electro_hardcodear(eElectro array[], int size);
int electro_ordenar(eElectro array[], int size);

//------------------------------------------------------------------------------------------------------------------------

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int marca_inicializar(eMarca array[], int size);

/** \brief  Hardcodeo
* \param array
* \param size int Array length
*
*/
void marca_hardcodear(eMarca array[], int size);

/** \brief Lista los elementos de un array
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int marca_listado(eMarca array[], int size);

