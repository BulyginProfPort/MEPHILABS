#include "shaker_sort.h"
#include "sort_fx/compare_swap.h"
#include <stdio.h>
#include <time.h>

void shaker_sort(void* base, int size,int n, int(*comp)(void* ,void* )){
    int left = 0;
    int exm;
    n=n-1;
    printf("Shaker sort start\nTime == %lu(ms)\n", clock());
    while ( left < n ){
        for ( int i = left; i < n; i++){
            exm = comp( base + i * size , base+ (i + 1) * size );
            if (exm > 0){
                swap(base+( i * size ),base+(( i + 1 ) * size));
            }
        }
        n--;
        for ( int i = n; i > left; i--){
            exm = comp( base+(i*size), base+((i-1)*size));
            if ( exm < 0){
                swap(base+(i*size),base+((i-1)*size));
            }
        }
        left++;
    }
    printf("Shaker sort done\nTime == %lu(ms)\n", clock());
}
