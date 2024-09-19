/*
Escribir la función queContiene que reciba dos strings s1 y s2. 
El string s1  puede contener cualquier valor ASCII. 
El string s2 contiene únicamente letras minúsculas o mayúsculas (no debe validarse, se asegura que sólo son letras del
 alfabeto inglés).
La función debe retornar cuántos caracteres de s1 son letras contenidas en s2, sin distinguir entre minúsculas o mayúsculas. */

//------------------------CHEQUEADO-------------------------------
#include <stdio.h>
#include <ctype.h>
#define TO_LOWER(a) ( ((a)>= 'A' && (a)<= 'Z') ? ((a) -'A'+'a') : (a) )
#define IDX(a) ((TO_LOWER(a)-'a'))

void marcarLetras(char s2[], char vecApLetras[]);
int queContiene(char s1[],char s2[]);
int main(){

}
int queContiene(char s1[],char s2[]){
    int contador=0;
    char vecApLetras[26]={0};   //Para marcar que letras contiene s2
    marcarLetras(s2,vecApLetras);

    for(int i=0;s1[i]!='\0';i++){   //Recorro el primer string
        if(isalpha(s1[i])){         //verifico que sea una letra
            if(vecApLetras[IDX(s1[i])]){     //Chequeo si esa letra estaba en s2
                contador++;
            }
        }
    }
    return contador;
}


//Funcion auxiliar para marcar las letras presentes en s2
void marcarLetras(char s2[], char vecApLetras[]){
    for(int i=0;s2[i]!= '\0';i++){
        vecApLetras[IDX(s2[i])]=1;
    }
}

