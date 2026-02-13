#include <stdio.h>
#define TAM 5

struct Dato {
	int arreglo[TAM];
	int i;
};

struct Dato2 {
	int arreglo[TAM];
	int *ptr;
};

struct Dato3 {
	int arreglo[TAM];
	int i;	
};

int main() {

	printf("Primera forma\n");
	struct Dato dato;
	for(dato.i = 0; dato.i < TAM; dato.i += 1) {
		printf("Ingrese un entero\n");
		scanf("%d", &dato.arreglo[dato.i]);
	}


	for(dato.i = 0; dato.i < TAM; dato.i += 1) {
		printf("En la celda %d esta el valor %d en la dir %p\n", dato.i, dato.arreglo[dato.i], &dato.arreglo[dato.i]);
	}

	printf("Segunda forma\n");
	struct Dato2 dato2;

	for(dato2.ptr = dato2.arreglo; dato2.ptr < &dato2.arreglo[TAM]; dato2.ptr += 1 ) {
		printf("Ingrese un entero\n");
		scanf("%d", dato2.ptr);
	}

	
	for(dato2.ptr = dato2.arreglo; dato2.ptr < &dato2.arreglo[TAM]; dato2.ptr += 1 ) {
		printf("En la celda %d esta el valor %d en la dir %p\n", (int) (dato2.ptr - dato2.arreglo), *dato2.ptr, dato2.ptr);
	}



	printf("Tercera forma\n");
	struct Dato dato3, *ptrs;
	ptrs = &dato3;


	for(ptrs -> i = 0; ptrs -> i < TAM; ptrs -> i += 1) {
		printf("Ingrese un entero\n");
		scanf("%d", &ptrs->arreglo[ptrs->i]);
	}


	for(ptrs -> i = 0; ptrs -> i < TAM; ptrs -> i += 1) {
		printf("En la celda %d esta el valor %d en la dir %p\n", ptrs -> i, ptrs->arreglo[ptrs->i], &ptrs->arreglo[ptrs->i]);
	}

	return 0;
}
