/*Escribir una función esMagica que reciba como único parámetro una matriz de enteros de N filas y N columnas y determine si es un “cuadrado mágico”.
Una matriz es cuadrado mágico cuando:
es cuadrada (NxN) (donde N es una constante simbólica)
tiene todos los números del 1 al N2
la suma de los elementos de cualquier fila es igual a la suma de los elementos de cualquier columna

Pensamiento:
    (La matriz es cuadrada)
    Como me piden que chequee q se cumple para todas las filas y columnas, si una no cumple listo.(asumo que cumple)

*/
#define N 3
#include <stdio.h>
#include <assert.h>
#define NUMBERS (N*N)
int esMagica(const unsigned int m[N][N]);

int main(void) {

	int m1[N][N] = {{4,9,2}, {3,5,7}, {8,1,6}};
	int m2[N][N] = {{4,9,2}, {4,5,6}, {7,1,7}};
	int m3[N][N] = {{5,5,5}, {5,5,5}, {5,5,5}};
	int m4[N][N] = {{3,10,2}, {4,2,9}, {8,3,6}};

	assert(esMagica(m1));
	assert(!esMagica(m2));
	assert(!esMagica(m3));
	assert(!esMagica(m4));
	

	puts("OK");
}

int esMagica(const unsigned int m[][N]){
    int vecAp[NUMBERS]={0};
    int valor,sumaCol,sumaFil,sumaRef;
    sumaCol=sumaRef=sumaFil=0;

    for(int i=0;i<N;i++){
        if(sumaFil!=sumaRef || sumaCol!=sumaRef){
            return 0;
        }
        sumaCol=0;
        sumaFil=0;
        for(int j=0;j<N;j++){
            valor=m[i][j];
            if(vecAp[valor-1]||valor>NUMBERS){
                return 0;
            }else{
                sumaFil+=m[i][j];
                sumaCol+=m[j][i];
                vecAp[valor-1]=1;
            }
        }
        if(i==0){
            sumaRef=sumaFil;
        }
        
    }
    return 1;
}