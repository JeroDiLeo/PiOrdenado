/*
 Escribir una función contieneFilas que reciba dos matrices de enteros de
 NxN, donde N es una constante previamente definida.
 Se dice que una fila A está contenida en la fila B si todos los elementos de A
 (sin importar el orden y repetición) están en la fila B. 
 Por ejemplo la fila {1,3,1,4} está contenida en la fila {2,3,4,1}, la fila {1,1,1,1} está contenida en la fila {3,1,4,5}
 Se dice que una fila A está contenida en una matriz M si la fila A está
 contenida en alguna de las filas de M.
 Se dice que una matriz M1 está contenida en la matriz M2 si todas las filas de
 M1 están contenidas en M2.

 La función debe retornar:
 ● 1si la primera matriz está contenida en la segunda
 ● 2si la segunda matriz está contenida en la primera matriz
 ● 0sinosecumple ninguna de las condiciones anteriores

 Pensamiento:{
        -primero recibe dos matrices
        -desp un vec y una matriz 
        -desp dos vec
        -desp un vec y un elemento
        }
*/

//--------------------------CHEQUEADO(Javi)----------------------------------------
 #include <stdio.h>
 #define N 4

 
int existeEnFila(int elem, int fila[]);
int esVecContenido(int vec1[],int vec2[]);
int filaEnMatriz(int fila,int m2[][N]);
int contieneTodas(int m1[][N],int m2[][N]);
int contieneFila(int m1[][N], int m2[][N]);


int main(){
 }

int contieneFila(int m1[][N], int m2[][N]){
    if(contieneTodas(m1,m2)){
        return 1;
    }else if(contieneTodas(m2,m1)){
        return 2;
    }else{
        return 0;
    }
 }

//Verifica si todas las filas de m1 estan contenidas en m2
int contieneTodas(int m1[][N],int m2[][N]){
    for(int i=0;i<N;i++){
        if(!filaEnMatriz(m1[i],m2)){    //Si alguna fila no esta contenida, salgo
            return 0;
        }
    }
    return 1;
}

//Verifica si una fila esta contenida en alguna de las filas de la otra matriz
int filaEnMatriz(int fila[],int m2[][N]){
    int filaEncontrada=0;   //Supongo que la fila no esta
    for(int i=0;i<N && !filaEncontrada;i++){    //Recorro mientras no lo haya encontrado
        if(esVecContenido(fila,m2[i])){
            filaEncontrada=1;
        }
    }
    return filaEncontrada;
}

//Verifica si todos los elementos de v1 estan en v2
int esVecContenido(int vec1[],int vec2[]){
    int todosContenidos=1;  //Supongo que estan todos
    for(int i=0;i<N && todosContenidos; i++){
        if(!existeEnFila(vec1[i],i)){
            todosContenidos=0;          //Si no encontre un elemento salgo
        }
    }
    return todosContenidos;
}

//Verifico si esta el elem q estoy buscando en la fila que le pase
int existeEnFila(int elem, int fila[]){
    for(int j=0;j<N;j++){
        if(fila[j]==elem){
            return 1;
        }
    }
    return 0;
}
