import sys
rl = lambda: sys.stdin.readline()
L26 = 1.414973347970818
for cases in range(int(rl())):
    pwd = []
    maxV = 0
    for i in range(int(rl())):
        s = str(rl()[0:-1])
        tmpSum = sum(c.isdigit() for c in s)
        tmpSum += (len(s)-tmpSum)*L26
        if tmpSum < maxV:
            continue
        if tmpSum > maxV:
            maxV = tmpSum
            pwd = [s]
        elif tmpSum == maxV:
            pwd.append(s)
    if len(pwd) > 1:
        pwd.sort()
    print(pwd[0])
