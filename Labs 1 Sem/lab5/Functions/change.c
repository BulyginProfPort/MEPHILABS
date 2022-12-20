#include "change.h"
#include <stdlib.h>
#include "change.h"
void main_change(int **a, int *buf,int nstr,int nst,int str,int st,int m,int n){
    int k=0;
    buf=malloc(str*sizeof(int));
    
    for (int i = 0; i < str; i++){
        
        if (nstr-n>0){
            k=i-1;
            
            change(buf,n,nstr,m);
            
            for (int j = 0; (i-1) + j < str; j++){
                a[(i-1)+j][j]=buf[j];
            }
            
            free(buf);
            
            buf=malloc(nstr*sizeof(int));
        }
        nstr = 0;
        for (int j = 0; i + j < str; j++){
            buf[j]=a[i+j][j];
            nstr++;
        }
    }
    free(buf);
    buf=malloc((st-1)*sizeof(int));
    for (int j = 1; j < st; j++){
        if (nst-n>0){
            change(buf,n,nst,m);
            for (int i = 0; i+(j-1) < st; i++){
                a[i][(j-1)+i]=buf[i];
            }
            free(buf);
            buf=malloc(nst*sizeof(int));
        }
        nst = 0;
        for (int i = 0; i + j < st; i++){
            buf[i]= a[i][i+j];
            nst++;
        }
    }
    free(buf);
}
void change(int *buf,int n,int nstr,int m){
    int *buf3 = NULL;
    buf3 = malloc(n*sizeof(int));
    if (m==1){
        for (int i=0;i<n;i++){
            buf3[i] = buf[(nstr-n) + i ];//копируем  в буфер элементы до n
        }
        for (int i=0;i<nstr-n;i++){
            buf[(nstr-1)-i]=buf[((nstr-1)-n)-i];//переносим элементы на место скопированных элементов
        }
        for (int i=0;i<n;i++){
            buf[i]=buf3[i];//переносим скопированные в буфер элементы на n позиций
        }
    }
    else{
        for ( int i = 0; i < n; i++){
            buf3[i] = buf[i];//копируем  в буфер элементы до n
        }
        for (int i = 0; i+n<nstr; i++){
            buf[i]=buf[n+i]; //переносим элементы на место скопированных элементов
        }
        for (int i = 0;i<n;i++){
            buf[(nstr-n)+i]=buf3[i]; //переносим скопированные в буфер элементы на n позиций
        }
    }
    free(buf3);
}
