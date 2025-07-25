def sol(b, ans):
    if len(b) == 2:
        return ans
    
    m = 0
    for i in range(1, len(b) - 1):
        s = b[i - 1] * b[i + 1]
        li = b[:i] + b[i+1:]
        m = max(m, sol(li, ans + s))
    return m

n = int(input())
b = list(map(int, input().split()))
print(sol(b, 0))
