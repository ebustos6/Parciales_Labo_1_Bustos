#ifndef VENTA_CLIENTE_H_
#define VENTA_CLIENTE_H_

typedef struct{
	int dia;
	int mes;
	int anio;
}Fecha;

typedef struct{
	int idCliente;
	char nombre[25];
	char telefono[12];
	int isEmpty;
}Cliente;

typedef struct{
	int idVenta;  //empieza en 20000
	int idCliente;  //validar existencia
	int idArticulo;  //validar existencia
	int cantidad;
	float precioTotal;
	Fecha fecha;  //validar dia, mes y año
	int isEmpty;
}Venta;

#endif /* VENTA_CLIENTE_H_ */

/** \brief  Hardcodeo
* \param array
* \param size int Array length
*
*/
void cliente_hardcodear(Cliente array[], int size, int *id);

/** \brief Lista los elementos de un array
* \param array
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int cliente_listado(Cliente array[], int size);

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int cliente_buscarID(Cliente array[], int size, int valorBuscado,
		int *posicion);
/////////////////////////////////////////////////////////////////////////////

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int venta_inicializar(Venta array[], int size);

/** \brief Busca el primer lugar vacio en un array
* \param array
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int venta_buscarEmpty(Venta array[], int size, int *posicion);
