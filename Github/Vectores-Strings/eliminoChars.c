/*
Se desea eliminar de un string los caracteres que estén contenidos en
otra cadena, y también registrar en qué posiciones estaban los caracteres
eliminados.
Para ello se pide escribir la función int elimChars que reciba los siguientes
parámetros:
● text: cadena de caracteres null terminated
● chars: cadena de caracteres null terminated
● pos: vector de enteros, donde se irán guardando en qué posición
estaba cada carácter eliminado (en la posición 0 el que se eliminó
primero, en la 1 el que se eliminó segundo, etc.)
y retorne la cantidad de caracteres eliminados.
A continuación un ejemplo de testeo, en el cual el parámetro text es breve,
pero se espera -en su uso habitual- que text sea una cadena extensa, no así el
string chars.

int main(void) {
char s[] = "Los artificios y el candor del hombre no tienen fin."
int idxs[100];
int n = elimChars(s, "?xAE92#", idxs);
assert(n==0); // No se elimina ningún carácter
n = elimChars(s, "o", idxs);
assert(n==5);   // La o minúscula aparece 5 veces
assert(idxs[0]==1);
assert(idxs[1]==12);
char t[] = "Los artificios y el candor del hombre no tienen fin."
n = elimChars(t, "oLs", idxs);
assert(n==8);  // L:1, o:5, s:2
assert(strcmp(t, " artifici y el candr del hmbre n tienen fin.")==0);
char u[]="aeiaouuuuuaaeeee";
n = elimChars(u, "oueai", idxs);
for(int i=0; i<n; i++) {
assert(idxs[i]==i);
}
assert(strlen(u)==0);
assert(n==16);
return 0;
}
3
*/

#define MAXCHAR 256

int elminaChars(char text[], char chars[],unsigned int pos[]){
    char vecAp[MAXCHAR]={0};
    int k=0,cantEliminados=0;
    llenoVecAp(vecAp,chars);
    for(int i=0;text[i]!='\0';i++){
        if(!vecAp[text[i]]){    //Si no esta en el vector chars, lo copio
            text[k++]=text[i];
        }else{                  //Sino me guardo la pos de eliminacion
            pos[cantEliminados++]=i;
        }
    }
    return cantEliminados;
}

void llenoVecAp(char vecAp[],char s[]){
    for(int i=0;s[i]!='\0';i++){
        if(isalpha(s[i])){
            vecAp[s[i]]=1;
        }
    }
}