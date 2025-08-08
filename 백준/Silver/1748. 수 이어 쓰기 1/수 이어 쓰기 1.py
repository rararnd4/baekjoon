a = int(input())

length = 0
digit = 1
start = 1

while True:
    end = start * 10 - 1
    if a <= end:
        length += (a - start + 1) * digit
        break
    else:
        length += (end - start + 1) * digit
        start *= 10
        digit += 1

print(length)
