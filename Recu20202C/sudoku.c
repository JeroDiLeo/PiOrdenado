/*
Se resuelve igual que el del parcial (ver si es solución completa de Sudoku) pero ignorando las celdas con un cero. Esto es, si es cero o está entre 1 y 9 y no está repetida entonces esa celda es válida*/

#define DIM 9

int chequearFilCol(char m[][DIM]){
   for ( int i=0; i<DIM; i++) {
       char vFil[DIM] = {0};
       char vCol[DIM] = {0};
       for(int j = 0; j < DIM; j++){
           if(vFil[m[i][j]-1]++ == 1){
               return 0;
           }
           if(vCol[m[j][i]-1]++ == 1){
               return 0;
            }
        }
    }
   return 1;
}
       

int chequearSubcuadrado(char m[][DIM], int fil, int col){
   int i, j;
   char v[9] = {0};
   for(i = fil; i < fil + 3; i++){
       for(j = col; j < col + 3 && ok; j++){
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

int chequearSudoku(char m[][DIM]){
   int i, j, ok =1;
   for(i = 0; i < DIM && ok; i += 3){
       for(j = 0; j < DIM && ok; j+= 3){
           ok = chequearSubcuadrado(m[i][j], i, j);
       }
   }
   // Al verificar los cuadrados verificamos que estén entre 1 y 9
   if(ok){
      int k;
      for(k = 0; k < DIM && ok; k++){
            ok = chequearFil(m[k]);
      }
      if(ok){
            int n;
            for(n = 0; n < DIM && ok; n++){
                 ok = chequearCol(m, n);
             }
      }
   }
   return ok;
}
