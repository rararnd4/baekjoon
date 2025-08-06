#include <stdio.h>

int N, M, money[100000];

// K원이면 M번 안에 가능한지 확인
int check(int K) {
    int count = 1, left = K;
    for (int i = 0; i < N; i++) {
        if (money[i] > K) return 0;
        if (left < money[i]) {
            count++;
            left = K;
        }
        left -= money[i];
    }
    return count <= M;
}

int main() {
    scanf("%d %d", &N, &M);
    int max = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &money[i]);
        if (money[i] > max) max = money[i];
        sum += money[i];
    }

    int left = max, right = sum, ans = sum;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}
