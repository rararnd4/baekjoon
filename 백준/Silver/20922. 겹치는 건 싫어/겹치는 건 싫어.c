#include <stdio.h>
#include <string.h>

#define MAX_N 200000
#define MAX_A 100000

int arr[MAX_N];
int count[MAX_A + 1];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int left = 0, right = 0;
    int max_len = 0;

    for (right = 0; right < N; right++) {
        count[arr[right]]++;

        while (count[arr[right]] > K) {
            count[arr[left]]--;
            left++;
        }

        if (right - left + 1 > max_len)
            max_len = right - left + 1;
    }

    printf("%d\n", max_len);

    return 0;
}
