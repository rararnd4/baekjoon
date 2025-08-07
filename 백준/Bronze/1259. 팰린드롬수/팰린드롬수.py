while True:
    a=input()
    if a == '0':
        break
    t=True
    for i in range(len(a)//2):
        if a[i] != a[len(a)-i-1]:
            print("no")
            t=False
            break
    if t == True:
        print("yes")