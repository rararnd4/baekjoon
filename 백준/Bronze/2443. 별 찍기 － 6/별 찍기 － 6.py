a=int(input())
l=2*a-1
for i in range(a,0,-1):
    print(' '*((l-(i*2-1))//2)+'*'*(i*2-1))
