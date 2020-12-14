#include "Articulo.h"
#include "LinkedList.h"

/* \brief loads the articles from file in text mode
 *	\papram this LinkedList*
 *	\return int (-1) Error [path pointer and pList pointer are NULL]
 * 				(1) is ok
 */
int controller_readFromFile(LinkedList* this);

/* \brief sort the articles from LinkedList
 *	\papram this LinkedList*
 *	\return int (-1) Error [pList pointer are NULL or lenLL equal than 0]
 * 				(1) is ok
 */
int controller_sortArticles(LinkedList* this);

/* \brief list and print the articles from LinkedList
 *	\param this LinkedList*
 *	\return int (-1) Error [pList pointer are NULL or lenLL equal than 0]
 * 				(1) is ok
 */
int controller_listArticles(LinkedList* this);

/* \brief calculate an discount on articles from LinkedList
 *	\param this LinkedList*
 *	\return int (-1) Error [pList pointer are NULL or lenLL equal than 0]
 * 				(1) is ok
 */
int controller_calculateDiscount(LinkedList* this);

/* \brief saves the articles to a file in text mode
 *	\param this LinkedList*
 *	\return int (-1) Error [path pointer and pList pointer are NULL or lenLL equal than 0]
 * 				(1) is ok
 */
int controller_saveOnFile(LinkedList* this,char* path);

/*	\brief generates reports from the list of articles.
 *  \param this LinkedList*
 *	\return int (-1) Error [pList pointer are NULL or lenLL equal than 0]
 * 				(1) is ok
 */
int controller_reports(LinkedList* this);

/** \brief print all articles from Linkedlist.
 *
 * \param this LinkedList*
 * \param lenList int
 * \return int (-1) Error [pList pointer are NULL or lenList less than 0]
 * 				(1) is ok
 *
 */
int controller_printAllArticles (eArticulo* this , int lenList);

