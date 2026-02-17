#define TAM 5
#include <stdio.h>


struct per {
	char nombre[30];
	int edad;
	char sexo;
};

struct Dato {
	struct per arreglo[TAM];
	int i;
};

int main() {
	struct Dato dato;
	for(dato.i = 0; dato.i < TAM; dato.i+=1) {
		printf("Ingrese nombre\n");
		gets(dato.arreglo[dato.i].nombre);
		printf("Ingrese edad\n");
		scanf("%d", &dato.arreglo[dato.i].edad);
		printf("Ingrese sexo\n");
		dato.arreglo[dato.i].sexo = getchar();

	}

	for(dato.i = 0; dato.i < TAM; dato.i+=1) {
		printf("En la celda %d esta %s con dir %p \t de %d anios en dir %p, %c con dir %p", dato.i, dato.arreglo[dato.i].nombre, 
				&dato.arreglo[dato.i].nombre, dato.arreglo[dato.i].edad, &dato.arreglo[dato.i].edad,
				dato.arreglo[dato.i].sexo, &dato.arreglo[dato.i].sexo);
	}
	
}
