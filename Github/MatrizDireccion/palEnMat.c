/*
Escribir una función palEnMat que reciba:
    ● una matriz cuadrada de chars de dimensión N (con N constante simbólica previamente definida)
    ● un puntero a entero que indica una fila
    ● un puntero a entero que indica una columna
    ● un string
y retorne 1 si el string se encuentra dentro de la matriz, ya sea en sentido
horizontal, vertical o diagonal y en cualquier dirección. 
En caso de haberla encontrado, debe dejar en el parámetro fila la fila en que comenzó la palabra
encontrada y en el parámetro columna la columna en la que comenzó la palabra
indicada
Ejemplos:
Para la siguiente matriz y con N = 6
L O B R A Z
F H R G O R
C O S A D A
R L A H N N
W A O Y U T
Q S G S M A
2
● Si recibe "SAL" debe retornar 1, y en fila el valor 5 y en columna el
valor 1
● Si recibe "A" retorna 1 y hay varios posibles valores para fila y
columna, por ejemplo 0 y 4, 2 y 3, 2 y 5, etc.
● Si recibe "HOLA" retorna 1, y en fila el valor 1 y en columna el valor 1
● Si recibe "XXX" retorna 0 y no modifica fila ni columna
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define DIM
#define MAXDIR
#define ERROR -1
#define DIRECCIONES

int errorParams(int x,int y){
    return (x<0||x>=DIM||x<0 || y>=DIM);
}


int PalEnMAt(char m[][DIM],int *fila, int *col, char s[]){
    if(!isalpha(s[0])){     //Si el primer carac del string NO es una letra
        return ERROR;
    }
    int flag=0,i,j; //Asumo que no esta la palabra
    for(i=0;i<DIM && !flag;i++){
        for(j=0;j<DIM && !flag;j++){
            if(m[i][j]==s[0]){
                flag=buscoPal(m,i,j,s);
            }
        }
    }
    if(flag){    //Si la palabra esta guardo el inicio
        *fila=i-1;
        *col=j-1;   
    }
    return flag;
}
//Funcion aux que verifica que la palabra esta completa
int buscoPal(char m[][DIM], int fila,int col,char s[]){
    static int dir[2][DIRECCIONES]={{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,1,0,-1,-1}};
    int flag=0;
    for(int i=0;i<DIM && !flag;i++){
        flag=buscoEnDIr(m,fila,col,s,dir[0][i],dir[1][i]);
    }
    return flag;    
}

int buscoEnDir(char m[][DIM], int fila, int col,char s[],int x,int y){
    int i=fila;
    int j=col;
    int k=0;
    while(!errorParams(fila+x,col+y)&& s[k]==m[i][j] && s[k]!='\0'){
        i+=x;
        j+=y;
        k++;
    }
    return s[k]=='\0'  //Si efectivamente recorri toda la palabra y estaba
}