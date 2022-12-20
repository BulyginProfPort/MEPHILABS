
#include<stdio.h>
int main(){
    int k1=0,k=0,sum=0,t=0, n1=0 , s=10, c=0;
    int n;
    printf("Введите значение k \n");
    scanf("%d",&k);
    printf("Введите число n \n");
    scanf("%d",&n);
    n1=n;
    while (n1!=0)
    {
        n1=n1/10;
        k1+=1;
    }
    c=k1-k;
    while (c!=1)
    {   c=c-1;
        s=s*10;
    }
    n=n/s;
    while (k!=0)
    {
        if(n<0)
        {
            n=-n;
        }
        t=n%10;
        sum=sum+t;
        k=k-1;
        n=n/10;
    }
    printf("%d\n",sum);
        return 0;
}
//ДОП.ЗАДАНИЕ
