#include <stdio.h>

int solve(int S, int T) {
    if (S > T) return 1000; // 불가능한 큰 값
    if (S == T) return 0;
    int a = solve(S+S, T+3);
    int b = solve(S+1, T);
    return 1 + (a < b ? a : b);
}

int main(void) {
    int C, S, T;
    scanf("%d", &C);
    while (C--) {
        scanf("%d %d", &S, &T);
        printf("%d\n", solve(S, T));
    }
    return 0;
}
