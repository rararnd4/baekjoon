#include <stdio.h>

int count = 0;
int A, B;

void dfs(long long num) {
    if (num > B) return;  // 범위 초과 시 종료
    if (num >= A) count++;  // 범위 내일 때만 카운트

    dfs(num * 10 + 4);  // 다음 자리 4
    dfs(num * 10 + 7);  // 다음 자리 7
}

int main() {
    scanf("%d %d", &A, &B);

    dfs(4);
    dfs(7);

    printf("%d\n", count);
    return 0;
}
