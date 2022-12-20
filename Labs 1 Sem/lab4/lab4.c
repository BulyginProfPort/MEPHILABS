#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "menu.h"
#include "sorts/sort_fx/struct.h"
#include "input.h"
#include "sorts/sort_fx/compare_swap.h"
#include "sorts/shaker_sort.h"
#include "sorts/insertion_sort.h"
#include "sorts/double_selection_sort.h"
int main(){
    int variant=0, a = 0, c = 0, b = 0, d = 0, k = 0, i = -1, data_k = 0,pr_data_k=0 ,m = 0, len=0,v13 = 0,v21 = 0;
    char path[100] = {'\0'};
    FILE *file_in;
    FILE *file_out;
    struct data *base = NULL;
    srand(time(NULL));
    do{
    A:  print_menu();
        scanf("%d",&variant);
        switch(variant){
            case 1://ВВОД ИНФОРМАЦИИ
                print_menu1();
                scanf( "%d", &a );
                do{
                    switch(a){
                        case 1: //ВВОД С КЛАИВАТУРЫ
                            base = (struct data*) realloc( base,( ( data_k+1 ) * sizeof( struct data ) ) );
                            set_data(base, data_k);
                            data_k++;
                            printf( "\n\n" );
                            goto A;
                        
                        case 2: //ВВОД С ПОМОЩЬЮ ФАЙЛА
                            printf( "Укажите путь к файлу: " );
                            scanf( "%s",path );
                            file_in = fopen( path, "r" );
                            while (file_in==NULL){
                                printf( "Ошибка! Не получатеся открыть файл\n" );
                                printf( "Попробуйте указать путь к файлу еще раз: " );
                                scanf( "%99[^\n]",path );
                                scanf( "%*c" );
                                file_in = fopen( path, "r" );
                            }
                            i=data_k;
                            if (data_k==0){
                                i=0;
                            }
                            base = (struct data*) realloc( base, (data_k+1) * sizeof(struct data) );
                            base[i].FIO = (char*)malloc(1000*sizeof(char));
                                            
                            while(fscanf(file_in,"%[^\n]s %[^\n]s %lu",base[i].FIO,base[i].phone_num,&base[i].time)!=EOF){
                                fscanf(file_in,"%[^\n]s",base[i].FIO);
                                base[i].FIO = (char*) realloc(base[i].FIO,( strlen(base[i].FIO)+1 )* sizeof(char) );
                                fgetc(file_in);
                                fscanf(file_in,"%[^\n]s",base[i].phone_num);
                                fgetc(file_in);
                                fscanf(file_in,"%lu",&base[i].time);
                                fgetc(file_in);
                                i++;
                                data_k++;
                                base = (struct data*) realloc(base,(data_k+1)*sizeof(struct data));
                                base[i].FIO = malloc(1000*sizeof(char));
                            }
                            free(base[i].FIO);
                            fclose(file_in);
                            goto A;
                        
                        case 3: //ВВОД С ПОМОЩЬЮ РАНДОМНОЙ ГЕНЕРАЦИИ
                            printf( "Введите количество пользователей: " );
                            scanf( "%d",&k );
                            pr_data_k = data_k;
                            while (c<k){
                                base = (struct data*)realloc( base, ( ( ( data_k + 1 ) ) * sizeof(struct data ) ) );
                                m = data_k;
                            
                                len=rand()%101+20;
                            
                                base[m].FIO = malloc( len+1 * sizeof(char));
                                set_data_rand(base, m,len, data_k+1);
                                                    
                                data_k++;
                                c = data_k - pr_data_k;
                            }
                            c=0;
                            printf("\n");
                            goto A;
                    }
                }while(a<3);
                
            case 2: //ВЫБОР СОРТИРОВКИ
                print_menu14();
                scanf("%d",&b);
                switch(b){
                    case 1: //ШЕЙКЕРНАЯ СОРТИРОВКА
                        print_menu2(&v21);
                        if (v21 == 1 ){
                            shaker_sort(base,sizeof(struct data),data_k,compare_fio);
                        }
                        if (v21 == 2){
                            shaker_sort(base,sizeof(struct data),data_k,compare_phone_num);
                        }
                        if (v21 == 3){
                            shaker_sort(base,sizeof(struct data),data_k,compare_time);
                        }
                        //print_struct(base, data_k);
                        goto A;
                        
                    case 2: //СОРТИРОВКА ВСТАВКАМИ
                        print_menu2(&v21);
                        if (v21 == 1){
                            insertion_sort(base,sizeof(struct data),data_k,compare_fio);
                        }
                        if (v21 == 2){
                            insertion_sort(base,sizeof(struct data),data_k,compare_phone_num);
                        }
                        if (v21 == 3){
                            insertion_sort(base,sizeof(struct data),data_k,compare_time);
                        }
                        //print_struct(base, data_k);
                        goto A;
                        
                    case 3: //ДВУХСТОРОННЯЯ СОРТИРОВКА
                        print_menu2(&v21);
                        if (v21 == 1 ){
                            double_selection_sort(base,sizeof(struct data),data_k,compare_fio);
                        }
                        
                        if (v21 == 2){
                            double_selection_sort(base,sizeof(struct data),data_k,compare_phone_num);
                        }
                        if (v21 == 3){
                            double_selection_sort(base,sizeof(struct data),data_k,compare_time);
                        }
                        //print_struct(base, data_k);
                        goto A;
                }
                
            case 3: //ВСТАВКА ПО ИНДЕКСУ
                if (data_k==0){
                    printf("Стурктуры не существует!\n");
                    goto A;
                }
                printf("Введите индекс пользовотеля, данные которого хотите изменить\n");
                scanf("%d",&i);
                while (i>data_k-1){
                    printf("Ошибка! Такого индекса не существует\n Введите индекс ещё раз: ");
                    scanf("%d",&i);
                }
                print_menu3(&v13);
                switch (v13) {
                    case 1: //ФИО
                        scanf("%*c");
                        printf("Введите ФИО [%d] пользовотеля: ",i);
                        free(base[i].FIO);
                        base[i].FIO = readstr(base[i].FIO);
                        printf("Теперь массив не отсортирован!\n");
                        goto A;
                    case 2: //Номер телефона
                        printf("Введите номер телефона [%d] пользовотеля: ",i);
                        scanf("%16s",base[i].phone_num );
                        printf("Теперь массив не отсортирован!\n");
                        goto A;
                    case 3: //Время последнего звонка
                        printf("Введите время оследнего звонка [%d] пользовотеля: ",i);
                        scanf("%lu",&base[i].time);
                        printf("Теперь массив не отсортирован!\n");
                        goto A;
                    
                }
            case 4:
                print_menu4();
                scanf("%d",&d);
                switch(d){
                    case 1: //ВЫХОДНЫЕ ДАННЫЕ ЗАПИСАТЬ В ТЕКСТОВЫЙ ФАЙЛ

                        printf("Введите путь до файла, который хотите создать или перейти: ");
                        scanf("%s",path);
                        file_out = fopen(path,"w");
                        for (int i=0;i<data_k;i++){
                            fprintf(file_out,"%s\n",base[i].FIO);
                            fprintf(file_out,"%s\n",base[i].phone_num);
                            fprintf(file_out,"%lu\n",base[i].time);

                        }
                        fclose(file_out);
                        goto A;
                    case 2: //ВЫВОД ДАННЫХ НА ЭКРАН
                        print_struct(base, data_k);
                        goto A;
                }
                goto A;
        }
        
    }while (variant<5);
    for ( int i = 0; i < data_k; i++ ){
        printf("%d) ФИО = %s \nНОМЕР ТЕЛЕФОНА = %s \nВРЕМЯ = %lu\n",(i+1), base[i].FIO , base[i].phone_num ,base[i].time);
    }
    if (data_k>0){
        for (int i=0;i<data_k;i++){
            free(base[i].FIO);
        }
    }
    free(base);
    return 0;
}
