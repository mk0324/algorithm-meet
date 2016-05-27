# https://www.acmicpc.net/problem/10214

def main():
    baseball()

def baseball():
    case = int(input())
    while(case):
        result = 0
        for _ in range(9):
            scores = input().split(' ')
            result = result + int(scores[0]) - int(scores[1])
        print("Yonsei" if result > 0 else "Korea" if result < 0 else "Draw")
        case -= 1

if __name__ == '__main__':
    main()
