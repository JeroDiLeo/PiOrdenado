/*
Escribir la función ordena que recibe un vector de enteros donde cada elemento es mayor o igual a cero, y el 
valor -1 como marca de final. La función debe dejar en el vector únicamente los elementos que son mayores que el 
anterior, considerando que el primer elemento debe quedar en el vector.
*/

void ordena(int v[]){
   int copia=1;
   for(int i=1; v[i]!=-1; i++){  //arranco en 1 xq el primer elemento debe quedar
      if(v[copia-1]<v[i]){    //si el que tengo en copia es menor que en el que estoy
         v[copia++]=v[i];
      }
   }
   v[copia]=-1;
}







void ordena(int v[]){
   int copia=1;
   for(int i=1;v[i]!=-1;i++){
      if(v[copia-1]<v[i]){
         v[copia]=v[i];
         copia++;
      }
   }
   v[copia]=-1;
}