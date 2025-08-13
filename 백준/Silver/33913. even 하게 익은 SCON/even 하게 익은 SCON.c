#include <stdio.h>

#define MOD 1000000007

long long mod_pow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    long long N;
    scanf("%lld", &N);

    long long pow26 = mod_pow(26, N, MOD);
    long long pow22 = mod_pow(22, N, MOD);

    long long ans = (pow26 + pow22) % MOD;
    ans = ans * 500000004 % MOD; // 2의 모듈러 역원

    printf("%lld\n", ans);
    return 0;
}
