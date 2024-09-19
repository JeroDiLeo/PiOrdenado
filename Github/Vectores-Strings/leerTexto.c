/*
Generar una letra mayus aleatoria y un numero aleatorio entre 1 y 256
Invocar a una funcion que lea un texto hasta N caracteres 
(si aparece antes EOF, termina la lectura ) y retorna la cantidad de veces que dicha letra aparece en mayus o minus


*/

int main(){
randomize();
int N=getint(1,256);
int letra=getint('A','Z');
printf("La letra %d, aparece %d veces en el texto\n",leerTexto(letra, N));



int leerTexto(int letra, int N){
    int c,int indice=0,contador=0;
    while((c=getchar()!=EOF)&&(indice<N)){
        if(c==N ||c==tolower(N)){
            contador++;
        }
        indice++;

    }
    return contador;
}
}