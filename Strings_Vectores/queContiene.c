/* 
Escribir la función queContiene que reciba dos strings s1 y s2. El string s1 puede contener cualquier valor ASCII. 
El string s2 contiene únicamente letras minúsculas o mayúsculas (no debe validarse, se asegura que sólo son 
letras del alfabeto inglés). La función debe retornar cuántos caracteres de s1 son letras contenidas en s2. 
Para más detalles ver programa debajo

Programa de testeo:
int 
main(void) {
   int c = queContiene("Ahora me pongo a llorar", "zaMo");
   assert(c==9);    // A o a m   o  o a   o a 

   c = queContiene("Ahora me pongo a llorar", "");
   assert(c==0);    

   c = queContiene("143 I love you", "xaprarczd");
   assert(c==0);    

}

*/
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#define MAX_CHARS 256


int queContiene(const char * s1, const char * s2);

int 
main(void) {
   
   int c = queContiene("Ahora me pongo a llorar @@*", "zaMo@");
   
   assert(c==11);    // A o a m   o  o a   o a 

   c = queContiene("Ahora me pongo a llorar", "");
   
   assert(c==0);    

   c = queContiene("143 I love you", "xaprarczd");
   
   assert(c==0);    

   puts("OK!");
}


int queContiene(const char * s1, const char * s2){

	int vecAp[MAX_CHARS+1]={0};
	int cont = 0;
	int x, y, i, j;
	for(i=0; s2[i]!=0; i++){									//Cargo el vector de apariciones
		x = toupper(s2[i]);
		vecAp[x]=1;												//Si aparece la letra, pongo un 1 en la posicion de la letra
	}
	
	for(j=0; s1[j]!=0; j++){
		y = toupper(s1[j]);
		if(vecAp[y]==1){
			cont++;
		}
	}
	return cont;
}






















