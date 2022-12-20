#ifndef shaker_sort_h
#define shaker_sort_h

#include <stdio.h>
#include "struct.h"

void shaker_sort(void* base, int size,int n, int(*comp)(void* ,void* ) );
#endif /* shaker_sort_h */
