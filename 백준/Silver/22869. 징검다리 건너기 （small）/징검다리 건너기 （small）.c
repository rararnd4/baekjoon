#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int A[5000];
    for (int i=0;i<N;i++) scanf("%d",&A[i]);

    int reachable[5000]={0};
    reachable[0]=1;

    for(int i=0;i<N;i++) if(reachable[i])
        for(int j=i+1;j<N;j++)
            if((j-i)*(1+abs(A[i]-A[j]))<=K) reachable[j]=1;

    puts(reachable[N-1]?"YES":"NO");
}
