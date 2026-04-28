#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
	int valor;
	struct Nodo *ptrSig;
};

struct Nodo* crearNodo() {
	return (struct Nodo*) malloc(sizeof(struct Nodo));
}

int agregarNodo(struct Nodo **ptr, int dato) {


	printf("Agregando nodo\n");

	struct Nodo *ptrNew = crearNodo();
	ptrNew->valor = dato;

	if(*ptr == NULL) {
		printf("El ptr actual es nulo, asginando el nuevo al actual\n");
		*ptr = ptrNew;
		return 0;
	}

	if((*ptr)->ptrSig == NULL) {
		printf("Ptr siguiente es nulo, asignando el siguiente a nulo\n");
		if(dato < (*ptr)->valor) {
			ptrNew -> ptrSig = *ptr;
			*ptr = ptrNew;
		} else {
			(*ptr)->ptrSig = ptrNew;	
		}
		printf("%p->%p\n", *ptr, ptrNew);
		return 0;
	}

	struct Nodo *ptrPre = *ptr;
	struct Nodo *ptrPos = ptrPre->ptrSig;

	printf("%p->%p\n",ptrPre, ptrPos);

	int valor = 0;

	printf("Iniciando recorrimiento\n");
	for(; ptrPre->valor <= dato && ptrPos->ptrSig->valor >= dato; ptrPre = ptrPre->ptrSig, ptrPos = ptrPos->ptrSig) {
		printf("%d->{%d?]->%d",ptrPre->valor, dato, ptrPos->valor);
		if(ptrPos == NULL) break;
	}

	printf("Final de recorrimiento\n");

	if(ptrPre->valor == dato || ptrPos->valor == dato)
		return -2;

	if(ptrPos == NULL) {
		ptrPre->ptrSig = ptrNew;
		return 0;
	}

	ptrPre->ptrSig = ptrNew;
	ptrNew->ptrSig = ptrPos;

	return 0;

}

int recorrerArreglo(struct Nodo **ptr) {
	for(struct Nodo *ptrRec = *ptr; ptrRec != NULL; ptrRec = ptrRec->ptrSig) {
		printf("[%d]->", ptrRec->valor);
	}
	printf("\n");
}

int main() {
	struct Nodo **ptr, **ptrPre, *ref;
	ptr = &ref;
	ptrPre = &ref;
	for(int i = 0; i < 4; i++) {
		printf("Ingrese el dato: ");
		int valor;
		scanf("%d",&valor);
		printf("\n");
		agregarNodo(ptr, valor);	
	}
       	recorrerArreglo(ptr);
}
