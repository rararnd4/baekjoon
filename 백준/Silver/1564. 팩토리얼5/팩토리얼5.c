#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    long long res = 1;
    int count2 = 0, count5 = 0;
    
    for (int i = 2; i <= n; i++) {
        int x = i;
        
        // 2의 개수 세기
        while (x % 2 == 0) {
            count2++;
            x /= 2;
        }
        // 5의 개수 세기
        while (x % 5 == 0) {
            count5++;
            x /= 5;
        }
        
        res *= x;
        
        // 너무 커지면 줄임
        if (res > 100000000000LL)
            res %= 100000000000LL;
    }
    
    // 2의 개수에서 5의 개수를 빼서 0의 개수만큼 2 곱하기
    int diff = count2 - count5;
    for (int i = 0; i < diff; i++) {
        res *= 2;
        if (res > 100000000000LL)
            res %= 100000000000LL;
    }
    
    // 뒤 0 제거 (이 경우 없을 수도 있지만 안전하게)
    while (res % 10 == 0)
        res /= 10;
    
    // 마지막 5자리만 출력
    res %= 100000;
    printf("%05lld\n", res);
    
    return 0;
}
