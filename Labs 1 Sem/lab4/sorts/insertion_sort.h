#ifndef insertion_sort_h
#define insertion_sort_h

#include <stdio.h>
#include "sort_fx/struct.h"
void insertion_sort(void* base,int size,int  len,int(*comp)(void* ,void* ));
#endif /* insertion_sort_h */
