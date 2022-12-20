#include "compare_swap.h"
#include "struct.h"
#include <stdio.h>
void swap(void* b,void* m){
    struct data* base1 = b;
    struct data* base2 = m;
    struct data buf = *base1;
    *base1 = *base2;
    *base2 = buf;
}

int alphcmp(char a){
    if (a > 96){
        a = a - 32;
    }
    return(a);
}
int compare_fio(void *a,void *b){
    int i = 0;
    struct data *base1 = a;
    struct data *base2 = b;
    char* x = base1->FIO;
    char* y = base2->FIO;

    while(1){
        if ( ( x[i]=='\0') || ( alphcmp(x[i]) > alphcmp(y[i]) ) ){
            return 1;
        }
        if ( (y[i]=='\0') || (  alphcmp(y[i] > alphcmp(x[i]) ) ) ){
            return -1;
        }
        i++;
    }
}

int compare_phone_num(void *a,void *b){
    int i = 0;
    struct data *base1 = a;
    struct data *base2 = b;
    char* x = base1->phone_num;
    char* y = base2->phone_num;

    while(1){
        if ( ( x[i]=='\0') || ( alphcmp(x[i]) > alphcmp(y[i]) ) ){
            return 1;
        }
        if ( (y[i]=='\0') || (  alphcmp(y[i] > alphcmp(x[i]) ) ) ){
            return -1;
        }
        i++;
    }
}
int compare_time(void *a,void *b){
    struct data *base1 = a;
    struct data *base2 = b;
    unsigned long int x = base1->time;
    unsigned long int y = base2->time;
    return(x-y);
}
void print_struct(struct data* base,int data_k){
    for ( int i = 0; i < data_k; i++ ){
        printf( "%d) ФИО = %s \n\nНОМЕР ТЕЛЕФОНА = %s \n\nВРЕМЯ = %lu\n\n",(i+1), (base[i].FIO),(base[i].phone_num), (base[i].time) );
    }
}
