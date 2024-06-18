/*Escribir una funcion eliminaN que, dados un string, una letra y un entero n
elimina del string la aparicion de esa letra(sin importar mayus o minus)
y los n caracteres siguientes a la misma. Si el caracter recibido no es una letra o si el n no es positivo, no debe modificar el string
*/


void eliminaN(char *string, char letra, int n){
   int j;
   if(!(isalpha(letra) && n > 0)){
       return;
   }
  
       int i;
       for(i = 0, j = 0; string[i]; i++){
              
           if(string[i] != letra){
               string[j++] = string[i];
           } else {
               for(int aux = n; string[i] && aux != 0; i++, aux--){


               }
              
           }
          
       } 
       string[j] = '\0';
   }

//---------------------------------------------(El de abajo es de keo)
#include <stdio.h>
#include <ctype.h>


void eliminaN(char s, char x, int n);

void eliminaN(char * s, char x, int n){
     int cont=0;
     char l;
     char a=toupper(x);     //convierte a mayuscula(LA LETRA QUE QUIERO ELIMINAR)
     int i=0;
     while(s[i]!=0){
          l=toupper(s[i]);      //convierte a mayuscula(LA LETRA QUE ESTOY ANALIZANDO)
          if(l!=a){             //si la letra que estoy analizando no es la que quiero eliminar la guardo
               s[cont++]=s[i++]; 
          }else{                            //si la letra que estoy analizando es la que quiero eliminar la salteo
               for(int j=0; j<n+1; j++){
                    i++;
               }
          }

     }
     s[cont]='\0';
}