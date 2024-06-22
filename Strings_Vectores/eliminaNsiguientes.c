/*Escribir una funcion eliminaN que, dados un string, una letra y un entero n
elimina del string la aparicion de esa letra(sin importar mayus o minus)
y los n caracteres siguientes a la misma. Si el caracter recibido no es una letra o si el n no es positivo, no debe modificar el string
*/


#include <stdio.h>
#include <ctype.h>


void eliminaN(char s, char x, int n); //x es la letra que quiero eliminar y n es la cantidad de caracteres que quiero eliminar despues de la letra

void eliminaN(char * s, char x, int n){
     int cont=0;
     char l;
     char a=toupper(x);     
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

//-------------------------------------
