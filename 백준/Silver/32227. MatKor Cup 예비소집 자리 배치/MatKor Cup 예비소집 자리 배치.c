#include <stdio.h>

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    long long N, M;
    scanf("%lld %lld", &N, &M);
    long long g = gcd(N, M);
    printf("%lld/%lld\n", N / g, M / g);
    return 0;
}
