#include <stdio.h>

int mistrlen(char *s){
	int n = 0;
	while (*s != '\0'){
		s++;
		n++;
	}
	return n;
}

int main(void){
	char *s = "Hola Mundo\0";
	char *p = ", Buenas!\0";
	int slen = mistrlen(s);
	int plen = mistrlen(p);
	int destlen = slen + plen;

	char dest[destlen];

	for (int i = 0; i<slen; i++) *(dest + i) = *(s + i);
	for (int i = 0; i<plen; i++) *(dest + slen + i) = *(p + i);

	*(dest + destlen) = '\0';	
	printf("%s\n", dest);
	return 0;
}
	
	
