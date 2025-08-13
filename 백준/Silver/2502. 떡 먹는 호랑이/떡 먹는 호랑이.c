#include <stdio.h>

int main() {
    int D, K;
    scanf("%d %d", &D, &K);

    int coeffA[31] = {0};
    int coeffB[31] = {0};

    // 첫째 날, 둘째 날 초기값
    coeffA[1] = 1; coeffB[1] = 0;
    coeffA[2] = 0; coeffB[2] = 1;

    // 피보나치처럼 계수 계산
    for (int i = 3; i <= D; i++) {
        coeffA[i] = coeffA[i - 1] + coeffA[i - 2];
        coeffB[i] = coeffB[i - 1] + coeffB[i - 2];
    }

    // A, B 찾기
    for (int A = 1; A <= K; A++) {
        int rest = K - coeffA[D] * A;
        if (rest % coeffB[D] == 0) {
            int B = rest / coeffB[D];
            if (A >= 1 && A <= B) {
                printf("%d\n%d\n", A, B);
                break;
            }
        }
    }

    return 0;
}
