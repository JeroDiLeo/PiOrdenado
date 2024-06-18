/*
Se desea almacenar nombres de personas, y para cada persona los nombres de sus "allegados".
Se asegura para todos los nombres (de las personas y sus allegados) que se cumple:
se enviarán en minúsculas (no es necesario validarlo)
estarán compuestos por valores ASCII menores a 128 (US-ASCII)
no serán extensos (a lo sumo 20 cacharacteres)
El objetivo es poder mantener la base actualizada de personas y sus allegados, para lo cual se definió el siguiente contrato para manejarlo con un TAD.
Tener en cuenta que al almacenar nombres se almacena una COPIA de los mismos (ver ejemplos de uso antes de comenzar a programar el TAD)
*/

typedef struct socialCDT * socialADT;


/* Crea un nuevo TAD vacío */
socialADT newSocial();


/* Libera todos los recursos reservados por el TAD */
void freeSocial(socialADT soc);


/* Almacena una nueva persona. Si la persona existe, no hace nada
** Guarda una copia del nombre, no simplemente el puntero */
void addPerson(socialADT soc, const char * name);


/* Si existe una persona con ese nombre, agrega la nueva relación
** Si la persona no existe, no hace nada
** Si related ya estaba relacionado, lo agrega repetido
** Almacena una copia de related, no simplemente el puntero
**
*/
void addRelated(socialADT soc, const char * name, const char * related);


/* Retorna una copia de los nombres relacionados con una persona
** en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si la persona no existe, retorna un vector que sólo tiene a NULL como
** elemento
*/
char ** related(const socialADT soc, const char * person);


/* Retorna una copia de los nombres de las personas en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si no hay personas, retorna un vector que sólo tiene a NULL como
** elemento
*/
char ** persons(const socialADT soc);   