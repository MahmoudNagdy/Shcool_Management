void string_scan(char *str, int maxSize){

    int i = 0;
    fflush(stdin);
    scanf("%c", &str[i]);

    for(; str[i] != '\n'; ){

        i++;
        scanf("%c", &str[i]);

        if(i == maxSize - 1){
            break;
        }

    }

    str[i] = 0;

}