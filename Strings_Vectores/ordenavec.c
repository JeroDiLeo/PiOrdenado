/*
Escribir la función ordena que recibe un vector de enteros donde cada elemento es mayor o igual a cero, y el 
valor -1 como marca de final. La función debe dejar en el vector únicamente los elementos que son mayores que el 
anterior, considerando que el primer elemento debe quedar en el vector.
*/

void ordena(int v[]){
   int copia=1;
   for(int lect=1; v[lect]!=-1; lect++){
      if(v[copia-1]<v[lect]){
         v[copia++]=v[lect];
      }
   }
   v[copia]=-1;
}