/*Escribir la función nQueens que,dada una matriz de chars de NxN,verifique si
 el mismo contiene Nreinas de ajedrez de forma tal que ninguna reina amenacea
 otra.Una reina amenaza a otra si está en la misma fila,columna o en alguna de
 sus dos diagonales.Una posición libre se indica con el valor '0' y una celda con
 una reina se indica con el valor '1'.Se asume que en el tablero sólo hay caracteres
 ceros y unos,no es necesario validarlo.
 */
#include <stdio.h>
#include <assert.h>

#define QUEEN '1'
#define DIRECCIONES 8
int errorParametros(int x, int y, unsigned int N);
int nQueens(unsigned int N,char m[][N]);
int buscoQueen(unsigned int N, char m[][N],int fila, int col);
int buscoEnDir(unsigned int N, char m[][N],int fila, int col, int x, int y);

int main(void) {
char board[][8] = {
{'0', '0', '0', '0', '1', '0', '0', '0'},
{'0', '0', '1', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '1', '0', '0', '0'},
{'0', '0', '0', '0', '0', '0', '0', '0'},
{'0', '1', '0', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0', '0', '1', '0'},
{'1', '0', '0', '0', '1', '0', '0', '0'},
{'0', '0', '0', '0', '0', '0', '0', '1'},
};
// por ejemplo, hay tres reinas en la columna 4 y dos en la fila 6
assert(nQueens(8, board) == 0);
char board2[][6] = {
{'0', '0', '0', '1', '0', '0'},
{'1', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '1', '0'},
{'0', '1', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0', '1'},
{'0', '0', '1', '0', '0', '0'}
};
// Hay 6 reinas y no se atacan, retorna true
assert(nQueens(6, board2));
char board3[][6] = {
{'0', '0', '1', '0', '0', '0'},
{'1', '0', '0', '0', '0', '0'},
{'0', '1', '0', '0', '0', '0'},
{'0', '0', '0', '0', '1', '0'},
{'0', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0', '1'}
};
// Las reinas en (1,0) y (2,1) se amenazan en forma diagonal
assert(nQueens(6, board3) == 0);
char board4[][6] = {
{'0', '0', '0', '1', '0', '0'},
{'0', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '1', '0'},
{'0', '1', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0', '1'},
{'0', '0', '1', '0', '0', '0'}
};
// No se amenazan pero hay menos de 6 reinas
assert(nQueens(6, board4) == 0);
// No hay solución para tableros de dimensión 2 o 3
assert(nQueens(3, board2) == 0);
assert(nQueens(2, board2) == 0);
// En un tablero de 1x1 debe haber una reina
char board1[][1] = {{'1'}};
assert(nQueens(1, board1));
puts("OK!");
return 0;
}


int errorParametros(int x, int y, unsigned int N){
    return(N<=x || N<=y || x<0 || y<0 );
}

int nQueens(unsigned int N,char m[][N]){
    if(N==2 || N==3){
        return 0;
    }
    if(N==1){
        return (m[0][0]==QUEEN);
    }
    int flag=1; //Asumo que es valida 
    int cont=0;
    for(int i=0;i<N && flag;i++){           //Recorro la matriz y busco las reinas mientras que no haya encontrado una reina que no sea valida
        for(int j=0;j<N && flag;j++){
            if(m[i][j]==QUEEN){
                cont++;
                flag=buscoQueen(N,m,i,j);
            }
        }
    }
    return flag && cont==N;
}


//Funcion auxiliar que verifica si una reina en la posicion fila,col es valida (Que no este amenazada)
int buscoQueen(unsigned int N, char m[][N],int fila, int col){
    static int dir[2][DIRECCIONES]={{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,1,0,-1,-1}};
    for(int i=0;i<DIRECCIONES;i++){
        if(buscoEnDir(N,m,fila,col,dir[0][i],dir[1][i])){  //Si encontre una reina en esa direccion => No es valida
            return 0;
        }
    }
    return 1;
}
//Funcion auxiliar que verifica si hay una reina en la direccion x,y   (Devuelve 1 si esta amenazada)
int buscoEnDir(unsigned int N, char m[][N],int fila, int col, int x, int y){
    int posX=fila+x;
    int posY=col+y;
    while(!errorParametros(posX,posY,N)){   //Mientras no me pase de los limites del tablero => Sigo buscando. 
        if(m[posX][posY]==QUEEN){
            return 1;
        }else{
            posX+=x;
            posY+=y;
        }
    }
    return 0;
}
//--------------------------------Solucion Catedra--------------------------------------------------
/*
int hasQueen(unsigned int n, char tablero[][n], int row, int col, int dir[2]){
    for(int i = row, j = col; i >= 0 && i < n && j >=0 && j < n; i += dir[0], j += dir[1]){
        if(tablero[i][j] == '1'){
            return 1;
        }
    }
    return 0;
}

int underAttack(unsigned int n, char tablero[][n], int row, int col){
    static int dir[][2] = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1},{-1,-1},{-1,0},{-1,1}};
    int nearQueen = 0;
    for(int i = 0; i < DIRECCIONES && !nearQueen; i++){
        nearQueen = hasQueen(n, tablero, row + dir[i][0], col + dir[i][1], dir[i]); // dir[i][0] y dir[0]
    }
    return nearQueen;
}

int nQueens(unsigned int n, char tablero[][n]){
    if(n == 2 || n == 3){
        return 0;
    }

    int safe = 1;
    int queens = 0;
    for(int i = 0; i < n && safe; i++){
        for(int j = 0; j < n && safe; j++){
            if(tablero[i][j] == '1'){
                queens++;
                safe = !underAttack(n, tablero, i, j);
            }
        }
    }
    return safe && queens == n;
}
*/