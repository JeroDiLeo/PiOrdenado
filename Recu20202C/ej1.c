#include <stdio.h>

void
eliminaDigitos(char * s) {
	int j = 0;
	for(int i = 0; s[i]; i++) {
		if(s[i] < '0' || s[i] > '9') {
			s[j++] = s[i];
		}
	}
	s[j] = 0;
}

int 
main(void) {
	char s[] = "H0la 123Mund0";
	eliminaDigitos(s);
	printf("%s\n", s);
}