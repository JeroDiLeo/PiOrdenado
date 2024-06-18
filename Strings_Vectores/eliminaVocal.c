/*
Se desea eliminar de un texto todas las vocales, siempre y cuando no sean vocales "sueltas", esto es, para 
eliminarlas deben tener al menos una letra antes o una letra después (y que no sea vocal).

Escribir una función eliminaVoc que reciba únicamente un string y elimine todas las vocales siguiendo las reglas 
mencionadas anteriormente.

Ejemplos: 

Si recibe "hola mundo" lo deja como "hl mnd"
Si recibe "hola a todo el mundo" lo deja como "hl a td l mnd"
Si recibe "xyz" lo deja sin cambios
Si recibe el string "aholoaaa" lo deja como "hlaaa"
Si recibe el string vacío "" lo deja sin cambios
Si recibe "aa eo iu oa uo" lo deja sin cambios
Si recibe "pa po pi po pu" lo deja como "p p p p p"
Si recibe "aeiou" lo deja igual
Si recibe "a,e,i,o,u" lo deja igual
*/



int isVocal(char c){

  	static char vocales[] = "AEIOU";

  	char * p = strchr(vocales, toupper(c));				//me guarda la letra en p y me devuelve 1 

	return p != NULL;

}



void eliminaVoc(char * s){

	char l = 'A';
  	int t=0;

  	for (int i=0; s[i] != '\0'; i++){

    	char a= s[i];
    	char n= s[i+1];
  

    	if ( !(isVocal(a) && ( ( (isalpha(n) && !isVocal(n) ) ) || ( isalpha(l) && !isVocal(l))) )  ){
        	s[t++] = s[i]; 
   			l = a;
    	}


  		s[t] = '\0';
	}

}

























