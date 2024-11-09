#include <stdio.h>

int main(void){
	const double millasporkm = 0.6213712;
	for (int i = 1; i<11; i++){
		printf("%d km = %f millas\n", i, i*millasporkm);
	}
	return 0;
}
