#include <stdio.h>
#define TAM 1

struct per{
	char nombre[30];
	int edad;
	char sexo;
};

struct Dato {
	struct per arreglo[TAM];
	int i;
};

int main() {
	struct Dato dato, *ptrs;
	ptrs = &dato;

	for(ptrs->i = 0; ptrs->i < TAM; ptrs->i += 1) {
		printf("Ingrese el nombre\n");
		gets(ptrs->arreglo[ptrs->i].nombre);
		printf("Ingrese la edad\n");
		scanf("%d", &ptrs->arreglo[ptrs->i].edad);
	}

	
	for(ptrs->i = 0; ptrs->i < TAM; ptrs->i += 1) {
		printf("En la posicion %d esta %s con dir %p", ptrs->i, ptrs->arreglo[ptrs->i].nombre, &ptrs->arreglo[ptrs->i].nombre);
	}
}
