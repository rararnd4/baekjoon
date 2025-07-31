import sys
import math
G, L = map(int, sys.stdin.readline().split())
mul = L // G
min_sum = float('inf')
res = (0, 0)
for i in range(1, int(math.sqrt(mul)) + 1):
    if mul % i == 0:
        j = mul // i
        if math.gcd(i, j) == 1:
            a, b = G * i, G * j
            if a > b:
                a, b = b, a
            if a + b < min_sum:
                min_sum = a + b
                res = (a, b)
print(*res)