/*
Escribir una funcion verifica que recibe como unico parametro una matriz de enteros de N*N
La funcion debe retornar 1 si se cumplen todas las condiciones:
    -TODOS los elem estan entre 1 y 3*N INCLUSIVE
    -En cada submatriz de 3x3 no se pueden repetir elementos
    -AL sumar los elementos de cada submatriz de 3x3 se obtiene el mismo resultado
*/
/*
Pensamiento
    Una funcion que verifique un subcuadrado(Aca reviso que todos los elementos estan en rango)(Deberia guardar en un puntero la suma)
    Una funcion que verifique todos los subcuadrados y que se fije si todas las sumas son iguales(Guardando los valores en un vec)-Posiblemente en una fun aux 
    */


//-------------------------------------------CHEQUEADO(Javi y chelo)--------------------------------
#include <stdio.h>
#include <assert.h>
#define N 6 
#define NUMVALIDO(a) ((a)>=1 && (a)<=3*N)
#define NUMBERS 3*N
#define ERROR -1

int verificaSubcuadrados(int m[][N],int fila,int columna);
int verifica(int m[][N]);
int main(){
}


int verificaSubcuadrados(int m[][N],int fila,int columna){
    int valor,i;
    int suma=i=0;
    int vecAp[NUMBERS]={0};             //Me armo un vecAp para ver los repetidos
    for(i=fila;i<fila+3;i++){
        for(int j=columna;j<columna+3;j++){
            valor=m[i][j];
            if(!NUMVALIDO(valor)||vecAp[valor-1]==1){   //Si hay algun numero fuera de rango o repetido, devuelvo que no cumple (ERROR)
                return ERROR;
            }else{
                vecAp[valor-1]=1;
            }
        }
    }
    return suma;
}

int verifica(int m[][N]){
    int verifica=1; 
    int sumaAnterior;                                //Asumo que Verifican todos los subcuadrados
    for(int i=0;i<N && verifica;i+=3){
        for(int j=0;j<N && verifica;j+=3){
            if (!i && !j){
                sumaAnterior = verificaSubcuadrados(m, i, j);
            }else{
                int sumaActual=verificaSubcuadrados(m,i,j);
                if(sumaActual==ERROR || sumaActual!=sumaAnterior){    //Si Algun subcuadrado no es valido o no suma lo mismo que el primero,sale
                    verifica=0;
                }
            }
        }
    }
    return verifica;
}

