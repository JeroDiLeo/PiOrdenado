/*
Se tiene un tablero de chars con FIL filas y COL columnas. Un '0' representa un
espacio vacío, un valor '1' representa un jugador contrario y una 'X' representa
un obstáculo.
Dada la posición de un jugador (fila,columna) deberá calcularse la dirección ( 0
(E), 45 (NE), 90 (N), 135 (NO), 180 (O), 225 (SO), 270 (S), 315 (SE)) en la que
puede moverse de tal forma de llegar lo más lejos posible sin encontrarse con un
enemigo o un obstáculo. La función se invoca con el tablero, el tamaño real y la
posición del jugador. Retorna la dirección posible o -1 en caso de no poder
efectuarse ningún movimiento o de haber error en los parámetros.
Ejemplo:
En el ejemplo, calculaDireccion(tablero, 7, 6, 4, 1) retorna 0 ó 45.*/

//x e Y son las coordenadas del jugador
int calculaDireccion(char mat[FILAS][COLS], int ancho, int alto, int x, int y){
    int dir, maxdir =-1;
    int longitud, maxlong =-1;
    //Si la posición del jugador es inválida
    if(x<0 || x>=ancho || y<0 || y>=alto){
        return ERROR;
    }

    for(dir=0; dir<360; dir +=45){
        longitud= camino(mat,ancho,alto,x,y,dir);
        printf("\nEn direccion %d, longitud %d", dir, longitud);
        if(longitud>maxlong){
            maxlong=longitud;
            maxdir=dir;
        }
    }
    return maxdir;
}

//Esta fun calcula la longitud del camino en una dirección específica sin encontrarse con un enemigo o un obstáculo
int camino(char mat[FILAS][COLS], int ancho, int alto, int x, int y, int dir){
    int longitud, i ,j;
    int dirx, diry;
    transformarXY(dir, &dirx, &diry);
    i=x+dirx;   //Nueva fila
    j=y+diry;   //Nueva columna
    if(i<0 || i>=ancho || j<0 || j>=alto || mat[i][j]=='1' || mat[i][j]=='X'){
        return 0;
    }
    longitud=1;
    while(i>0 && i<alto-1 && j>0 && j<ancho-1 && mat[i][j]=='0'){  //Es alto -1 y ancho -1 porque se considera que el tablero empieza en 0
        i+=dirx;
        j+=diry;
        longitud++;
    }
    return longitud;
}

//Esta función transforma un ángulo en coordenadas x e y
void transformarXY(int angulo, int *dirx, int *diry){
    static int direcciones[][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
    int indice=angulo/45;       //Me va a dar el índice de la matriz de direcciones(entre 1)
    *dirx=direcciones[indice][0];
    *diry=direcciones[indice][1];
}

