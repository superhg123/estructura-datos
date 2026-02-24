#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct DatosEst {
	float arreglo[20];
	int numDatos;
	float prom;
	float desvEst;
	float *ptr;
};

int meterDatos(struct DatosEst *ptrs) {
	printf("Ingrese el numero de datos a ingresar\n");
	scanf("%d", &ptrs->numDatos);

	for(ptrs -> ptr = ptrs -> arreglo;  ptrs -> ptr < &ptrs->arreglo[20]; ptrs->ptr+=1) {
		printf("Ingrese dato:\n");
		scanf("%f", ptrs -> ptr);
	}

	return 0;
}

int calcEst(struct DatosEst *ptrs) {
	float suma = 0.0;
	for(ptrs -> ptr = ptrs -> arreglo;  ptrs -> ptr < &ptrs->arreglo[20]; ptrs->ptr+=1)
		suma += *ptrs -> ptr;
	ptrs -> prom = suma / (ptrs -> numDatos);
	suma = 0.0;

	for(ptrs -> ptr = ptrs -> arreglo;  ptrs -> ptr < &ptrs->arreglo[20]; ptrs->ptr+=1)
		suma += pow((ptrs -> prom - *ptrs -> ptr), 2);
	ptrs -> desvEst = pow(suma, 0.5);
	return 0;
}
int menu() {
	int opc;
	printf("1. para ingresar\n");
	printf("2. para calcular\n");
	printf("3. para salir\n");
	printf("Ingrese opcion\n");
	scanf("%d", &opc);
	return opc;
}


int main() {

	struct DatosEst datos, *ptrs;
	ptrs = &datos;

	for(;;) {
		switch(menu()) {
			case 1:
				meterDatos(ptrs);
				break;
			case 2:
				calcEst(ptrs);
				printf("Promedio: %f, Desviacion estandar: %f", ptrs-> prom, ptrs -> desvEst);
				break;
			case 3:
				exit(0);
				break;
		}
	}
	return 0;
}
