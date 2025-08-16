import math

T = int(input())
for _ in range(T):
    a, b = map(int, input().split())
    g = math.gcd(a, b)
    l = a * b // g
    print(l, g)
