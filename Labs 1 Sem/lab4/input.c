#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *readstr(char *basefio) {
    char arr[101] = {'0'};
    char *res = NULL;
    unsigned long int str_len=0,arr_len=0,len = 0;
    int n = 0;
    do {
        n = scanf("%100[^\n]", arr);
        if (n > 0){
            arr_len = strlen(arr);
            str_len = len + arr_len;
            res = realloc(res, str_len + 1);
            memcpy(res, arr, str_len);
            res[str_len] = '\0';
            len = str_len;
        }
        else if (n < 0){
            if (!res){
                printf("Ошибка!\n");
            }
        }
        else{
            scanf("%*c");
        }
    }
    while (n > 0);
    if (len > 0){
        res[len] = '\0';
    }
    else{
        res = calloc(1, sizeof(char*));
    }
    return(res);
}

void set_data( struct data *base, int k ){
    printf( "Введите ФИО: \n" );
    scanf( "%*c" );
    base[k].FIO = readstr(base[k].FIO);
    printf( "Введите номер телефона: \n" );
    scanf( "%15[^\n]", base[k].phone_num );
    printf( "Введите время последнего звонка: \n" );
    scanf( "%*c" );
    scanf( "%lu", &base[k].time );
    printf( "\n" );
}
void rand_num( char *a, int v, int len ){
    char num1[] = "0123456789 ";
    char num2[] = "+0123456789 ";
    char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";
    switch(v){
        case 1:
            for (int i=0; i<len;i++){
                a[i] = alph[rand() % (sizeof(alph)-1)];
            }
            a[len]='\0';
            break;
        
        case 2:
            a[0] = num2[rand()% (sizeof(num2)-1)];
            for (int i=1; i < len; ++i) {
                a[i] = num1[rand()%(sizeof(num1)-1)];
            }
            a[len]='\0';
            break;
            
    }
}
void rand_time(unsigned long int *a){
    *a = rand()%4294967295+1000000000;
}
void set_data_rand( struct data* base, int k, int len, int data_k){
    rand_time( &base[k].time);
    rand_num( ( base[k].FIO ), 1, len);
    rand_num( ( base[k].phone_num ), 2, 16);
}
