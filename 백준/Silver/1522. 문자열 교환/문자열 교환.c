#include <stdio.h>
#include <string.h>

int main() {
    char s[2001]; 
    char doubled[4002];
    int len, a_count = 0, min_swaps, i;

    scanf("%s", s);
    len = strlen(s);

    // 'a' 개수 세기
    for (i = 0; i < len; i++) {
        if (s[i] == 'a') a_count++;
    }

    // 문자열 2번 붙여서 원형 표현
    for (i = 0; i < len * 2; i++) {
        doubled[i] = s[i % len];
    }
    doubled[len * 2] = '\0';

    // 처음 구간 설정
    int current_non_a = 0;
    for (i = 0; i < a_count; i++) {
        if (doubled[i] != 'a') current_non_a++;
    }
    min_swaps = current_non_a;

    // 슬라이딩 윈도우로 최소값 탐색
    for (i = a_count; i < len * 2; i++) {
        if (doubled[i - a_count] != 'a') current_non_a--;
        if (doubled[i] != 'a') current_non_a++;
        if (i - a_count + 1 < len) { // 윈도우가 원래 문자열 길이를 넘지 않도록
            if (current_non_a < min_swaps) min_swaps = current_non_a;
        }
    }

    printf("%d\n", min_swaps);
    return 0;
}
