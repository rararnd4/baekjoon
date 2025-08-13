#include <stdio.h>

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    long long k = n2 - n1 + 1;
    long long ans = k * (k - 1) / 2;

    printf("%lld\n", ans);
    return 0;
}
