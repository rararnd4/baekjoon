import math

D, H, W = map(int, input().split())
k = D / math.sqrt(H**2 + W**2)
print(int(H * k), int(W * k))
