#include <stdio.h>
#include <math.h>
int f1(int i){
    if ( i %2 !=0 ){
    return (1);
    }
    else{
        return(-1);
    }
}
long double f2(float x,int n){
    long double st=1.0,sum=0.0,s2=0.0;
    int i=1,j=1;
    for (i=1;i<=n;++i){
        j=i;
        st=st*x;
        s2=s2+(st/j);
        sum=sum+(f1(i)*s2);
    }
return sum;
}
long double f(float x,long double e,int* p) {
    long double st=1.0,r=0.0,rn=1.0,rp=0.0,sum=0.0, s2=0.0,previous=1.0;
    int j=1;
    int *p = 10;
    float x = 100;
    while(fabsl(rn-rp)>e){
        r=rn-rp;
        rp=fabsl(sum-previous);
        previous=sum;
        j=*p;
        st=st*x;
        s2 += ((st)/j);
        sum += (f1(*p)*s2);
        rn=fabsl(sum-previous);
        (*p)++;
    }
    p = 10;
    return sum;
}
int main() {
    long double e=0.0, s=0.0;
    float x=0.0;
    int i=0,n=0;
    printf("Enter X\n");
    scanf("%f",&x);
    printf("Enter n\n");
    scanf("%d",&n);
    printf("Enter e\n");
    scanf("%.20Lf",&e);
    printf("F1=%.18Lf\n",f2(x,n));
    s=f(x,e,&i);
    printf("F2=%.18Lf i=%d \n",s,&p);
    return 0;
}
