n = int(input())
li = list(map(int, input().split()))
cnt = 0
for x in li:
  for i in range(2, x+1):
    if x % i == 0:
      if x == i:
        cnt += 1
      break
print(cnt)