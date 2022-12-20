#include "gr.h"
//ФУНКЦИЯ ПОДСЧЁТА КОЛИЧЕСТВА ГЛАСНЫХ В СЛОВЕ
int gr(char *line){
    int m=0;
    char gl[]= "AaEeIiOoUuYy";
    for (int ix=0; line[ix]!='\0';ix++) {
        for(int i = 0; gl[i] != '\0'; i++)
        {
            if(line[ix] == gl[i])
            {
                m += 1;
                continue;
            }
        }
    }
    return m;
}
