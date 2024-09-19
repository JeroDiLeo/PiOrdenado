/*
Escribir una función que reciba dos matrices cuadradas de enteros, de dimensión DIM (DIM es una constante simbólica ya definida) y retorne:
1 si cada elemento de la fila n de la primera matriz está en la columna n de la segunda matriz, para todo n entre 0 y DIM-1
2 si cada elemento de la columna n de la primera matriz está en la fila n de la segunda matriz, para todo n entre 0 y DIM-1
En caso de cumplir ambas condiciones puede retornar 1 ó 2
0 si no se cumple ninguna de las dos condiciones

Las matrices pueden tener elementos repetidos y no hay ningún tipo de orden,
*/
#include <stdio.h>
#include <assert.h>

#define DIM 4
int contieneTodas(const int m1[][DIM], const int m2[][DIM]);
int perteneceFilCol(const int m[][DIM], int vec[],unsigned int fila);
int estaContenido(const int m[][DIM],int elem, int col);
int matrices(const int m1[][DIM], const int m2[][DIM]);

int main()
{
    int m1[DIM][DIM] = {{1, 3, 1, 2},
                        {5, 5, 6, 6},
                        {2, 3, 4, 5},
                        {1, 1, 1, 2}};
    int m2[DIM][DIM] = {{1, 6, 5, 2},
                        {2, 6, 3, 2},
                        {3, 6, 2, 1},
                        {3, 5, 4, 1}};
    assert(matrices(m1, m2) == 1);

    int m3[DIM][DIM] = {{1, 3, 1, 2},
                        {5, 5, 6, 6},
                        {2, 3, 4, 5},
                        {1, 1, 1, 2}};
    int m4[DIM][DIM] = {{1, 2, 5, 2},
                        {1, 3, 3, 5},
                        {1, 4, 4, 6},
                        {2, 5, 6, 6}};
    assert(matrices(m3, m4) == 2);

    int m5[DIM][DIM] = {{1, 3, 1, 2},
                        {5, 5, 6, 6},
                        {2, 3, 4, 5},
                        {1, 1, 1, 2}};
    int m6[DIM][DIM] = {{1, 2, 5, 2},
                        {1, 3, 3, 5},
                        {4, 4, 4, 6},
                        {2, 5, 6, 6}};
    assert(matrices(m5, m6) == 0);

    int m7[DIM][DIM] = {{1, 1, 1, 1},
                        {2, 2, 2, 2},
                        {3, 3, 3, 3},
                        {4, 4, 4, 4}};
    int m8[DIM][DIM] = {{1, 2, 3, 4},
                        {1, 2, 3, 4},
                        {1, 2, 3, 4},
                        {1, 2, 3, 4}};
    int res;
    assert((res = matrices(m7, m8)) == 1 || res == 2);

    puts("OK!");
}

int matrices(const int m1[][DIM],const int m2[][DIM]){
    if(contieneTodas(m1,m2)){
        return 1;
    }else if(contieneTodas(m2,m1)){
        return 2;
    }else{
        return 0;
    }
}

int contieneTodas(const int m1[][DIM], const int m2[][DIM]){
    for(int i=0;i<DIM;i++){
        if(!perteneceFilCol(m2,m1[i],i)){
            return 0;
        }
    }
    return 1;
}

int perteneceFilCol(const int m[][DIM], int vec[],unsigned int fila){
    for(int k=0;k<DIM;k++){
        if(!estaContenido(m,vec[k],fila)){
            return 0;
        }
    }
    return 1;
}

int estaContenido(const int m[][DIM],int elem, int col){
    for(int i=0;i<DIM;i++){
        if(m[i][col]==elem){
            return 1;
        }
    }
    return 0;
}