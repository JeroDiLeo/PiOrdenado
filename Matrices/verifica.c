/*
Escribir una función verifica que recibe como único parámetro una "matriz" de enteros de NxN, donde N es una 
constante previamente definida, de tipo entero y múltiplo de 3, por ejemplo 3, 6, 9, etc.
La función debe retornar 1 si se cumplen todas las siguientes condiciones:
	-	Todos los elementos de la matriz están entre 1 y 3*N inclusive
	-	Cada submatriz de 3x3 debe tener elementos sin repetir
	-	Al sumar los elementos de cada submatriz de 3x3 se obtiene el mismo resultado
	-	Las submatrices son similares a las del juego de Sudoku, comienzan en las posiciones (0,0), (0,3), (3,0), 
		(3,3), (0,6), etc.

Ejemplos:
Si N es 3 y recibe la siguiente matriz, debe retornar 1:
1 3 2
9 8 6
4 7 5


Si N es 6 y recibe la siguiente matriz, debe retornar 1, ya que no hay repetidos en cada una de las cuatro submatrices y todas suman lo mismo
10 3  2  3  8  7
12 8  6  6  2  4
 4 7  5  5 12 10
 2 12 6 10  4  5
 5 10 3  7  2  9
 8 4  7  3  6 11


Si N es 3 y recibe la siguiente matriz, debe retornar 0 (el 15 está fuera del rango 1 a 3*N)
1 3 2
9 8 6
4 7 15


Si N es 6 y recibe la siguiente matriz, debe retornar 0. Si bien las 4 submatrices suman lo mismo, en una se repiten valores:
1 3 2 3 8 5
9 8 6 6 2 4
4 7 5 5 9 3
2 9 6 1 4 5
5 1 3 7 2 8
8 4 7 3 6 9
*/

#include <stdio.h>
#define N
// DIM: la dimension de cada submatriz
#define DIM 3   
#define MULT 3

// Función para verificar las condiciones de la matriz
int verifica(const int mat[][N]){

    int actual, anterior;

    // Recorrer las submatrices de 3x3
    for (int i=0; i<N; i+=3){
        for(int j=0; j<N; j+=3){

            // Calcular el resultado de la submatriz actual
            actual = isSubMatrix(mat, i, j);

            // Verificar si se cumple la condición de la submatriz actual
            if(actual==0 || (i!=0 && actual != anterior))
                return 0;

        }

        anterior = actual;

    }

    return 1;
}

// Función para verificar una submatriz de 3x3
int isSubMatrix(const int mat[][N], size_t posI, size_t posJ){

    int cont = 0, m;
    int aux[3*N] = {0};

    // Recorrer los elementos de la submatriz
    for (int i = posI; i<(posI+3); i++){
        for (int j = posJ; j<(posJ+3); j++){

            m = mat[i][j]; 

            // Verificar si el elemento está dentro del rango y no se repite en la submatriz
            if( m>=1 && m<=(3*N) && aux[m]==0 ){
                aux[m] = 1;
                cont += m;
            }else{
                return 0;
            }

        }
    }

    return cont;
}

int main(void) {
    // Definir matriz de ejemplo m1
    int m1[N][N] = { {10, 3, 2, 3, 8, 7},
                     {12, 8, 6, 6, 2, 4},
                     { 4, 7, 5, 5,12,10},
                     { 2,12, 6,10, 4, 5},
                     { 5,10, 3, 7, 2, 9},
                     { 8, 4, 7, 3, 6,11}};

    // Verificar si la matriz m1 cumple las condiciones
    assert(verifica(m1)==1); // Verificar que la función devuelve 1 para la matriz m1

    // Definir matriz de ejemplo m2
    int m2[N][N] = { {10, 3, 2, 3, 8, 7},
                     {12, 8, 6, 6, 2, 4},
                     { 4, 7, 5, 5,12,10},
                     { 2,12, 6,10, 4, 5},
                     { 5,10, 3, 7, 2, 9},
                     { 8, 4, 7, 3, 6,12}};

    // Verificar si la matriz m2 cumple las condiciones
    assert(verifica(m2)==0); // Verificar que la función devuelve 0 para la matriz m2

    // Definir matriz de ejemplo m3
    int m3[N][N] = { {10, 3, 2, 3, 8, 7},
                     {12, 8, 6, 6, 2, 4},
                     { 4, 7, 5, 5,12,10},
                     { 2,12, 6,10, 4, 5},
                     { 5,10, 3, 7, 2, 9},
                     { 8, 4, 7, 4, 5,11}};

    // Verificar si la matriz m3 cumple las condiciones
    assert(verifica(m3)==0); // Verificar que la función devuelve 0 para la matriz m3

    puts("OK");
    return 0;
}


//cuando i=0 no verifica si la suma coincide