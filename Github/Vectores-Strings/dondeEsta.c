/*
Donde esta. Dado un arreglo ordenado de enteros, su dim y un numero determinado, determine si el numero esta y en que posiciones
Asumir que esta ordenado en forma creciente y puede estar repetido*/




int main(){
    int dim=
    int num=10;
    int vec[dim]={}
    int vecAp[]={0};
    int cantdePos=dondeEsta(vec,dim,num,vecAp);
    for(int j=0;j<cantdePos;j++){
        printf("El numero %d",num)
    }
    
}

int dondeEsta(int vec[],int dim,int num,int vecAp[]){
    int dim2=0;
    for(int i=0;i<dim;i++){
        if(vec[i]==num){
            vecAp[dim2++]=i;
        }
    }
    return dim2;
}