/*Escribir la función interseccion que reciba dos matrices m1 y m2 con igual cantidad de filas y columnas 
(dadas por las constantes simbólicas FILS y COLS), 
y una tercera matriz donde se guardará el resultado (también de dimensiones FILS y COLS). 
En cada fila i de la matriz resultado debe dejar -sin repetidos- la intersección de las flas i de las matrices m1 y m2.
 Si la cantidad de elementos resultantes es menor a COLS debe completar la fila con ceros

Consideraciones:
Los elementos de las matrices m1 y m2 son mayores a cero (no hace falta validarlo)
Los elementos en cada fila no están ordenados y pueden contener repetidos
Las 3 matrices tienen la misma cantidad de filas y columnas
En cada fila de la matriz resultado no debe haber números repetidos (exceptuando los ceros del final)
El orden en que quedan guardados los números de cada fila de la matriz resultado no es importante.
La matriz de salida no está inicializada.
Las matrices m1 y m2 no deben ser modificadas
Se asegura que FILS y COLS son mayores que cero (no hay que validarlo)
*/
#include <stdio.h>
#define FILS
#define COLS

void interseccion(const unsigned int m1[][COLS],const unsigned int m2[][COLS],unsigned int m3[][COLS]){
    for(int i=0;i<FILS;i++){
        interseccionFilas(m1[i],m2[i],m3[i]);
    }
}

void interseccionFilas(const unsigned int m1[],const unsigned int m2[],const unsigned int m3[]){
    int k=0;
    for(int i=0;i<COLS;i++){
        //Primero chequeo q el elemento este en m1 y m2, y desp que no haya estado repetido, por eso lo busco en m3
        if(estaContenidoenFila(m2,COLS,m1[i]) && !estaContenidoenFila(m3,k,m1[i])){
            m3[k++]=m1[i];
        }
    }
    while(k<COLS){
        m3[k++]=0;
    }
}

int estaContenidoenFila(const unsigned int vec[],unsigned int dim,unsigned int elem){
    for(int j=0;j<dim;j++){
        valor=vec[j];
        if(valor==elem){
            return 1;
        }
    }
    return 0;
}