#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int dato;
	struct nodo *ptrSig;	
};

struct nodo *crearNodo() {
	struct nodo *ptrN;
	ptrN = (struct nodo*) malloc(sizeof(struct nodo));
	return ptrN;
}

int meterDato(struct nodo **ptrRef, int dato) {
	struct nodo *ptrN = crearNodo();
	ptrN->dato = dato;
	ptrN->ptrSig = *ptrRef;
	*ptrRef = ptrN;
	return 1;
}


int sacarDato(struct nodo **ptrRef) {
	if(*ptrRef == NULL) {
		return 0;
	}
	int datoRec = (*ptrRef)->dato;
	struct nodo *ptrBas;
	ptrBas = *ptrRef;
	*ptrRef = (*ptrRef) -> ptrSig;
	free(ptrBas);
	return datoRec;
}

int imprimirContenido(struct nodo *ptrRef) {
	for(struct nodo *ptrRec = ptrRef; ptrRec != NULL; ptrRec = ptrRec -> ptrSig) {
		printf("El dato es %d\n", ptrRec->dato);
	}
	return 0;
}

int menu() {
	int dato;
	printf("Programa de pilas dinamicas\n");
	printf("1.- Para meter dato");
	printf("2.- Para sacar dato");
	printf("3.- Para recorrer arreglo");
	scanf("%d", &dato);
	return dato;	
}

int main() {
}
