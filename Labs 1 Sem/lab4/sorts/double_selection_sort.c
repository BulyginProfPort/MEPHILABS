#include "double_selection_sort.h"
#include "sort_fx/compare_swap.h"
#include <stdio.h>
#include <time.h>
void double_selection_sort(void* base,int size,int len,int(*comp)(void* ,void* )){
    int min,max;
    printf("Double selection sort start\nTime == %lu(ms)\n", clock());
    for (int i = 0; i < len/2;i++){
        min=i;
        max=i;
        for( int j=i;j<len-i;j++){
            if (comp( base+(min * size), base+(j*size) )> 0 ){
                min=j;
            }
        }
        
        if (min != i ){
            swap(base+(i * size),base+( min * size));
        }
        for (int j=i;j<len-i;j++){
            if (comp(base+(i * size) , base+(j*size) )< 0 ){
                max=j;
            }
        }
        
        if (max!=len-1-i){
        swap(base+(len-(i*size)-1),base+(max*size) );
        }
    }
    printf("Double selection sort done\nTime == %lu(ms)\n", clock());
}
