#include <stdio.h>

int longCad(char* str) {
	char* ptr;
	for(ptr = str; *ptr != '\n'; ptr++);
	return ((int) (ptr - str));
}

int main() {

	char str[50];
	printf("Ingrese su cadena: \n");
	fgets(str, 50, stdin);
	printf("La longitud de la cadena \"%s\" es %d", str, longCad(str));
}
