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
#include <ctype.h>


int isVocal(char letra){
    char c=tolower(s[i]);
    return(c=='a'||c=='e' ||c=='i'||c=='o'||c=='u');
}

void eliminaVoc(char s[]){
    int t=0;
    for(int i=0;s[i]!='\0';i++){
                            //SI ES VOCAl    Y                         (  ESTA ENTRE DOS VOCALES  )        O      ( ESTA SUELTA )    
        if(!isVocal(s[i])||((isVocal(s[i])) && i>0 && s[i+1]!='\0' && ((isVocal(s[i-1])&& isVocal(s[i+1]))||(s[i-1]==' '&& s[i+1]==' ')))){
            s[t++]=s[i];
        }
    }
    s[t]='\0';
}




























// Función para verificar si un carácter es una vocal
int isVocal(char letra) {
    char c = tolower(letra);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Función para eliminar vocales según las reglas especificadas
void eliminaVoc(char *s) {
    int t = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (!isVocal(s[i]) || 
            ((i > 0 && !isVocal(s[i-1])) || (s[i+1] != '\0' && !isVocal(s[i+1])))) {
            s[t++] = s[i];
        }
    }
    s[t] = '\0';
}

//---------------Esta solucion de abajo que hice se entiende mejor-----------------

int isVocal(char letra){
    char c=tolower(letra);
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
        return 1;
    }else{
        return 0;
    }

}
void eliminaVoc(char *s){
    int t=0;
    for(int i=0;s[i]!='\0';i++){
        if ((!isVocal(s[i]))||((i > 0 && isalpha(s[i-1])) || (s[i+1] != '\0' && isalpha(s[i+1])))){
            s[t++]=s[i];
        }
    }
    s[t]='\0';
}