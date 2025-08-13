#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int dp[N + 1];   // 최소 연산 횟수
    int prev[N + 1]; // 경로 복원을 위한 이전 값
    dp[1] = 0;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        prev[i] = i - 1;

        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            prev[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            prev[i] = i / 3;
        }
    }

    // 최소 연산 횟수 출력
    printf("%d\n", dp[N]);

    // 경로 출력
    int path[N]; // 경로 저장
    int idx = 0;
    int x = N;
    while (x != 0) {
        path[idx++] = x;
        if (x == 1) break;
        x = prev[x];
    }

    for (int i = 0; i < idx; i++) {
        printf("%d ", path[i]);
    }

    return 0;
}
