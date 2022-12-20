
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Functions/menu.h"
#include "Functions/delete.h"
#include "Functions/change.h"
#include "Functions/randv.h"
#include "Functions/other_functions.h"
int main(int argc, const char * argv[]) {
    FILE *file_in = NULL;
    FILE *file_out = NULL;
    int **a = NULL;
    int *buf = NULL;
    int *buf1 = NULL;
    char path[100]={};
    int v = 0, v1 = 0,v2 = 0, v3 = 0, nst = 0, nstr = 0,n = 0,m = 0, af = 0, str = 0, st = 0;
        do{
A:      menu();
        scanf("%d",&v);
        printf("\n\n\n");
        switch(v){
            case 1:
                if (af!=0){
                    for (int i=0; i<str; i++){
                        free(a[i]);
                    }
                    free(a);
                }
                menu11();
                scanf("%d",&v1);
                scanf( "%*c" );
                switch(v1){
                    case 1:     //Pаполняет Матрицу с клавиатуры
                        menu1(&str,&st);
                        a = (int**)malloc(str * sizeof(int*));
                        af=1;
                        vkl(a,str,st);
                        goto A; //Возврат в основное меню
                    case 2:     //Заполняет матрицу с помощью Файла
                        af=1;
                        printf("Введите путь к файлу: ");
                        scanf("%99[^\n]",path );
                        file_in=fopen( path, "rb" );
                        while(file_in==NULL){
                            scanf( "%*c" );
                            printf( "Ошибка! Не получатеся открыть файл\n" );
                            printf( "Попробуйте указать путь к файлу еще раз: " );
                            scanf( "%99[^\n]s",path );
                            scanf( "%*c" );
                            file_in = fopen( path, "rb" );
                        }
                        fread(&st,sizeof(int),1,file_in);
                        fread(&str,sizeof(int),1,file_in);
                        a = (int**)malloc(str * sizeof(int*));
                        for (int i=0;i<str;i++){
                            a[i] = (int*) malloc( st * sizeof(int) );
                            for( int j=0; j<st; j++){
                                fread(&a[i][j],sizeof(int),1,file_in);
                            }
                        }
                        fclose(file_in);
                        goto A; //Возврат в основное меню
                        
                    case 3:     //Заполняет рандомно матрицу
                        af=1;
                        menu1(&str,&st);
                        a = (int**)malloc(str * sizeof(int*));
                        randvv(a, str, st);
                        goto A; //Возврат в основное меню
                };
                goto A;
            case 2:
                do{
B:                  menu12();//ДЕЙТСВИЯ НАД МАТРИЦАМИ
                    scanf("%d",&v2);
                    switch(v2){
                        case 1:
                            menu21(a, str, st, nstr);
                            prmatrix(a, str, st);
                            printf("\n\n\n");
                            goto B; //Возврат в предыдющее меню
                        case 2:
                            menu22(a,nst, str, st);
                            printf("\n");
                            prmatrix(a, str, st);
                            printf("\n\n'n");
                            goto B; //Возврат в предыдющее меню
                        case 3:
                            if (str==0 || st==0){
                                printf("                ОШИБКА!\nСТРОКИ И СТОЛБЦЫ В МАТРИЦЕ ЗАКОНЧИЛИСЬ\n\n");
                                break;
                            }
                            else{
                                menu23(str, st, &nstr);
                                buf1 = (int*) malloc(str*sizeof(int));
                                delstr(a,buf1,nstr,str,st,nstr);
                                free(a[str-1]);
				str--;
                               	a = (int**) realloc(a, str*sizeof(int*));
                                prmatrix(a, str, st);
                                printf("\n\n");
                            }
                            goto B;
                        case 4:
                            if (st==0 || str==0){
                                printf("                 ОШИБКА!\n                  "
                                       "СТРОКИ И СТОЛБЦЫ В МАТРИЦЕ ЗАКОНЧИЛИСЬ \n\n");
                                break;
                            }
                            else{
                                menu24(&nst, st);
                                delst(a, nst,str, st);
                                st--;
                                for (int i=0; i<str; i++){
                                    a[i]=(int*)realloc(a[i],st*sizeof(int*));
                                }
                                prmatrix(a, str, st);
                                printf("\n\n");
                            }
                            goto B;
                        case 5:
                            if (str==st){
                                printf("\n");
                                printf("Введите количество позиций, на которые нужно сдвинуть элементы: ");
                                scanf("%d",&n);
                                if (n<0){
                                    m=1;
                                    n=n*(-1);
                                }
				while (n>str){
                                    n=n-str;
                                }
                                main_change(a, buf,0,0, str, st, m, n);
                            }
                            else{
                                printf("Ошибка, измините размер матрицы\n\n");
                                goto A;
                            }
                        case 6:
                            goto C;

                    };
                }while(v2<7);
                goto A; //Возврат в основное меню
C:              case 3:
                menu3();
                scanf("%d",&v3);
                do{
                    switch(v3){
                        case 1:
                            prmatrix(a, str, st);
                            printf("\n");
                            goto A; //Возврат в основное меню
                        case 2:
                            scanf("%*c");
                            printf("Введите имя файла или путь до него, в который хотите записать результат: ");
                            scanf("%99[^\n]",path);
                            file_out = fopen(path,"wb");
			    fwrite(&st,sizeof(int),1,file_out);
			    fwrite(&str,sizeof(int),1,file_out);
	      	            for(int i=0;i<st;i++){
			        fwrite(a[i],sizeof(int),st,file_out);
			    }
			    fclose(file_out);
                    };
                }while (v3<2);
        }
    }while(v<4);
    if (af!=0){
        for (int i=0; i<str; i++){
            free(a[i]);
        }
        free(a);
    }
    free(buf1);
    free(buf);
    return 0;
}
