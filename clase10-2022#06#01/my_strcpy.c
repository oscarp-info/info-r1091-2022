/*
 * Esta función siempre asume que en destino hay
 * suficiente lugar para copiar todos los elementos de
 * origen, sino ocurre el resultado es indefinido
 */


void my_str_cpy (char destino[], char origen[]){
    int i;
    
    for (i = 0; origen[i] != 0; i++)
        destino[i] = origen[i];
    
    destino[i] = '\0';
    
    return;
}