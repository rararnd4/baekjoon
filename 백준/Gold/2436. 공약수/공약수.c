#include <stdio.h>
long long g(long long a,long long b){return b?g(b,a%b):a;}
int main(){
    long long G,L,a,b,i,m=1e18,A,B;
    scanf("%lld%lld",&G,&L);L/=G;
    for(i=1;i*i<=L;i++)if(L%i==0&&g(i,L/i)==1){
        a=G*i;b=G*(L/i);
        if(a+b<m){m=a+b;A=a;B=b;}
    }
    if(A>B){long long t=A;A=B;B=t;}
    printf("%lld %lld",A,B);
}
