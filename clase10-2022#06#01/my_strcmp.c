

int str_cmp(char string1[], char string2[]) {
    int i = 0;
    
    while (string1[i] == string2[i])
        if (string1[i++] == 0)
            return 0;
        return(string1[i] - string2[i]);
}

