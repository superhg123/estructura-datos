#define TAM 1
#include <stdio.h>

struct per {
	char nombre[30];
	int edad;
	char sexo;
};

struct Dato {
	struct per arreglo[TAM];
	struct per *ptr;
};

int main() {
	struct Dato dato;
	for(dato.ptr = dato.arreglo; dato.ptr < &dato.arreglo[TAM]; dato.ptr += 1) {
		printf("Ingrese nombre\n");
		gets(dato.ptr->nombre);
		printf("Ingrese edad\n");
		scanf("%d", &dato.ptr->edad);
		printf("Ingrese sexo\n");
		dato.ptr->sexo = getchar();
	}

	
	for(dato.ptr = dato.arreglo; dato.ptr < &dato.arreglo[TAM]; dato.ptr += 1) {
		printf("En la celda %d esta %s con dir %p", (int) (dato.ptr - dato.arreglo), dato.ptr->nombre, &dato.ptr->nombre);
	}

	return 0;
}
