/*Escribir una función analize que reciba un string de nombre text (se espera que sea muy extenso) 
y un vector de chars de nombre chars que tiene al menos 256 posiciones reservadas pero no inicializadas (contienen basura). 
La función debe dejar en chars los distintos caracteres que aparecen en text , ordenados ascendentemente por valor ASCII y sin repetir.
 El vector chars debe quedar null terminated.
Como siempre, se asegura que el string contiene únicamente caracteres US-ASCII (entre 1 y 255).
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>

#define CHARSMAX 256

void llenoVecAp(const char s[],char vecAp[]);
void analize(const char text[],char chars[]);

int main(){
    char chars[CHARSMAX];
    analize("El zorro mete la cola, Pero no la pata!", chars);
    printf("%s\n",chars);
    return 0;
}
/*
void analize(const char text[], char chars[]){
    chars[CHARSMAX]={0};                            //Inicializo en 0 y guardo en cada pos del ascii, el valor de ascii(SI aparece)(ASi se mantiene ordenado)
    for(int i=0; text[i];i++){
        chars[text[i]]=text[i];
    }
    eliminaCeros(chars);                    //Le saco los ceros y queda ordenado
}


void eliminaCeros(char vec[]){
    int k=0;
    for(int i=0;i<CHARSMAX;i++){
        if(vec[i]!=0){
            vec[k++]=vec[i];
        }
    }
    vec[k]='\0';
}

*/

//----------------------------------Otra manera------------------------------

void analize(const char text[],char chars[]){
    char vecAp[CHARSMAX]={0};
    int k=0;
    llenoVecAp(text,vecAp);
    for(int i=0;i<CHARSMAX;i++){
        if(vecAp[i]!=0){
            chars[k++]=i;
        }
    }
    chars[k]='\0';


}


void llenoVecAp(const char s[],char vecAp[]){
    int contDistintos=0;
    for(int i=0;s[i]!='\0'&& contDistintos<CHARSMAX;i++){
        if(vecAp[s[i]]==0){
            vecAp[s[i]]=1;
            contDistintos++;
        }
    }
    
}











