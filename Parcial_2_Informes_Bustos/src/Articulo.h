#ifndef ARTICULO_H_
#define ARTICULO_H_

typedef struct{
	int id;
	char articulo[64];
	float precio;
	char medida[16];
	int rubroId;
}eArticulo;


#endif /* ARTICULO_H_ */

/*
 *\brief create a new article by reserving dynamic memory
 *\return eArticulo* if ok
 *\return NULL if haven't memory.
 *
 */
eArticulo* articulo_new();

/*
 *\brief create a new article with parameters.
 *\param idStr char*
 *\param articuloStr char*
 *\param precioStr char*
 *\param medidaStr char*
 *\param rubroIdStr char*
 *\return newArticulo eArticulo*
 */
eArticulo* articulo_newParametros(char* idStr, char* articuloStr, char* precioStr, char* medidaStr, char* rubroIdStr);

/*
 *	\brief  set id of the article.
 *	\param this eArticulo*
 *	\param id int
 *	\return int (-1) Error [this pointer is NULL]
 *				(0) Is ok.
 */
int articulo_setId(eArticulo* this, int id);

/*
 *	\brief  get id of the article.
 *	\param this eArticulo*
 *	\param id int*
 *	\return int (-1) Error [this and id pointers are NULL]
 *				(1) Is ok.
 */
int articulo_getId(eArticulo* this, int* id);

/*
 *	\brief  set name of the article.
 *	\param this eArticulo*
 *	\param articulo char*
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_setArticulo(eArticulo* this, char* articulo);

/*
 *	\brief  get name of the article.
 *	\param this eArticulo*
 *	\param articulo char*
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_getArticulo(eArticulo* this, char* articulo);

/*
 *	\brief  set price of the articles.
 *	\param this eArticulo*
 *	\param precio float
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_setPrecio(eArticulo* this, float precio);

/*
 *	\brief  get price of the articles.
 *	\param this eArticulo*
 *	\param precio float*
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_getPrecio(eArticulo* this, float* precio);

/*
 *	\brief  set measurement of the article.
 *	\param this eArticulo*
 *	\param medida char*
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_setMedida(eArticulo* this, char* medida);

/*
 *	\brief  get measurement of the article.
 *	\param this eArticulo*
 *	\param medida char*
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_getMedida(eArticulo* this, char* medida);

/*
 *	\brief  set entry id of the articles.
 *	\param this eArticulo*
 *	\param rubroId int
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_setRubrioId(eArticulo* this, int rubroId);

/*
 *	\brief  get entry id of the articles.
 *	\param this eArticulo*
 *	\param rubroId int*
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_getRubroId(eArticulo* this, int* rubroId);

/*
 *	\brief  get name by entry of the article.
 *	\param this eArticulo*
 *	\param rubroId char*
 *	\return int (-1) Error [this and name pointers are NULL]
 *				(1) Is ok.
 */
int articulo_getRubroChar(eArticulo* this, char* rubroId);

/*
 *	\brief  print an article.
 *	\param this eArticulo*
 *	\param rubroId int
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_printArticle(eArticulo* this);

/* \brief sort employees by id.
 * \param employee1 void*
 * \param employee2 void*
 * \return int (0) [employee1 and employee2 pointers are NULL or equal]
 *			   (1) [employee1 is higher than employee2].
 *			   (-1)[employee2 is higher than emploee1].
 */
int sortByArticle(void* article1, void* article2);

/*\brief calcula el descuento del precio de los articulos segun el rubro
 * \param articulo void*
 *
 */
void articulo_discount(void *articulo);

/*
 *\brief devuelve la cantidad de articulos con el precio mayor a 100
 *\param pArticle void*
 *\return int (0) si el articulo es NULL o el precio es menos a 100.0
 *			  (1) si el precio dle articulo es mayor a 100.0
 */
int articulo_masDe100(void* pArticle);

/*
 *\brief devuelve la cantidad de articulos del rubroId 1
 *\param pArticle void*
 *\return int (0) si el articulo es NULL o el rubroId es distinto de 1.
 *			  (1) si el articulo es del rubroId 1.
 */
int articulo_cantidadRubro1(void* pArticle);

/*
 *
 *
 */
void articulo_delete(eArticulo* this);
