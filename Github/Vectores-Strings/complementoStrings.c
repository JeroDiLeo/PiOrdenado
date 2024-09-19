/*
Escribir la funcion void complemento, recibe un string y arma otro string
ue contenga UNICAMENTE las letras del alfabeto ingles que NO esten en el primer string
----------------------------------------------
(-)Si el string esta vacio, agrego todas las letras del alfabeto Ingles
(-)Como me piden que quede en orden alfabetico, tengo que recorrer primero todo el string y marcar las posiciones
y desp volver a recorrerlo para ir guardando en orden alfabetico
*/

//---------------------CHEQUEADO(BIEN)--------------------------------
#include <stdio.h>
#include <ctype.h>
#define LETTERS 26

int index(char letter);
void llenoVecAp(char vecAp[], char s[]);
void complemento(char s[], char out[]);
int main(){
    
}





void complemento(char s[], char out[]){
    char lettersOnString[LETTERS]={0};
    int k=0;    //Lo voy a usar para ir moviendome en el vec OUT
    llenoVecAp(lettersOnString,s);
    for(int i=0;i<LETTERS;i++){             //Recorro todas las posiciones del VecAp y si la letra NO estaba en el string de entrada => La copio
        if(lettersOnString[i]==0){  
            out[k++]=(i+'A');       //convierto el indice en una letra
        }
    }
    out[k]='\0';
}


int index(char letter){
    return (toupper(letter)-'A');
}
void llenoVecAp(char vecAp[], char s[]){      
    for(int i=0;s[i]!='\0';i++){
        if(isalpha(s[i])){                  //Chequeo que sea una letra
            vecAp[index(s[i])]=1;
        }
    }
}