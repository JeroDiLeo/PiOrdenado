/*
Escribir una función que, dada una matriz de N filas y N columnas determine si es un “cuadrado
mágico”.
Una matriz es cuadrado mágico cuando:
● es cuadrada (NxN) (donde N es una constante simbólica)
● tiene todos los números del 1 al N^2                      
● la suma de los elementos de cualquier fila es igual a la suma de los elementos de cualquier
columna
Ejemplos
La siguiente matriz cuadrada de dimensión 4x4 es mágica pues están todos los números del 1 al 16 y los
elementos de cada fila y cada columna suman 34:

16 3 2 13
5 10 11 8
9  6 7 12
4 15 14 1

La siguiente matriz cuadrada de dimensión 4x4 no es mágica pues si bien están todos los números del 1
al 16, la primera fila suma 35 y la segunda 22:

16 4  5 10
11 2  3  6
12 9 13 15
 7 8  1 14

La siguiente matriz cuadrada de dimensión 3x3 es mágica pues están todos los números del 1 al 9 y los
elementos de cada fila y cada columna suman 15:

4 9 2
3 5 7
8 1 6

La siguiente matriz cuadrada de dimensión 3x3 no es mágica pues no están todos los números del 1 al 9
(faltan el 3 y el 8) a pesar de que los elementos de cada fila y cada columna suman 15:

4 9 2
4 5 6
7 1 7

*/

#define N 5
//Asumo que recibe solo numeros positivos
int verificaNumeros(int m[][N]){
    int vecAp[N*N]={0};
    for(int i=0; i<N;i++){
        for(int j=0;j<N;j++){
            int num=m[i][j];
            if(num>0 && num<=N*N){
                vecAp[num-1]++;
                if(vecAp[num-1]>1){
                    return 0;
                }
            }else{
                return 0;
            }
        }
    }
    return 1;
}
int sumaFila(int m[][N], int fila){
    int sumFila=0;
    for(int j=0;j<N;j++){
        sumFila+=m[fila][j];
        
    }
    return sumFila;
}
int sumaColumna(int m[][N],int columna){
    int sumaColumna=0;
    for(int i=0;i<N;i++){
        sumaColumna+=m[i][columna];
    }
    return sumaColumna;
}
int DiagonalesIguales(int m[][N]){
    int sumaDiagonal1=0;
    int sumaDiagonal2=0;
    for(int i=0;i<N;i++){
        sumaDiagonal1+=m[i][i];
        sumaDiagonal2+=m[i][N-1-i];
    }
    return(sumaDiagonal1==sumaDiagonal2)
}


int magicCube(int m[][N]){
    if(verificaNumeros(m)){ 
        int cont=0;
        for(int i=0;i<N;i++){
            if(sumaColumna(m,i)!=sumaFila(m,i)){
                return 0;
            }else{
                cont++;
            }
        }
        if(cont!=N){
            return 0;
        }else{
            return 1;
        }
    }else{
        return 0;
    }

}




int numeroValido(int num){
    return (num>0 && num<=(N*N))
}


int magicCube(int m[][N]){
    int vecAp[N*N]={0};
    int sumaFil,sumaCol, modelo=0;
    for(int i=0;i<N;i++){
        sumaFil=0;
        sumaCol=0;
        for(int j=0; j<N;j++){
            int fila=m[i][j];
            int col=m[j][i];
            if(!verifica(fila,col,vecAp,sumaFia,sumaCol,modelo,i)){
                return NOT_MAGIC;
            }
        }
        if(modelo!=sumaFila || modelo!=sumaCol){
            return NOT_MAGIC;
        }
        return MAGIC;
    }

}


int verifica(int fila, int col, int vecAp[], int *sumaFila,int *sumaCol, int modelo,int i){
    if(numeroValido(fila)){
        if(!vecAp[fila-1]){
            vecAp[f-1]=1;
        }else{
            return NOT_MAGIC;
        }
        if(i==0)
            modelo +=fila;
        sumaFila+=fila;
        sumaCol+=col;
    }else{
        return NOT_MAGIC;
    }
    return MAGIC;

    }
