a = int(input())

def fibo(n):
    if n <= 1:
        return n
    b, c = 0, 1
    for _ in range(2, n + 1):
        b, c = c, b + c
    return c

print(fibo(a))
