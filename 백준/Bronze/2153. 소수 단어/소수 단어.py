import math
s = input().strip()

total = 0
for ch in s:
    if 'a' <= ch <= 'z':
        total += ord(ch) - ord('a') + 1
    else:
        total += ord(ch) - ord('A') + 27

def is_prime(x: int) -> bool:
    if x == 1:
        return True
    if x < 2:
        return False
    if x % 2 == 0:
        return x == 2
    r = int(math.isqrt(x))
    for d in range(3, r + 1, 2):
        if x % d == 0:
            return False
    return True

print("It is a prime word." if is_prime(total) else "It is not a prime word.")
