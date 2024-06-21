/*Una escalera de palabras (Word Ladder) consiste en un conjunto de
palabras donde cada una difiere de la anterior únicamente en una letra (sin
distinguir mayúsculas de minúsculas) en una posición.
A partir de una primera palabra TEST se puede conseguir la palabra BEST
cambiando la primer letra, y luego se puede conseguir BEET cambiando la tercer
letra de la anterior. De esta forma TEST -> BEST -> BEET es una escalera de
palabras.
No se forma una escalera de palabras si:
● Cambian dos o más letras de una palabra a otra. Por ejemplo TEST ->
EAST cambia T->E y E->A
● La posición de la letra que cambió se repite entre dos palabras
seguidas. Por ejemplo TEST -> BEST -> REST cambia dos veces
seguidas la primera letra T->B y B->R.
Implementar una función isWordLadder que recibe:
● la cantidad de palabras del conjunto
● la longitud de cada una de las palabras (Se asume que todas son de la
misma longitud, no es necesario validarlo)
● una matriz de chars donde cada fila de la matriz corresponde a una
palabra
y retorna 1 si la matriz corresponde a una escalera de palabras y 0 sino*/

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#define COLS 4

int
isWordLadder(unsigned words, unsigned length, char matrix[][length]) {
    for(int i = 0, lastLadderCol = -1; i < words - 1; i++) { // LastladdeCol es la columna del cambio del par anterior(Que necesito para compararla con la actual para q no se repita)
        int ladderCol = -1; // La columna del cambio del par de filas actual
        for(int j = 0; j < length; j++) {
            if(toupper(matrix[i][j]) != toupper(matrix[i+1][j])) { // Encontré un cambio
                // Termina si es el segundo cambio o coincide en columna con el cambio del par anterior
                if(ladderCol >= 0 || j == lastLadderCol) { //El caso de j==lastLadderCol es para evitar que se repita la columna
                    return 0;
                }
                ladderCol = j;
            }
        }
        if(ladderCol == -1) { // Termina si no se encontró ningún cambio en la fila
            return 0;
        }
        lastLadderCol = ladderCol;  // Guardo la columna del cambio del par actual para compararla con la siguiente
    }
    return 1;
}
