/* Escribir una función que, dados un string y una letra, elimine del string la aparición de esa letra (sin
importar si es minúscula o mayúscula) y los dos caracteres siguientes a la misma. Si el caracter recibido no
es una letra, no debe modificar el string.
Ejemplo 1
S = “El sol sale por el este”
Letra = ‘e’
Resulta:
S = “sol salor ”
Ejemplo 2
S = “El sol sale por el este”
Letra = ‘t’
Resulta:
S = “El sol sale por el es”
Ejemplo 3
S = “El sol sale por el este”
Letra = ‘x’
Resulta:
S = “El sol sale por el este”
*/
void eliminaN(char *s, char letter){
    if(!isalpha(letter) || s[0]=='\0')
        return;
    char c=toupper(letter);
    int t=0;
    for(int i=0;s[i]!='\0';i++){
        if(toupper(s[i])!=c){
            s[t++]=s[i];
        }else{
            i++;
            if(s[i]!='\0'){
                i++;
                if(s[i]!='\0'){
                    i++;
                }
            }

        }
          
    }
    s[t]='\0';
}