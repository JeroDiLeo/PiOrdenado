/*
Eliminar de un texto todas las vocales, siempre y cuando no sean vocales sueltas.
 Para eliminarlas deben tener al menos una letra antes o despues(Y que no sea vocal)
 Fun:EliminaVoc recibe unicamente un string  y elimina las reglas mencionadas antes
 --------Resumen------
 Si esta pegada a una letra, se puede borrar
 si esta pegada a dos vocales NO se borra
 si esta pegada a una vocal y un espacio NO se borra
 */
#include <stdio.h>
#include <ctype.h>

int EliminaVoc(char s[]){
    char letra;
    int k=0;
    for(int i=0;s[i]!='\0';i++){
        letra=tolower(s[i]);
       
        if(i!=0){
            anterior=s[i-1];
            siguiente=s[i+1];
            if(!isVocal(letra)||(isVocal(anterior)||anterior=='')&&(isVocal(siguiente)||siguiente==''||siguiente=='\0')){
                s[k++]=s[i];
            }
        }else{
            if(!isVocal(letra)||isalpha(s[i+1])){
                s[k++]=s[i];
            }
        }
    }
}


int isVocal(char c){
    return(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
       