#include <stdio.h>

int mistrlen(char *s){
	int n = 0;
	while (*s != '\0'){
		s++;
		n++;
	}
	return n;
}

int mistrcmp(char *s, char *p){
	return mistrlen(s) - mistrlen(p);
}

int main(void){
	char *s = "Hola Mundo\0";
	char *p = "Buenas\0";
	printf("%d\n", mistrcmp(s, p));
	return 0;
}
	
	
