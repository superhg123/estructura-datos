#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int dato;
	struct Nodo *ptrSig;
};

struct Nodo* crearNodo(int dato1) {
	struct Nodo *ptrNew = (struct Nodo*) malloc(sizeof(struct Nodo));
	ptrNew->dato = dato1;
	return ptrNew;
}

int meterNodo(struct Nodo **ptrRef2, int dato1) {
	struct Nodo *ptrNew;
	ptrNew = crearNodo(dato1);

	if(*ptrRef2 == NULL) {
		*ptrRef2 = ptrNew;
	} else {
		ptrNew->ptrSig = *ptrRef2;
		*ptrRef2 = ptrNew;
	}
	return 0;
}

int recorrerPila(struct Nodo **ptrRef2) {
	for(struct Nodo *ptr = *ptrRef2; ptr != NULL; ptr = ptr->ptrSig) {
		printf("[%d]->", ptr->dato);
	}
	printf("\n");
	return 0;
}

int main() {
	struct Nodo *miPtrRef1, **miPtrRef2;
	miPtrRef1 = NULL;
	miPtrRef2 = &miPtrRef1;
	for(int i = 0; i < 10; i++) {
		meterNodo(miPtrRef2, i);
	}

	recorrerPila(miPtrRef2);
	return 0;
}
