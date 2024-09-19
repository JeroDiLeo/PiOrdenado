/*
Dados s1,s2 y s3
Escribir la funcion Exclude que elimine de s1 TODAS las letras sin distinguir entre minus y mayus
que esten en s2 pero NO esten en s3
------------------------------------------
No tengo que validar si es una letra
Si s2 esta vacio, no hago nada
Si s3 esta vacio,borro todos los carac que estan en s2

Cargo en vecAp los que estan en s2 pero si esta en s3, apago el flag
*/

//--------------------------CHEQUEADO(CON CHATGPT)---------------------------
#include <stdio.h>
#include <ctype.h>
#define LETRAS 26
#define TO_LOWER(a) ( ((a)>= 'A' && (a)<= 'Z') ? ((a) -'A'+'a') : (a) )
#define IDX(a) ((TO_LOWER(a)-'a'))

int exclude(char s1[],char s2[],char s3[]){
    char vecAps2[LETRAS]={0};
    char vecAps3[LETRAS]={0};
    int k=0;
    char c;
    
    if(s2[0]!='\0'){       //Para evitar recorrer si s2 es vacio
        cargoVecAp(vecAps2,s2);
        cargoVecAp(vecAps3,s3);
        for(int i=0;s1[i]!='\0';i++){
            c=IDX(s1[i]);
            if((vecAps2[c] && !vecAps3[c])){   //Si debe ser eliminado, no copio
                ;
            }else{
                s1[k++]=s1[i];  //Mantengo el caracter
            }
        }
        s1[k]='\0';
        return k;
    }

}




//Funcion Aux para marcar que letras se encontraron 
void cargoVecAp(char v[],char s[]){
    for(int i=0;s[i]!='\0';i++){
        v[IDX(s[i])]=1;
    }
}
