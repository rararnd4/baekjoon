a,b=input().split()
la,lb=len(a),len(b)
al=[a[i] for i in range(len(a))]
bl=[b[i] for i in range(len(b))]
s=0
for i in range(len(a)):
    for j in range(len(b)):
        s+=int(a[i])*int(b[j])
print(s)