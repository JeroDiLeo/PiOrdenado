/*
Escribir la función esTableroValido que reciba como argumento una matriz de
signed chars, de dimensión DIM (donde DIM es una constante previamente definida) que
representa un tablero del juego Buscaminas. La función debe determinar si la
configuración del tablero es válida según las reglas del juego de Buscaminas.
Un tablero de Buscaminas válido cumple con las siguientes condiciones:
● Cada celda del tablero contiene uno de los siguientes valores:
○ -1 si hay una mina en esa posición.
○ Un número positivo indicando la cantidad de minas adyacentes a esa
posición.
○ 0 si no hay minas adyacentes.
El siguiente es un tablero válido
-1 3 -1
-1 3 1
1 1 0
El siguiente es un tablero válido
-1 3 -1
-1 6 3
-1 -1 -1
El siguiente es un tablero inválido
-1 2 -1
-1 2 1
1 1 0
El siguiente es un tablero inválido
-1 0 -1
-1 3 1
1 1 0
Un tablero únicamente formado por minas (-1 en todas las posiciones) es un tablero válido
Un tablero sin minas (0 en todas las posiciones) es un tablero válido
*/
#include <stdio.h>
#define DIM 
#define MINA -1
#define EN_TABLERO(i,j,alto,ancho) ((i)>=0 && (i)<(alto)&&(j)>=0 && (j)<(ancho))
#define DIRECCIONES 8



int buscoMinas(signed char tablero[][DIM],int fila, int col, int numero){
    static int dir[2][8]={{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,1,0,-1,-1}};
    int flag, cantMinas=0;
    for(i=0;i<DIRECCIONES;i++){
        int x=dir[0][i];
        int y=dir[1][i];
        if(EN_TABLERO(fila,col,x,y)){
            if(tablero[x+fila][y+col]==MINA){
                cantMinas++;
            }
        }
    }
    return cantMinas==numero;
}

int esTableroValido(signed char tablero[][DIM]){
    int esValido=1;         //Asumo que cumple
    for(int i=0;i<DIM && esValido;i++){
        for(int j=0;j<DIM && esValido;j++){
            if(tablero[i][j]!=MINA){
                esValido=buscoMinas(tablero,i,j,tablero[i][j]);
            }
        }
    }
    return esValido; 
}