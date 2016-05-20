for case in range(int(input())):
    N = input()
    p = list(map(int, input().split()))
    profit = 0
    curVal = 0
    for i in reversed(p):
        if curVal > i:
            profit += curVal - i
        else:
            curVal = i
    print(profit)
