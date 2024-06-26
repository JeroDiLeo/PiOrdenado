#include <stdio.h>

// Definimos la dimensión del tablero
#define DIM 3
#define MINE -1
#define DIR_AMOUNT 8
#define VALID_INDEX(i, j) ((i) >= 0 && (i) < DIM && (j) >= 0 && (j) < DIM)

// Matriz de direcciones para las 8 celdas adyacentes
int direcciones[DIR_AMOUNT][2] = {
    {-1, -1}, {-1, 0}, {-1, 1}, // Celdas adyacentes superiores
    { 0, -1},          { 0, 1}, // Celdas adyacentes laterales
    { 1, -1}, { 1, 0}, { 1, 1}  // Celdas adyacentes inferiores
};

// Función que cuenta el número de minas adyacentes a una celda dada
int contarMinasAdyacentes(signed char tablero[DIM][DIM], int fila, int col) {
    int minas = 0;
    // Recorre las direcciones adyacentes
    for (int d = 0; d < DIR_AMOUNT; d++) {
        int nuevaFila = fila + direcciones[d][0];
        int nuevaCol = col + direcciones[d][1];
        // Verifica que las coordenadas estén dentro del tablero
        if (VALID_INDEX(nuevaFila, nuevaCol)){
            if (tablero[nuevaFila][nuevaCol] == MINE) {
                minas++;
            }
        }
    }
    return minas;
}

// Función que verifica si el tablero es válido según las reglas del Buscaminas
int esTableroValido(signed char tablero[DIM][DIM]) {
    // Recorre cada celda del tablero
    for (int fila = 0; fila < DIM; fila++) {
        for (int col = 0; col < DIM; col++) {
            signed char valor = tablero[fila][col];
            if (valor >= 0) {
                // Verificar que el número de minas adyacentes coincide con el valor de la celda
                if (valor != contarMinasAdyacentes(tablero, fila, col)) {
                    return 0;
                }
            } else if (valor < -1) {
                // Valor inválido
                return 0;
            }
        }
    }
    // Si todas las celdas son válidas, el tablero es válido
    return 1;
}