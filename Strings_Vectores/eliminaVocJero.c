/*
Se desea eliminar de un texto todas las vocales, siempre y cuando no sean vocales "sueltas", esto es, para 
eliminarlas deben tener al menos una letra antes o una letra después (y que no sea vocal).

Escribir una función eliminaVoc que reciba únicamente un string y elimine todas las vocales siguiendo las reglas 
mencionadas anteriormente.

Ejemplos: 

Si recibe "hola mundo" lo deja como "hl mnd"
Si recibe "hola a todo el mundo" lo deja como "hl a td l mnd"
Si recibe "xyz" lo deja sin cambios
Si recibe el string "aholoaaa" lo deja como "hlaaa"
Si recibe el string vacío "" lo deja sin cambios
Si recibe "aa eo iu oa uo" lo deja sin cambios
Si recibe "pa po pi po pu" lo deja como "p p p p p"
Si recibe "aeiou" lo deja igual
Si recibe "a,e,i,o,u" lo deja igual
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isalpha(char c){
    return (c>='a' && c<='z') || (c>='A' && c<='Z');   //Devuelve 1 si c es una letra, sino 0
}
int isVocal(char c) {
    char vocal = tolower(c);
    return (vocal == 'a' || vocal == 'e' || vocal == 'i' || vocal == 'o' || vocal == 'u');
}
void eliminaVoc(char* str) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        if (isVocal(str[i])) {
            if ((i > 0 && !isalpha(str[i-1])) || (str[i+1] != '\0' && !isalpha(str[i+1]))) {    //Veo si la vocal esta suelta
                for (j = i; str[j] != '\0'; j++) {  //Desplaza todo a la izq
                    str[j] = str[j+1];              //Sobre escribo el caracter actual con el siguiente
                }
                i--;
            }
        }
    }
}   