#include "sortm.h"
//ФУНКЦИЯ СОРТИРОВКИ КОЛИЧЕСТВА ГЛАСНЫХ
void sortm(int *sort, char **words, int it){
    char pz1, *pz2;
    for(int j=0; j < it-1; j++) {
        for (int i = 0; i < it-1; i++) {
            if (sort[i]>sort[i+1]) {
                pz1 = sort[i];
                pz2 = words[i];
                
                sort[i] = sort[i+1];
                words[i] = words[i+1];
                
                sort[i+1] = pz1;
                words[i+1] = pz2;
            }
        }
    }
}
