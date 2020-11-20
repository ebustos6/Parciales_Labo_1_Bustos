#ifndef UTN_H_
#define UTN_H_

/*
 * \brief Lee un string hasta '\n' o hasta - 1
 * \param cadena Puntero a la direccion de memoria donde se va a copiar el string
 * \param tamaño del string
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int utn_myGets(char *input, int size);
//------------------------------------------------------------------------------------------------------------------------
/*
 * \brief Toma un int
 * \param Mensaje
 * \param Mensaje de error
 * \param Valor minimo
 * \param Valor maximo
 * \param Reintentos
 * \param Direccion de memoria donde se guardara el entero
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int utn_getEntero(char *msg, char *msgError, int minimo, int maximo,
		int reintentos, int *input);

/*
 * \brief Obtiene un int
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int utn_getInt(int *input);

/*
 * \brief Recibe un string y lo valida
 * \param input string a evaluar
 * \param size tamaño del string
 * \return int (1) if OK y (0) if Error
 *
 */
int isValidNumbers(char *input, int size);
//------------------------------------------------------------------------------------------------------------------------
/*
 * \brief Toma un float
 * \param Mensaje
 * \param Mensaje de error
 * \param Valor minimo posible
 * \param Valor maximo posible
 * \param Cantidad de intentos para ingresar el dato correctamente
 * \param Direccion de memoria donde se guardara el flotante
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int utn_getFlotante(char *msg, char *msgError, float minimo,
		float maximo, int reintentos, float *input);

/*
 * \brief Obtiene un float
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int utn_getFloat(float *input);

/*
 * \brief Recibe un string y lo valida
 * \param cadena string a evaluar
 * \param limite tamaño del string
 * \return int (1) if OK y (0) if Error
 *
 */
int isValidFloatNumber(char *input, int size);

//------------------------------------------------------------------------------------------------------------------------
/*
 * \brief Toma una cadena por teclado y la devuelve
 * \param Mensaje
 * \param Mensaje de error
 * \param Valor minimo
 * \param Valor maximo
 * \param Reintentos
 * \param Direccion de memoria donde se guardara la cadena
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int utn_getCadena(char *msg, char *msgError, int minimo, int maximo,
		int reintentos, char *input);

//------------------------------------------------------------------------------------------------------------------------

#endif /* UTN_H_ */
