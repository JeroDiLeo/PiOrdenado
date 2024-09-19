/*Los teléfonos (incluyendo los celulares) poseen grabado en sus teclas no sólo el número sino un conjunto de letras, 
esto quiere decir que a cada dígito (excepto el 0 y el 1) le corresponden 3 posibles letras. A continuación, se 
colocan las equivalencias de un teléfono tradicional entre el valor numerico y las letras.

Tecla 0: no posee valores alfabéticos
Tecla 1: no posee valores alfabéticos

Tecla 2: ABC
Tecla 3: DEF
Tecla 4: GHI
Tecla 5: JKL
Tecla 6: MNO
Tecla 7: PQRS
Tecla 8: TUV
Tecla 9: WXYZ

Hacer una función void convertirATexto que reciba como parámetros:
Un unsigned long representando un número teléfonico
Un vector de chars con espacio suficiente para dejar una posible representación alfanumérica del número de teléfono
En caso que la tecla no tenga equivalencia, debe colocar el dígito original. 
*/
#include <stdio.h>
#include "../../Bibliotecas/random.h"
#define NO_ALF -1
#define FROM_COLUMN 0
#define TO_COLUMN 1





void convertirATexto(unsigned long phone char phoneToText[]);
void convertirATexto(unsigned long phone char phoneToText[]){
        static char digitToLetter[][2]={
            {NO_ALF,NO_ALF},
            {NO_ALF,NO_ALF},
            {'A','C'},
            {'D','F'},
            {'G','I'},
            {'J','L'},
            {'M','O'},
            {'P','S'}, 
            {'T', 'V'},
            {'W', 'Z'}
        };


    int i=0;
    signed char digitChar;
    int from,to;
    //Lo voy a estar recorriendo de derecha a izquierda, por lo que lo voy a tener que dar vuelta
    while(phone>0){
        int digit=phone%10; //TOma el valor del digito que esta mas a la derecha
        from=digitToLetter[digit][FROM_COLUMN];
        if(from==NO_ALF){           //Si es un cero o 1, guardo el valor en forma de ascii para guardar en el vec
            digitChar=digit+'0';
        }else{
            to=digitToLetter[digit][TO_COLUMN];
            digitChar=randInt(from,to);
        }
        phoneToText[i++]=digitChar;
        phone/=10;  //Lo hago para ir sacando 1 digito

    }  
    //El indice "i" ya va a estar en la ultima posicion => 
    // me guardo en un vec aux el valor de la ult posicion de la derecha y luego la copio en la primera posicion
    for(int j=0;j<i/2;j++){
        char aux=phoneToText[i-j-1];
        phoneToText[i-j-1]=phoneToText[j];
        phoneToText[j]=aux;
    }
    phoneToText[i]='\0';

}