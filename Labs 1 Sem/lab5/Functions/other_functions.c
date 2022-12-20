#include "other_functions.h"
#include <stdlib.h>
void vkl(int **a,int str, int st){
    for (int i = 0; i < str; i++){
        a[i] = malloc( st * sizeof(int) );
        for (int j = 0; j < st; j++){
            scanf("%*c");
            printf("Ведите элемент матрицы a[%d][%d]: ",i,j);
            scanf("%d",&(a[i][j]));
        }
    }
}

void prmatrix(int **a,int str, int st){
    for (int i = 0; i < str; i++){
        printf("\n");
        for(int j = 0; j < st; j++){
            printf("%d ",a[i][j]);
        }
    }
    printf("\n");
}
