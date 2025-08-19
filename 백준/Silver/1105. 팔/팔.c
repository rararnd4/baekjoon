#include <stdio.h>

int lo(int n){
    int cnt = 0;
    while(n){
        n /= 10;
        cnt++;
    }
    return cnt;
}
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int l = lo(a);
    int cnt = 0;
    for(int i = 0; i < l; i++){
        if(a % 10 == 8){
            if(b - a == 0) cnt++;
        }
        a /= 10;
        b /= 10;
    }
    printf("%d", cnt);
}
