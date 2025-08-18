#include <stdio.h>
#include <stdlib.h>

typedef struct { int *stk, top; } Stack;

int main(){
    int n,p,i,s,t,c=0;
    scanf("%d%d",&n,&p);
    Stack f[7];
    for(i=1;i<=6;i++){ f[i].stk=malloc((p+1)*sizeof(int)); f[i].top=0; }
    while(n--){
        scanf("%d%d",&s,&t);
        while(f[s].top && f[s].stk[f[s].top-1]>t)c++,f[s].top--;
        if(!f[s].top || f[s].stk[f[s].top-1]<t)c++,f[s].stk[f[s].top++]=t;
    }
    printf("%d",c);
}
