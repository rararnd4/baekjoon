#include <stdio.h>
#include <string.h>
#include <ctype.h>

int used[26];

int main() {
    int N;
    char line[101];
    scanf("%d\n", &N);

    for (int i = 0; i < N; i++) {
        fgets(line, 101, stdin);
        int len = strlen(line);
        if (line[len - 1] == '\n') line[len - 1] = 0;

        int pos = -1;
        // 단어 첫 글자 우선
        for (int j = 0; line[j]; j++) {
            if (j == 0 || line[j - 1] == ' ') {
                char ch = tolower(line[j]);
                if ('a' <= ch && ch <= 'z' && !used[ch - 'a']) {
                    used[ch - 'a'] = 1;
                    pos = j;
                    break;
                }
            }
        }
        // 전체 탐색
        if (pos == -1) {
            for (int j = 0; line[j]; j++) {
                char ch = tolower(line[j]);
                if ('a' <= ch && ch <= 'z' && !used[ch - 'a']) {
                    used[ch - 'a'] = 1;
                    pos = j;
                    break;
                }
            }
        }
        for (int j = 0; line[j]; j++) {
            if (j == pos) printf("[%c]", line[j]);
            else putchar(line[j]);
        }
        puts("");
    }
    return 0;
}
