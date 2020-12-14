/*
 ============================================================================
 Name        : Parcial_2_Informes_Bustos.c
 Author      : Emanuel Bustos
 ============================================================================
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "LinkedList.h"
#include "utn.h"

#define PATH_SAVE "mapeado.csv"

int main(void) {
	setbuf(stdout, NULL);
	LinkedList* articlesList = ll_newLinkedList();
	int option;
	do{
		option = menu();
		switch(option){
		case 1:
			controller_readFromFile(articlesList);
			break;
		case 2:
			controller_sortArticles(articlesList);
			break;
		case 3:
			controller_listArticles(articlesList);
			break;
		case 4:
			controller_calculateDiscount(articlesList);
			break;
		case 5:
			controller_saveOnFile(articlesList,PATH_SAVE);
			break;
		case 6:
			controller_reports(articlesList);
			break;
		case 7:
			printf("2do Parcial Emanuel Bustos");
			break;
		}
	}while(option!=7);
	ll_clear(articlesList);
	ll_deleteLinkedList(articlesList);
	return 0;
}
