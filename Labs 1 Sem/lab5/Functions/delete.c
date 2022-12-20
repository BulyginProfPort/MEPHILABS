#include "delete.h"
#include <stdlib.h>
void delstr(int **a,int *buf1,int nstr,int str, int st,int i){
    for (int j = 0; j < st; j++){
        buf1[j]=a[i][j];
    }
    for (int i = nstr; i < str-1; i++){
        for (int j = 0; j<st; j++){
            a[i][j]=a[i+1][j];
        }
    }
    for (int j = 0; j<st;j++){
        a[(str-1)][(st-1)] = buf1[j];
    }
}
void delst(int **a,int nst,int str,int st){
    for (int i = 0; i < str; i++){
        for (int j = nst; j<st-1;j++){
            a[i][j]=a[i][j+1];
        }
    }
}
