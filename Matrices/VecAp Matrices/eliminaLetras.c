/*
Escribir una función que reciba un string s y una matriz de COLS columnas ( COLS es una constante simbólica) y nfilas,
 donde cada columna representa una letra comenzando por la 'A' (si COLS es 5 las letras a considerar son de la‘a’ a la ‘e’ , 
 si COLS es 3 las letras a considerar son 'a','b','c', etc.). Se asegura que COLS está entre 1 y 26 inclusive.
 Sólo se consideran letras del alfabeto inglés.La función deberá devolver el string s sin las letras seleccionadas (tanto en mayúscula como en minúscula),
  y la matriz con las ubicaciones de las letras eliminadas. Cada columna de la matriz debe “cerrarse” con un -1. 
  La función tiene que controlar el espacio disponible en la matriz para seguir guardando ubicaciones. 
  Si no hay espacio suficiente, devuelve ERROR, aunque haya quedado modificado parte del string.
*/
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define COLS 5
#define ERROR 0
#define EXITO 1
//Maximo de COLS=26(cant de letras)

//En m[i][j] se guarda en que posicion esta la letra




#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define COLS 5
#define ERROR 0
#define EXITO 1

// Función para eliminar una letra de una posición específica en un string
void eliminarLetraDelString(char *s, int pos) {
    for (int i = pos; s[i] != '\0'; i++) {
        s[i] = s[i + 1];
    }
}

// Función que elimina letras del string y registra sus posiciones en la matriz
int eliminaLetras(char s[], int m[][COLS], int nfilas) {
    if (COLS < 1 || COLS > 26) {
        return ERROR;  // Verifica si COLS está en el rango válido
    }

    int filasUsadas[COLS] = {0}; // Para llevar la cuenta de las filas usadas en cada columna
    int i = 0;

    while (s[i] != '\0') {
        char c = tolower(s[i]);
        if (c >= 'a' && c < 'a' + COLS) { // Verifica si el carácter está en el rango de letras válidas
            int col = c - 'a';  // Calcula la columna correspondiente a la letra
            if (filasUsadas[col] >= nfilas) {
                return ERROR;  // Verifica si hay espacio suficiente en la matriz
            }

            m[filasUsadas[col]][col] = i; // Guarda la posición en el string de dicha letra en la matriz
            filasUsadas[col]++; // Incrementa el contador de filas usadas en la columna

            eliminarLetraDelString(s, i); // Elimina la letra del string
        } else {
            i++;
        }
    }

    // Añade el fin (-1) en cada columna de la matriz
    for (int j = 0; j < COLS; j++) {
        if (filasUsadas[j] < nfilas) {
            m[filasUsadas[j]][j] = -1;
        } else {
            return ERROR;  // Verifica si hay espacio para el marcador de fin
        }
    }

    return EXITO;
}

































int main(){
    int M[6][COLS];
    char s[]="lAs buenas Ideas Escasean";
    assert(eliminaLetras(s,M,6,5)==EXITO);
    assert(strcmp(s,"ls uns Is ssn")==0);
    assert(M[0][0] == 1 && M[0][1] == 4 && M[0][2] == 19 && M[0][3] == 12 && M[0][4] == 6); 
    assert(M[1][0] == 8 && M[1][1] == -1 && M[1][2] == -1 && M[1][3] == -1 && M[1][4] == 13);
    assert(M[2][0] == 14 && M[2][4] == 17);
    assert(M[3][0] == 20 && M[3][4] == 22);
    assert(M[4][0] == 23 && M[4][4] == -1);
    assert(M[5][0] == -1);

    int M2[5][COLS];
    char s2[]="lAs buenas Ideas Escasean";
    assert(eliminaLetras(s2,M2,5,4)==ERROR);
    assert(strcmp(s2,"ls uens Ies Essean")==0);
    assert(M2[0][0] == 1 && M2[0][1] == 4 && M2[0][2] == 19 && M2[0][3] == 12);
    assert(M2[1][0] == 8 && M2[1][1] == -1 && M2[1][2] == -1 && M2[1][3] == -1);
    assert(M2[2][0] == 14);
    assert(M2[3][0] == 20);
    assert(M2[4][0] == -1);
    printf("OK!\n");
    return EXIT_SUCCESS;
}