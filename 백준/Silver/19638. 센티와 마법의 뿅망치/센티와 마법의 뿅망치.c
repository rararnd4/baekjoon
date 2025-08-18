#include <stdio.h>

#define MAXN 100005

long long heap[MAXN];
int heap_size = 0;

void push(long long x) {
    int i = ++heap_size;
    while(i > 1 && heap[i/2] < x) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = x;
}

long long pop() {
    long long top = heap[1];
    long long last = heap[heap_size--];
    int i = 1;
    while(i*2 <= heap_size) {
        int c = i*2;
        if(c+1 <= heap_size && heap[c+1] > heap[c]) c++;
        if(last >= heap[c]) break;
        heap[i] = heap[c];
        i = c;
    }
    heap[i] = last;
    return top;
}

int main() {
    int N, T;
    long long Hcenti;
    scanf("%d %lld %d", &N, &Hcenti, &T);
    for(int i=0;i<N;i++){
        long long h;
        scanf("%lld",&h);
        push(h);
    }

    int cnt = 0;
    while(T--) {
        long long top = pop();
        if(top < Hcenti) {
            push(top);
            break;
        }
        if(top > 1) push(top/2);
        else push(top); // 1이면 그대로 다시 push
        cnt++;
    }

    long long maxH = heap[1];
    if(maxH < Hcenti) printf("YES\n%d\n", cnt);
    else printf("NO\n%lld\n", maxH);
}
