/*
Escribir la función posiciónFinal que recibe:
- Tablero: es una matriz de FILAS filas y COLS columnas, donde FILAS y COLUMNAS sonconstantes simbólicas previamente definidas
- Posición inicial de una bola en el tablero: (xi, yi), ambos parámetros enteros
- Dirección de movimiento (dirx, diry) ambos parámetros enteros
- Pasos (n), donde n es entero
-
La función deberá retornar en dos variables (xf, yf), de tipo entero, 
la posición final de la bola en el tablero si se mueve n pasos a partir de (xi, yi) en la dirección indicada por (dirx,diry), 
actualizando el tablero con una ‘B’ en la posición final. La dirección indicada (dirx, diry) puede ser alguna de estas:

(0,1)
(0,-1)
(1,1)
(1,-1)
(-1,1)
(-1,-1)
(1,0)
(-1,0)

Ejemplo: Si la casilla sombreada es la que corresponde a (xi, yi) = (1,1) , y la dirección es (-1, -1), se muevehacia (0,0)

Al efectuar n pasos, si llega a un borde deberá detenerse allí.La función devolverá EXITO si pudo completar los n pasos en la dirección indicada.
La función devolverá ERRORPASOS si no puede completar los n pasos en la dirección indicada.
La función devolverá ERRORPARAMETROS si hay error en los argumentos de la función.
*/

#define FILS    3
#define COLS    3
#define EXITO 1
#define ERRORPASOS 2
#define ERRORPARAMETROS 3
#define DIR 8

//Verifica que este en un lugar valido
int dentroDelTablero(int x,int y){
    return(x>=0&& x<FILS && y>=0 && y<COLS);
}
int direccionesPermitidas(int dirx,int diry){
    return((dirx>=-1 && dirx<=1)&&(diry>=-1 && diry<=1))
}

//Xi es fila inicial, Yi es Columna inicial
int posicionfinal(char tablero[][COLS],int xi, int yi,int dirx,int diry,int n,int *xf, int *yf){

    if(!dentroDelTablero(xi,yi)||!direccionesPermitidas(dirx,diry)||n<=0){
        return ERRORPARAMETROS;
    }

    int x=xi;
    int y=yi;

    for(int paso=0;paso<n;paso++){
        nx=x+dirx;
        ny=y+diry;

        if(!dentroDelTablero(nx,ny)){   //si se sale del tablero con este paso, me guardo la posicion final del paso anterior
            *xf=x;
            *yf=y;
            return ERRORPASOS
        }
        x=nx;
        y=ny;
    }
    tablero[x][y]='B';
    *xf=x;
    *yf=y;
    
    return EXITO;


}










//---------------------Si no me pasara dirx y dirY como param----------------------


// Matriz de direcciones: cada fila representa una dirección (dx, dy)
int direcciones[][2] = {
    {0, 1},   // (0,1)
    {0, -1},  // (0,-1)
    {1, 1},   // (1,1)
    {1, -1},  // (1,-1)
    {-1, 1},  // (-1,1)
    {-1, -1}, // (-1,-1)
    {1, 0},   // (1,0)
    {-1, 0}   // (-1,0)
};

// Función para verificar si una posición está dentro del tablero
int dentroDelTablero(int x, int y) {
    return (x >= 0 && x < FILS && y >= 0 && y < COLS);
}

// Función principal para calcular la posición final y actualizar el tablero
int posicionfinal(char tablero[][COLS], int xi, int yi, int dir, int n, int *xf, int *yf) {
    // Verificar parámetros
    if (!dentroDelTablero(xi, yi) || dir < 0 || n <= 0) {
        return ERRORPARAMETROS;
    }

    int dirx = direcciones[dir][0];
    int diry = direcciones[dir][1];

    // Calcular posición final
    int x = xi;
    int y = yi;
    for (int paso = 0; paso < n; paso++) {
        int nx = x + dirx;
        int ny = y + diry;

        if (!dentroDelTablero(nx, ny)) {
            // Si se sale del tablero, detenerse
            *xf = x;
            *yf = y;
            return ERRORPASOS;
        }

        x = nx;
        y = ny;
    }

    // Actualizar el tablero con 'B' en la posición final
    tablero[x][y] = 'B';
    *xf = x;
    *yf = y;

    return EXITO;
}




















#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define FILAS 8
#define COLS 8
#define EXITO 1
#define ERRORPASOS 2
#define ERRORPARAMETROS 3
#define DIRECCIONES 8

int posicionFinal(int tablero[FILAS][COLS], int xi, int yi, int dirx, int diry, int n, int *xf, int *yf);

static int setFinalPosition(int f, int fils);

int main(){
    int tablero[FILAS][COLS]={0};
    int xi, yi;
    int xf, yf;
    int n;  
    int dirx, diry;
	xi = yi = 0;
	dirx = diry = 1;
	n = 4;
    assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf)==EXITO);
    assert(xf==4 && yf==4);
    assert(tablero[xf][yf]=='B');
	
	xi = yi = 0;
	dirx = -1; 
	diry = 0;
	n = 2;
    assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf)==ERRORPASOS);
    assert(xf==0 && yf==0);
    assert(tablero[xf][yf]=='B');
    
	xi = yi = 2;
	dirx = -1; 
	diry = 0;
	n = 2;
	assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf)==EXITO);
    assert(xf==0 && yf==2);
    assert(tablero[xf][yf]=='B');
    
	xi = -1;
	dirx = -1;
	yi = 0;
	diry = 0;
	n = 2;
	assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf)==ERRORPARAMETROS);
    
	xi = yi = 3;
    dirx = diry = 1;
    n = 3;
    assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf) == EXITO);
    assert(xf == 6 && yf == 6);
	assert(tablero[xf][yf]=='B');

    dirx = 0;
    diry = 1;
    n = 4;
    assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf) == EXITO);
    assert(xf == 3 && yf == 7);
	assert(tablero[xf][yf]=='B');

    n = 5;
    assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf) == ERRORPASOS);
	assert(tablero[xf][yf]=='B');
	
    dirx = diry = -1;
    n = 20;
    assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf) == ERRORPASOS);
	assert(tablero[xf][yf]=='B');
	
    dirx = diry = 0;
    n = 3;
    assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf) == ERRORPARAMETROS);

    dirx = diry = 2;
    assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf) == ERRORPARAMETROS);
	
    dirx = -1;
    diry = -2;
    assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf) == ERRORPARAMETROS);

    dirx = 0;
    diry = -1;
    n = -2;
    assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf) == ERRORPARAMETROS);

    xi = yi = -1;
    n = 1;
    assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf) == ERRORPARAMETROS);

    xi = yi = 20;
    assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf) == ERRORPARAMETROS);

    xi = yi = 0;
    assert(posicionFinal(tablero, xi, yi, dirx, diry, n, &xf, &yf) == ERRORPASOS);
	assert(tablero[xf][yf]=='B');
	
    printf("OK!");
    return EXIT_SUCCESS;
}