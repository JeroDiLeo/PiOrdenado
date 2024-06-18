/* Escribir la función elimina que recibe tres strings s1, s2 y s3 y elimina de s1
aquellos caracteres que están presentes en s2 o en s3 en la misma posición que
en s1. */
#include <stdio.h>
#include <string.h>
#include <assert.h>

void elimina(char s[], const char s2[],const char s3[]){
    int i2 = 0;
    int i3= 0;
    int k=0;
    for(int i1=0; s[i1]!='\0';i1++){                        //recorro s1 hasta que encuentra el final
        if((s[i1]!=s2[i2]) && (s[i1]!=s3[i3])){             //si el caracter de s1 no esta en s2 ni en s3       
            s[k++]=s[i1];                                           //lo copio
        }
        if(s2[i2] !='\0'){                                  //si no llego al final de s2 avanzo
            i2++;
        }
        if(s3[i3] !='\0'){                                 //si no llego al final de s3 avanzoo
            i3++;
        }
    }
    s[k]='\0';                                             //pongo el fin de cadena
    
}


int main(void) {
char s[] = "abc";
elimina(s, "123", "cab");
assert(strcmp(s, "abc") == 0); // No se eliminan caracteres
elimina(s, "axc", "xbc");
// Se elimina la a porque está en s2 en la misma posición
// se elimina la b porque está en s3 en la misma posición
// Se elimina la c porque está en s2 o en s3 en la misma posición
assert(strcmp(s, "") == 0);
char t[] = "abc 123";
elimina(t, "b", "1");
assert(strcmp(t, "abc 123") == 0); // No se eliminan caracteres
elimina(t, "aaaaaaaaaaaaaaaaaaaaaa", "2222222222222222222");
assert(strcmp(t, "bc 13") == 0);
elimina(t, "", ""); // No se eliminan caracteres
assert(strcmp(t, "bc 13") == 0);
puts("OK!");
return 0;
}
