#include <stdio.h>
#include <stdlib.h>
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

int imprimirContenidoPila(struct Pila *ptrP) {
	int* ptr;
	for(ptr = ptrP -> arreglo; ptr < ptrP -> ptrC; ptrP += 1) 
		printf("El elemento de la celda %d es %d\n", ((int) (ptr - ptrP -> arreglo)), *ptr);
	return 0;
}

int menu() {
	int opc;

	printf("1. Para meter en pila\n");
	printf("2. Para sacar de pila\n");
	printf("3. Para imprimir la pila\n");
	printf("4. Para salir\n");
	printf("Ingrese opcion\n");
	scanf("%d", &opc);
	return opc;
}

int main() {
	struct Pila pila, *miptrP;
	int miDato;
	
	miptrP = &pila;
	miptrP -> ptrC = miptrP -> arreglo;
	
	for(;;) {
		int opc = menu();
		switch(opc) {
			case 1:
				if(estaPilaLlena(miptrP))
					printf("La pila esta llena\n");
				else {
					printf("Ingrese un entero\n");
					scanf("%d", &miDato);
					meterPila(miptrP, miDato);
				}
			break;

			case 2:
				if(estaPilaVacia(miptrP))
					printf("La pila esta vacia\n");
				else
					printf("El valor recuperado es %d\n", sacarPila(miptrP));
			break;

			case 3:
				if(estaPilaVacia(miptrP))
					printf("La pila esta vacia\n");
				else
					imprimirContenidoPila(miptrP);
			break;

			case 4:
				exit(0);
			break;

			default:
				printf("Ingrese valores de 1 a 3, valor ingresado: %d\n", opc);
				
			break;

		}
	}

	return 0;
}
