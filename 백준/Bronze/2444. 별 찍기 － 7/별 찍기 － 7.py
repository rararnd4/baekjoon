a=int(input())
l=a*2-1
s1=1
for i in range(1,a+1):
    print(' '*(a-i)+'*'*s1)
    s1+=2
s2=s1-4
for i in range(1,a):
    print(' '*i+'*'*s2)
    s2-=2