def brackets2(b_str):
    m_dict = {'{':'}', '[':']', '(':')'}
    # 문자열 길이가 홀수 or 길이가 0 or 첫 글자가 시작 형태가 아니면 NO 출력
    if len(b_str) % 2 or len(b_str) == 0 or b_str[0] not in m_dict:
        print("NO")
        return

    stack = [];
    for c in list(b_str):   # 문자열 문자 하나하나 쪼개서 반복
        if c in m_dict:     # 문자가 시작 형태라면
            stack.append(c) # stack 리스트에 추가
        else:  # 시작형태가 아니라면
            if len(stack) != 0 and m_dict[stack[-1]] == c:  # stack이 비지 않고, 바로 직전의 문자와 동일한 형태일 때
                stack.pop(-1)           # 직전 문자를 없앤다.
            else:                       # 직전 문자와 다른 형태라면
                print("NO")             # NO 출력하고 바로 리턴해서 종료
                return

    print("NO" if stack else "YES") # stack이 비었을 때만 YES 출력

if __name__ == '__main__':
    case = int(input())
    while(case):
        b_str = input()
        brackets2(b_str)
        case -= 1

# 문제 링크: https://algospot.com/judge/problem/read/BRACKETS2
# 입력
# 3
# ()()
# ({[}])
# ({}[(){}])
# 출력
# YES
# NO
# YES
