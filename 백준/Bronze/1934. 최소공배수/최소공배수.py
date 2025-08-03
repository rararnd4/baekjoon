import math
a=int(input())

for i in range(a):
    n,m=map(int,input().split())
    g=math.gcd(n,m)
    print(n*m//g)