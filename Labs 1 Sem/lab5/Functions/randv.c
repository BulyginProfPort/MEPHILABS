#include "randv.h"
#include <stdlib.h>
#include <time.h>
void randvv(int **a, int str, int st){
    srand(time(NULL));
    for ( int i = 0; i < str; i++ ){
        a[i] = (int*) malloc( st * sizeof(int) );
        for ( int j = 0; j < st; j++ ){
            a[i][j]=(rand()%9)+1;
        }
    }
}
