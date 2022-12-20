#ifndef input_h
#define input_h

#include <stdio.h>
#include "sorts/sort_fx/struct.h"
char *readstr(char *basefio);
void set_data( struct data *base, int k );
void rand_num( char *a, int v, int len );
void rand_time(unsigned long int *a);
void set_data_rand( struct data* base, int k, int len, int data_k);
#endif /* input_h */
