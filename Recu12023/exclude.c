/*
Dado un string s1, y otros dos s2 y s3, se pide escribir la funcion exclude que
elimine de s1 todas las letras del alfabeto inglés (sin distinguir minúscula de
mayúscula) que estén en s2, pero que NO estén en s3.
Se asume que todos los caracteres son letras del alfabeto inglés junto con el
espacio.

Ejemplos de invocación:
char s[] = "This is Seoul city Numerous miracles have come true";
exclude(s, "teuos totototo nononononononon", "the");
assert(strcmp(s,"Thi i el city mer miracle have cme tre")==0);
char t[] = "This is Seoul city Numerous miracles have come true";
// No elimina nada, ya que todas las letras están en s3
exclude(t, "This is Seoul city Numerous miracles have come true",
"This Seoul cty Numerous mracles have cme rue");
char x[] = "abc abc"
exclude(x, "", "ab");
assert(strcmp(x, "abc abc") == 0); // No elimina nada porque s2 es vacío
char y[] = "abc ABc"
exclude(y, "abba", "");
assert(strcmp(y, "c c") == 0); // Elimina todo lo de s2 pues s3 es vacío
char u[] = "abc abc"
exclude(u, "", ""); // al ser s2 vacío, s3 no importa
assert(strcmp(u, "abc abc") == 0);
En el ejemplo se muestran frases cortas, pero también podrían ser frases
mucho más extensas, no sólo el primer string sino también los otros dos
*/






#include <stdio.h>
#include <string.h>
#include <ctype.h>

void exclude(char *s1, const char *s2, const char *s3) {
    int to_remove[26] = {0}; // Arreglo para letras que deben ser eliminadas

    // Marcar las letras de s2
    for (int i = 0; s2[i] != '\0'; i++) {
        if (isalpha(s2[i])) {
            to_remove[tolower(s2[i]) - 'a'] = 1;
        }
    }

    // Desmarcar las letras de s3
    for (int i = 0; s3[i] != '\0'; i++) {
        if (isalpha(s3[i])) {
            to_remove[tolower(s3[i]) - 'a'] = 0;
        }
    }

    // Recorrer s1 y construir la cadena resultante
    int j = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        char ch = tolower(s1[i]);
        if (isalpha(ch) && to_remove[ch - 'a']) {
            // Caracter está marcado para ser eliminado
            continue;
        }
        // Mantener el caracter en s1
        s1[j++] = s1[i];
    }
    s1[j] = '\0'; // Terminar la cadena resultante
}