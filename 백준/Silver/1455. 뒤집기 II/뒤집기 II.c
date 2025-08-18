#include <stdio.h>
char map[105][105];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%s", map[i]);

    int cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = M - 1; j >= 0; j--) {
            if (map[i][j] == '1') {
                cnt++;
                for (int x = 0; x <= i; x++)
                    for (int y = 0; y <= j; y++)
                        map[x][y] = (map[x][y] == '1' ? '0' : '1');
            }
        }
    }
    printf("%d\n", cnt);
}
