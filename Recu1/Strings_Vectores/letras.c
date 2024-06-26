/*
Escribir una función letras que reciba un string de longitud desconocida y retorne en un string de salida sólo las
letras del alfabeto inglés (sin importar mayúsculas o minúsculas) que forman parte del string recibido, en orden
alfabético.
Ejemplo de uso
#define LETRAS ('Z' - 'A' + 1)
int
main(void) {
char s[LETRAS + 1];
letras("Abracadabra Pata De Cabra", s);
printf("%s\n", s); // Imprime ABCDEPRT o abcdeprt

letras("123456 ()", s);
printf("%s\n", s); // Imprime una línea en blanco
letras("1x234ZxZ56 ()0x", s);
printf("%s\n", s); // Imprime XZ o xz
return 0;
}
*/
#define LETRAS 26

void letras(char *s1, char *s2){
    if(s1[0]=='\0'){
        return;
    }

    int vecAp[LETRAS]={0};
    for(int i=0;s1[i]!='\0';i++){
        if(isalpha(s1[i])){
            char c=tolower(s1[i]);
            vecAp[c-'a']=1;             //Le marco que encontre esa letra y existe al menos 1 vez
        }
    }
    int t=0;
    for(int i=0;s1[i]!='\0';i++){
        if(vecAp[i]=1){                 //Si tengo esa letra, la copio en el nuevo string
            s2[t++]=(i+'a');            //Tengo que hacer la conversion de indice a la letra
        }
    }
    s2[t]='\0';
}