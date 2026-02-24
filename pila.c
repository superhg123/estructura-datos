#include <stdio.h>
#define TAM 5

// Estructura de datos:
// - Lineales
// 	- Pila
// 	- Cola
// 	- Lista
// - No lineales
// 	- Arboles
// 	-Grafos
// Pila (Stack) Last in - First Out (LIFO)
// 	Eliminar - (POP)
// 	Meter - (PUSH)
// 	Aux - estaVacia (0 / 1)
// 	Aux - estaLlena (0 / 1)
// 	El elemento cima (El ultimo) ( TOP )
// 	Ameral - Data structures in C


// Pila de enteros

struct Pila {
	int arreglo[TAM];
	int* ptrC;
};

int meterPila(struct Pila *ptrP, int dato) {
	*ptrP -> ptrC = dato;
	ptrP -> ptrC += 1;
	return 0;
}

int estaPilaLlena(struct Pila *ptrP) {
	if(ptrP->ptrC == &ptrP->arreglo[TAM])
		return 1;
	else 
		return 0;
}

// Dato recuperado
int sacarPila(struct Pila *ptrP) {
	ptrP -> ptrC -= 1;
	int datoRecuperado = *ptrP -> ptrC;
	return datoRecuperado;
}

int estaPilaVacia(struct Pila *ptrP) {
	if(ptrP -> ptrC == ptrP -> arreglo)
		return 1;
	else 
		return 0;
}

int main() {
	struct Pila pila, *miptrP;
	int miDato;
	
	miptrP = &pila;
	miptrP -> ptrC = miptrP -> arreglo;
	

	return 0;
}
