#include <stdio.h>

int es_palindromo(char* str) {
	char *izq, *der;
	int palindromo = 1;

	for(der = str; *der != '\0'; der++);
	der-=2;
	for(izq = str; izq < der; izq+=1, der-=1) {

		if(*izq == ' ') izq+=1;
		if(*der == ' ') der-=1;

		if(*izq != *der) {
			palindromo = 0;
			break;
		}
	}

	return palindromo;
}

int main() {
	
	char str[50];
	printf("Ingrese su texto\n");
	fgets(str, 50, stdin);

	char* resultado = (es_palindromo(str)) ? "es palindromo" : "no es palindromo";
	printf("El texto %s\n", resultado);

	return 0;
}
