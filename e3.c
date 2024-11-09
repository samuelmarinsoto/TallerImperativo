#include <stdio.h>

int contardigitos(int num){
	if (num%10 == 0){
		return 0;
	} else {
		return 1 + contardigitos(num/10);
	}
}

int main(void){
	int num = 12345; // cambiar para usar otros numeros

	int digitos = contardigitos(num);

	printf("%d digitos en %d\n", digitos, num);

	return 0;
}
