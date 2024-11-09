#include <stdio.h>

double c2f(double celsius){
	return (celsius*1.8 + 32);
}

int main(void){
	double resultado;
	double input = 33; // cambiar para calcular otro valor
	resultado = c2f(input);
	printf("%f C = %f F\n", input, resultado);

	return 0;
}
	
