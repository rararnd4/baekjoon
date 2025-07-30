#include <stdio.h>
#include <string.h>

#define MAX 1001

int n, m;
int board[MAX][MAX]; // 0: 안전, 1: 말 있음, 2: 공격 범위

// Knight 이동 방향 (8방향)
int dxK[8] = {-2,-1,1,2,2,1,-1,-2};
int dyK[8] = {1,2,2,1,-1,-2,-2,-1};

// Queen 이동 방향 (8방향 직선+대각선)
int dxQ[8] = {-1,-1,-1,0,1,1,1,0};
int dyQ[8] = {-1,0,1,1,1,0,-1,-1};

void placeAttackQueen(int x, int y) {
    for (int d = 0; d < 8; d++) {
        int nx = x + dxQ[d];
        int ny = y + dyQ[d];
        while (nx >= 1 && ny >= 1 && nx <= n && ny <= m) {
            if (board[nx][ny] == 1) break; // 장애물
            if (board[nx][ny] == 0) board[nx][ny] = 2;
            nx += dxQ[d];
            ny += dyQ[d];
        }
    }
}

void placeAttackKnight(int x, int y) {
    for (int d = 0; d < 8; d++) {
        int nx = x + dxK[d];
        int ny = y + dyK[d];
        if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && board[nx][ny] == 0)
            board[nx][ny] = 2;
    }
}

int main() {
    scanf("%d %d", &n, &m);

    int q, x, y;
    // Queen 위치
    scanf("%d", &q);
    int qx[100], qy[100];
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &qx[i], &qy[i]);
        board[qx[i]][qy[i]] = 1;
    }

    // Knight 위치
    int k;
    scanf("%d", &k);
    int kx[100], ky[100];
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &kx[i], &ky[i]);
        board[kx[i]][ky[i]] = 1;
    }

    // Pawn 위치
    int p;
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        scanf("%d %d", &x, &y);
        board[x][y] = 1;
    }

    // Queen 공격 범위 마킹
    for (int i = 0; i < q; i++)
        placeAttackQueen(qx[i], qy[i]);

    // Knight 공격 범위 마킹
    for (int i = 0; i < k; i++)
        placeAttackKnight(kx[i], ky[i]);

    // 안전한 칸 세기
    int safe = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (board[i][j] == 0)
                safe++;

    printf("%d\n", safe);
    return 0;
}
