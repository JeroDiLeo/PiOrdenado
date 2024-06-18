//Recibe dos vectores ordenados ascendentemente y sin elementos repetidos
//al final terminan con -1

void unirArreglos(const int v1[], const int v2[], int resp[]){
    int i=0, j=0, k=0;
    
    while(v1[i]!= (-1) && v2[j]!= (-1)){    //mientras no llegue al final de alguno de los v[]
        if(v1[i]<v2[j]){
            resp[k++]=v1[i++];
        }else if(v1[i]>v2[j]){
            resp[k++]=v2[j++];
        }else{
            resp[k++]=v1[i++];
            j++;
        }
    }
    while(v1[i]!= (-1)){
        resp[k++]=v1[i++];
    }
    while(v2[j] != (-1)){
        resp[k++]=v2[j++];
    }
    resp[k]= -1;

}