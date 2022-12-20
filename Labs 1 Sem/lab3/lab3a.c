#include <stdlib.h>
#include <readline/readline.h>
#include <string.h>
#include <stdio.h>
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
//ФУНКЦИЯ ПОДСЧЁТА КОЛИЧЕСТВА ГЛАСНЫХ В СЛОВЕ
int gr(char *line){
    int m=0;
    char* gl = "AaEeIiOoUuYy";
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
//ФУНКЦИЯ ВЫДЕЛЕНИЯ СЛОВ В СТРОКЕ
void vwords(char **words,char *templ,unsigned long int len,int *it){
    int i=0,marker=0;
    for (i = 0; i < len; i++) {
        if (templ[i] == ' '||templ[i] == '\t') {
            if (i!=0 && (templ[i-1] != ' '|| templ[i-1] != '\t'|| templ[i-1]=='\0')) {
                templ[i]='\0';
                marker=0;
            }
        }
        else if (marker==0) {
            words[(*it)++]=(templ+i);
            marker=1;
        }
    }
}
int main(){
    int c=0;
    char *templ = NULL;
    char **words = NULL;
    unsigned long int len = 0;

    while(1){
        printf("Введите строку: \n");
        templ = readline("");
        int it = 0;
        if (templ != NULL){
            len=strlen(templ)+1;
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
    printf("\n");
    return 0;
}

