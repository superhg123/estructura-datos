#include <stdio.h>
#include <stdlib.h>
#define BANDERA -1000


struct Nodo {
	int dato;
	struct Nodo *ptrSig;
};

int iniciarNodo(struct Nodo **ptr) {
	*ptr = (struct Nodo*) malloc(sizeof(struct Nodo));
	(*ptr)->dato = BANDERA;
	(*ptr)->ptrSig = NULL;
}

struct Nodo* agregarNodo(struct Nodo *ptr) {
	return (struct Nodo*) malloc(sizeof(struct Nodo));
}

int agregarDato(struct Nodo **ptr, int dato) {
	struct Nodo *ptrNew = agregarNodo(*ptr);
	ptrNew->dato = dato;
	ptrNew->ptrSig = *ptr;
	*ptr = ptrNew;
	return 0;
}

int recorrerArreglo(struct Nodo *ptr) {
	for(struct Nodo *ptrRec = ptr; ptrRec != NULL; ptrRec = ptrRec->ptrSig) {
		printf("[%d]->",ptrRec->dato);
	}
	printf("\n");
	return 0;
}

int sacarDato(struct Nodo *ptr) {
	struct Nodo *ptrRet = ptr;
	struct Nodo *ptrAv = ptrRet->ptrSig;
	for(;  ptrAv->ptrSig != NULL; ptrRet = ptrAv, ptrAv = ptrAv->ptrSig);
	printf("El dato es: %d\n", ptrAv->dato);
	free(ptrAv);
	if(ptrRet != NULL) {
		ptrRet->ptrSig = NULL;
	}
	return 0;
}

int main() {
	struct Nodo nodo, *ptrRef;
	ptrRef = &nodo;
	iniciarNodo(&ptrRef);
	for(int i = 0; i < 10; i++) {
		agregarDato(&ptrRef, i*i - i);
	}
	recorrerArreglo(ptrRef);
	sacarDato(ptrRef);
	sacarDato(ptrRef);
	recorrerArreglo(ptrRef);
	return 0;
}
