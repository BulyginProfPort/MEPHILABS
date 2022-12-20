#include "vwords.h"
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
