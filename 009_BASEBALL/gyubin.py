# https://www.acmicpc.net/problem/10214

def main():
    case = int(input())
    while(case):
        baseball()
        case -= 1

def baseball():
    result = 0
    for _ in range(9):
        scores = input().split(' ')
        result = result + int(scores[0]) - int(scores[1])
    print("Yonsei" if result > 0 else "Korea" if result < 0 else "Draw")

if __name__ == '__main__':
    main()
