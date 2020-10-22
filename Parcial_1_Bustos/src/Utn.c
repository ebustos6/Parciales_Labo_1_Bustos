#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

int utn_myGets(char *input, int size) {
	int retorno = -1;
	char bufferString[99999];

	if (input != NULL && size > 0) {
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			if (bufferString[strlen(bufferString) - 1] == '\n') {
				bufferString[strlen(bufferString) - 1] = '\0';
			}
			if (strlen(bufferString) <= size) {
				strncpy(input, bufferString, size);
				retorno = 0;
			}
		}

	}
	return retorno;
}

//------------------------------------------------------------------------------------------------------------------------
int utn_getEntero(char *msg, char *msgError, int minimo, int maximo,
		int reintentos, int *input) {

	int retorno = -1;
	int buffer;

	do {

		printf("%s", msg);

		if (utn_getInt(&buffer) == 0 && buffer >= minimo
				&& buffer <= maximo) {
			retorno = 0;
			*input = buffer;
			break;
		}

		printf("%s", msgError);
		reintentos--;

	} while (reintentos <= 0);

	return retorno;
}

int isValidNumbers(char *input, int size) {
	int retorno = 1;
	int i;

	for (i = 0; i < size && input[i] != '\0'; i++) {
		if (i == 0 && (input[i] == '+' || input[i] == '-')) {
			continue;
		}
		if (input[i] < '0' || input[i] > '9') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int utn_getInt(int *input) {
	int retorno = -1;
	char buffer[50];

	if (input != NULL
			&& utn_myGets(buffer, sizeof(buffer)) == 0
			&& isValidNumbers(buffer, strlen(buffer))) {
		retorno = 0;
		*input = atoi(buffer);
	}
	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------
int utn_getFlotante(char *msg, char *msgError, float minimo,
		float maximo, int reintentos, float *input) {

	int retorno = -1;
	float buffer;

	do {

		printf("%s", msg);

		if (utn_getFloat(&buffer) == 0 && buffer >= minimo
				&& buffer <= maximo) {
			retorno = 0;
			*input = buffer;
			break;
		}

		printf("%s", msgError);
		reintentos--;

	} while (reintentos <= 0);

	return retorno;
}

int isValidFloatNumber(char *input, int size) {
	int retorno = 1;
	int i;

	for (i = 0; i < size && input[i] != '\0'; i++) {
		if (i == 0 && (input[i] == '+' || input[i] == '-')) {
			continue;
		}
		if ((input[i] < '0' || input[i] > '9') && input[i] != '.') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int utn_getFloat(float *input) {
	int retorno = -1;
	char buffer[50];

	if (input != NULL
			&& utn_myGets(buffer, sizeof(buffer)) == 0
			&& isValidFloatNumber(buffer, strlen(buffer))) {
		retorno = 0;
		*input = atof(buffer);
	}
	return retorno;
}

//------------------------------------------------------------------------------------------------------------------------
int utn_getCadena(char *msg, char *msgError, int minimo, int maximo,
		int reintentos, char *input) {

	int retorno = -1;
	char buffer[101];

	do {

		printf("%s", msg);
		fflush(stdin);
		gets(buffer);

		if (strlen(buffer) >= minimo && strlen(buffer) < maximo) {
			strcpy(input, buffer);
			retorno = 0;
			break;
		}

		printf("%s", msgError);
		reintentos--;

	} while (reintentos <= 0);

	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------



