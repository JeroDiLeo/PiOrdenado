/*Escribir la función nQueens que, dada una matriz de chars de NxN, verifique si
el mismo contiene N reinas de ajedrez de forma tal que ninguna reina amenace a
otra. Una reina amenaza a otra si está en la misma fila, columna o en alguna de
sus dos diagonales. Una posición libre se indica con el valor '0' y una celda con
una reina se indica con el valor '1'. Se asume que en el tablero sólo hay caracteres
ceros y unos, no es necesario validarlo.

*/
#include <stdio.h>
#include <assert.h>

#define DIR 8

int nQueens(unsigned int n, char mat[][n]);
int isUnderAttack(unsigned int n, char mat[][n], int row, int col);
int hasQueen(unsigned int n, char mat[][n],int row, int col, int dir[2]);

int nQueens(unsigned int n, char mat[][n]){
	if ( n==2 || n==3) {        // Si el tablero es de 2x2 o 3x3 no se puede poner n reinas
		return 0;
	}
    int rta = 1;
	int queens = 0;
    for (int i = 0; i < n && rta; i ++){
        for (int j = 0; j < n && rta; j++){
                if(mat[i][j]=='1') {    // Si hay una reina en la posición i,j se verifica que no esté amenazada
					queens++;
                    rta = ! isUnderAttack(n, mat, i, j);
				}
        }
    }
    return rta && queens==n;        // Se verifica que no haya más ni menos de n reinas
}
int isUnderAttack(unsigned int n, char mat[][n], int row, int col){
    static int direcciones [][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};   
    int rta = 0;
    for(int d=0; d < DIR && !rta; d++){
        rta = hasQueen(n, mat, row+direcciones[d][0],col+direcciones[d][1], direcciones[d]);
    }
    return rta;
}
int hasQueen(unsigned int n, char mat[][n], int row, int col, int dir[2]){
    for(int i = row, j = col; i >=0 && i <n && j >= 0 && j < n ; i+=dir[0],j+=dir[1])
            if(mat[i][j]=='1')
                return 1;
    return 0;
}