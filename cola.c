#include <stdio.h>
#include <stdlib.h>
#define TAM 10

// Cola estatica
// First in - First out
// Como la cola de las tortillas


struct Cola {
	int arreglo[TAM];
	int *ptrM, *ptrS;
};

int meterCola(struct Cola *ptrC, int dato) {
	*ptrC->ptrM = dato;
	ptrC->ptrM += 1;
	return 0;
}

int sacarCola(struct Cola *ptrC) {
	int datoRec;
	datoRec = *ptrC -> ptrS;
	ptrC -> ptrS += 1;
	return datoRec;
}

int estaColaLlena(struct Cola *ptrC) {
	return ptrC->ptrM == &ptrC -> arreglo[TAM];
}

int estaColaVacia(struct Cola *ptrC) {
	return ptrC->ptrM == ptrC->ptrS;
}

int resetearCola(struct Cola *ptrC) { 
	ptrC->ptrS = ptrC->arreglo;
	ptrC->ptrM = ptrC->arreglo;
}


int main() {
	struct Cola cola, *ptrC;
	int miDato;
	ptrC = &cola;
	resetearCola(ptrC);
}
