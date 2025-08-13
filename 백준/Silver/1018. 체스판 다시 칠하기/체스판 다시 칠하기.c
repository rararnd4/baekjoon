#include <stdio.h>
#include <string.h>

char board[51][51];
int N, M;

int min(int a, int b) {
    return a < b ? a : b;
}

// 주어진 8x8 영역에서 다시 칠해야 하는 최소 칸 수 계산
int repaint_count(int x, int y) {
    int cnt1 = 0; // 시작이 W인 경우
    int cnt2 = 0; // 시작이 B인 경우

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // 체스판 패턴에 맞춰서 비교
            if ((i + j) % 2 == 0) { // 짝수칸 → 시작 색
                if (board[x + i][y + j] != 'W') cnt1++;
                if (board[x + i][y + j] != 'B') cnt2++;
            } else { // 홀수칸 → 반대 색
                if (board[x + i][y + j] != 'B') cnt1++;
                if (board[x + i][y + j] != 'W') cnt2++;
            }
        }
    }
    return min(cnt1, cnt2);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", board[i]);
    }

    int answer = 64; // 최대 8x8 전부 다 칠하는 경우

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            int cnt = repaint_count(i, j);
            if (cnt < answer) answer = cnt;
        }
    }

    printf("%d\n", answer);
    return 0;
}
