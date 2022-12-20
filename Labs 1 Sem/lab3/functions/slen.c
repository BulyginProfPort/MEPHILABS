#include "slen.h"
//ФУНКЦИЯ ПОДСЧЁТА ДЛИНЫ СТРОКИ
int slen(char *line){
    int l=0;
    for (int i=0;line[i]!='\0';i++){
        l+=1;
    }
    return l;
}

