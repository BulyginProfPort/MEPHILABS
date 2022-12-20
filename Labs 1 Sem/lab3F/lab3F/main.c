#include <stdlib.h>
#include <stdio.h>
#include "slen.h"
#include "sortm.h"
#include "readstr.h"
#include "vwords.h"
#include "gr.h"
int main(){
    int c = 0;
    char *templ = NULL;
    char **words = NULL;
    unsigned long int len = 0;
    while(1){
        printf("Введите строку: \n");
        templ = readstr();
        int it = 0;
        if (templ != NULL){
            len=slen(templ)+1;
            words = (char**)malloc(len*sizeof(char*));
            
            vwords(words, templ, len,&it);
            
            int *sort = (int*)malloc(it*sizeof(int));
            
            for (int i=0; i<it;i++) {
                sort[i] = gr(words[i]);
            }
            
            sortm(sort, words, it);
            c++;
            
            printf("\n");
            printf("%d)Получившаяся строка:\n",c+1);
            
            for (int i = 0; i < it; i++)
            {
                printf("%s ", words[i]);
            }
            
            printf("\n");
            
            
            free(sort);
            free(words);
            free(templ);
        }
        else{
            break;
        }
    }
    return 0;
}


