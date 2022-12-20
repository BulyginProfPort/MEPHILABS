#include <stdlib.h>
#include "readstr.h"
#include "slen.h"
#include "memc.h"

//ФУНКЦИЯ РЕАЛИЗАЦИИ READLINEa
char *readstr() {
    char arr[101] = {0};
    char *res = NULL;
    unsigned long int str_len=0,arr_len=0,len = 0;
    int n = 0;
    do {
        n = scanf("%100[^\n]", arr);
        if (n > 0){
            arr_len = slen(arr);
            str_len = len + arr_len;
            res = realloc(res, str_len + 1);
            memc(res, arr, str_len);
            len = str_len;
        }
        else if (n < 0){
            if (!res){
                return NULL;
            }
        }
        else{
            scanf("%*c");
        }
        
    }
    while (n > 0);
    
    if (len > 0) {
        res[len] = '\0';
    }
    else {
        res = calloc(1, sizeof(char));
    }
    return res;
}

