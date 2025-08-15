while True:
    try:
        n, k = map(int, input().split())
    except EOFError:
        break

    chicken = n
    stamp = n

    while stamp >= k:
        extra = stamp // k
        chicken += extra
        stamp = stamp % k + extra

    print(chicken)
