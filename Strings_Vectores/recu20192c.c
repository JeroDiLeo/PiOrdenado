//Escribir una funcion elimina que recibe un string y elimina las primeras apariciones de los caracteres repetidos, dejando solo la ultima aparicion
#include <stdio.h>
#define MAXCHAR 256

void elimina(char *s);

void elimina(char *s){
    int i, aux =0;
    int v[MAXCHAR] = {0};
    for(i = 0; s[i] != '\0'; i++){
        v[s[i]]=v[s[i]]+1;
    }
    for(i = 0; s[i] != '\0'; i++){
        v[s[i]]=v[s[i]]-1;
        if(v[s[i]] == 0)
            s[aux++] = s[i];
    }
    s[aux] = '\0';
}
