#include <stdio.h>
#include <stdlib.h>
typedef struct list{
    char letter;
    struct list *next;
}list;
void delete_all(struct list **a){
    while ( (*a)!= NULL ){
        struct list* previous =(*a);
        (*a) = (*a)->next;
        free(previous);
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
struct list* push(char x){
    struct list* b;
    b=malloc(sizeof(struct list));
    b->letter=x;
    b->next=NULL;
    return(b);
}
struct list* delete_sgl(struct list* a){
    struct list* main = a;
    struct list *buf, *previous = NULL;
    while ( main != NULL ){
        if(check_sgl(main->letter)==1){
            if (a == main){
                a = main->next;
            }
            buf=main;
            main = main->next;
            free(buf);
            if ( previous != NULL ){
                previous->next = main;
            }
        }
        else{
            previous = main;
            main = main->next;
        }
    }
    return a;
}
struct list* getst(struct list *a){
    char x;
    printf("Введите строку\n");
    x=getchar();
    if((x == '\0') || (x == '\n')){
        printf("Zero size string\n");
        return NULL;
    }
    else{
        struct list* main=push(x);
        struct list* previous = main;
        x=getchar();
        while((x != EOF) && (x != '\n')){
            struct list* buf = push(x);
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
    a=getst(a);
    
    a=delete_sgl(a);
    print_list(a);
    printf("\n\n");
    
    delete_all(&a);
    return 0;
}

