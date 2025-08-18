e, f, c = map(int, input().split())
bottles = e + f
ans = 0

while bottles >= c:
    new = bottles // c
    ans += new
    bottles = new + bottles % c

print(ans)
