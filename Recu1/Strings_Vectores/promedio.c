/*Escribir una funcion que reciba un arreglo de enteros y su dimension y retorne en tres parametros de salida el menor, el mayor
 y el promedio de los elementos del arreglo.La funcion debe retornar en su nombre EXITO si el vector no estaba vacio y ERROR
 si el vector estaba vacio. Si estaba vacio los parametros de salida no deben alterarse.*/

 int promedio(int v[], size_t dim, int *mayor, int *menor, double *promedio){
    int sum=0;
    if(dim==0){
        return ERROR;
    }
    (*mayor)=v[0];
    (*menor)=v[0];
    for(int i=0; i<dim; i++){
        sum+=v[i];
        if(v[i]>(*mayor)){
            (*mayor)=v[i];
        }
        if(v[i]<(*menor)){
            (*menor)=v[i];
        }
    }
    (*promedio)=((double)sum/(double)dim);
    return EXITO;
 }
