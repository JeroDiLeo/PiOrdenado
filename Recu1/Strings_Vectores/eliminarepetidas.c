/*Escribir la función eliminaRepetidas, que recibe un string y que, por cadasecuencia de caracteres repetidos, deja uno solo.
 Ejemplos:Recibe “goooooooooooool de Argentinaaaaaaaaaaaaaaaaaaaaaaaaa gol deMessssssssiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii” → “gol de Argentina gol de Mesi”
 Recibe “la llama que llama” → “la lama que lama”
 Recibe “aaaaaaa aaaa” → “a a”
*/
void eliminaRepetidas(char s[]);
void eliminaRepetidas(char s[]){
    int i = 0;
    int j = 0;
    while(s[i] != '\0'){ //Mientras no llegue al fin de la cadena
        s[j++] = s[i];      //Copio el caracter en la posicion j y luego incremento j
        while(s[i] == s[i + 1]){    //Mientras el caracter actual sea igual al siguiente
            i++;                    //Incremento i
        }
        i++;                        //Incremento i para que no quede en el mismo caracter
    }
    s[j] = '\0';                  //Pongo el fin de cadena
}

//-----------------------------------------------------------------------------------------------
//Otra Forma de Hacerlo

void eliminaRepetidas(char s[]){
    int i, j;
    if (s[0]!='\0'){                            //Si la cadena no está vacía
        for (i = j = 1; s[i] != '\0'; i++){         //Recorro la cadena desde el segundo caracter hasta el fin de cadena
            if (s[i]!= s[i - 1])                    //Si el caracter actual es distinto al anterior
                s[j++] = s[i];                      //Copio el caracter en la posicion j y luego incremento j
        }
        s[j] = '\0';                                //Pongo el fin de cadena en la posicion j (que es la ultima posicion)
    }
    return;
        
    }