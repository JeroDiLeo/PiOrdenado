/*
Se dice que una palabra o frase es anagrama de otra palabra o frase si ambas
están compuestas por las mismas letras y con la misma cantidad de apariciones de
cada letra, sin tener en cuenta los blancos.
Por ejemplo "anagrama" es anagrama de "amar gana", pero no de "margana", ya que
esta última tiene sólo 3 letras 'a' en vez de 4.
Escribir la función anagrama que reciba dos strings formados únicamente por letras
del alfabeto inglés y espacios (no es necesario validarlo, se asume que ambos cumplen con
esta condición) y retorne 1 si ambos son anagramas o 0 si no lo son.*/
#include <assert.h>
#include <ctype.h>

#define LETTERS ('Z'-'A'+1)

int cuenta2(int frec[], const char *s) {
    int cant = 0;
    while(*s) {
		if(isalpha(*s)) {	
			frec[*s-'a']++;    // como se aclaró, podían asumir que eran minúsculas
			cant++;
		}
		s++;	
	}
	return cant;
}

int anagrama2(const char *s, const char *t) {
	// Creamos un vector para contar cuantas veces aparece cada letra en la primer frase
	// Luego decrementamos para el segundo vector
	unsigned int frec[LETTERS] = {0};
	int letras_s, letras_t=0;
	
	letras_s = cuenta2(frec, s);
	
	// Mostramos otra forma válida de recorrer un string
	for(int i=0; t[i]!='\0'; i++) {
		if(isalpha(t[i])) {
			int idx=t[i]-'a';
			if (frec[idx]==0) {
				return 0;
			}
			frec[idx]--;	
			letras_t++;
		}
	}
	return letras_s==letras_t;
}




//ABAJO ES MENOS EFICIENTE
void cuenta(int frec[], const char *s) {
    while(*s) {
		if(isalpha(*s)) {
			frec[*s-'a']++;    // como se aclaró, podían asumir que eran minúsculas
		}
		s++;	
	}
}

int anagrama(const char *s, const char *t) {
	// Creamos un vector para contar cuantas veces aparece cada letra en la primer frase
	// Luego decrementamos para el segundo vector
	unsigned int frec[LETTERS] = {0};
	
	cuenta(frec, s);
	
	// Mostramos otra forma válida de recorrer un string
	for(int i=0; t[i]!='\0'; i++) {
		if(isalpha(t[i])) {
			int idx=t[i]-'a';
			if (frec[idx]==0) {
				return 0;
			}
			frec[idx]--;	
		}
	}
	// El vector tiene que haber quedado con todos sus elementos en cero
	for(int i=0; i<LETTERS; i++) {
		if ( frec[i] !=0 ) {
			return 0;
		}
	}	
	return 1;
}
int main(void) {
char * s = "anagrama";

assert(anagrama(s, "amar gana"));
assert(anagrama("enrique", "quieren"));
assert(anagrama(s,s));
assert(anagrama("         ", ""));
assert(anagrama("amar gana", s));
assert(anagrama("", ""));
assert(anagrama("a gentleman", "elegant man"));

assert(anagrama("a", "")==0);
assert(anagrama("mar", "amar")==0);

}