import math

a, b = map(int, input().split())
for i in range(a, b + 1):
    if i < 2:
        continue
    t = True
    for j in range(2, int(math.sqrt(i)) + 1):
        if i % j == 0:
            t = False
            break
    if t:
        print(i)
