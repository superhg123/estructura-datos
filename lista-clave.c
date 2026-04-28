#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dato {
	char nombre[30];
	int edad;
};

struct Nodo {
	struct Dato dato;
	char* clave;
	struct Nodo *ptrSig, *ptrAnt;
};

struct Nodo* crearNodo() {
	return (struct Nodo*) calloc(1, sizeof(struct Nodo));
}

int vaAntes(char* texto1, char* texto2) {
	for(;;) {

		if(*texto1 < *texto2) {
			return 1;
		}

		if(*texto1 > *texto2) {
			return 0;
		}

		if(*texto1 == '\0' || *texto2 == '\0') {
			return 2;
		}

		*texto1++;
		*texto2++;
	}
	return 0;
}

int agregarNodo(struct Nodo **ptrList, struct Dato dato, char* clave) {
	struct Nodo *ptrNew = crearNodo();
	strcpy(ptrNew->dato.nombre, dato.nombre);
	ptrNew->dato.edad = dato.edad;
	ptrNew->clave = strdup(clave);

	if(*ptrList == NULL) {
		*ptrList = ptrNew;
		return 0;
	}

	if((*ptrList)->ptrSig == NULL) {
		if(vaAntes(clave, (*ptrList)->clave)) {
			(*ptrList)->ptrAnt = ptrNew;
			ptrNew->ptrSig = *ptrList;
			*ptrList = ptrNew;
		} else {
			(*ptrList)->ptrSig = ptrNew;
			ptrNew->ptrAnt = *ptrList;
		}
		return 0;
	}

	int amntRec = 0;
	struct Nodo *ptrRec = *ptrList;
	for(; ptrRec->ptrSig != NULL; ptrRec = ptrRec->ptrSig) {
		if(vaAntes(clave, ptrRec->clave)) {
			break;
		}
		amntRec++;
	}

	if(amntRec == 0) {
		ptrNew->ptrSig = ptrRec;
		ptrRec->ptrAnt = ptrNew;
		*ptrList = ptrNew;
		return 0;
	}

	if(ptrRec->ptrSig == NULL && vaAntes(ptrRec->clave, clave)) {
		ptrRec->ptrSig = ptrNew;
		ptrNew->ptrAnt = ptrRec;
		return 0;
	}

	struct Nodo *ptrPiv = ptrRec->ptrAnt;
	ptrPiv->ptrSig = ptrNew;
	ptrNew->ptrSig = ptrRec;
	ptrRec->ptrAnt = ptrNew;
	ptrNew->ptrAnt = ptrPiv;
	return 0;
}

int recorrerLista(struct Nodo **ptrList) {
	printf("Recorrido por claves\n");
	for(struct Nodo *ptr = *ptrList; ptr != NULL; ptr = ptr->ptrSig) {
		printf("[%s]->", ptr->clave);
	}
	return 0;
}

int main() {


	printf("%s", "Si se crearon los datos\n");
	struct Nodo *ptr = crearNodo();
	struct Dato *dato = (struct Dato*) malloc(sizeof(struct Dato));
	strcpy(dato->nombre, "Hugo");
	dato->edad = 18;

	for(int i = 0; i < 5; i++) {
		
		char* texto;
		sprintf(texto, "%d", dato->edad);
		agregarNodo(&ptr, *dato, texto);
	}
}
