#ifndef UTN_H_
#define UTN_H_
#define LEN_ARRAY 4096 //ajustar el len de los arrays de string si se desea tener mayor espacio.
#endif /* UTN_H_ */

/** \brief confirmation function
 * \param message char*
 * \param messageError char*
 * \return int (0) for not.
 * 			   (1) for yes.
 * 			   (-1) Error [message and messageError pointers are NULL].
 **/
int questionConfirm(char* message, char* messageCancel);

/** \brief funcion para crear un menu de opciones.
 * \return int retorna la opcion elegida.
 * */
int menu();

/** \brief se utiliza para pedirle al usuario un numero decimal
 * \param pResultado es la direccion de memoria en donde voy a guardar el numero decimal obtenido
 * \param mensaje es la cadena de caracteres que muestra al inicio de la funcion al usuario
 * \param mensajeError es la cadena de caracteres que se muestra al usuario cuando sucede un error
 * \param min rango minimo del valor ingresado
 * \param max rango maximo del valor ingresado
 * \param reintentos el numero de reintentos para iongresar el numero
 * \return -1 si hay un error y 1 si es un numero.
 */
int getNumberDecimal(float* pResultado, char* mensaje, char* mensajeError, int min,int max, int reintentos);

/** \brief se utiliza para pedirle al usuario un numero
 * \param pResultado es la direccion de memoria en donde voy a guardar el numero obtenido
 * \param mensaje es la cadena de caracteres que muestra al inicio de la funcion al usuario
 * \param mensajeError es la cadena de caracteres que se muestra al usuario cuando sucede un error
 * \param min rango minimo del valor ingresado
 * \param max rango maximo del valor ingresado
 * \param reintentos el numero de reintentos para iongresar el numero
 * \return -1 si hay un error y 1 si es un numero.
 */
int getNumber (int* pResultado, char* mensaje, char* mensajeError, int min, int max, int reintentos);

/** \brief se utiliza para ingresar un caracter.
 * \param pResultado es la direccion de memoria en donde voy a guardar el caracter obtenido
 * \param mensaje es la cadena de caracteres que muestra al inicio de la funcion al usuario
 * \param mensajeError es la cadena de caracteres que se muestra al usuario cuando sucede un error
 * \param min rango minimo del caracter ingresado
 * \param max rango maximo del caracter ingresado
 * \param reintentos el numero de reintentos para ingresar el caracter
 * \return -1 si hay un error y 1 si es un caracter.
 */
int getChar (char* pResutlado, char* mensaje, char* mensajeError, char min, char max, int reintentos);

/** \brief se utiliza para ingresar una cadena de caracteres.
 * \param pResultado es la direccion de memoria en donde voy a guardar la cadena de caracteres obtenido
 * \param mensaje es la cadena de caracteres que muestra al inicio de la funcion al usuario
 * \param mensajeError es la cadena de caracteres que se muestra al usuario cuando sucede un error
 * \param min rango minimo de caracteres ingresado
 * \param max rango maximo de caracteres ingresado
 * \param reintentos el numero de reintentos para ingresar la cadena.
 * \return -1 si hay un error y 1 si es una cadena.
 */
int getString (char* cadena, char* mensaje, char* mensajeError, int len, int reintentos);

/**\brief inicializa un array de enteros en un determinado int.
 *\param *pArray array entero
 *\param size tama�o del array
 *\param pValor valor que deseamos inicializar
 *\return 0 no pudo inicializarlo 1 si pudo inicializarlo
*/
int initArrayInt(int* pArray, int size, int pValor);

/**\brief inicializa un array de float en un determinado float.
 *\param *pArray array float
 *\param size tama�o del array
 *\param pValor valor que deseamos inicializar
 *\return 0 no pudo inicializarlo 1 si pudo inicializarlo
*/
int initArrayFloat(float* pArray, int size, float pValor);

/**\brief imrpime un array de string
 *\param *pArray array de string
 *\param size tama�o del array
*/
int printArrayStr (char* pArray, int size);

/**\brief imprime un array INT
 *\param *pArray array
 *\param size tama�o dle array
 *\return -1 no pudo imprimirlo, 0 lo imprimio correctamente
*/
int printArrayInt (int* pArray, int size);

/**\brief imprime un array float
 *\param *pArray array FLOAT
 *\param sizeFloat tama�o del array FLOAT
 *\return -1 si no pudo hacerlo 0 si pudo hacerlo
 */
int printArrayFloat(float *pArrayFloat, int sizeFloat);

/**\brief imprime un array int y un array float
 *\param *pArray array INT
 *\param size tama�o del primer array
 *\param *pArrayFloat array FLOAT
 *\param sizeFloat tama�o del array FLOAT
 */
int printArrayIntFloat(int *pArray, int size, float *pArrayFloat, int sizeFloat);

/**\brief funcion para ordenar dos array INT del mismo tama�o
 *\param *pArray1 primer array
 *\param *pArray2 segundo array
 *\param size tama�o de los array
 *\return -1 si no pudo ordenarlos 0 si pudo ordenarlos
 */
int ordenarArrayInt_2(int* pArrayEdad,int* pArraySalario,int size);

/**\brief funcion para ordenar un array INT con otro float de igual tama�o
 *\param *pArrayInt array INT
 *\param *pArrayFloat array FLOAT
 *\param size tama�o de los arrays
 */
int ordenarArrayIntFloat(int *pArrayInt, float *pArrayFloat, int size);

/**\brief se utiliza para cargar un array de enteros
 *\param *pArray array de INT
 *\param size tama�o del array
 *\param indice valor del indice que quiero cargar
 *\return 0 si no pudo cargarlo 1 si pudo cargarlo
 */
int cargarArrayInt (int* pArray,int size,int indice);

/**\brief saca el promedio de los numeros de un array.
 *\param *pArray primer array int
 *\param size tama�o del primer array
 *\param *pArray2 segundo array int
 *\param size2 tama�o del segundo array
 *\param *pPromedio array de float donde se guardara el promedio
 *\return 0 si no pudo hacerlo 1 si pudo hacerlo
 */
int promedioArray (int* pArray,int size,int* pArray2, int size2,float* pPromedio);

