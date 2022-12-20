#include "memc.h"
//ФУНКЦИЯ РЕАЛИЗАЦИИ MEMCPY
char memc(char *arr_out,char *arr_in,unsigned long int k){
    for (int i=0;i<k;i++){
        *arr_out++ = *arr_in++;
    }
    return *arr_out;
}
