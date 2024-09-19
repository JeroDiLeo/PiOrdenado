
/*Hacer la función incrementoFCMinMax que recibe un arreglo con ángulos
y un arreglo con las distancias que se pueden recorrer en cada
dirección.
La función deberá determinar el ángulo correspondiente a la mínima y
a la máxima distancia que puede recorrer y obtener los incrementos en
Fila y en Columna para esos ángulos, para retornar dichos incrementos
al programa que invoque la función.Tener en cuenta que los
incrementos son:
    Angulo 0 45 90 135 180 225 270 315
    En Fila 0 -1 -1 -1 0 1 1 1
    En Col 1 1 0 -1 -1 -1 0 1
    Ejemplo: Si recibe
    Ángulos[] = {45,90,135,225,180,0} y
    Distancias[] = {12, 1,4,20,7,9}
    La máxima distancia la puede obtener en ángulo 225 y la mínima en ángulo 90,
    por lo que lo que debe retornar es:
    fMin = -1 y cMin = 0
    fMax = 1 y cMax = -1
*/