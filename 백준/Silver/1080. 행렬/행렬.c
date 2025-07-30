#include <stdio.h>

int A[50][50], B[50][50];
int N, M;

void flip(int x, int y) {
    for (int i = x; i < x + 3; i++)
        for (int j = y; j < y + 3; j++)
            A[i][j] = 1 - A[i][j];  // 0->1, 1->0
}

int main() {
    scanf("%d %d", &N, &M);

    // 입력 받기
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%1d", &A[i][j]);  // 한 글자씩 입력

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%1d", &B[i][j]);

    int count = 0;
    // 왼쪽 위부터 3x3 뒤집기 가능한 곳만 탐색
    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= M - 3; j++) {
            if (A[i][j] != B[i][j]) {
                flip(i, j);
                count++;
            }
        }
    }

    // A와 B가 완전히 같은지 확인
    int same = 1;
    for (int i = 0; i < N && same; i++)
        for (int j = 0; j < M && same; j++)
            if (A[i][j] != B[i][j])
                same = 0;

    printf("%d\n", same ? count : -1);
    return 0;
}
