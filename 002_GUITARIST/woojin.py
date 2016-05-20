import sys
rl = lambda: sys.stdin.readline()
N, S, M = map(int, rl().split())
V = list(map(int, rl().split()))
p = dict()
        
def getVal(idx1, idx2):
    idx = (idx1, idx2)

    if idx in p:
        return p[idx]
    if idx1 == N:
        return idx2

    tmp1, tmp2 = -1, -1

    if idx2+V[idx1] <= M:
        tmp1 = getVal(idx1+1, idx2+V[idx1])
    if idx2-V[idx1] >= 0:
        tmp2 = getVal(idx1+1, idx2-V[idx1])
    if tmp1 > tmp2: p[idx] = tmp1
    else:           p[idx] = tmp2
    return p[idx]
print(getVal(0,S))
