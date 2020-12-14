#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "Articulo.h"
#include "parser.h"


int controller_printAllArticles (LinkedList* this , int lenList){
	int ret = -1;
	int i;
	eArticulo* aux;
	if(this != NULL && lenList > 0){
		for(i = 0; i <lenList; i++){
			aux = ll_get(this,i);
			if(aux != NULL){
				articulo_printArticle(aux);
				ret = 1;
			}
		}
	}else{
		printf("Primero debe cargar los articulos\n");
	}
	return ret;
}


int controller_readFromFile(LinkedList* this){
	int ret = -1;
	FILE* file = openFileFromText();
	if(file != NULL){
		if(parser_articlesFromText(file,this)){
			ret = 1;
		}
	}

	if(ret == 1){
		printf("Se han cargado los archivos exitosamente!\n");
	}

	return ret;
}


int controller_listArticles(LinkedList* this) {
	int ret = -1;
	int lenLL = ll_len(this);
	if (this != NULL && lenLL >0) {
		if (controller_printAllArticles(this, lenLL)) {
			ret = 1;
		}
	}else{
		printf("Primero debe cargar los articulos\n");
	}
	return ret;
}


int controller_sortArticles(LinkedList* this){
	int ret = -1;
	int lenLL = ll_len(this);
	if(this != NULL && lenLL >2){
		if(!ll_sort(this,sortByArticle,1)){
			ret = 1;
		}
	}else{
		printf("Primero debe cargar los articulos\n");
	}

	if(ret == 1){
		printf("Los articulos se han ordenado correctamente\n");
	}

	return ret;
}


int controller_calculateDiscount(LinkedList* this){
	int ret = -1;
	int lenLL = ll_len(this);
	if(this != NULL && lenLL > 0){
		if(ll_map(this,articulo_discount)!= NULL){
			ret = 1;
		}
	}else{
		printf("Primero debe cargar los articulos\n");
	}

	if(ret == 1){
		printf("Se han calculado los descuentos exitosamente!\n");
	}

	return ret;
}


int controller_saveOnFile(LinkedList* this,char* path){
	int ret = -1;
	FILE* file;
	int lenLL = ll_len(this);
	if(this != NULL && path != NULL && lenLL >0){
		file = writeFileFromText(path);
		if(file != NULL){
			if(saveAsText(file,this)){
				ret = 1;
			}
		}
	}else{
		printf("Primero debe cargar los articulos\n");
	}

	if(ret == 1){
			printf("Se ha guardado exitosamente!\n");
		}

	return ret;
}


int controller_reports(LinkedList* this){
	int ret = -1;
	int informe1;
	int informe2;
	int lenLL = ll_len(this);
	if(this != NULL && lenLL >0){
		informe1 = ll_count(this,articulo_masDe100);
		informe2 = ll_count(this,articulo_cantidadRubro1);
		printf("Informe de articulos\n");
		printf("*****************************\n");
		printf("- Cantidad de articulos cuyo precio es mayor a $100  : %d\n",informe1);
		printf("- Cantidad de articulos del rubro 1 - CUIDADO PARA LA ROPA  : %d\n",informe2);
		printf("*****************************\n");
		ret = 1;
	}else{
		printf("Primero debe cargar los articulos\n");
	}
	return ret;
}
