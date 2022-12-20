#include<stdio.h>
int main(){
    short int k=0,sum=0;
    char t=0;
    int n=0;
    printf("Введите значение k \n");
    scanf("%d",&k);
    printf("Введите число n \n");
    scanf("%d",&n);
    while (k!=0){
	 if(n<0){
	 n=-n;
        }
        t=n%10;
        sum=sum+t;
        n=n/10;
        k=k-1;
    }
    printf("%d \n",sum);
    return 0;
}
