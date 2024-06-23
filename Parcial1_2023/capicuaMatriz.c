/*
Dada una matriz de chars de COLS columnas -donde COLS es una constante
previamente definida-, verificar las filas que representan un palíndromo (capicúa). En
cada celda puede haber letras, dígitos, símbolos, etc. Se debe considerar que las letras
minúsculas no son equivalentes a las letras mayúsculas, por lo que "ala" es palíndromo
pero "Ala" no lo es.
Escribir una función elimina que reciba la matriz y la cantidad de filas de la misma, y
elimine de la matriz las filas que sean capicúas. La función debe retornar cuántas filas
quedaron en la matriz.
Ejemplo: Con COLS = 6, si la matriz es:
L # B B # L
3 1 r R 1 3
3 2 S S 2 3
R L A H N N
W A O Y U T
Q S G S M A
debe quedar de la siguiente forma y retornar 4, donde lo que quede almacenado en
las últimas dos filas no tiene importancia.
3 1 r R 1 3
R L A H N N
W A O Y U T
Q S G S M A
*/

#include <assert.h>
#include <string.h>

#define COLS 6  // Definición de la constante COLS que representa el número de columnas de la matriz

// Función capicua: verifica si un arreglo de caracteres es un palíndromo
int capicua(char v[], unsigned int dim) {
    for(int i = 0, j = dim - 1; i < j; i++, j--) {
        if(v[i] != v[j]) {
            return 0;  // No es palíndromo
        }
    }
    return 1;  // Es palíndromo
}

// Función copiarFila: copia una fila de la matriz de origen a destino
void copiarFila(char m[][COLS], int destino, int origen) {
    if(destino == origen) {
        return;  // Si el destino es igual al origen, no se hace ninguna copia
    }
    for(int i = 0; i < COLS; i++) {
        m[destino][i] = m[origen][i];  // Copia cada elemento de la fila origen a la fila destino
    }
}

// Función elimina: elimina las filas palíndromas de la matriz
int elimina(char m[][COLS], unsigned int filas) {
    int j = 0;  // Contador para las filas no palíndromas
    for(int i = 0; i < filas; i++) {
        if(!capicua(m[i], COLS)) {  // Si la fila no es un palíndromo
            copiarFila(m, j, i);   // Copia la fila i en la posición j
            j++;  // Incrementa el contador de filas no palíndromas
        }
    }
    return j;  // Retorna el número de filas que quedaron en la matriz después de eliminar las palíndromas
}


int main(void) {

    char mat[][COLS] = {{ 'L', '#', 'B', 'B', '#', 'L'},
	    		{ '3', '1', 'r', 'R', '1', '3'},
	    		{ '3', '2', 'S', 'S', '2', '3'},
	    		{ 'R', 'L', 'A', 'H', 'N', 'N'},
	    		{ 'W', 'A', 'O', 'Y', 'U', 'T'},
	    		{ 'Q', 'S', 'G', 'S', 'M', 'A'}};

    int fil=elimina(mat, 6);
    assert(fil==4);
    assert(strncmp(mat[0], "31rR13", 6)==0);
    assert(strncmp(mat[1], "RLAHNN", 6)==0);
    assert(strncmp(mat[2], "WAOYUT", 6)==0);
    assert(strncmp(mat[3], "QSGSMA", 6)==0);

    return 0;
}
