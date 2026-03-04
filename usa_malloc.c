#include <stdio.h>
#include <stdlib.h>

// Uso de malloc
// void  *malloc(size_t size);
// - Retorno en un apuntador / Tamaño en bytes / Reserva de forma dinamica
// - Requiere un apuntador al inicio del objeto de tamaño size
// - No se inicializa
// - El espacio creado para usarse se llama por costumbre nodo cuando
// 		trae un enlace

// Estructura autoreferenciada: 
// Es una estructura que tiene un enlace a si mismo de la definicion de 
// la estructura

struct Nodo {
	int dato; 
	struct Nodo *ptrSig;
};

int main() {
	struct Nodo *ptrRef, *ptrN, *ptrRec, *ptrBas;

	ptrRef = NULL;
	// Cast --┐
	//		  v
	ptrN = (struct Nodo*) malloc(sizeof(struct Nodo));
	printf("Ingresa dato\n");
	scanf("%d", &ptrN->dato);

	// ------------------------------------------------
	ptrRef = ptrN;
	ptrN = (struct Nodo*) malloc(sizeof(struct Nodo));
	printf("Ingrese entero\n");
	scanf("%d", &ptrN->dato);
	ptrN->ptrSig = ptrRef;
	ptrRef = ptrN;

	ptrRec = ptrRef;
	while(ptrRec != NULL) {
		printf("El dato es %d\n", ptrRec->dato);
		ptrRec = ptrRec->ptrSig;
	}

	ptrBas = ptrRef;
	ptrRef = ptrBas -> ptrSig;
	printf("Borrando %d\n", ptrBas->dato);
	free(ptrBas);

	ptrRec = ptrRef;
	while(ptrRec != NULL) {
		printf("El dato es %d\n", ptrRec->dato);
		ptrRec = ptrRec->ptrSig;
	}
}
