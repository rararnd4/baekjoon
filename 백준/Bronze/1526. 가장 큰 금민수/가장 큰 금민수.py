a = int(input())
m = 0
for i in range(1, a+1):
    if all(b in '47' for b in str(i)):
        m = i
print(m)
