#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[5000];
    for (int i = 0; i < N; i++)
        arr[i] = i + 1;  // 1부터 N까지 넣기

    int index = 0;  // 현재 위치
    int count = N;  // 남은 사람 수

    printf("<");
    while (count > 0) {
        // K번째 사람 찾기
        index = (index + K - 1) % count;

        printf("%d", arr[index]);  // 출력

        // 배열에서 그 사람 빼기
        for (int i = index; i < count - 1; i++)
            arr[i] = arr[i + 1];

        count--;  // 한 명 줄임

        if (count > 0)
            printf(", ");
    }
    printf(">\n");

    return 0;
}
