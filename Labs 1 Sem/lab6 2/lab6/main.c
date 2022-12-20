#include <stdio.h>
#include <stdlib.h>
typedef struct list{
    char letter;
    struct list *next;
} list;
void delete_all(struct list **a,int *k){
    while ( (*a)!= NULL ){
        struct list* previous =(*a);
        (*a) = (*a)->next;
        free(previous);
        (*k)--;
        previous=NULL;
    }
    printf("Удалено\n");
}
int check_sgl(char x){
    char arr[]={"BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz"};
    int m=0,len=sizeof(arr)/sizeof(char);
    for (int i=0;i<len;i++){
        if (x==arr[i]){
            m=1;
        }
    }
    return m;
}
struct list* push(char x,int *k){
    struct list* b;
    b=malloc(sizeof(struct list));
    (*k)++;
    b->letter=x;
    b->next=NULL;
    return(b);
}
struct list* delete_sgl(struct list* a,int *k){
    struct list* main = a;
    struct list *buf, *previous = NULL;
    while ( main != NULL ){
        if(check_sgl(main->letter)==1){
            if (a == main){         //проверка на первую согласную
                a = main->next;
            }
            buf=main;
            main = main->next;//скип символа
            free(buf);
            (*k)--;
            if ( previous != NULL ){
                previous->next = main;
            }
        }
        else{
            previous = main;
            main = main->next;//skip символа
        }
    }
    return a;
}
struct list* getst(struct list *a,int *k){
    char x;
    printf("Введите строку\n");
    x=getchar();
    if((x == '\0') || (x == '\n')){
        printf("Zero size string\n");
        return NULL;
    }
    else{
        struct list* main=push(x,k);
        struct list* previous = main;
        x=getchar();
        while((x != EOF) && (x != '\n')){
            struct list* buf = push(x,k);
            previous->next = buf;
            previous = buf;
            x=getchar();
        }
        a=main;
    }
    return a;
}
void print_list(struct list *a){
    if (a==NULL){
        printf("NULL\n");
    }
    else{
        while (a!=NULL){
            printf("%c", a->letter);
            a=a->next;
        }
        printf("\n");
    }
}
int main() {
    int k=0;
    struct list *a = NULL;
    a=getst(a,&k);
    print_list(a);
    printf("k=%d\n",k);
    
    a=delete_sgl(a,&k);
    print_list(a);
    printf("k=%d\n",k);

    printf("\n\n");
    
    delete_all(&a,&k);
    printf("k=%d\n",k);
    print_list(a);
    
    return 0;
}
