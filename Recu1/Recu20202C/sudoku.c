/*
Se resuelve igual que el del parcial (ver si es solución completa de Sudoku) pero ignorando las celdas con un cero. Esto es, si es cero o está entre 1 y 9 y no está repetida entonces esa celda es válida*/

#define DIM 9

int chequeaSubcuadrados(char m[][DIM],int fila, int col){
    char vecAp[DIM]={0};
    for(int i=fila;i<fila+3;i++){
        for(int j=col;j<col+3; j++){
            char numero=m[i][j];
            if(numero>=1 && numero<=9 && vecAp[numero-1]==0){   //Si numero es 0 no se hace nada
                vecAp[numero-1]++;
            }else{
                return 0;
            }
        }
    }
    return 1;
}

int chequearFilYCol(char m[][DIM]){
    for(int i=0;i<DIM;i++){
        char vecApFil[DIM]={0};
        char vecApCol[DIM]={0};
        for(int j=0;j<DIM;j++){
            int numFila=m[i][j];
            int numCol=m[j][i];
            if(vecApFil[numFila]==0 && vecApCol[numCol]==0){
                vecApFil[numFila]++;
                vecApCol[numCol]++;
            }else{
                return 0;
            }

        }
    }
    return 1;
}





int chequeaSudoku(char m[][DIM]){
    int ok=1;
    for(int i=0;i<DIM && ok;i+=3){  //Mientras que ok sea 1
        for(int j=0;j<DIM;j+=3){
            ok=chequeaSubcuadrados(m[i][j],i,j);    // Al verificar los cuadrados verificamos que estén entre 1 y 9
        }
    }
    if(ok){     
        ok=chequearFilYCol(m);
    }
    return ok;
}


//----------------Otra solucion(modularizada pero menos eficiente)----------------

#define DIM 9

int chequearFil(const char m[]){
   char v[DIM] = {0};  // vector auxiliar para marcar si un dígito ya estaba
   int aux, ok = 1;
   for(int i = 0; i < DIM && ok; i++){
       aux = m[i]-1;
       if(v[aux] == 0){
           v[aux]++;
       }else{
            ok = 0; 
       }
   }
   return ok;
}

int chequearCol(char m[][DIM], int col){
   char v[DIM] = {0};
   for(int i = 0; i < DIM; i++){
       aux = m[i][col]-1;
       if(v[aux] == 1){
           return 0;
       v[aux]++;
       }
   }
   return 1;
}

int chequearSubcuadrado(char m[][DIM], int fil, int col){
   char v[9] = {0};
   for(int i = fil; i < fil + 3; i++){
       for(int j = col; j < col + 3 && ok; j++){
           aux = m[i][j];
           if(aux > = 1 && aux < = 9 && v[aux-1] == 0){
                v[aux-1]++;
            }else{
                 return 0;
            }
       }
   }
   return 1;
}

int sudokuSolver(char m[][DIM]){
   int ok =1;
   for(int i = 0; i < DIM && ok; i += 3){
       for(int j = 0; j < DIM && ok; j+= 3){
           ok = chequearSubcuadrado(m, i, j);
       }
   }
   // Al verificar los cuadrados verificamos que estén entre 1 y 9
   if(ok){
      for(int k = 0; k < DIM && ok; k++){
            ok = chequearFil(m[k]);
      }
      if(ok){
            for(int n = 0; n < DIM && ok; n++){
                 ok = chequearCol(m, n);
             }
      }
   }
   return ok;
}