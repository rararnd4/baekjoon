#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[101][101]; // n 최대 크기에 맞게 조정

    // 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // 플로이드-워셜 형태로 경로 갱신
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][k] && a[k][j]) {
                    a[i][j] = 1;
                }
            }
        }
    }

    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
