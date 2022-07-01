/*
 * Esta función siempre asume que en destino hay
 * suficiente lugar para concatenar todos los elementos de
 * origen, sino ocurre el resultado es indefinido
 */


void my_str_cat(char destino[], char origen[]) {
    int pos1, pos2;

    pos1 = 0;
    while (destino[pos1] != 0)
        pos1++;
    
    pos2 = 0;
    while (origen[pos2] != 0)
        destino[pos1++] = origen[pos2++];
    
    destino[pos1] = 0;
    
    return;
}
