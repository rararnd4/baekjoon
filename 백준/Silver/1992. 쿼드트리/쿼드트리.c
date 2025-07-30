#include <stdio.h>
#include <string.h>

char map[64][65]; // 한 줄에 최대 64 + '\0'

void compress(int x, int y, int size) {
    char first = map[x][y];
    int same = 1;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (map[i][j] != first) {
                same = 0;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        putchar(first);
        return;
    }

    putchar('(');
    int half = size / 2;
    compress(x, y, half);             // 왼쪽 위
    compress(x, y + half, half);      // 오른쪽 위
    compress(x + half, y, half);      // 왼쪽 아래
    compress(x + half, y + half, half); // 오른쪽 아래
    putchar(')');
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", map[i]);

    compress(0, 0, n);
    return 0;
}
