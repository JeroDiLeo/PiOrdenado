/*
Escribir una función que reciba una matriz cuadrada de dimensión N (N es una constante previamente definida) y 
retorne 1 si la misma cumple con las siguientes condiciones:
1) Contiene todos los números de 1 a N * N inclusive
2) En cada fila contiene números consecutivos, no necesariamente ordenados
Ejemplos:
Si N es 5, se debe cumplir que tenga todos los números del 1 al 25 y la primer fila tenga los números del 1 al 5 
(no necesariamente en ese orden), la segunda fila los números del 6 al 10, la tercera fila del 11 a 15, la cuarta 
fila del 16 al 20 y la última del 21 al 25.
Si N es 3, se debe cumplir que tenga los números de 1 a 9 y que la primer fila tenga los números del 1 al 3, la 
segunda del 4 al 6 y la última del 7 al 9.

Si N es 4 y recibe la siguiente matriz, debe retornar 1:
 
 3  4  1  2
 8  7  6  5 
 9 10 11 12 
15 16 13 14

Si N es 4 y recibe la siguiente matriz, debe retornar 0 (repite el 1 en la primer fila y no está el 4):
 
 3  1  1  2
 8  7  6  5
 9 10 11 12
15 16 13 14


Si N es 4 y recibe la siguiente matriz, debe retornar 0 (está el 11 en la última fila, y no está el 14):

 3  1  4  2
 8  7  6  5
 9 10 11 12
15 16 13 11

*/

//No tiene que haber repetidos
//por cada fila que pasa numero aumenta 4
#define N
int cumpleRequisitos(int m[][N]){
    int vecAp[N*N]={0};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int num=m[i][j];

            if(num<1 || num>N*N){       //Si esta fuera del rango que me permiten
                return 0;
            }

            vecAp[num-1]++;

            if(vecAp[num-1]>1){         //Si esta repetido
                return 0;
            }
        }
    }
    return 1;
}

int requirements(int m[][N]){
    if(cumpleRequisitos(m)){
        for(int i=0;i<N;i++){
            int suma=0;                //Me guardo para ver si los numeros correctos coinciden con la cant de numeros correctos x fila
            for(int j=0;j<N;j++){     //Ej en la primera fila voy de 0 a 3 (son 4 numeros)
                int num=m[i][j];
                if(num>i*N && num<=(N*(i+1))){
                    suma++;
                }
            }
            if(suma!=N){
                return 0;
            }
        }
        return 1;
    }else{
        return 0;
    }
}






#include <stdio.h>
#include <assert.h>
#define N 4

int requirments(int mat[][N]);

int main(){

  int mat[N][N] = {{3,4,1,2},{8,7,6,5},{9,10,11,12},{15,16,13,14}};

  assert(requirments(mat)==1);

  int mat2[N][N] = {{3,1,1,2},{8,7,6,5},{9,10,11,12},{15,16,13,14}};

  assert(requirments(mat2)==0);

  int mat3[N][N] = {{3,1,4,2},{8,7,6,5},{9,10,11,12},{15,16,13,11}};

  assert(requirments(mat3)==0);

  puts("OK!");
  return 0;
}