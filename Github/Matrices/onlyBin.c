/*
Dada una matriz de chars donde COLS esta previamente definida
Verificar que las filas que representan numeros binarios
Escribir una funcion onlybin que reciba la matri y la cant de filas de la misma,
y elimine de la matriz las filas que no representen numeros binarios.
Debe retornar cuantas filas quedaron en la matriz.
(Asumo matriz cuadrada)
*/
#include <stdio.h>
#define COLS

//Ver si de esta manera va o si conviene dejar la que esta bien, encontrar la que esta mal y si la siguiente esta bien, pisar con la pos anterior
int onlybin(char m[][COLS],int FILS){
    int i,j,k=0;
    for(i=0;i<FILS;i++){
        if(isBin(m[i])){
            for(j=0;j<COLS;j++){
                m[k][j]=m[i][j];
            
            }
            k++;
        }
        
    }
    return k;
}


//Si encuentra algun elemento en la fila que no sea ni 0 ni 1, devuelve 0
int isBin(int fila[]){
    for(int j=0;j<COLS;j++){
        if(fila[j]!='0'&& fila[j]!='1'){
            return 0;
        }
    }
    return 1;
}

