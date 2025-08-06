#include <stdio.h>
#include <math.h>

// 소수인지 판별하는 함수 (제곱근 이용)
int is_prime(int num) {
    if (num < 2) return 0;
    int limit = (int)sqrt(num);
    for (int i = 2; i <= limit; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// 팰린드롬인지 판별하는 함수
int is_palindrome(int num) {
    int rev = 0, original = num;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev == original;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = N;; i++) {  // 무한 반복하며 조건 만족하는 수 찾기
        if (is_palindrome(i) && is_prime(i)) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
