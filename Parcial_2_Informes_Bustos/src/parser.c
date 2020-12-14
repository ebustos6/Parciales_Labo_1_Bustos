#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "utn.h"
#include "Articulo.h"


FILE* openFileFromText(){
	FILE* file;
	char path[32];
	getString(path,"Ingrese el nombre del archivo: ","Error, nombre incorrecto, no se olvide de agregarle .csv",32,2);
	file = fopen(path, "r");
	if (file == NULL) {
		printf("No se pudo abrir el archivo.\n");
	}
	return file;
}


int parser_articlesFromText(FILE *pFile, LinkedList *this) {
	int ret = -1;
	eArticulo *newArticle;
	char buffer[5][40];
	int count;
	if (pFile != NULL && this != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],
				buffer[1], buffer[2], buffer[3], buffer[4]);
		while (!feof(pFile)) {
			count = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
			if (count < 5) {
				ret = -1;
				printf("No se pudo leer un articulo\n");
				break;
			}
			newArticle = articulo_newParametros(buffer[0], buffer[1], buffer[3], buffer[2], buffer[4]);
			if(newArticle != NULL){
				ll_add(this, (eArticulo*)newArticle);
				ret = 1;
			}
		}

	}

	return ret;
}


FILE* writeFileFromText(char* path){

	FILE* file;
		file = fopen(path,"w");
		if(file == NULL){
			printf("El archivo no se puede abrir en modo escritura");
		}
	return file;
}


int fprintfArticle (eArticulo* this, FILE* pFile){
	int ret = -1;
	int bufferId;
	char bufferArticulo[64];
	float bufferPrecio;
	char bufferMedida[16];
	int bufferRubroId;
	if(this != NULL && pFile != NULL){
		articulo_getId(this,&bufferId);
		articulo_getArticulo(this,bufferArticulo);
		articulo_getPrecio(this,&bufferPrecio);
		articulo_getMedida(this,bufferMedida);
		articulo_getRubroId(this,&bufferRubroId);

		fprintf(pFile,"%d,%s,%.0f,%s,%d\n",bufferId,bufferArticulo,bufferPrecio,bufferMedida,bufferRubroId);
		ret = 1;
	}
	return ret;
}


int saveAsText(FILE *pFile, LinkedList *this) {
	int ret = -1;
	eArticulo* auxArticulo;
	int i;
	int lenLL = ll_len(this);
	if(pFile != NULL && this != NULL){
		fprintf(pFile,"id,articulo,precio,medida,rubroId\n");
		for(i=0;i<lenLL;i++){
			auxArticulo = ll_get(this,i);
			if(auxArticulo != NULL){
				fprintfArticle(auxArticulo,pFile);
				ret = 1;
			}
		}
	}
	return ret;
}
