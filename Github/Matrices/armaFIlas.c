/*ArmaFilas: recibe una mat de enteros de N filas y M columnas y un vector de dim N
Tarea: armar los numeros que se forman con cada fila y guardarlos en el vector.
Si hubiera numeros negativos o de mas de una cifra en una fila, no se completa el armado de ese numero pero se sigue con la proxima fula.
La funcion retorna en su nombre la dimension final del vector de numeros
*/
#include <stdio.h>
#include <assert.h>
#define N 4
#define M 5
#define ERROR -1
#define errorDeParametros(a) ((a)>=0 && (a)<=9)

int armaFilas(const int m[][M], unsigned int vec[]);

int main(void)
{
     int m1[N][M] = { { 1,2,3,4,5},
                { 1,2,13,4,5},
                { 1,2,4,4,5},
                { 1,2,-3,4,5}};
    int vec[N];
    int n = armaFilas(m1, vec);
    assert(n==2);
    assert(vec[0]==12345);
    assert(vec[1]==12445);

    int m2[N][M] = { { 1,0,3,4,5},
                { 0,2,1,4,5},
                { 9,9,9,9,9},
                { 0,0,1,4,5}};
     n = armaFilas(m2, vec);
    assert(n==4);
    assert(vec[0]==10345);
    assert(vec[1]==2145);
    assert(vec[2]==99999);
    assert(vec[3]==145);


    int m3[N][M] = { { 11,0,3,4,5},
                { 0,2,1,14,5},
                { 9,9,9,91,9},
                { 0,0,1,14,5}};
     n = armaFilas(m3, vec);
    assert(n==0);
    

    printf("OK!\n");
    return 0;
}




int armaFilas(const int m[][M],unsigned int vec[]){
    int i,valor,k=0;
    for(i=0;i<N;i++){
        valor=ArmaNumero(i,m);
        if(valor!=ERROR){
            vec[k++]=valor;
        }
        
    }
    return k;
}

int ArmaNumero(unsigned int fila,const int m[][M]){
    int j,suma=0,numero,flagError=0;
    for(j=0;j<M&& (!flagError);j++){     //mientras que no encuentre un error
        numero=m[fila][j];
        if(errorDeParametros(numero)){
            suma=(suma*10)+numero;
        }else{
            flagError=1;
        }

    }
    if(flagError){
        return ERROR;
    }else{
        return suma;
    }
}