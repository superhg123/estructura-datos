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

int menu() {
	int opc;

	printf("1. Para meter a cola\n");
	printf("2. Para sacar de cola\n");
	printf("3. Para resetear cola\n");
	printf("4. Para salir\n");

	scanf("%d", &opc);
	return opc;
}

int main() {
	struct Cola cola, *ptrC;
	int miDato;
	ptrC = &cola;
	resetearCola(ptrC);

	switch(menu()) {
		case 1:	
			printf("Ingrese el dato\n");
			scanf("%d", miDato);
			meterCola(ptrC, miDato);
		break;

		case 2:
			int dato = sacarCola(ptrC);
			printf("El dato recuperado es %d\n", dato);
		break;

		case 3:
			resetearCola(ptrC);
			printf("Cola reseteada\n");
		break;

		case 4:
			exit(0);
		break;

		default:
			printf("Ingrese una opcion del 1 al 4\N");
		break;
	}
}
