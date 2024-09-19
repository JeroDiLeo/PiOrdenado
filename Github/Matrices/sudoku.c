/*
sudoku:9 filas 9 columnas
cada casilla tiene que tener un numero del 1 al 9
Por fila no hay valores repetidos
Por Columna no hay valores repetidos
Por subcuadrado no hay valores repetidos
*/
#include <stdio.h>
#include <assert.h>
#define NUMBERS 9
#define DIM 9
#define NUMVALIDO(a) ((a)>=1 && (a)<=9)

int chequeoSubCuadrados(int m[][DIM],int fila, int columna);
int chequeoColumna(int columna, int m[][DIM]);
int chequeoFila(int fila, int m[][DIM]);
int sudokuSolver(char m[][DIM]);

int main(void) {
  // Una matriz vacía no es solución
  char sudoku[DIM][DIM] = {{0}};

  assert(sudokuSolver(sudoku)==0);

  char sudoku2[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,2}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku2)==1);
  
  char sudoku3[DIM][DIM] = {
        {2,8,1,9,7,6,5,4,2}, 
        {3,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku3)==0);
  
  // Cuando se tomó este ejercicio en un parcial, en una de las respuestas
  // sólo chequeaban que la suma de cada fila, columna y cuadrado fuera 45
  char sudoku4[DIM][DIM] = {
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}
  };

  assert(sudokuSolver(sudoku4)==0);

  char sudoku5[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,12}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku5)==0);

  return 0;
}

int sudokuSolver(char m[][DIM]){
    int cumple=1;
    for(int i=0;i<DIM && cumple!=0;i+=3){
        for(int j=0;j<DIM && cumple!=0;j+=3){
            cumple=chequeoSubCuadrados(m,i,j);
        }
    }
    if(cumple==1){
        for(int k=0;k<DIM && cumple!=0;k++){
            if(!chequeoFila(k,m)){
                cumple=0;
            }
        }
        if(cumple==1){
            for(int h=0;h<DIM && cumple!=0;h++){
                if(!chequeoColumna(h,m)){
                    cumple=0;
                }
            }
        }
    }
    return cumple;
}



int chequeoSubCuadrados(int m[][DIM],int fila, int columna){
    int aux;
    int vecAp[NUMBERS]={0};
    for(int i=fila;i<(fila+3);i++){
        for(int j=columna;j<(columna+3);j++){
            aux=m[i][j];
            if(!NUMVALIDO(aux) || vecAp[aux-1]==1){
                return 0;
            }else{
                vecAp[aux-1]=1;
            }
        }
    }
    return 0;
}

int chequeoColumna(int columna, int m[][DIM]){
    int vecAp[NUMBERS]={0};
    for(int i=0;i<DIM;i++){
            if(vecAp[m[i][columna]-1]==1 || !NUMVALIDO(m[i][columna])){
                return 0;
            }else{
                vecAp[m[i][columna]-1]=1;
            }
        
    }
    return 1;
}

int chequeoFila(int fila, int m[][DIM]){
    int vecAp[NUMBERS]={0};
    for(int j=0;j<DIM;j++){
        if(vecAp[m[fila][j]-1]==1 || !NUMVALIDO(m[fila][j])){        //Le resto uno para estar en rango, SI el vec de ap esta encendido(es decir q estaba antes el num)
            return 0;
        }else{
            vecAp[m[fila][j]-1]=1;
        }               
    }
    return 1;
}


//------Optimizacion catedra------------------

// Otra versión posible sería chequear filas y columnas en una sola función, evitando recorrer dos veces la matriz. Luego de verificar los subcuadrados, se llamaría a esta función
// Además creamos el vector auxiliar con una posición más (un solo char) para evitar restar 1 todo el tiempo
int chequearFilCol(char m[][DIM]){
   for ( int i=0; i<DIM; i++) {
       char vFil[DIM+1] = {0};
       char vCol[DIM+1] = {0};
       for(int j = 0; j < DIM; j++){
           if(vFil[m[i][j]]++ == 1){
               return 0;
           }
           if(vCol[m[j][i]]++ == 1){
               return 0;
           }
        }
   }
   return 1;
}
