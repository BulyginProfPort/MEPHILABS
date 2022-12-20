#ifndef compare_swap_h
#define compare_swap_h

#include <stdio.h>
#include "struct.h"

void swap(void* b,void* m);
int alphcmp(char a);
int compare_fio(void *a,void *b);
int compare_phone_num(void *a,void *b);
int compare_time(void *a,void *b);
void print_struct(struct data* base,int data_k);
#endif /* compare_swap_h */

