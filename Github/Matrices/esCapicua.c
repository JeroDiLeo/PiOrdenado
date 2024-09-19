#include <assert.h>
#include <string.h>
#include <stdio.h>

#define COLS 6  // Define la cantidad de columnas en la matriz

// Función que verifica si un vector es capicúa
// Un vector es capicúa si sus elementos son iguales de izquierda a derecha y de derecha a izquierda.
int capicua(char v[], unsigned int dim) {
    // Recorre el vector desde ambos extremos hacia el centro
    for (int i = 0, j = dim - 1; i < j; i++, j--) {
        // Si los elementos correspondientes no son iguales, no es capicúa
        if (v[i] != v[j]) {
            return 0;  // Retorna 0 si no es capicúa
        }
    }
    return 1;  // Retorna 1 si es capicúa
}

// Función que copia una fila de la matriz a otra
// Copia la fila en la posición 'origen' a la posición 'destino'
void copiarFila(char m[][COLS], int destino, int origen) {
    // Si la fila de destino es la misma que la de origen, no hace nada
    if (destino == origen) {
        return;
    }
    // Copia los elementos de la fila 'origen' a la fila 'destino'
    for (int i = 0; i < COLS; i++)
        m[destino][i] = m[origen][i];
}

// Función que elimina las filas capicúas de la matriz
// Retorna la cantidad de filas restantes en la matriz luego de eliminar las capicúas
int elimina(char m[][COLS], unsigned int filas) {
    int i, j;
    // Recorre todas las filas de la matriz
    for (i = 0, j = 0; i < filas; i++) {
        // Verifica si la fila actual no es capicúa
        if (!capicua(m[i], COLS)) {  // Se verifica cada fila con la longitud de columnas (COLS)
            copiarFila(m, j, i);  // Copia la fila no capicúa a la posición correspondiente
            j++;  // Incrementa el índice para las filas no capicúas
        }
    }
    return j;  // Retorna la cantidad de filas no capicúas
}

int main(void) {
    // Declaración e inicialización de una matriz de caracteres
    char mat[][COLS] = {
        {'L', '#', 'B', 'B', '#', 'L'},  // Capicúa
        {'3', '1', 'r', 'R', '1', '3'},  // Capicúa
        {'3', '2', 'S', 'S', '2', '3'},  // Capicúa
        {'R', 'L', 'A', 'H', 'N', 'N'},  // No capicúa
        {'W', 'A', 'O', 'Y', 'U', 'T'},  // No capicúa
        {'Q', 'S', 'G', 'S', 'M', 'A'}   // No capicúa
    };

    int fil = elimina(mat, 6);  // Llama a la función para eliminar filas capicúas
    int passed = 1;  // Variable para controlar si todos los asserts pasan

    // Verificación de las condiciones esperadas con asserts
    if (fil != 4) {
        passed = 0;  // Si el número de filas no capicúas no es 4, marca como fallo
    }
    if (strncmp(mat[0], "31rR13", 6) != 0) {
        passed = 0;  // Compara la primera fila esperada
    }
    if (strncmp(mat[1], "RLAHNN", 6) != 0) {
        passed = 0;  // Compara la segunda fila esperada
    }
    if (strncmp(mat[2], "WAOYUT", 6) != 0) {
        passed = 0;  // Compara la tercera fila esperada
    }
    if (strncmp(mat[3], "QSGSMA", 6) != 0) {
        passed = 0;  // Compara la cuarta fila esperada
    }

    // Imprimir "Ok" si todos los asserts pasan
    if (passed) {
        printf("Ok\n");  // Si todas las condiciones son correctas, imprime "Ok"
    } else {
        printf("Error\n");  // Si alguna condición falla, imprime "Error"
    }

    return 0;  // Fin del programa
}
