n = int(input())

a = [input() for i in range(n)]

a = list(set(a))
a.sort()
a.sort(key=len)

for i in a:
    print(i)