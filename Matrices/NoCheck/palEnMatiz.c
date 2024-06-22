/*
Escribir una función palEnMat que reciba:
	una matriz cuadrada de chars de dimensión N (con N constante simbólica previamente definida)
	un entero que indica una fila
	un entero que indica una columna 
	un string
y retorne 1 si el string se encuentra dentro de la matriz, ya sea en sentido horizontal, vertical o diagonal y en 
cualquier dirección, donde el primer carácter del string se encuentra en la fila y columna indicada.

Ejemplos: 
Para la siguiente matriz y con N = 6

L O B R A Z
F H R G O R
C O S A D A
R L A H N N
W A O Y U T
Q S G S M A


retornaría 1 si recibe:
fila = 5, columna = 1, string = "SAL"
fila = 2, columna = 0, string = “COSA”
fila = 2, columna = 0, string = “CHB”
fila = 2, columna = 0, string = “CLOS”
fila = 2, columna = 0, string = ""
fila = 2, columna = 0, string = "C"

retornaría 0 si recibe: 
fila = 5, columna = 1, string = "sal"
fila = 5, columna = 1, string = "SALA"
fila = 2, columna = 0, string = “COSADAS”
fila = 6, columna y string no importa, la fila está fuera de rango
*/
#define N 6
#define DIR 8
//Verifico si la cadena de texto esta en la matriz en una direccion
//PosI y PosJ son las posiciones iniciales(La primera letra)
int esString(const char m[][N], int posI,int posJ,int incI,int incJ,char *s,int c){
    int i,j;
    int t=0;    //Contador para recorrer el string

    //Itero en la matriz en la direccion dada por incI e incJ
    for(i=posI,j=posJ;i>=0 && i<N && j>=0 &&j<N && c!=t;i+=incI,j+=incJ){

        if(s[t]==m[i][j]){  //Si los caracteres coinciden aumento t
            t++;
        }else{
            return 0;
        }
    }
    if(t==c){
        return 1;
    }
    return 0;
 }


int palEnMat(const char m[][N], int fil, int col, char *s){
    static int matPos[][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
    int c=strlen(s);

    //Itero sobre las diferentes direcciones de busqueda
    for(int d=0;d<DIR;d++){
        if(esString(m,fil,col,matPos[d][0],matPos[d][1],s,c)){
            return 1;
        }
    }
    return 0;

}


