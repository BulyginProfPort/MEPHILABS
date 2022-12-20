#include "insertion_sort.h"
#include "sort_fx/compare_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void insertion_sort(void* base,int size,int len,int(*comp)(void* ,void* )){
    void* p = NULL;
    printf("Insertion sort start\nTime == %lu(ms)\n", clock());
    for (int i=0;i<len;i++){
        p = malloc(size);
        memcpy(p,base+(i*size),size);
        int j=i;
        while ( (j > 0) && ( comp( (base+ (j-1) * size) , p)  > 0 ) ){
            swap( base+((j-1)*size), base+(j*size) );
            j--;
        }
        memcpy(base+(j*size),p,size);
        free(p);
    }
    printf("Insertion sort done\nTime == %lu(ms)\n", clock());
}

