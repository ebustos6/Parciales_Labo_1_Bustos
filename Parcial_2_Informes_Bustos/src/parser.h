#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
#include "Articulo.h"
#include <stdio.h>



#endif /* PARSER_H_ */

/** \brief opens a text file in read mode by entering the file name of the by command line.
 *
 * \return FILE*
 *
 */
FILE* openFileFromText();

/** \brief Parse data employee data from file (text mode).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) Error [pFile pointer and pArrayListEmployee are NULL or fscanf can't read the file]
 * 				(1) is ok.
 *
 */
int parser_articlesFromText(FILE* pFile , LinkedList* this);

/**\brief opens file from text in write mode.
 *
 * \param path char*
 * \return FILE*
 *
 */
FILE* writeFileFromText(char* path);

/** \brief save information in the file.
 *	\param pFile FILE*
 *	\param pArrayListEmployee LinkedList*
 *	\return (-1) Error [pFile and pList pointers are NULL].
 *			(1)Is ok.
 */
int saveAsText(FILE *pFile, LinkedList *this);

/*  \brief write all articles in text mode.
 *	\param pFile FILE*
 *	\param pArrayListEmployee LinkedList*
 *	\return int (-1) Error [pFile and eArticulo pointers are NULL].
 *			(1)Is ok.
 */
int fprintfArticle (eArticulo* this, FILE* pFile);
