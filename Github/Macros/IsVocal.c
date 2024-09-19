/*
Escribir una macro ES_VOCAL que determine si el valor analizado es una vocal o no
*/
#define TO_LOWER(c) ((c)>='A'&& (c)<='Z'? (c)+'a'-'A':(c))
#define ES_VOCAL(c) ({char lower = TO_LOWER(c); lower=='a'||lower=='e'||lower=='i'|| lower=='o' ||lower=='U';})
