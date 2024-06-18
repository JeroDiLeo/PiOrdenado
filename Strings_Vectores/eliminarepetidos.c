//Funcion que recibe un v[] desordenado y su dim y construye un nuevo vector
//retorna la dimde resp
int estaRepetido(const int v[], int elem, int dim){
    for(i=elem +1; i<dim; i++){
        if(v[elem]==v[i]){
            return 1;
        }
    }
}



int eliminaRepetidos(const int v[], int dim, int resp[]){
    int dimResp=0;
    for(int i=0; i<dim; i++){
        if(!estaRepetido(v, i, dim)){           //Si no esta repetido
            resp[dimResp++]=v[i];
        }
    }
    return dimResp;
}
>>
//----------------------------------------------------------------------
//Caso que esten ordenados


int eliminaRepetidosOrden(const int v[], int dim, int resp[]){
    int dimResp;
    int i;

    if(dim>0){
        resp[0]=v[0];
        for(i=1, dimResp=1; i<dim; i++){
            if(v[i]!=v[i-1]){
                resp[dimResp++]=v[i];
            }
        }
    }
    return dimResp;
}

